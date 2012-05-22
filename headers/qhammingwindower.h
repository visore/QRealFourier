#ifndef QHAMMINGWINDOWER_H
#define QHAMMINGWINDOWER_H

#include "qwindower.h"

class QHammingWindower : public QWindower
{

	public:

		double calculate(int currentSample, int totalSamples);
		QString name();

};

#endif
