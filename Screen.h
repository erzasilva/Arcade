#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include <vector>
#include "ScreenBuffer.h"
#include "Color.h"

class Vec2D;
class Line2D;
class Triangle;
class Rectangle;
class Circle;
struct SDL_Window;
struct SDL_Surface;


class Screen
{
public:
	Screen();
	~Screen();

	SDL_Window* Init(uint32_t width, uint32_t height, uint32_t mag);

	void SwapScreen();

	inline void SetClearColor(const Color& clearColor) { mClearColor = clearColor; }
	inline uint32_t Width() const { return mWidth; }
	inline uint32_t Height() const { return mHeight; }

	//Drawing Calls

	void Draw(int x, int y, const Color& color);
	void Draw(const Vec2D& point, const Color& color);
	void Draw(const Line2D& line, const Color& color);
	void Draw(const Triangle& triangle, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const Rectangle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());
	void Draw(const Circle& rect, const Color& color, bool fill = false, const Color& fillColor = Color::White());

private:
	// Make it non Copyable
	Screen(const Screen& oScreen);
	Screen& operator=(const Screen& oScreen);

	void ClearScreen();
	void PolyFill(const std::vector<Vec2D> points, const Color& color);

	uint32_t mWidth, mHeight;

	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* oWindow;
	SDL_Surface* noWindowSurface;


};

#endif
