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
	if(!transformer.setFixedSize(SIZE))
	{
		print("This size is not a supported power of 2. Using a variable FFT instead.\n");
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
