#pragma once
#include <iostream>
using namespace std;

template <class S> class Vector3Dx;
typedef Vector3Dx<float> Vector3D;
typedef Vector3Dx<float> Vector3Df;
typedef Vector3Dx<double> Vector3Dd;
typedef Vector3Dx<int> Vector3Di;

template<class S> class Vector3Dx
{
private:
	S coordinateX;
	S coordinateY;
	S coordinateZ;

public:
	Vector3Dx() : coordinateX(0), coordinateY(0), coordinateZ(0) { }

	Vector3Dx(S x, S y, S z) : coordinateX(x), coordinateY(y), coordinateZ(z) {}

	inline S getCoordinateX() const {
		return coordinateX;
	}

	inline S getCoordinateY() const {
		return coordinateY;
	}

	inline S getCoordinateZ() const {
		return coordinateZ;
	}

	inline void setCoordinateX(S coordinateXtoSet) {
		coordinateX = coordinateXtoSet;
	}

	inline void setCoordinateY(S coordinateYtoSet) {
		coordinateY = coordinateYtoSet;
	}

	inline void setCoordinateZ(S coordinateZtoSet) {
		coordinateZ = coordinateZtoSet;
	}

	Vector3Dx<S> operator+(Vector3Dx<S> vector);
	Vector3Dx<S> operator-(Vector3Dx<S> vector);
	Vector3Dx<S> operator*(S s);
	Vector3Dx<S> operator/(S vector);
	S operator*(Vector3Dx<S> vector);

};

template <class S> Vector3Dx<S> Vector3Dx<S>::operator+(Vector3Dx<S> vector) {
	S x = coordinateX + vector.coordinateX;
	S y = coordinateY + vector.coordinateY;
	S z = coordinateZ + vector.coordinateZ;

	Vector3Dx newVect(x, y, z);
	return newVect;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator-(Vector3Dx<S> vector) {
	float x = coordinateX - vector.coordinateX;
	float y = coordinateY - vector.coordinateY;
	float z = coordinateZ - vector.coordinateZ;

	Vector3Dx newVect(x, y, z);
	return newVect;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator*(S value) {
	float x = coordinateX * value;
	float y = coordinateY * value;
	float z = coordinateZ * value;

	Vector3Dx newVect(x, y, z);
	return newVect;
}

template <class S> Vector3Dx<S> Vector3Dx<S>::operator/(S value) {
	float x = coordinateX / value;
	float y = coordinateY / value;
	float z = coordinateZ / value;

	Vector3Dx newVect(x, y, z);
	return newVect;
}

template <class S> S Vector3Dx<S>::operator*(Vector3Dx<S> vector) {
	float x = coordinateX * vector.coordinateX;
	float y = coordinateY * vector.coordinateY;
	float z = coordinateZ * vector.coordinateZ;

	return x + y + z;
}





