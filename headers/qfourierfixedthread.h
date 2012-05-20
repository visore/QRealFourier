#ifndef QFOURIERFIXEDTHREAD_H
#define QFOURIERFIXEDTHREAD_H

#include <QtCore/qmath.h> 
#include "FFTRealFixLen.h"
#include "qfourierthread.h"

template <int T>
class QFourierFixedThread : public QFourierThread
{

	public:
		
		QFourierFixedThread();
		virtual void run() = 0;

	protected:

		ffft::FFTRealFixLen<T> mFourierTransform;

};

template <int T>
class QFourierFixedForwardThread : public QFourierFixedThread<T>
{

	public:

		QFourierFixedForwardThread();
		void run();

};

template <int T>
class QFourierFixedInverseThread : public QFourierFixedThread<T>
{

	public:

		QFourierFixedInverseThread();
		void run();

};

#include "../sources/qfourierfixedthread.cpp"

#endif
