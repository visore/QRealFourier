#ifdef QFOURIERFIXEDTHREAD_H

template <int T>
QFourierFixedThread<T>::QFourierFixedThread()
	: QFourierThread()
{
	setSize(qPow(2, T));
}

template <int T>
QFourierFixedForwardThread<T>::QFourierFixedForwardThread()
	: QFourierFixedThread<T>()
{
}

template <int T>
void QFourierFixedForwardThread<T>::run()
{
	QFourierFixedThread<T>::mFourierTransform.do_fft(QFourierThread::mOutput, QFourierThread::mInput);
}

template <int T>
QFourierFixedInverseThread<T>::QFourierFixedInverseThread()
	: QFourierFixedThread<T>()
{
}

template <int T>
void QFourierFixedInverseThread<T>::run()
{
	QFourierFixedThread<T>::mFourierTransform.do_ifft(QFourierThread::mInput, QFourierThread::mOutput);
}

#endif
