#include "qhammingwindower.h"

qreal QHammingWindower::calculate(qint32 currentSample, qint32 totalSamples)
{
	return 0.54 + (0.46 * qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

QString QHammingWindower::name()
{
	return "Hamming";
}
