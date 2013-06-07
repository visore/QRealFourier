/***********************************************************************

example2.cpp

This example illustrates the normal behaviour of a forward FFT using
the Hamming window function followed by an inverse FFT. The values have
to be rescaled after a FFT followed by an inverse FFT.

The basic steps:
 1. Forward FFT (window function automatically applied here)
 2. Inverse FFT
 3. Rescaling

************************************************************************

This file is part of QRealFourier.

QRealFourier is free software: you can redistribute it and/or modify it
under the terms of the Lesser GNU General Public License as published
by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Foobar is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the Lesser GNU General Public
License for more details.

You should have received a copy of the Lesser GNU General Public License
along with Foobar.  If not, see <http://www.gnu.org/licenses/>.

************************************************************************

Copyright © 2012 - 2013 Christoph Stallmann, University of Pretoria

Developer: Christoph Stallmann
University of Pretoria
Department of Computer Science

http://www.visore.org
http://sourceforge.net/projects/qrealfourier
http://github.com/visore/QRealFourier

qrealfourier@visore.org
qrealfourier@gmail.com

***********************************************************************/

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

	QFourierTransformer transformer;

	QStringList functions = transformer.windowFunctions();
	print("The following window functions are available:\n");
	for(int i = 0; i < functions.size(); ++i)
	{
		print(QString::number(i + 1) + ". " + functions[i] + "\n");
	}

	print("Samples before transformation:\n");
	print(samples, SIZE);

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

	if(!transformer.setWindowFunction("Hamming"))
	{
		print("Could not find this window function. Defaulting to the previous one.\n");
	}

	transformer.forwardTransform(samples, fft);
	transformer.inverseTransform(fft, samples);
	
	print("Samples after transformation and before rescaling:\n");
	print(samples, SIZE);

	transformer.rescale(samples);
	print("Samples after rescaling:\n");
	print(samples, SIZE);

	return 0;
}
