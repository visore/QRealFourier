#ifndef QFOURIERTRANSFORMER_H
#define QFOURIERTRANSFORMER_H

#include "qfourierfixedthread.h"
#include "qfouriervariablethread.h"
#include "qwindower.h"
#include "qcomplexnumber.h"

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
			SeperateThread = 1
		};

	public:

		QFourierTransformer(Execution execution = QFourierTransformer::SameThread, int fixedSize = -1);
		~QFourierTransformer();

		bool setFixedSize(int size);
		void setExecution(Execution execution);
		
		void transform(float input[], float output[], QWindower *windower = NULL, Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output, QWindower *windower = NULL);
		void inverseTransform(float input[], float output[]);

		void transform(float input[], float output[], qint32 numberOfSamples, QWindower *windower = NULL, Direction direction = QFourierTransformer::Forward);
		void forwardTransform(float *input, float *output, qint32 numberOfSamples, QWindower *windower = NULL);
		void inverseTransform(float input[], float output[], qint32 numberOfSamples);

		static QVector<QComplexFloat> toComplexFloat(float input[], qint32 numberOfSamples);
		static QVector<QComplexDouble> toComplexDouble(float input[], qint32 numberOfSamples);

	private:

		void initialize();

		void fixedForwardTransform(float *input, float *output);
		void fixedInverseTransform(float input[], float output[]);
		void variableForwardTransform(float input[], float output[], qint32 numberOfSamples);
		void variableInverseTransform(float input[], float output[], qint32 numberOfSamples);

		void forwardTransformSameThread();
		void forwardTransformSeperateThread();
		void inverseTransformSameThread();
		void inverseTransformSeperateThread();

	private:

		Execution mExecution;
		int mSize;

		QList<QFourierThread*> mFixedForwardThreads;
		QList<QFourierThread*> mFixedInverseThreads;
		QFourierThread* mVariableForwardThread;
		QFourierThread* mVariableInverseThread;
		QFourierThread *mForwardThread;
		QFourierThread *mInverseThread;

		void (QFourierTransformer::*forwardTransformtion)();
		void (QFourierTransformer::*inverseTransformtion)();
};

#endif
