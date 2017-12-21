#ifndef LZ_GL_WINDOW_H
#define LZ_GL_WINDOW_H

#include <QtOpenGL\qglwidget>
#include <Qt\qtimer.h>

class LZGLWindow : public QGLWidget
{
	Q_OBJECT

	QTimer timer;

protected:
	void initializeGL();
	void UpdatePlayer();
	void paintGL();
	private slots:
	void Repainter();
	void updateAcceleration();
	void updateRotation();
private:
	void setupViewport();
	void bounce();
	void warp();
	void handleMiscKeys();
	void lerpTheLerper();
	void theUpdate();
	void draw();
	void drawGL();
public:
	void keyPressEvent(QKeyEvent* e);
	bool Initialize();
	bool Shutdown();
};


#endif