#include "qfouriervariablecalculator.h"

QFourierVariableCalculator::QFourierVariableCalculator()
	: QFourierCalculator()
{
	mFourierTransform = 0;
}

QFourierVariableCalculator::~QFourierVariableCalculator()
{
	if(mFourierTransform != 0)
	{
		delete mFourierTransform;
	}
}

void QFourierVariableCalculator::setSize(int size)
{
	QFourierCalculator::setSize(size);
	if(mFourierTransform == 0)
	{
		mFourierTransform = new ffft::FFTReal<float>(mSize);
	}
	else if(mFourierTransform->get_length() != mSize)
	{
		delete mFourierTransform;
		mFourierTransform = new ffft::FFTReal<float>(mSize);
	}
}

void QFourierVariableCalculator::forward()
{
	mFourierTransform->do_fft(mOutput, mInput);
}

void QFourierVariableCalculator::inverse()
{
	mFourierTransform->do_ifft(mInput, mOutput);
}

void QFourierVariableCalculator::rescale()
{
	mFourierTransform->rescale(mInput);
}
