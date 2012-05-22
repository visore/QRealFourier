#ifndef QFOURIERTHREAD_H
#define QFOURIERTHREAD_H

#include <QThread>

class QFourierTransformer;

class QFourierThread : public QThread
{

	public:
		
		QFourierThread(QFourierTransformer *transformer);
		void setData(float input[], float output[] = NULL);
		void setSize(int size);
		int size();

		virtual void run() = 0;

	protected:

		void notify();

	protected:

		QFourierTransformer *mTransformer; // Tight coupling due to template class problems with signals/slots
		float *mInput;
		float *mOutput;
		int mSize;

};

#endif
