#include "qfourierfixedcalculator.h"

template <int T>
QFourierFixedCalculator<T>::QFourierFixedCalculator()
	: QFourierCalculator()
{
	setSize(mFourierTransform.get_length());
}

template <int T>
void QFourierFixedCalculator<T>::setSize(int size)
{
}

template <int T>
void QFourierFixedCalculator<T>::forward()
{
	QFourierFixedCalculator<T>::mFourierTransform.do_fft(QFourierCalculator::mOutput, QFourierCalculator::mInput);
}

template <int T>
void QFourierFixedCalculator<T>::inverse()
{
	QFourierFixedCalculator<T>::mFourierTransform.do_ifft(QFourierCalculator::mInput, QFourierCalculator::mOutput);
}

template <int T>
void QFourierFixedCalculator<T>::rescale()
{
	QFourierFixedCalculator<T>::mFourierTransform.rescale(QFourierCalculator::mInput);
}

template class QFourierFixedCalculator<3>;
template class QFourierFixedCalculator<4>;
template class QFourierFixedCalculator<5>;
template class QFourierFixedCalculator<6>;
template class QFourierFixedCalculator<7>;
template class QFourierFixedCalculator<8>;
template class QFourierFixedCalculator<9>;
template class QFourierFixedCalculator<10>;
template class QFourierFixedCalculator<11>;
template class QFourierFixedCalculator<12>;
template class QFourierFixedCalculator<13>;
template class QFourierFixedCalculator<14>;
