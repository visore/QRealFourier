#include "qfourierthread.h"

QFourierThread::QFourierThread()
	: QThread()
{
	mInput = NULL;
	mOutput = NULL;
	mSize = 0;
}

void QFourierThread::setData(float input[], float output[])
{
	mInput = input;
	mOutput = output;
}

void QFourierThread::setSize(int size)
{
	mSize = size;
}

int QFourierThread::size()
{
	return mSize;
}
