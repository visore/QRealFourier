#ifndef QWINDOWFUNCTION_H
#define QWINDOWFUNCTION_H

#include <QList>
#include <QStringList>
#include <QVector>
#include "math.h"
#include <qmath.h>

/**********************************************************
QWindowFunction
**********************************************************/

template <typename T>
class QWindowFunction
{

	typedef QVector<T> QWindow;

	public:

		void apply(T *data, int size);
		void create(int size);

	protected:

		void fillWindow(int size);
		virtual T calculate(int currentSample, int totalSamples) = 0;

	protected:

		QWindow mWindow;

};

/**********************************************************
QWindowFunctionManager
**********************************************************/
template <typename T>
class QWindowFunctionManager
{

	public:

		static QWindowFunction<T>* createFunction(QString functionName);
		static QStringList functions();

};

/**********************************************************
QRectangularFunction
**********************************************************/

template <typename T>
class QRectangularFunction : public QWindowFunction<T>
{

	protected:

		T calculate(int currentSample, int totalSamples);

};

/**********************************************************
QHammingFunction
**********************************************************/

template <typename T>
class QHammingFunction : public QWindowFunction<T>
{

	protected:

		T calculate(int currentSample, int totalSamples);

};

/**********************************************************
QHannFunction
**********************************************************/

template <typename T>
class QHannFunction : public QWindowFunction<T>
{

	protected:

		T calculate(int currentSample, int totalSamples);

};

#include "../sources/qwindowfunction.cpp"

#endif
