#ifndef QFOURIERVARIABLETHREAD_H
#define QFOURIERVARIABLETHREAD_H

#include <QThread>
#include "FFTReal.h"
#include "qfourierthread.h"

class QFourierVariableThread : public QFourierThread
{

	public:

		QFourierVariableThread(QFourierTransformer *transformer);

};

class QFourierVariableForwardThread : public QFourierVariableThread
{

	public:

		QFourierVariableForwardThread(QFourierTransformer *transformer);
		void run();

};

class QFourierVariableInverseThread : public QFourierVariableThread
{

	public:

		QFourierVariableInverseThread(QFourierTransformer *transformer);
		void run();

};

class QFourierVariableRescaleThread : public QFourierVariableThread
{

	public:

		QFourierVariableRescaleThread(QFourierTransformer *transformer);
		void run();

};

#endif
