#ifndef SCREEN_H
#define SCREEN_H

#include <stdint.h>
#include "ScreenBuffer.h"
#include "Color.h"

class Vec2D;
class Line2D;
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

private:
	// Make it non Copyable
	Screen(const Screen& oScreen);
	Screen& operator=(const Screen& oScreen);

	void ClearScreen();

	uint32_t mWidth, mHeight;

	Color mClearColor;
	ScreenBuffer mBackBuffer;

	SDL_Window* oWindow;
	SDL_Surface* noWindowSurface;


};

#endif
