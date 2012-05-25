/*

This example illustrates the normal behaviour of a forward FFT using the Hamming window function followed by an inverse FFT.
The values have to be rescaled after a FFT followed by an inverse FFT.

The basic steps:
 1. Forward FFT (window function automatically applied here)
 2. Inverse FFT
 3. Rescaling

*/

#include "qfouriertransformer.h"
#include "qwindowfunction.h"
#include "print.h"

const int SIZE = 128;

int main()
{

	float samples[SIZE];
	float fft[SIZE];

	//Creating sample values
	for(int i = 0; i < SIZE; ++i)
	{
		samples[i] = i / float(SIZE);
	}

	print("Samples before transformation:\n");
	print(samples, SIZE);

	QFourierTransformer transformer;
	QHammingFunction<float> windowFunction;
	windowFunction.create(SIZE);

	//Setting a fixed size for the transformation
	if(transformer.setSize(SIZE) == QFourierTransformer::VariableSize)
	{
		print("This size is not a default fixed size of QRealFourier. Using a variable size instead.\n");
	}
	else if(transformer.setSize(SIZE) == QFourierTransformer::InvalidSize)
	{
		print("Invalid FFT size.\n");
		return -1;
	}

	transformer.forwardTransform(samples, fft, &windowFunction);
	transformer.inverseTransform(fft, samples);
	
	print("Samples after transformation and before rescaling:\n");
	print(samples, SIZE);

	transformer.rescale(samples);
	print("Samples after rescaling:\n");
	print(samples, SIZE);

	return 0;
}
