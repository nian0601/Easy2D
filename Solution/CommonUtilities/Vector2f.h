#pragma once

#include <cassert>
#include <cmath>

namespace CU
{
	class Vector2f
	{
	public:
		Vector2f(float aX = 0.f, float aY = 0.f)
			: x(aX)
			, y(aY)
		{}

		float x;
		float y;

		//*************************
		//	VECTOR MATH OPERATORS
		//*************************
		friend Vector2f operator+=(Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator+(const Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator-=(Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator-(const Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator*=(Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator*(const Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator/=(Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend Vector2f operator/(const Vector2f& aFirstVector, const Vector2f& aSecondVector);


		//*************************
		//	SCALAR MATH OPERATORS
		//*************************
		friend Vector2f operator+(const Vector2f& aVector, float aScalar);
		friend Vector2f operator+(float aScalar, const Vector2f& aVector);
		friend Vector2f operator+=(Vector2f& aVector, float aScalar);
		friend Vector2f operator-(const Vector2f& aVector, float aScalar);
		friend Vector2f operator-=(Vector2f& aVector, float aScalar);
		friend Vector2f operator*(const Vector2f& aVector, float aScalar);
		friend Vector2f operator*(float aScalar, const Vector2f& aVector);
		friend Vector2f operator*=(Vector2f& aVector, float aScalar);
		friend Vector2f operator/(const Vector2f& aVector, float aScalar);
		friend Vector2f operator/=(Vector2f& aVector, float aScalar);
		friend Vector2f operator-(const Vector2f& aVector);


		//*************************
		//	COMPARISONS
		//*************************
		friend bool operator==(const Vector2f& aFirstVector, const Vector2f& aSecondVector);
		friend bool operator!=(const Vector2f& aFirstVector, const Vector2f& aSecondVector);
	};


	//*************************
	//	VECTOR MATH OPERATORS
	//*************************
	inline Vector2f operator+=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x += aSecondVector.x;
		aFirstVector.y += aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2f operator+(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result += aSecondVector;
		return result;
	}

	inline Vector2f operator-=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x -= aSecondVector.x;
		aFirstVector.y -= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2f operator-(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result -= aSecondVector;
		return result;
	}

	inline Vector2f operator*=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x *= aSecondVector.x;
		aFirstVector.y *= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2f operator*(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result *= aSecondVector;
		return result;
	}

	inline Vector2f operator/=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		assert(aSecondVector.x != 0 && aSecondVector.y != 0 && "Division by zero.");
		aFirstVector.x /= aSecondVector.x;
		aFirstVector.y /= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2f operator/(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result /= aSecondVector;
		return result;
	}


	//*************************
	//	SCALAR MATH OPERATORS
	//*************************
	inline Vector2f operator+(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result += aScalar;
		return result;
	}

	inline Vector2f operator+(float aScalar, const Vector2f& aVector)
	{
		return aVector + aScalar;
	}

	inline Vector2f operator+=(Vector2f& aVector, float aScalar)
	{
		aVector.x += aScalar;
		aVector.y += aScalar;
		return aVector;
	}

	inline Vector2f operator-(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result -= aScalar;
		return result;
	}

	inline Vector2f operator-=(Vector2f& aVector, float aScalar)
	{
		aVector.x -= aScalar;
		aVector.y -= aScalar;
		return aVector;
	}

	inline Vector2f operator*(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result *= aScalar;
		return result;
	}

	inline Vector2f operator*(float aScalar, const Vector2f& aVector)
	{
		return aVector * aScalar;
	}

	inline Vector2f operator*=(Vector2f& aVector, float aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
		return aVector;
	}

	inline Vector2f operator/(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result /= aScalar;
		return result;
	}

	inline Vector2f operator/=(Vector2f& aVector, float aScalar)
	{
		assert(aScalar != 0 && "Division by zero.");
		aVector.x /= aScalar;
		aVector.y /= aScalar;
		return aVector;
	}

	inline Vector2f operator-(const Vector2f& aVector)
	{
		return Vector2f(-aVector.x, -aVector.y);
	}


	//*************************
	//	VECTOR OPERATIONS
	//*************************
	inline float Dot(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return aFirstVector.x * aSecondVector.x + aFirstVector.y * aSecondVector.y;
	}

	inline float Length2(const Vector2f& aVector)
	{
		return Dot(aVector, aVector);
	}

	inline float Length(const Vector2f& aVector)
	{
		return float(sqrt(Length2(aVector)));
	}

	inline Vector2f GetNormalized(const Vector2f& aVector)
	{
		float length = Length(aVector);
		if (length == 0)
		{
			return aVector;
		}

		return Vector2f(aVector / length);
	}

	inline void Normalize(Vector2f& aVector)
	{
		aVector = GetNormalized(aVector);
	}


	//*************************
	//	COMPARISONS
	//*************************
	inline bool operator==(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return aFirstVector.x == aSecondVector.x && aFirstVector.y == aSecondVector.y;
	}

	inline bool operator!=(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return !(aFirstVector == aSecondVector);
	}
}

