#include "Screen.h"
#include "Vec2D.h"
#include "SDL.h"
#include "Line2D.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Utils.h"
#include <algorithm>
#include <cmath>
#include <cassert>
#include <vector>

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
		SDL_PixelFormat* pFormat = SDL_AllocFormat(SDL_PIXELFORMAT_ABGR8888);
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

void Screen::Draw(const Triangle& triangle, const Color& color, bool fill, const Color& fillColor)
{
	Line2D P0tP1 = Line2D(triangle.GetP0(), triangle.GetP1());
	Line2D P1tP2 = Line2D(triangle.GetP1(), triangle.GetP2());
	Line2D P2tP0 = Line2D(triangle.GetP2(), triangle.GetP0());
	if (fill)
	{
		PolyFill(triangle.GetPoints(), fillColor);
	}

	Draw(P0tP1, color);
	Draw(P1tP2, color);
	Draw(P2tP0, color);

}

void Screen::Draw(const Rectangle& rect, const Color& color, bool fill, const Color& fillColor)
{
	if (fill)
	{
		PolyFill(rect.GetPoints(), fillColor);
	}
	std::vector<Vec2D> points = rect.GetPoints();
	Line2D P0tP1 = Line2D(points[0], points[1]);
	Line2D P1tP2 = Line2D(points[1], points[2]);
	Line2D P2tP3 = Line2D(points[2], points[3]);
	Line2D P3tP0 = Line2D(points[3], points[0]);

	Draw(P0tP1, color);
	Draw(P1tP2, color);
	Draw(P2tP3, color);
	Draw(P3tP0, color);

}

void Screen::Draw(const Circle& circle, const Color& color, bool fill, const Color& fillColor)
{
	static unsigned int NUM_CIRCLE_SEGMENTS = 30;

	std::vector<Vec2D> CirclePoints;
	std::vector<Line2D> lines;

	float angle = TWO_PI / float(NUM_CIRCLE_SEGMENTS);

	Vec2D P0 = Vec2D(circle.GetCenterPoint().GetX() + circle.GetRadius(), circle.GetCenterPoint().GetY());
	Vec2D P1 = P0;

	Line2D nextLinetoDraw;

	for (unsigned int i = 0; i < NUM_CIRCLE_SEGMENTS; i++)
	{
		P1.Rotate(angle, circle.GetCenterPoint());
		nextLinetoDraw.SetP1(P1);
		nextLinetoDraw.SetP0(P0);

		lines.push_back(nextLinetoDraw);
		//Draw(nextLinetoDraw, color);

		P0 = P1;
		CirclePoints.push_back(P0);

	}

	if (fill)
	{
		PolyFill(CirclePoints, fillColor);
	}

	for (const Line2D& line : lines)
	{
		Draw(line, color);
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

void Screen::PolyFill(const std::vector<Vec2D> points, const Color& color)
{
	if (points.size() > 0)
	{
		float top = points[0].GetY();
		float bottom = points[0].GetY();
		float right = points[0].GetX();
		float left = points[0].GetX();

		for (size_t i = 0; i < points.size(); i++)
		{
			if (points[i].GetY() < top)
			{
				top = points[i].GetY();
			}
			if (points[i].GetY() > bottom)
			{
				bottom = points[i].GetY();
			}
			if (points[i].GetX() < left)
			{
				left = points[i].GetX();
			}
			if (points[i].GetX() > right)
			{
				right = points[i].GetX();
			}
		}

		for (int pixelY = top; pixelY < bottom; ++pixelY)
		{
			std::vector<float> nodeXVec;
			size_t j = points.size() - 1;

			for (size_t i = 0; i < points.size(); ++i)
			{
				float pointiY = points[i].GetY();
				float pointjY = points[j].GetY();

				if ((pointiY <= (float)pixelY && pointjY > (float)pixelY) || (pointjY <= (float)pixelY && pointiY > (float)pixelY))
				{
					float denom = pointjY - pointiY;
					if (IsEqual(denom, 0))
					{
						continue;
					}

					float x = points[i].GetX() + (pixelY - pointiY) / (denom) * (points[j].GetX() - points[i].GetX());
					nodeXVec.push_back(x);

				}
				j = i;
			}
			std::sort(nodeXVec.begin(), nodeXVec.end(), std::less<>());

			for (size_t k = 0; k < nodeXVec.size(); k += 2)
			{
				if (nodeXVec[k] > right)
				{
					break;
				}
				if (nodeXVec[k + 1] > left)
				{
					if (nodeXVec[k] < left)
					{
						nodeXVec[k] = left;
					}
					if (nodeXVec[k + 1] > right)
					{
						nodeXVec[k + 1] = right;
					}

					/*
					Line2D line = { Vec2D(nodeXVec[k], pixelY), Vec2D(nodeXVec[k + 1], pixelY) };
					Draw(line, color);
					*/

					for (int pixelX = nodeXVec[k]; pixelX < nodeXVec[k + 1]; ++pixelX)
					{
						Draw(pixelX, pixelY, color);
					}
				}
			}
		}

		
	}
}