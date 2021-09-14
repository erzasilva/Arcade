#include "Screen.h"
#include "Vec2D.h"
#include "SDL.h"
#include "Line2D.h"
#include <cmath>
#include <cassert>

Screen::Screen():mWidth(0), mHeight(0), oWindow(nullptr), noWindowSurface(nullptr)
{

}

Screen::~Screen()
{
	if (oWindow)
	{
		SDL_DestroyWindow(oWindow);
		oWindow = nullptr;
	}
	SDL_Quit();
}

SDL_Window* Screen::Init(uint32_t width, uint32_t height, uint32_t mag)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Error SDL_Init Failed!";
		return nullptr;
	}
	mWidth = width;
	mHeight = height;

	oWindow = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, mWidth * mag, mHeight * mag, SDL_WINDOW_SHOWN);

	if (oWindow)
	{
		noWindowSurface = SDL_GetWindowSurface(oWindow);
		SDL_PixelFormat* pFormat = noWindowSurface->format;
		Color::InitColorFormat(pFormat);

		mClearColor = Color::Black();

		mBackBuffer.Init(pFormat->format, mWidth, mHeight);

		mBackBuffer.Clear(mClearColor);
	}
	return oWindow;
	
}

void Screen::SwapScreen()
{
	assert(oWindow);
	if (oWindow)
	{
		ClearScreen();
		SDL_BlitScaled(mBackBuffer.GetSurface(), nullptr, noWindowSurface, nullptr);
		SDL_UpdateWindowSurface(oWindow);

		mBackBuffer.Clear(mClearColor);
	}
}


void Screen::Draw(int x, int y, const Color& color)
{
	assert(oWindow);
	if (oWindow)
	{
		mBackBuffer.SetPixel(color, x, y);
	}
}

void Screen::Draw(const Vec2D& point, const Color& color)
{
	assert(oWindow);
	if (oWindow)
	{
		mBackBuffer.SetPixel(color, point.GetX(), point.GetY());
	}
}

void Screen::Draw(const Line2D& line, const Color& color)
{
	assert(oWindow);
	if (oWindow)
	{
		int dx, dy;

		int x0 = roundf(line.GetP0().GetX());
		int y0 = roundf(line.GetP0().GetY());
		int x1 = roundf(line.GetP1().GetX());
		int y1 = roundf(line.GetP1().GetY());

		dx = x1 - x0;
		dy = y1 - y0;

		signed const char ix((dx > 0) - (dx < 0)); //evaluates to 1 or -1
		signed const char iy((dy > 0) - (dy < 0)); //evaluates to 1 or -1

		dx = abs(dx) * 2;
		dy = abs(dy) * 2;

		Draw(x0, y0, color);

		if (dx > dy)
		{
			//go along in the x axis
			int d = dy - dx / 2;

			while (x0 != x1)
			{
				if (d > 0)
				{
					d -= dx;
					y0 += iy;
				}

				d += dy;
				x0 += ix;
				Draw(x0, y0, color);
			}
		}
		else
		{
			int d = dx - dy / 2;

			while (y0 != y1)
			{
				if (d > 0)
				{
					d -= dy;
					x0 += ix;
				}

				d += dx;
				y0 += iy;
				Draw(x0, y0, color);
			}
		}
	}
}

void Screen::ClearScreen()
{
	assert(oWindow);
	if (oWindow)
	{
		SDL_FillRect(noWindowSurface, nullptr, mClearColor.GetPixelColor());
	}
}