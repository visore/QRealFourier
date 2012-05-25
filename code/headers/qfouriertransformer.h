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

		QFourierTransformer(int size = 0, QString functionName = "");
		~QFourierTransformer();

		Initialization setSize(int size);
		bool setWindowFunction(QString functionName);
		QStringList windowFunctions();

		void transform(float input[], float output[], Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output);
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
		QStringList mWindowFunctions;
		QWindowFunction<float> *mWindowFunction;

};

#endif
