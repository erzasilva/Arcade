#include "Color.h"
#include "SDL.h"

const SDL_PixelFormat* Color::mFormat = nullptr;
void Color::InitColorFormat(const SDL_PixelFormat* format)
{
	Color::mFormat = format;
}

Color::Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
	SetRGBA(R, G, B, A);
}

void Color::SetRGBA(uint8_t R, uint8_t G, uint8_t B, uint8_t A)
{
	mColor = SDL_MapRGBA(mFormat, R, G, B, A);
}

void Color::SetRed(uint8_t red)
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	SetRGBA(red, g, b, a);
}

void Color::SetGreen(uint8_t green)
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	SetRGBA(r, green, b, a);
}

void Color::SetBlue(uint8_t blue)
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	SetRGBA(r, g, blue, a);
}

void Color::SetAlpha(uint8_t alpha)
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	SetRGBA(r, g, b, alpha);
}


uint8_t Color::GetRed() const
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	return r;
}

uint8_t Color::GetGreen() const
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	return g;
}

uint8_t Color::GetBlue() const
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	return b;
}

uint8_t Color::GetAlpha() const
{
	uint8_t r, g, b, a;

	SDL_GetRGBA(mColor, mFormat, &r, &g, &b, &a);
	return a;
}
