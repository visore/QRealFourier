#ifndef QFOURIERVARIABLETHREAD_H
#define QFOURIERVARIABLETHREAD_H

#include <QThread>
#include "FFTReal.h"
#include "qfourierthread.h"

class QFourierVariableThread : public QFourierThread
{

	public:

		QFourierVariableThread();

};

class QFourierVariableForwardThread : public QFourierVariableThread
{

	public:

		QFourierVariableForwardThread();
		void run();

};

class QFourierVariableInverseThread : public QFourierVariableThread
{

	public:

		QFourierVariableInverseThread();
		void run();

};

#endif
