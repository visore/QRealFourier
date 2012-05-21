#ifdef QCOMPLEXNUMBER_H

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

#endif
