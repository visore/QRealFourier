#ifndef QFOURIERVARIABLECALCULATOR_H
#define QFOURIERVARIABLECALCULATOR_H

#include "FFTReal.h"
#include "qfouriercalculator.h"

class QFourierVariableCalculator : public QFourierCalculator
{

	public:

		QFourierVariableCalculator();
		~QFourierVariableCalculator();
		void setSize(int size);
		void forward();
		void inverse();
		void rescale();

	protected:

		ffft::FFTReal<float> *mFourierTransform;

};

class QFourierVariableForwardCalculator : public QFourierVariableCalculator
{

	public:

		QFourierVariableForwardCalculator();
		void calculate();

};

class QFourierVariableInverseCalculator : public QFourierVariableCalculator
{

	public:

		QFourierVariableInverseCalculator();
		void calculate();

};

class QFourierVariableRescaleCalculator : public QFourierVariableCalculator
{

	public:

		QFourierVariableRescaleCalculator();
		void calculate();

};

#endif
