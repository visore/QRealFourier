#include "qfouriertransformer.h"
#include <iostream>

using namespace std;

const int SIZE = 64;

void print(QString string)
{
	cout << string.toAscii().data();
}

void print(float values[], int size)
{
	for(int i = 0; i < size; ++i)
	{
		print(QString::number(values[i], 'f', 4));
		print(" ");
	}
	print("\n");
}

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
