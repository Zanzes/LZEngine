#include <qt\qapplication.h>
#include <GameFiles\MyGame.h>

int main(int argc, char* argv[])
{
	QApplication application(argc, argv);
	//LZGLWindow widget;
	LZSoft::MyGame widget;
	qDebug() << &widget;
	if (!widget.initialize())
		return -1;
	widget.go();
	int errorCode = application.exec();
	if (!widget.shutdown())
		errorCode |= 1;
    return errorCode;
}

