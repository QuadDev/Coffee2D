#pragma once
//META INFO
//Author: ¾ç±³¿ø(gyowonhikari@gmail.com)

namespace Coffee2D
{
		class ENGINE_API Vec2
		{
		public:
			Vec2(float xx, float yy);

			Vec2(float value);

			Vec2(const Vec2& value);

			Vec2(Vec2&& value);

			Vec2();

			//Get, Setter X
			GETSETTER(float, x, X);

			//Get, Setter Y
			GETSETTER(float, y, Y);

			//Compute Function
			//Add Value at Vector
			void add(float value);

			//Multiply Value at Vector
			void multiply(float value);

			//Divide Value at Vector
			void divide(float value);

			//Check this Vector is Zero(x == 0, y == 0)
			bool isZero() const;

			//Check this Vector is One(x == 1, y == 1)
			bool isOne() const;

			//Check this Vector is Unit(Vector Size == 1)
			bool isUnit() const;

			//Check this Vector and Target Vector is Equal (Src.x == Target.x, Src.y == Target.y)
			bool isEqual(const Vec2& target);

			//Get this Vector's Unit Vector (x/VectorSize, y/VectorSize)
			Vec2 getUnit() const;

			//Normalize this Vector (x = x/VectorSize, y = y/VectorSize)
			void normalize();

			//Get Squared Vector Size {(x * x) + (y * y)}
			float getSquaredSize() const;

			//Get Vector Size {sqrt(Squared Vector Size)}
			float getSize() const;

			//Get Vector's Dot Product {(Src.x * Target.x) + (Src.y * Target.y)}
			float dot(const Vec2& target) const;

			//Get Vector's Simillar Cross Product (x = -Src.y, y = Src.originX)
			Vec2 sCross() const;

			//Get Vector's Angle { acos(dot / (VectorSize * target.VectorSize)) }
			//Return to Radian
			float angle(const Vec2& target) const;

			//Get Vector's Angle
			//Return to Degree
			float angleDegree(const Vec2& target) const;

		private:
			//Member Var
			float x; //x Scalar
			float y; //y Scalar

		};
}
