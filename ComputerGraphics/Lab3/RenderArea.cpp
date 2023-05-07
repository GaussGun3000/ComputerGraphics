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
    this->surfacePoints = surface->interpolate(10, 10);
    this->update();
	return false;
}

void RenderArea::initializeGL()
{
    /*
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);

    // Set the clear color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // Compile the vertex shader
    QOpenGLShader vertexShader(QOpenGLShader::Vertex);
    vertexShader.compileSourceFile(":/shaders/simple.vert");

    // Compile the fragment shader
    QOpenGLShader fragmentShader(QOpenGLShader::Fragment);
    fragmentShader.compileSourceFile(":/shaders/simple.frag");

    // Link the shaders into a shader program
    m_shaderProgram = new QOpenGLShaderProgram();
    m_shaderProgram->addShader(&vertexShader);
    m_shaderProgram->addShader(&fragmentShader);
    m_shaderProgram->link();

    // Create a VAO
    m_vao = new QOpenGLVertexArrayObject();
    m_vao->create();
    m_vao->bind();

    // Create a VBO for vertex data
    m_vbo = new QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    m_vbo->create();
    m_vbo->bind();
    m_vbo->setUsagePattern(QOpenGLBuffer::StaticDraw);

    // Enable the vertex attribute array and specify the layout
    m_shaderProgram->enableAttributeArray("vertexPosition");
    m_shaderProgram->setAttributeBuffer("vertexPosition", GL_FLOAT, 0, 3, sizeof(QVector3D));

    // Release the VBO and VAO
    m_vbo->release();
    m_vao->release();
    */
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
/*
    if (!surfacePoints.empty())
    {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glUseProgram(m_shaderProgram->programId());
        m_shaderProgram->bind();
        // Bind the VAO
        m_vao->bind();

        // Bind the VBO and set the data
        m_vbo->bind();
        m_vbo->allocate(surfacePoints.constData(), surfacePoints.size() * sizeof(QVector3D));

        // Draw the surface
        glDrawArrays(GL_TRIANGLE_STRIP, 0, surfacePoints.size());

        // Release the VBO and VAO
        m_vbo->release();
        m_vao->release();
    }
 */


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    paintAxis();
    paintCornerPoints();

    glColor3f(1.0, 1.0, 1.0); // White
    //glBindTexture(GL_TEXTURE_2D, textureId);

    // Define the vertices and texture coordinates

    // Draw the surface
    glBegin(GL_POINTS);

    glVertex3f(1.f, 1.f, 1.f);

    for (auto p : surfacePoints)
    {
        glVertex3f(p.x(), p.y(), p.z());
    }
    glEnd();
}


void RenderArea::resizeGL(int width, int height)
{
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

    // reset color and point size to defaults
    glColor3f(1.0f, 1.0f, 1.0f);
    glPointSize(1.0f);
}



