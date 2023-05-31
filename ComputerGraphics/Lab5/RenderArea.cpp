#include "RenderArea.h"
#include <QtCore>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <QOpenGLVertexArrayObject>
#include <qscopedpointer.h>
#include <QOpenGLWidget>
#include <GL/glu.h>
#include <GL/gl.h> 

RenderArea::RenderArea(QWidget *parent): polyhedronSort(new PolyhedronSort)
{

}

bool RenderArea::updateScene()
{
    /*auto pgs = PolyhedronSort::PolyhedronGeneratorSettings();
    polyhedronSort->setGeneratorSettings(pgs);
    this->update();*/
	return false;
}

void RenderArea::initializeGL()
{
    initializeOpenGLFunctions();
    
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
    
    glEnable(GL_DEPTH_TEST);
}

void RenderArea::paintGL()
{
    // Clear the color and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    paintAxis();

    glColor3f(1.0, 1.0, 1.0); // White

    paintSortedFaces();
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

void RenderArea::paintSortedFaces()
{
    if (polyhedronSort->isReady())
    {
        auto triangles = polyhedronSort->getFacesSortedByZ();
        glBegin(GL_TRIANGLES);
        for (const auto& triangle : triangles)
        {
            glVertex3f(triangle.p1.x(), triangle.p1.y(), triangle.p1.z());
            glVertex3f(triangle.p2.x(), triangle.p2.y(), triangle.p2.z());
            glVertex3f(triangle.p3.x(), triangle.p3.y(), triangle.p3.z());
        }
        glEnd();
    }

}




