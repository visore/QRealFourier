#ifdef QFOURIERFIXEDCALCULATOR_H

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

#endif
