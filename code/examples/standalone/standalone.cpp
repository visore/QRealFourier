/***********************************************************************

standalone.cpp

Example illustrating the use of a pre-built QRealFourier library.

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
