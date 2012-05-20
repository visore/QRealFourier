#ifndef QFOURIERTHREAD_H
#define QFOURIERTHREAD_H

#include <QThread>

class QFourierThread : public QThread
{

	public:
		
		QFourierThread();
		void setData(float input[], float output[]);
		void setSize(int size);
		int size();

		virtual void run() = 0;

	protected:

		float *mInput;
		float *mOutput;
		int mSize;

};

#endif
