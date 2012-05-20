#include "qhannwindower.h"

qreal QHannWindower::calculate(qint32 currentSample, qint32 totalSamples)
{
	return 0.5 * (1 - qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

QString QHannWindower::name()
{
	return "Hann";
}
