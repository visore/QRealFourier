#ifndef QRECTANGULARWINDOWER_H
#define QRECTANGULARWINDOWER_H

#include "qwindower.h"

class QRectangularWindower : public QWindower
{

		double calculate(int currentSample, int totalSamples);
		QString name();

};

#endif
