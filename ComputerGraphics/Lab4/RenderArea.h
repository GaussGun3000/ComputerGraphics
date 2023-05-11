#pragma once

#include <QWidget>
#include <QVector>
#include <QVector3D>
#include <QScopedPointer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>

class RenderArea : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent = nullptr);
    bool updateSurface(float angleX, float angleY);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    void paintAxis();
    void paintCornerPoints();

    const uint32_t interpolationIters = 10;

};

