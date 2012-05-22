#include "qfourierthread.h"
#include "qfouriertransformer.h"

QFourierThread::QFourierThread(QFourierTransformer *transformer)
	: QThread()
{
	mTransformer = transformer;
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

void QFourierThread::notify()
{
	mTransformer->emitFinished();
}
