#ifndef QWINDOWER_H
#define QWINDOWER_H

#include <QtGlobal>
#include <QString>
#include <QVector>
#include "math.h"
#include <qmath.h>

typedef QVector<qreal> QWindow;

class QWindower
{

	public:

		QWindower();
		~QWindower();
		void apply(float *data, qint32 size);
		virtual qreal calculate(qint32 currentSample, qint32 totalSamples) = 0;
		virtual QString name() = 0;

	protected:

		void createWindow(qint32 size);
		void fillWindow(qint32 size);

	protected:

		QWindow *mWindow;

};

#endif
