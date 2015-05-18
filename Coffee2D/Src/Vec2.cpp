#include "Engine.hpp"
#include "Vec2.hpp"

namespace Coffee2D
{
		Vec2::Vec2(float xx, float yy) :
			x(xx),
			y(yy)
		{

		}

		Vec2::Vec2(float value) :
			Vec2(value, value)
		{

		}

		Vec2::Vec2() : Vec2(0.0f)
		{
			
		}

		Vec2::Vec2(const Vec2& value) :
			Vec2(value.x, value.y)
		{

		}

		Vec2::Vec2(Vec2&& value) :
			Vec2(value.x, value.y)
		{

		}

		void Vec2::add(float value)
		{
			this->x += value;
			this->y += value;
		}

		void Vec2::multiply(float value)
		{
			this->x *= value;
			this->y *= value;
		}

		void Vec2::divide(float value)
		{
			this->x /= value;
			this->y /= value;
		}

		bool Vec2::isZero() const
		{
			return this->x == 0.0f &&
				this->y == 0.0f;
		}

		bool Vec2::isOne() const
		{
			return this->x == 1.0f &&
				this->y == 1.0f;
		}

		bool Vec2::isUnit() const
		{
			return this->getSize() == 1.0f;
		}

		bool Vec2::isEqual(const Vec2& target)
		{
			return this->x == target.x && 
				this->y == target.y;
		}

		Vec2 Vec2::getUnit() const
		{
			return Vec2(this->x / this->getSize(),
				this->y / this->getSize());
		}

		void Vec2::normalize()
		{
			float size = this->getSize();
			this->x = this->x / size;
			this->y = this->y / size;
		}

		float Vec2::getSquaredSize() const
		{
			return (this->x * this->x) + (this->y * this->y);
		}

		float Vec2::getSize() const
		{
			return sqrtf(this->getSquaredSize());
		}

		float Vec2::dot(const Vec2& target) const
		{
			return (this->x * target.x) + (this->y * target.y);
		}

		Vec2 Vec2::sCross() const
		{
			return Vec2(-this->y, this->x);
		}

		float Vec2::angle(const Vec2& target) const
		{
			return acosf(this->dot(std::move(target)) / 
				(this->getSize() * target.getSize()));
		}

		float Vec2::angleDegree(const Vec2& target) const
		{
			return D3DXToDegree(this->angle(target));
		}
}