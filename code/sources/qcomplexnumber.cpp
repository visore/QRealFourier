#include "qcomplexnumber.h"

template <typename T>
QComplexNumber<T>::QComplexNumber()
{
	mReal = 0;
	mImaginary = 0;
}

template <typename T>
QComplexNumber<T>::QComplexNumber(T real, T imaginary)
{
	mReal = real;
	mImaginary = imaginary;
}

template <typename T>
void QComplexNumber<T>::setReal(T real)
{
	mReal = real;
}

template <typename T>
void QComplexNumber<T>::setImaginary(T imaginary)
{
	mImaginary = imaginary;
}

template <typename T>
void QComplexNumber<T>::set(T real, T imaginary)
{
	mReal = real;
	mImaginary = imaginary;
}

template <typename T>
void QComplexNumber<T>::set(QComplexNumber complex)
{
	mReal = complex.real();
	mImaginary = complex.imaginary();
}

template <typename T>
T QComplexNumber<T>::real()
{
	return mReal;
}

template <typename T>
T QComplexNumber<T>::imaginary()
{
	return mImaginary;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator+=(const QComplexNumber<T> &number)
{
	mReal += number.mReal;
	mImaginary += number.mImaginary;
	return *this;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator-=(const QComplexNumber<T> &number)
{
	mReal -= number.mReal;
	mImaginary -= number.mImaginary;
	return *this;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator/=(const QComplexNumber<T> &number)
{
	mReal /= number.mReal;
	mImaginary /= number.mImaginary;
	return *this;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator*=(const QComplexNumber<T> &number)
{
	mReal *= number.mReal;
	mImaginary *= number.mImaginary;
	return *this;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator/=(const T &value)
{
	mReal /= value;
	mImaginary /= value;
	return *this;
}

template <typename T>
QComplexNumber<T>& QComplexNumber<T>::operator*=(const T &value)
{
	mReal *= value;
	mImaginary *= value;
	return *this;
}

template class QComplexNumber<short>;
template class QComplexNumber<int>;
template class QComplexNumber<long>;
template class QComplexNumber<float>;
template class QComplexNumber<double>;
