#include "qfouriertransformer.h"

QFourierTransformer::QFourierTransformer(Execution execution, int fixedSize)
	 : QObject()
{
	mSize = 0;

	mForwardThread = NULL;
	mInverseThread = NULL;

	initialize();
	setFixedSize(fixedSize);
	setExecution(execution);

	QObject::connect(mForwardThread, SIGNAL(finished()), this, SIGNAL(finished()));
	QObject::connect(mInverseThread, SIGNAL(finished()), this, SIGNAL(finished()));
}

QFourierTransformer::~QFourierTransformer()
{
	qDeleteAll(mFixedForwardThreads.begin(), mFixedForwardThreads.end());
	mFixedForwardThreads.clear();

	qDeleteAll(mFixedInverseThreads.begin(), mFixedInverseThreads.end());
	mFixedInverseThreads.clear();

	delete mVariableForwardThread;
	delete mVariableInverseThread;
}

bool QFourierTransformer::setFixedSize(int size)
{
	bool wasSetForward = false;
	bool wasSetInverse = false;
	int index;
	for(index = 0; index < mFixedForwardThreads.size(); ++index)
	{
		if(mFixedForwardThreads[index]->size() == size)
		{
			mForwardThread = mFixedForwardThreads[index];
			wasSetForward = true;
		}
	}
	for(index = 0; index < mFixedInverseThreads.size(); ++index)
	{
		if(mFixedInverseThreads[index]->size() == size)
		{
			mInverseThread = mFixedInverseThreads[index];
			wasSetInverse = true;
		}
	}
	if(wasSetForward && wasSetInverse)
	{
		mSize = size;
		return true;
	}
	
	mSize = 0;
	mForwardThread = mVariableForwardThread;
	mInverseThread = mVariableInverseThread;
	return false;
}

void QFourierTransformer::setExecution(Execution execution)
{
	if(execution == QFourierTransformer::SameThread)
	{
		forwardTransformtion = &QFourierTransformer::forwardTransformSameThread;
		inverseTransformtion = &QFourierTransformer::inverseTransformSameThread;
	}
	else
	{
		forwardTransformtion = &QFourierTransformer::forwardTransformSeperateThread;
		inverseTransformtion = &QFourierTransformer::inverseTransformSeperateThread;
	}
}

void QFourierTransformer::transform(float input[], float output[], QWindower *windower, Direction direction)
{
	if(direction == QFourierTransformer::Forward)
	{
		forwardTransform(input, output, windower);
	}
	else
	{
		inverseTransform(input, output);
	}
}

void QFourierTransformer::forwardTransform(float *input, float *output, QWindower *windower)
{
	if(windower != NULL)
	{
		windower->apply(input, mSize);
	}
	QFourierTransformer::fixedForwardTransform(input, output);
}

void QFourierTransformer::inverseTransform(float input[], float output[])
{
	QFourierTransformer::fixedInverseTransform(input, output);
}

void QFourierTransformer::transform(float input[], float output[], qint32 numberOfSamples, QWindower *windower, Direction direction)
{
	if(direction == QFourierTransformer::Forward)
	{
		forwardTransform(input, output, numberOfSamples, windower);
	}
	else
	{
		inverseTransform(input, output, numberOfSamples);
	}
}

void QFourierTransformer::forwardTransform(float *input, float *output, qint32 numberOfSamples, QWindower *windower)
{
	if(windower != NULL)
	{
		windower->apply(input, numberOfSamples);
	}
	variableForwardTransform(input, output, numberOfSamples);
}

void QFourierTransformer::inverseTransform(float input[], float output[], qint32 numberOfSamples)
{
	variableInverseTransform(input, output, numberOfSamples);
}

void QFourierTransformer::initialize()
{
	mFixedForwardThreads.append(new QFourierFixedForwardThread<3>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<4>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<5>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<6>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<7>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<8>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<9>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<10>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<11>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<12>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<13>());
	mFixedForwardThreads.append(new QFourierFixedForwardThread<14>());

	mFixedInverseThreads.append(new QFourierFixedInverseThread<3>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<4>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<5>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<6>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<7>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<8>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<9>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<10>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<11>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<12>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<13>());
	mFixedInverseThreads.append(new QFourierFixedInverseThread<14>());

	mVariableForwardThread = new QFourierVariableForwardThread();
	mVariableInverseThread = new QFourierVariableInverseThread();
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

void QFourierTransformer::variableForwardTransform(float input[], float output[], qint32 numberOfSamples)
{
	mForwardThread->setData(input, output);
	mForwardThread->setSize(numberOfSamples);
	(this->*forwardTransformtion)();
}

void QFourierTransformer::variableInverseTransform(float input[], float output[], qint32 numberOfSamples)
{
	mInverseThread->setData(input, output);
	mInverseThread->setSize(numberOfSamples);
	(this->*inverseTransformtion)();
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

QVector<QComplexFloat> toComplexFloat(float input[], qint32 numberOfSamples)
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

QVector<QComplexDouble> toComplexDouble(float input[], qint32 numberOfSamples)
{
	QVector<QComplexDouble> result;
	int last = numberOfSamples / 2;
	result.push_back(QComplexDouble(input[0], 0));
	for(int i = 1; i < last; ++i)
	{
		result.push_back(QComplexDouble(input[i], -input[last + i]));
	}
	result.push_back(QComplexDouble(input[last], 0));
	return result;
}
