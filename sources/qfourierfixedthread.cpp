#ifdef QFOURIERFIXEDTHREAD_H

template <int T>
QFourierFixedThread<T>::QFourierFixedThread(QFourierTransformer *transformer)
	: QFourierThread(transformer)
{
	setSize(qPow(2, T));
}

template <int T>
QFourierFixedForwardThread<T>::QFourierFixedForwardThread(QFourierTransformer *transformer)
	: QFourierFixedThread<T>(transformer)
{
}

template <int T>
void QFourierFixedForwardThread<T>::run()
{
	QFourierFixedThread<T>::mFourierTransform.do_fft(QFourierThread::mOutput, QFourierThread::mInput);
	QFourierThread::notify();
}

template <int T>
QFourierFixedInverseThread<T>::QFourierFixedInverseThread(QFourierTransformer *transformer)
	: QFourierFixedThread<T>(transformer)
{
}

template <int T>
void QFourierFixedInverseThread<T>::run()
{
	QFourierFixedThread<T>::mFourierTransform.do_ifft(QFourierThread::mInput, QFourierThread::mOutput);
	QFourierThread::notify();
}

template <int T>
QFourierFixedRescaleThread<T>::QFourierFixedRescaleThread(QFourierTransformer *transformer)
	: QFourierFixedThread<T>(transformer)
{
}

template <int T>
void QFourierFixedRescaleThread<T>::run()
{
	QFourierFixedThread<T>::mFourierTransform.rescale(QFourierThread::mInput);
	QFourierThread::notify();
}

#endif
