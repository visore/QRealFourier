#include "qfouriercalculator.h"

QFourierCalculator::QFourierCalculator()
{
	mInput = 0;
	mOutput = 0;
	mSize = 0;
}

void QFourierCalculator::setData(float input[], float output[])
{
	mInput = input;
	mOutput = output;
}

void QFourierCalculator::setSize(int size)
{
	mSize = size;
}

int QFourierCalculator::size()
{
	return mSize;
}
