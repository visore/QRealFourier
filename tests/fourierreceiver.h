#ifndef FOURIERRECEIVER_H
#define FOURIERRECEIVER_H

#include "qfouriertransformer.h"
#include <QObject>

const int SIZE = 128;

class FourierReceiver : public QObject
{

	Q_OBJECT

	public slots:

		void doAction();

	public:

		FourierReceiver();
		~FourierReceiver();
		int action();

	private:

		void doForward();
		void doInverse();
		void doRescale();
		void doLast();

		int mAction;
		float *mSamples;
		float *mFft;
		QFourierTransformer mTransformer;

};

#endif
