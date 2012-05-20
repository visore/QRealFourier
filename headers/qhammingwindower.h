#ifndef QHAMMINGWINDOWER_H
#define QHAMMINGWINDOWER_H

#include "qwindower.h"

class QHammingWindower : public QWindower
{

	public:

		qreal calculate(qint32 currentSample, qint32 totalSamples);
		QString name();

};

#endif
