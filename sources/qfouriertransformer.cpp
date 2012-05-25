#include "qfouriertransformer.h"

QFourierTransformer::QFourierTransformer(int size)
{
	mCalculator = NULL;
	initialize();
	setSize(size);
}

QFourierTransformer::~QFourierTransformer()
{
	qDeleteAll(mFixedCalculators.begin(), mFixedCalculators.end());
	mFixedCalculators.clear();
	delete mVariableCalculator;
}

QFourierTransformer::Initialization QFourierTransformer::setSize(int size)
{
	if(isValidSize(size))
	{
		mSize = size;
		int key = sizeToKey(mSize);
		if(mFixedCalculators.contains(key))
		{
			mCalculator = mFixedCalculators[key];
			return QFourierTransformer::FixedSize;
		}
		else
		{
			mCalculator = mVariableCalculator;
			mCalculator->setSize(mSize);
			return QFourierTransformer::VariableSize;
		}
	}
	mSize = -1;
	return QFourierTransformer::InvalidSize;
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
	mCalculator->setData(input, output);
	mCalculator->forward();
}

void QFourierTransformer::inverseTransform(float input[], float output[])
{
	mCalculator->setData(input, output);
	mCalculator->inverse();
}

void QFourierTransformer::rescale(float input[])
{
	mCalculator->setData(input);
	mCalculator->rescale();
}

void QFourierTransformer::initialize()
{
	mFixedCalculators.insert(3, new QFourierFixedCalculator<3>());
	mFixedCalculators.insert(4, new QFourierFixedCalculator<4>());
	mFixedCalculators.insert(5, new QFourierFixedCalculator<5>());
	mFixedCalculators.insert(6, new QFourierFixedCalculator<6>());
	mFixedCalculators.insert(7, new QFourierFixedCalculator<7>());
	mFixedCalculators.insert(8, new QFourierFixedCalculator<8>());
	mFixedCalculators.insert(9, new QFourierFixedCalculator<9>());
	mFixedCalculators.insert(10, new QFourierFixedCalculator<10>());
	mFixedCalculators.insert(11, new QFourierFixedCalculator<11>());
	mFixedCalculators.insert(12, new QFourierFixedCalculator<12>());
	mFixedCalculators.insert(13, new QFourierFixedCalculator<13>());
	mFixedCalculators.insert(14, new QFourierFixedCalculator<14>());

	mVariableCalculator = new QFourierVariableCalculator();
}

int QFourierTransformer::sizeToKey(int size)
{
	float result = log(size) / float(log(2));
	if(result == float(int(result)))
	{
		return result;
	}
	return -1;
}

bool QFourierTransformer::isValidSize(int value)
{
	return ((value > 0) && ((value & (~value + 1)) == value));
}

void QFourierTransformer::conjugate(float input[])
{
	for(int i = mSize / 2 + 1; i < mSize; ++i)
	{
		input[i] = -input[i];
	}
}

QComplexVector QFourierTransformer::toComplex(float input[])
{
	int last = mSize / 2;
	QVector<QComplexFloat> result(last + 1);
	result[0] = QComplexFloat(input[0], 0);
	for(int i = 1; i < last; ++i)
	{
		result[i] = QComplexFloat(input[i], -input[last + i]);
	}
	result[last] = QComplexFloat(input[last], 0);
	return result;
}
