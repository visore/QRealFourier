#include "qhammingwindower.h"

double QHammingWindower::calculate(int currentSample, int totalSamples)
{
	return 0.54 + (0.46 * qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

QString QHammingWindower::name()
{
	return "Hamming";
}
