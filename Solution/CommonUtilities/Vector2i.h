#pragma once

#include <cassert>
#include <cmath>

namespace CU
{
	class Vector2i
	{
	public:
		Vector2i(int aX = 0.f, int aY = 0.f)
			: x(aX)
			, y(aY)
		{}

		int x;
		int y;

		//*************************
		//	VECTOR MATH OPERATORS
		//*************************
		friend Vector2i operator+=(Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator+(const Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator-=(Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator-(const Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator*=(Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator*(const Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator/=(Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend Vector2i operator/(const Vector2i& aFirstVector, const Vector2i& aSecondVector);


		//*************************
		//	SCALAR MATH OPERATORS
		//*************************
		friend Vector2i operator+(const Vector2i& aVector, int aScalar);
		friend Vector2i operator+(int aScalar, const Vector2i& aVector);
		friend Vector2i operator+=(Vector2i& aVector, int aScalar);
		friend Vector2i operator-(const Vector2i& aVector, int aScalar);
		friend Vector2i operator-=(Vector2i& aVector, int aScalar);
		friend Vector2i operator*(const Vector2i& aVector, int aScalar);
		friend Vector2i operator*(int aScalar, const Vector2i& aVector);
		friend Vector2i operator*=(Vector2i& aVector, int aScalar);
		friend Vector2i operator/(const Vector2i& aVector, int aScalar);
		friend Vector2i operator/=(Vector2i& aVector, int aScalar);
		friend Vector2i operator-(const Vector2i& aVector);


		//*************************
		//	COMPARISONS
		//*************************
		friend bool operator==(const Vector2i& aFirstVector, const Vector2i& aSecondVector);
		friend bool operator!=(const Vector2i& aFirstVector, const Vector2i& aSecondVector);
	};


	//*************************
	//	VECTOR MATH OPERATORS
	//*************************
	inline Vector2i operator+=(Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		aFirstVector.x += aSecondVector.x;
		aFirstVector.y += aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2i operator+(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		Vector2i result(aFirstVector);
		result += aSecondVector;
		return result;
	}

	inline Vector2i operator-=(Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		aFirstVector.x -= aSecondVector.x;
		aFirstVector.y -= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2i operator-(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		Vector2i result(aFirstVector);
		result -= aSecondVector;
		return result;
	}

	inline Vector2i operator*=(Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		aFirstVector.x *= aSecondVector.x;
		aFirstVector.y *= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2i operator*(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		Vector2i result(aFirstVector);
		result *= aSecondVector;
		return result;
	}

	inline Vector2i operator/=(Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		assert(aSecondVector.x != 0 && aSecondVector.y != 0 && "Division by zero.");
		aFirstVector.x /= aSecondVector.x;
		aFirstVector.y /= aSecondVector.y;
		return aFirstVector;
	}

	inline Vector2i operator/(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		Vector2i result(aFirstVector);
		result /= aSecondVector;
		return result;
	}


	//*************************
	//	SCALAR MATH OPERATORS
	//*************************
	inline Vector2i operator+(const Vector2i& aVector, int aScalar)
	{
		Vector2i result(aVector);
		result += aScalar;
		return result;
	}

	inline Vector2i operator+(int aScalar, const Vector2i& aVector)
	{
		return aVector + aScalar;
	}

	inline Vector2i operator+=(Vector2i& aVector, int aScalar)
	{
		aVector.x += aScalar;
		aVector.y += aScalar;
		return aVector;
	}

	inline Vector2i operator-(const Vector2i& aVector, int aScalar)
	{
		Vector2i result(aVector);
		result -= aScalar;
		return result;
	}

	inline Vector2i operator-=(Vector2i& aVector, int aScalar)
	{
		aVector.x -= aScalar;
		aVector.y -= aScalar;
		return aVector;
	}

	inline Vector2i operator*(const Vector2i& aVector, int aScalar)
	{
		Vector2i result(aVector);
		result *= aScalar;
		return result;
	}

	inline Vector2i operator*(int aScalar, const Vector2i& aVector)
	{
		return aVector * aScalar;
	}

	inline Vector2i operator*=(Vector2i& aVector, int aScalar)
	{
		aVector.x *= aScalar;
		aVector.y *= aScalar;
		return aVector;
	}

	inline Vector2i operator/(const Vector2i& aVector, int aScalar)
	{
		Vector2i result(aVector);
		result /= aScalar;
		return result;
	}

	inline Vector2i operator/=(Vector2i& aVector, int aScalar)
	{
		assert(aScalar != 0 && "Division by zero.");
		aVector.x /= aScalar;
		aVector.y /= aScalar;
		return aVector;
	}

	inline Vector2i operator-(const Vector2i& aVector)
	{
		return Vector2i(-aVector.x, -aVector.y);
	}


	//*************************
	//	VECTOR OPERATIONS
	//*************************
	inline int Dot(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		return aFirstVector.x * aSecondVector.x + aFirstVector.y * aSecondVector.y;
	}

	inline int Length2(const Vector2i& aVector)
	{
		return Dot(aVector, aVector);
	}

	inline int Length(const Vector2i& aVector)
	{
		return int(sqrt(Length2(aVector)));
	}

	inline Vector2i GetNormalized(const Vector2i& aVector)
	{
		int length = Length(aVector);
		if (length == 0)
		{
			return aVector;
		}

		return Vector2i(aVector / length);
	}

	inline void Normalize(Vector2i& aVector)
	{
		aVector = GetNormalized(aVector);
	}


	//*************************
	//	COMPARISONS
	//*************************
	inline bool operator==(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		return aFirstVector.x == aSecondVector.x && aFirstVector.y == aSecondVector.y;
	}

	inline bool operator!=(const Vector2i& aFirstVector, const Vector2i& aSecondVector)
	{
		return !(aFirstVector == aSecondVector);
	}
}

