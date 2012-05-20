#include "qfouriervariablethread.h"

QFourierVariableThread::QFourierVariableThread()
	: QFourierThread()
{
}

QFourierVariableForwardThread::QFourierVariableForwardThread()
	: QFourierVariableThread()
{
}

void QFourierVariableForwardThread::run()
{
	ffft::FFTReal<float> fourierTransform(mSize);
	fourierTransform.do_fft(mOutput, mInput);
}

QFourierVariableInverseThread::QFourierVariableInverseThread()
	: QFourierVariableThread()
{
}

void QFourierVariableInverseThread::run()
{
	ffft::FFTReal<float> fourierTransform(mSize);
	fourierTransform.do_ifft(mInput, mOutput);
}
