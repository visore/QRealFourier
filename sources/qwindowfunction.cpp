#ifdef QWINDOWFUNCTION_H

/**********************************************************
QWindowFunction
**********************************************************/

template <typename T>
void QWindowFunction<T>::apply(T *data, int size)
{
	for(int i = 0; i < size; ++i)
	{
		data[i] *= mWindow[i];
	}
}

template <typename T>
void QWindowFunction<T>::create(int size)
{
	if(size != mWindow.size())
	{
		mWindow.clear();
		mWindow.resize(size);
		fillWindow(size);
	}
}

template <typename T>
void QWindowFunction<T>::fillWindow(int size)
{
	for(int i = 0; i < size; ++i)
	{
		mWindow[i] = calculate(i, size);
	}
}

/**********************************************************
QWindowFunctionManager
**********************************************************/

template <typename T>
QWindowFunction<T>* QWindowFunctionManager<T>::createFunction(QString functionName)
{
	functionName = functionName.trimmed().toLower().replace("function", "");
	if(functionName == "hamming")
	{
		return new QHammingFunction<T>;
	}
	else if(functionName == "hann")
	{
		return new QHannFunction<T>;
	}
	return NULL;
}

/**********************************************************
QRectangularFunction
**********************************************************/

template <typename T>
T QRectangularFunction<T>::calculate(int currentSample, int totalSamples)
{
	return 1.0;
}

/**********************************************************
QHammingFunction
**********************************************************/

template <typename T>
T QHammingFunction<T>::calculate(int currentSample, int totalSamples)
{
	return 0.54 + (0.46 * qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

/**********************************************************
QHannFunction
**********************************************************/

template <typename T>
T QHannFunction<T>::calculate(int currentSample, int totalSamples)
{
	return 0.5 * (1 - qCos((2 * M_PI * currentSample) / (totalSamples - 1)));
}

#endif
