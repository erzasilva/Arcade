#ifndef COLOR_H
#define COLOR_H
#include <stdint.h>

struct SDL_PixelFormat;

class Color {
private:
	uint32_t mColor;
public:
	
	static const SDL_PixelFormat* mFormat;
	static void InitColorFormat(const SDL_PixelFormat* format);
	
	static Color Black() { return Color(0, 0, 0, 255); }
	static Color White() { return Color(255, 255, 255, 255); }
	static Color Red() { return Color(255, 0, 0, 255); }
	static Color Green() { return Color(0, 255, 0, 255); }
	static Color Blue() { return Color(0, 0, 255, 255); }
	static Color Yellow() { return Color(255, 255, 0, 255); }
	static Color Magenta() { return Color(255, 0, 255, 255); }
	static Color Cyan() { return Color(37, 240, 217, 255); }
	static Color Pink() { return Color(252, 197, 224, 255); }
	static Color Orange() { return Color(245, 190, 100, 255); }
	

	Color(): Color(0){}
	Color(uint32_t color) { mColor = color; }
	Color(uint8_t R, uint8_t G, uint8_t B, uint8_t A);

	inline bool operator=(const Color& c) const { return mColor == c.mColor; }
	inline bool operator!=(const Color & c) const { return !(mColor == c.mColor); }
	inline uint32_t GetPixelColor() const { return mColor; }

	void SetRGBA(uint8_t R, uint8_t G, uint8_t B, uint8_t A);

	void SetRed(uint8_t red);
	void SetGreen(uint8_t green);
	void SetBlue(uint8_t blue);
	void SetAlpha(uint8_t alpha);

	uint8_t GetRed() const;
	uint8_t GetGreen() const;
	uint8_t GetBlue() const;
	uint8_t GetAlpha() const;

};


#endif
