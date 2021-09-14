#include <iostream>
#ifndef Vec2D_H
#define Vec2D_H

class Vec2D
{
	public:

		static const Vec2D ZERO;

		Vec2D() : Vec2D(0, 0) {}
		Vec2D(float x, float y) : mX(x), mY(y) {}

		inline void SetX(float x) { mX = x; }
		inline void SetY(float y) { mY = y; }
		inline float GetX() const { return mX; }
		inline float GetY() const { return mY; }

		//Operator Overloads
		//Ostream Overload
		friend std::ostream& operator<<(std::ostream& consoleOut, const Vec2D& vec);

		//Comparison Overloads
		bool operator==(const Vec2D& V2) const;
		bool operator!=(const Vec2D& V2) const;

		//Unary Overloads
		Vec2D operator-() const ;

		//Scalar
		Vec2D operator*(float scale) const;
		Vec2D operator/(float scale) const;
		Vec2D& operator*=(float scale);
		Vec2D& operator/=(float scale);
		friend Vec2D operator*(float scale, Vec2D& V1);

		//Vector Math Operator overloads
		Vec2D operator+(const Vec2D& V1) const;
		Vec2D operator-(const Vec2D& V1) const;
		Vec2D& operator+=(const Vec2D& V1);
		Vec2D& operator-=(const Vec2D& V1);


		//Helpers
		float Mag2() const;
		float Mag() const; 
		Vec2D GetUnitVec() const;
		Vec2D& Normalize();
		float Distance(const Vec2D& V2) const;
		float Dot(const Vec2D& V2) const;
		Vec2D ProjectOnto(const Vec2D& V2) const;
		float AngleBetween(const Vec2D& V2) const;
		Vec2D Reflect(const Vec2D& normal) const;

		void Rotate(float angle, const Vec2D& aroundPoint);
		Vec2D RotationResult(float angle, const Vec2D& aroundPoint) const;

	private:
		float mX, mY;
};

#endif