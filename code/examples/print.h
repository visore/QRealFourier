#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <QString>

using namespace std;

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

#endif
