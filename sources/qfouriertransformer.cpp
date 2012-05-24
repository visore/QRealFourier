#include "qfouriertransformer.h"

QFourierTransformer::QFourierTransformer(Execution execution, int fixedSize)
	 : QObject()
{
	mSize = 0;

	mForwardThread = NULL;
	mInverseThread = NULL;
	mRescaleThread = NULL;

	initialize();
	setFixedSize(fixedSize);
	setExecution(execution);
}

QFourierTransformer::~QFourierTransformer()
{
	qDeleteAll(mFixedForwardThreads.begin(), mFixedForwardThreads.end());
	mFixedForwardThreads.clear();

	qDeleteAll(mFixedInverseThreads.begin(), mFixedInverseThreads.end());
	mFixedInverseThreads.clear();

	qDeleteAll(mFixedRescaleThreads.begin(), mFixedRescaleThreads.end());
	mFixedRescaleThreads.clear();

	delete mVariableForwardThread;
	delete mVariableInverseThread;
	delete mVariableRescaleThread;
}

void QFourierTransformer::emitFinished()
{
	emit finished();
}

bool QFourierTransformer::setFixedSize(int size)
{
	bool wasSetForward = false;
	bool wasSetInverse = false;
	bool wasSetRescale = false;
	int index, last;
	last = mFixedForwardThreads.size();
	for(index = 0; index < last; ++index)
	{
		if(mFixedForwardThreads[index]->size() == size)
		{
			mForwardThread = mFixedForwardThreads[index];
			wasSetForward = true;
		}
	}
	last = mFixedInverseThreads.size();
	for(index = 0; index < last; ++index)
	{
		if(mFixedInverseThreads[index]->size() == size)
		{
			mInverseThread = mFixedInverseThreads[index];
			wasSetInverse = true;
		}
	}
	last = mFixedRescaleThreads.size();
	for(index = 0; index < last; ++index)
	{
		if(mFixedRescaleThreads[index]->size() == size)
		{
			mRescaleThread = mFixedRescaleThreads[index];
			wasSetRescale = true;
		}
	}
	if(wasSetForward && wasSetInverse && wasSetRescale)
	{
		mSize = size;
		return true;
	}
	else
	{
		mSize = 0;
		mForwardThread = mVariableForwardThread;
		mInverseThread = mVariableInverseThread;
		mRescaleThread = mVariableRescaleThread;
		return false;
	}
}

void QFourierTransformer::setExecution(Execution execution)
{
	if(execution == QFourierTransformer::SameThread)
	{
		forwardTransformtion = &QFourierTransformer::forwardTransformSameThread;
		inverseTransformtion = &QFourierTransformer::inverseTransformSameThread;
		rescaleTransformtion = &QFourierTransformer::rescaleTransformSameThread;
	}
	else
	{
		forwardTransformtion = &QFourierTransformer::forwardTransformSeperateThread;
		inverseTransformtion = &QFourierTransformer::inverseTransformSeperateThread;
		rescaleTransformtion = &QFourierTransformer::rescaleTransformSeperateThread;
	}
}

void QFourierTransformer::transform(float input[], float output[], QWindowFunction<float> *windowFunction, Direction direction)
{
	if(direction == QFourierTransformer::Forward)
	{
		forwardTransform(input, output, windowFunction);
	}
	else
	{
		inverseTransform(input, output);
	}
}

void QFourierTransformer::forwardTransform(float *input, float *output, QWindowFunction<float> *windowFunction)
{
	if(windowFunction != NULL)
	{
		windowFunction->apply(input, mSize);
	}
	fixedForwardTransform(input, output);
}

void QFourierTransformer::inverseTransform(float input[], float output[])
{
	fixedInverseTransform(input, output);
}

void QFourierTransformer::rescale(float input[])
{
	fixedRescale(input);
}

