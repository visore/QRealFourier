#include "qhannwindower.h"

double QHannWindower::calculate(int currentSample, int totalSamples)
{
	return 0.5 * (1 - qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

QString QHannWindower::name()
{
	return "Hann";
}
