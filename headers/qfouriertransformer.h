#ifndef QFOURIERTRANSFORMER_H
#define QFOURIERTRANSFORMER_H

#include "qfourierfixedthread.h"
#include "qfouriervariablethread.h"
#include "qwindower.h"
#include "qcomplexnumber.h"

typedef QVector<QComplexFloat> QComplexVector;

class QFourierTransformer : public QObject
{
	Q_OBJECT

	signals:

		void finished();

	public:

		enum Direction
		{
			Forward = 0,
			Inverse = 1
		};

		enum Execution
		{
			SameThread = 0,
			SeparateThread = 1
		};

	public:

		QFourierTransformer(Execution execution = QFourierTransformer::SameThread, int fixedSize = -1);
		~QFourierTransformer();
		void emitFinished();

		bool setFixedSize(int size);
		void setExecution(Execution execution);
		
		void transform(float input[], float output[], QWindower *windower = NULL, Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output, QWindower *windower = NULL);
		void inverseTransform(float input[], float output[]);
		void rescale(float input[]);

		void transform(float input[], float output[], int numberOfSamples, QWindower *windower = NULL, Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output, int numberOfSamples, QWindower *windower = NULL);
		void inverseTransform(float input[], float output[], int numberOfSamples);

		void rescale(float input[], int numberOfSamples);
		static QComplexVector toComplex(float input[], int numberOfSamples);

	private:

		void initialize();

		void fixedForwardTransform(float *input, float *output);
		void fixedInverseTransform(float input[], float output[]);
		void fixedRescale(float input[]);
		void variableForwardTransform(float input[], float output[], int numberOfSamples);
		void variableInverseTransform(float input[], float output[], int numberOfSamples);
		void variableRescale(float input[], int numberOfSamples);

		void forwardTransformSameThread();
		void forwardTransformSeperateThread();
		void inverseTransformSameThread();
		void inverseTransformSeperateThread();
		void rescaleTransformSameThread();
		void rescaleTransformSeperateThread();

	private:

		Execution mExecution;
		int mSize;

		QList<QFourierThread*> mFixedForwardThreads;
		QList<QFourierThread*> mFixedInverseThreads;
		QList<QFourierThread*> mFixedRescaleThreads;
		QFourierThread* mVariableForwardThread;
		QFourierThread* mVariableInverseThread;
		QFourierThread* mVariableRescaleThread;
		QFourierThread *mForwardThread;
		QFourierThread *mInverseThread;
		QFourierThread *mRescaleThread;

		void (QFourierTransformer::*forwardTransformtion)();
		void (QFourierTransformer::*inverseTransformtion)();
		void (QFourierTransformer::*rescaleTransformtion)();
};

#endif