void QFourierTransformer::transform(float input[], float output[], int numberOfSamples, QWindowFunction<float> *windowFunction, Direction direction)
{
	if(direction == QFourierTransformer::Forward)
	{
		forwardTransform(input, output, numberOfSamples, windowFunction);
	}
	else
	{
		inverseTransform(input, output, numberOfSamples);
	}
}

void QFourierTransformer::forwardTransform(float *input, float *output, int numberOfSamples, QWindowFunction<float> *windowFunction)
{
	if(windowFunction != NULL)
	{
		windowFunction->apply(input, numberOfSamples);
	}
	variableForwardTransform(input, output, numberOfSamples);
}

void QFourierTransformer::inverseTransform(float input[], float output[], int numberOfSamples)
{
	variableInverseTransform(input, output, numberOfSamples);
}

void QFourierTransformer::rescale(float input[], int numberOfSamples)
{
	variableRescale(input, numberOfSamples);
}

void QFourierTransformer::initialize()
{
	mFixedForwardThreads.append(new QFourierFixedForwardThread<3>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<4>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<5>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<6>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<7>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<8>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<9>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<10>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<11>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<12>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<13>(this));
	mFixedForwardThreads.append(new QFourierFixedForwardThread<14>(this));

	mFixedInverseThreads.append(new QFourierFixedInverseThread<3>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<4>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<5>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<6>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<7>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<8>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<9>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<10>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<11>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<12>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<13>(this));
	mFixedInverseThreads.append(new QFourierFixedInverseThread<14>(this));

	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<3>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<4>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<5>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<6>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<7>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<8>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<9>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<10>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<11>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<12>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<13>(this));
	mFixedRescaleThreads.append(new QFourierFixedRescaleThread<14>(this));

	mVariableForwardThread = new QFourierVariableForwardThread(this);
	mVariableInverseThread = new QFourierVariableInverseThread(this);
	mVariableRescaleThread = new QFourierVariableRescaleThread(this);
}

void QFourierTransformer::fixedForwardTransform(float *input, float *output)
{
	mForwardThread->setData(input, output);
	(this->*forwardTransformtion)();
}

void QFourierTransformer::fixedInverseTransform(float input[], float output[])
{
	mInverseThread->setData(input, output);
	(this->*inverseTransformtion)();
}

void QFourierTransformer::fixedRescale(float input[])
{
	mRescaleThread->setData(input);
	(this->*rescaleTransformtion)();
}

void QFourierTransformer::variableForwardTransform(float input[], float output[], int numberOfSamples)
{
	mForwardThread->setData(input, output);
	mForwardThread->setSize(numberOfSamples);
	(this->*forwardTransformtion)();
}

void QFourierTransformer::variableInverseTransform(float input[], float output[], int numberOfSamples)
{
	mInverseThread->setData(input, output);
	mInverseThread->setSize(numberOfSamples);
	(this->*inverseTransformtion)();
}

void QFourierTransformer::variableRescale(float input[], int numberOfSamples)
{
	mRescaleThread->setData(input);
	mRescaleThread->setSize(numberOfSamples);
	(this->*rescaleTransformtion)();
}

void QFourierTransformer::forwardTransformSameThread()
{
	mForwardThread->run();
}

void QFourierTransformer::forwardTransformSeperateThread()
{
	mForwardThread->start();
}

void QFourierTransformer::inverseTransformSameThread()
{
	mInverseThread->run();
}

void QFourierTransformer::inverseTransformSeperateThread()
{
	mInverseThread->start();
}

void QFourierTransformer::rescaleTransformSameThread()
{
	mRescaleThread->run();
}

void QFourierTransformer::rescaleTransformSeperateThread()
{
	mRescaleThread->start();
}

QComplexVector toComplex(float input[], int numberOfSamples)
{
	QVector<QComplexFloat> result;
	int last = numberOfSamples / 2;
	result.push_back(QComplexFloat(input[0], 0));
	for(int i = 1; i < last; ++i)
	{
		result.push_back(QComplexFloat(input[i], -input[last + i]));
	}
	result.push_back(QComplexFloat(input[last], 0));
	return result;
}
