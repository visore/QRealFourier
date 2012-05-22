#include "fourierreceiver.h"
#include <QCoreApplication>

int main(int argc, char **argv)
{
	QCoreApplication application(argc, argv);

	FourierReceiver receiver;
	receiver.doAction();

	application.exec();

	return 0;
}
