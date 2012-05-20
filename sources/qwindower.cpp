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

void QWindower::apply(float *data, qint32 size)
{
	createWindow(size);
	for(int i = 0; i < size; ++i)
	{
		data[i] *= mWindow->at(i);
	}
}

void QWindower::createWindow(qint32 size)
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

void QWindower::fillWindow(qint32 size)
{
	for(int i = 0; i < size; ++i)
	{
		(*mWindow)[i] = calculate(i, size);
	}
}
