==========================================================================================
==========================================================================================
==========================================================================================
====                                                                                  ====
====                                   QRealFourier                                   ====
====                                                                                  ====
==========================================================================================
==========================================================================================
==========================================================================================



A Qt-based C++ library for Fast Fourier Transform (FFT) of real samples.

Last Release: 22 May 2012
Latest version: 0.1
Developer: Christoph Stallmann


==========================================================================================
=                                         About                                          =
==========================================================================================

QRealFourier is a Qt library for calculating FFTs on real samples. This library is based 
on FFTReal designed and created by Laurent de Soras. I take no credit and on the work done
in FFTReal. This purpose of this library is to create a simple-to-use interface for novice
FFT users in Qt. A single class (QFourierTransformer) provides a number of function for
handling forward and inverse FFTs and rescaling. A lot of the work is done during compile-
time which creates a more efficient FFT implementation. The library is slightly larger and
takes up a couple of extra bytes, but this is a fair trade-off for simplicity.

==========================================================================================
=                                     Requirements                                       =
==========================================================================================

QRealFourier requires CMake (2.6 or later) for makefile generation. Qt (4.7 or later) is
also required. Qt5 will be supported soon. Any native compilers should do, recommended are
g++ for Linux and MinGW for Windows.

==========================================================================================
=                                       Compiling                                        =
==========================================================================================

1. mkdir build
2. cd build
3. ccmake ..
4. press 'c', 'c' and then 'g'
5. make

==========================================================================================
=                                         Usage                                          =
==========================================================================================

There are two examples under the tests directory.
One is using a separate thread, the other one uses the main thread.
After compiling, you can simply run the executables in the build directory.

==========================================================================================
=                                      Fixed Sizes                                       =
==========================================================================================

QRealFourier is optimized for the following sizes:

8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 and 16384

The transformation will have a better performance with chunks with one of these sizes.
Any other sizes will work, but pre-calculations have to be done during run-time which
reduces the performance.

==========================================================================================
=                                    Real & Imaginary                                    =
==========================================================================================

When doing the following:

transformer.forwardTransform(samples, fft);

the fft array will contain the following:

 Output array   | Values
 ---------------+----------------------
 f [0]          | Real (bin 0)
 f [...]        | Real (bin ...) 
 f [length/2]   | Real (bin length/2)
 f [length/2+1] | Imaginary (bin 1)
 f [...]        | Imaginary (bin ...)
 f [length-1]   | Imaginary (bin length/2-1)

The static function QFourierTransformer::toComplex(float input[], int numberOfSamples)
can be used to convert this array into a QComplexVector. QComplexVector is a QVector
with QComplexNumbers, each number has a real and imaginary part.

==========================================================================================
=                                     The Main Class                                     =
==========================================================================================

QRealFourier is the interface that should be used for all transformations.

1.	QFourierTransformer(Execution execution, int fixedSize);

	Constructor with both parameters optional.

	Execution specifies if the FFT or rescaling should be done in a separate thread.
	Default is execution in the same thread.

	The second parameter specifies the fixed size of the FFT.
	The default is -1 which will result in a slower variable size.
   

2.	bool setFixedSize(int size);

	Changes the fixed size to one of sizes given in the list above. This is the same as
	the second parameter in the constructor. Can be changed during runtime.
   
	If a size not in the prescribed list is passed, false will be returned and the
	slower variable size FFT will be used.

3.	void setExecution(Execution execution);

	Sets the execution of the FFT to run in the same thread as the caller or in a
	separate thread. For sizes 16384 or smaller, the same thread is recommended. This is
	the same as the first parameter of the constructor.
		
4.	void forwardTransform(float *input, float *output, QWindower *windower);

	This function is used for fixed-sized FFTs.

	Calculates the FFT of the input samples and stores them in output. The output array
	must be allocated beforehand and has the same size as the input array.

	If a window function is required, you can pass one to the function. The input array
	will automatically be adjusted according to the window function. If NULL is passed
	no windowing will be done.

5.	void inverseTransform(float input[], float output[]);

	This function is used for fixed-sized FFTs.

	Calculates the inverse FFT from the input and stores it as real samples in the output
	array. The output array must be allocated beforehand with the same size as input.
		
6.	void transform(float input[], float output[], QWindower *windower = NULL,
	Direction direction = QFourierTransformer::Forward);

	This function is used for fixed-sized FFTs.

	Calls one of the function in 4 or 5 above, depending on the direction parameter.
	This function is generally not recommended since it uses an extra if-statement.
	Rather use 4 or 5 instead.

7.	void rescale(float input[]);

	This function is used for fixed-sized FFTs.

	After the inverse FFT was calculated, you have to rescale the values of the samples.

8.	void forwardTransform(float *input, float *output, int numberOfSamples,
	QWindower *windower = NULL);

	This function is used for variable-sized FFTs.

	The same as the function in 4 above, except that it operates on variable-sized FFTs 
	constructed at run-time. If you can, use one of the fixed-sizes in the list above,
	set the size with the function in 2, and then do the transformation with the
	function in 4.

9.	void inverseTransform(float input[], float output[], int numberOfSamples);

	This function is used for variable-sized FFTs.

	The same as the function in 5 above, except that it operates on variable-sized FFTs 
	constructed at run-time. If you can, use one of the fixed-sizes in the list above,
	set the size with the function in 2, and then do the transformation with the
	function in 5.

10.	void transform(float input[], float output[], int numberOfSamples,
	QWindower *windower = NULL, Direction direction = QFourierTransformer::Forward);
	
	This function is used for variable-sized FFTs.

	The same as the function in 6 above, except that it operates on variable-sized FFTs 
	constructed at run-time.

11.	void rescale(float input[], int numberOfSamples);

	This function is used for variable-sized FFTs.

	The same as the function in 7 above, except that it operates on variable-sized FFTs 
	constructed at run-time.

12.	static QComplexVector toComplex(float input[], int numberOfSamples);

	Converts the FFT calculated with 4, 6, 8 or 10 above to a QVector of complex numbers
	as explained in a previous section.

==========================================================================================
=                                    Window Functions                                    =
==========================================================================================

The following window functions are supported:

1.	Rectangular
2.	Hamming
3.	Hann

==========================================================================================
=                                        History                                         =
==========================================================================================

22 May 2012
Version 0.1
Initial release

==========================================================================================
=                                        Contact                                         =
==========================================================================================

QRealFourier is part of the Visore project:

http://www.visore.org
http://github.com/visore/Visore
http://sourceforge.net/projects/visore/

QRealFourier:

Christoph Stallmann
University of Pretoria
Department of Computer Science

visore.project@gmail.com
http://github.com/visore/QRealFourier
http://sourceforge.net/p/qrealfourier

FFTReal:

Laurent de Soras
laurent.de.soras@free.fr
http://ldesoras.free.fr
