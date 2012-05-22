#include "qfouriervariablethread.h"

QFourierVariableThread::QFourierVariableThread(QFourierTransformer *transformer)
	: QFourierThread(transformer)
{
}

QFourierVariableForwardThread::QFourierVariableForwardThread(QFourierTransformer *transformer)
	: QFourierVariableThread(transformer)
{
}

void QFourierVariableForwardThread::run()
{
	ffft::FFTReal<float> fourierTransform(mSize);
	fourierTransform.do_fft(mOutput, mInput);
	QFourierThread::notify();
}

QFourierVariableInverseThread::QFourierVariableInverseThread(QFourierTransformer *transformer)
	: QFourierVariableThread(transformer)
{
}

void QFourierVariableInverseThread::run()
{
	ffft::FFTReal<float> fourierTransform(mSize);
	fourierTransform.do_ifft(mInput, mOutput);
	QFourierThread::notify();
}

QFourierVariableRescaleThread::QFourierVariableRescaleThread(QFourierTransformer *transformer)
	: QFourierVariableThread(transformer)
{
}

void QFourierVariableRescaleThread::run()
{
	ffft::FFTReal<float> fourierTransform(mSize);
	fourierTransform.rescale(mInput);
	QFourierThread::notify();
}
