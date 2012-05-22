#include "fourierreceiver.h"
#include "print.h"

void FourierReceiver::doAction()
{
	++mAction;
	if(mAction == 1)
	{
		doForward();
	}
	else if(mAction == 2)
	{
		doInverse();
	}
	else if(mAction == 3)
	{
		doRescale();
	}
	else if(mAction == 4)
	{
		doLast();
	}
}

FourierReceiver::FourierReceiver()
	: QObject()
{
	mAction = 0;
	mSamples = new float[SIZE];
	mFft = new float[SIZE];
	for(int i = 0; i < SIZE; ++i)
	{
		mSamples[i] = i / float(SIZE);
	}
	if(!mTransformer.setFixedSize(SIZE))
	{
		print("This size is not a supported power of 2. Using a variable FFT instead.\n");
	}
	mTransformer.setExecution(QFourierTransformer::SeparateThread);
	QObject::connect(&mTransformer, SIGNAL(finished()), this, SLOT(doAction()));
}

FourierReceiver::~FourierReceiver()
{
	delete [] mSamples;
	delete [] mFft;
}

int FourierReceiver::action()
{
	return mAction;
}

void FourierReceiver::doForward()
{
	print("Samples before transformation:\n");
	print(mSamples, SIZE);
	mTransformer.forwardTransform(mSamples, mFft);
}

void FourierReceiver::doInverse()
{
	mTransformer.inverseTransform(mFft, mSamples);
}

void FourierReceiver::doRescale()
{
	print("Samples after transformation and before rescaling:\n");
	print(mSamples, SIZE);
	mTransformer.rescale(mSamples);
}

void FourierReceiver::doLast()
{
	mAction = 0;
	print("Samples after rescaling:\n");
	print(mSamples, SIZE);
}
