/*

This example illustrates the normal behaviour of a forward FFT with a none-default size followed by an inverse FFT and a conjugation.
The values have to be rescaled after a FFT followed by an inverse FFT.

The basic steps:
 1. Forward FFT (window function automatically applied here)
 2. Inverse FFT
 3. Conjugation
 4. Rescaling

*/

#include "qfouriertransformer.h"
#include "print.h"

const int SIZE = 4;

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

	transformer.forwardTransform(samples, fft);
	transformer.inverseTransform(fft, samples);
	
	print("Samples after transformation and before conjugation and rescaling:\n");
	print(samples, SIZE);

	transformer.conjugate(samples);
	print("Samples after conjugation and before rescaling:\n");
	print(samples, SIZE);

	transformer.rescale(samples);
	print("Samples after rescaling:\n");
	print(samples, SIZE);

	return 0;
}
