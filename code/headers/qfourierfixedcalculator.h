#ifndef QFOURIERFIXEDCALCULATOR_H
#define QFOURIERFIXEDCALCULATOR_H

#include "FFTRealFixLen.h"
#include "qfouriercalculator.h"

template <int T>
class QFourierFixedCalculator : public QFourierCalculator
{

	public:
		
		QFourierFixedCalculator();
		void setSize(int size);
		void forward();
		void inverse();
		void rescale();

	protected:

		ffft::FFTRealFixLen<T> mFourierTransform;

};

#include "../sources/qfourierfixedcalculator.cpp"

#endif
