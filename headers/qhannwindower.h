#ifndef QHANNWINDOWER_H
#define QHANNWINDOWER_H

#include "qwindower.h"

class QHannWindower : public QWindower
{

	public:

		double calculate(int currentSample, int totalSamples);
		QString name();

};

#endif
