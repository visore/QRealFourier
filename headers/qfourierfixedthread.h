#ifndef QFOURIERFIXEDTHREAD_H
#define QFOURIERFIXEDTHREAD_H

#include <qmath.h> 
#include "FFTRealFixLen.h"
#include "qfourierthread.h"

template <int T>
class QFourierFixedThread : public QFourierThread
{

	public:
		
		QFourierFixedThread(QFourierTransformer *transformer);
		virtual void run() = 0;

	protected:

		ffft::FFTRealFixLen<T> mFourierTransform;

};

template <int T>
class QFourierFixedForwardThread : public QFourierFixedThread<T>
{

	public:

		QFourierFixedForwardThread(QFourierTransformer *transformer);
		void run();

};

template <int T>
class QFourierFixedInverseThread : public QFourierFixedThread<T>
{

	public:

		QFourierFixedInverseThread(QFourierTransformer *transformer);
		void run();

};

template <int T>
class QFourierFixedRescaleThread : public QFourierFixedThread<T>
{

	public:

		QFourierFixedRescaleThread(QFourierTransformer *transformer);
		void run();

};

#include "../sources/qfourierfixedthread.cpp"

#endif
