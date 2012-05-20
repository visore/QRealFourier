#ifndef QHANNWINDOWER_H
#define QHANNWINDOWER_H

#include "qwindower.h"

class QHannWindower : public QWindower
{

	public:

		qreal calculate(qint32 currentSample, qint32 totalSamples);
		QString name();

};

#endif
