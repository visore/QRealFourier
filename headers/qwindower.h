#ifndef QWINDOWER_H
#define QWINDOWER_H

#include <QtGlobal>
#include <QString>
#include <QVector>
#include "math.h"
#include <qmath.h>

typedef QVector<double> QWindow;

class QWindower
{

	public:

		QWindower();
		~QWindower();
		void apply(float *data, int size);
		virtual double calculate(int currentSample, int totalSamples) = 0;
		virtual QString name() = 0;

	protected:

		void createWindow(int size);
		void fillWindow(int size);

	protected:

		QWindow *mWindow;

};

#endif
