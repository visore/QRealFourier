#ifndef QFOURIERTRANSFORMER_H
#define QFOURIERTRANSFORMER_H

#include "qfourierfixedcalculator.h"
#include "qfouriervariablecalculator.h"
#include "qwindowfunction.h"
#include "qcomplexnumber.h"
#include <QMap>

typedef QVector<QComplexFloat> QComplexVector;

class QFourierTransformer
{

	public:

		enum Direction
		{
			Forward = 0,
			Inverse = 1
		};

		enum Initialization
		{
			VariableSize = 0,
			FixedSize = 1,
			InvalidSize = 2
		};

	public:

		QFourierTransformer(int size = -1);
		~QFourierTransformer();
		Initialization setSize(int size);
		void transform(float input[], float output[], QWindowFunction<float> *windowFunction = NULL, Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output, QWindowFunction<float> *windowFunction = NULL);
		void inverseTransform(float input[], float output[]);
		void rescale(float input[]);
		void conjugate(float input[]);
		QComplexVector toComplex(float input[]);

	protected:

		void initialize();
		int sizeToKey(int size);
		bool isValidSize(int value);

	private:

		int mSize;
		QMap<int, QFourierCalculator*> mFixedCalculators;
		QFourierCalculator* mVariableCalculator;
		QFourierCalculator *mCalculator;

};

#endif
