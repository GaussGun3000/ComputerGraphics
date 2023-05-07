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
#include "BilinearSurface.h"

class RenderArea : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent = nullptr);
    bool updateSurface(float angleX, float angleY);
    QScopedPointer<BilinearSurface> surface;


protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    void paintAxis();
    void paintCornerPoints();

    QVector<QVector3D> surfacePoints;
    QVector3D cameraPosition;
    QOpenGLShaderProgram* m_shaderProgram;
    QOpenGLBuffer* m_vbo;
    QOpenGLVertexArrayObject* m_vao;
    float cameraDistance;
    float m_angleX;
    float m_angleY;
};

