#ifndef QFOURIERCALCULATOR_H
#define QFOURIERCALCULATOR_H

class QFourierCalculator
{

	public:
		
		QFourierCalculator();
		virtual void setData(float input[], float output[] = 0);
		virtual void setSize(int size);
		virtual int size();

		virtual void forward() = 0;
		virtual void inverse() = 0;
		virtual void rescale() = 0;

	protected:

		float *mInput;
		float *mOutput;
		int mSize;

};

#endif
