
#include "Vector2f.h"
#include <cassert>
#include <cmath>

namespace CU
{
	Vector2f::Vector2f(float aX, float aY)
		: x(aX)
		, y(aY)
	{
	}

	//*************************
	//	VECTOR MATH OPERATORS
	//*************************
	Vector2f operator+=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x += aSecondVector.x;
		aFirstVector.y += aSecondVector.y;
		return aFirstVector;
	}

	Vector2f operator+(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result += aSecondVector;
		return result;
	}

	Vector2f operator-=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x -= aSecondVector.x;
		aFirstVector.y -= aSecondVector.y;
		return aFirstVector;
	}

	Vector2f operator-(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result -= aSecondVector;
		return result;
	}

	Vector2f operator*=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		aFirstVector.x *= aSecondVector.x;
		aFirstVector.y *= aSecondVector.y;
		return aFirstVector;
	}

	Vector2f operator*(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result *= aSecondVector;
		return result;
	}
	
	Vector2f operator/=(Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		assert(aSecondVector.x != 0 && aSecondVector.y != 0 && "Division by zero.");
		aFirstVector.x /= aSecondVector.x;
		aFirstVector.y /= aSecondVector.y;
		return aFirstVector;
	}

	Vector2f operator/(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		Vector2f result(aFirstVector);
		result /= aSecondVector;
		return result;
	}


	//*************************
	//	SCALAR MATH OPERATORS
	//*************************
	Vector2f operator+(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result += aScalar;
		return result;
	}

	Vector2f operator+(float aScalar, const Vector2f& aVector)
	{
		return aVector + aScalar;
	}

	Vector2f operator+=(Vector2f& aVector, float aScalar)
	{
		aVector.x += aScalar;
		aVector.y += aScalar;
		return aVector;
	}

	Vector2f operator-(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result -= aScalar;
		return result;
	}

	Vector2f operator-=(Vector2f& aVector, float aScalar)
	{
		aVector.x -= aScalar;
		aVector.y -= aScalar;
		return aVector;
	}

	Vector2f operator*(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result *= aScalar;
		return result;
	}

	Vector2f operator*(float aScalar, const Vector2f& aVector)
	{
		return aVector * aScalar;
	}

	Vector2f operator*=(Vector2f& aVector, float aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
		return aVector;
	}

	Vector2f operator/(const Vector2f& aVector, float aScalar)
	{
		Vector2f result(aVector);
		result /= aScalar;
		return result;
	}

	Vector2f operator/=(Vector2f& aVector, float aScalar)
	{
		assert(aScalar != 0 && "Division by zero.");
		aVector.x /= aScalar;
		aVector.y /= aScalar;
		return aVector;
	}

	Vector2f operator-(const Vector2f& aVector)
	{
		return Vector2f(-aVector.x, -aVector.y);
	}


	//*************************
	//	VECTOR OPERATIONS
	//*************************
	float Dot(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return aFirstVector.x * aSecondVector.x + aFirstVector.y * aSecondVector.y;
	}

	float Length2(const Vector2f& aVector)
	{
		return Dot(aVector, aVector);
	}

	float Length(const Vector2f& aVector)
	{
		return float(sqrt(Length2(aVector)));
	}

	Vector2f GetNormalized(const Vector2f& aVector)
	{
		float length = Length(aVector);
		if (length == 0)
		{
			return aVector;
		}

		return Vector2f(aVector / length);
	}

	void Normalize(Vector2f& aVector)
	{
		aVector = GetNormalized(aVector);
	}


	//*************************
	//	COMPARISONS
	//*************************
	bool operator==(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return aFirstVector.x == aSecondVector.x && aFirstVector.y == aSecondVector.y;
	}
	
	bool operator!=(const Vector2f& aFirstVector, const Vector2f& aSecondVector)
	{
		return !(aFirstVector == aSecondVector);
	}
}
