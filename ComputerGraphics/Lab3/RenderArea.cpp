#include "RenderArea.h"
#include "BilinearSurface.h"
#include <QtCore>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <qscopedpointer.h>
#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h> 

RenderArea::RenderArea(QWidget *parent):
	surface(new BilinearSurface)
{
    surfacePoints = QVector<QVector3D>();
    m_angleX = 0;
    m_angleY = 0;
}

bool RenderArea::updateSurface(float angleX, float angleY)
{
    if (!surface->cornerPoints().empty()) 
        this->surfacePoints = surface->interpolate(interpolationIters, interpolationIters, angleX, angleY);
    this->update();
	return false;
}

void RenderArea::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)width() / (GLfloat)height(), 0.1f, 100.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -10.0f);

    gluLookAt(1.0f, 1.0f, 1.0f, // Camera position (x, y, z)
        0.0f, 0.0f, 0.0f,  // Look at point (x, y, z)
        0.0f, 0.0f, 1.0f); // Up vector (x, y, z)

}

void RenderArea::paintGL()
{
    // Clear the color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    paintAxis();
    paintCornerPoints();

    glColor3f(1.0, 1.0, 1.0); // White

    glBegin(GL_POINTS);

    glVertex3f(1.f, 1.f, 1.f);

    for (auto p : surfacePoints)
    {
        glVertex3f(p.x(), p.y(), p.z());
    }
    glEnd();

    paintMeshGrid();
}


void RenderArea::resizeGL(int width, int height)
{
    this->update();
}

void RenderArea::paintAxis()
{
    // Draw the x-axis in red
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(10.0f, 0.0f, 0.0f);
    glEnd();

    // Draw the y-axis in green
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 10.0f, 0.0f);
    glEnd();

    // Draw the z-axis in blue
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 10.0f);
    glEnd();
}

void RenderArea::paintCornerPoints()
{
    glColor3f(1.0f, 1.0f, 0.0f); // set color to yellow
    glPointSize(3.0f); // set point size to 10

    glBegin(GL_POINTS);
    QVector<QVector3D> points = surface->cornerPoints();
    for (const QVector3D& point : points)
        glVertex3f(point.x(), point.y(), point.z()); // draw point
    glEnd();

    if (surface->isRotated())
    {
        glColor3f(1.f, 0.0f, 1.f); // set color to Blue
        glBegin(GL_POINTS);
        points = surface->cornerPointsRotated();
        for (const QVector3D& point : points)
            glVertex3f(point.x(), point.y(), point.z()); // draw point
        glEnd();
    }

    // reset color and point size to defaults
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.0f);
}

void RenderArea::paintMeshGrid()
{
    if (!surfacePoints.empty())
    {
        for (uint32_t i = 0; i < this->interpolationIters; i++)
        {
            for (uint32_t j = 0; j < this->interpolationIters; j++)
            {
                glBegin(GL_LINES);
                QVector3D point = surfacePoints.at(i + j * (interpolationIters + 1));
                QVector3D point2 = surfacePoints.at(i + j * (interpolationIters + 1) + 1);
                glVertex3f(point.x(), point.y(), point.z());
                glVertex3f(point2.x(), point2.y(), point2.z());
                glEnd();

                glBegin(GL_LINES);
                point = surfacePoints.at(i + j * (interpolationIters + 1));
                point2 = surfacePoints.at(i + (j + 1) * (interpolationIters + 1));
                glVertex3f(point.x(), point.y(), point.z());
                glVertex3f(point2.x(), point2.y(), point2.z());
                glEnd();
            }
        }

        // Draw lines connecting the last row of points
        for (uint32_t i = 0; i < interpolationIters; i++) {
            glBegin(GL_LINES);
            QVector3D point = surfacePoints.at(i + interpolationIters * (interpolationIters + 1));
            QVector3D point2 = surfacePoints.at(i + interpolationIters * (interpolationIters + 1) + 1);
            glVertex3f(point.x(), point.y(), point.z());
            glVertex3f(point2.x(), point2.y(), point2.z());
            glEnd();
        }

        // Draw lines connecting the last column of points
        for (uint32_t j = 0; j < interpolationIters; j++) {
            glBegin(GL_LINES);
            QVector3D point = surfacePoints.at(interpolationIters + j * (interpolationIters + 1));
            QVector3D point2 = surfacePoints.at(interpolationIters + (j + 1) * (interpolationIters + 1));
            glVertex3f(point.x(), point.y(), point.z());
            glVertex3f(point2.x(), point2.y(), point2.z());
            glEnd();
        }
    }
}


