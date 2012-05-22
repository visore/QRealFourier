#include "qwindower.h"

QWindower::QWindower()
{
	mWindow = NULL;
}

QWindower::~QWindower()
{
	if(mWindow != NULL)
	{
		delete mWindow;
	}
}

void QWindower::apply(float *data, int size)
{
	createWindow(size);
	for(int i = 0; i < size; ++i)
	{
		data[i] *= mWindow->at(i);
	}
}

void QWindower::createWindow(int size)
{
	if(mWindow == NULL)
	{
		mWindow = new QWindow(size);
		fillWindow(size);
	}
	else if(size != mWindow->size())
	{
		delete mWindow;
		mWindow = new QWindow(size);
		fillWindow(size);
	}
}

void QWindower::fillWindow(int size)
{
	for(int i = 0; i < size; ++i)
	{
		(*mWindow)[i] = calculate(i, size);
	}
}
