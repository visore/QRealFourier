#ifndef QRECTANGULARWINDOWER_H
#define QRECTANGULARWINDOWER_H

#include "qwindower.h"

class QRectangularWindower : public QWindower
{

		qreal calculate(qint32 currentSample, qint32 totalSamples);
		QString name();

};

#endif
