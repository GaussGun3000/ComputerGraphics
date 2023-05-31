#pragma once

#include <QWidget>
#include <QVector>
#include <QVector3D>
#include <QScopedPointer>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include "PolyhedronSort.h"

class RenderArea : public QOpenGLWidget, public QOpenGLFunctions
{
    Q_OBJECT

public:
    RenderArea(QWidget* parent = nullptr);
    bool updateScene();
    void setAlgorithmSettings(PolyhedronSort::PolyhedronGeneratorSettings& settings);
    PolyhedronSort::PolyhedronGeneratorSettings getAlgorithmSettings();

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    void paintAxis();
    void paintSortedFaces();

    QScopedPointer<PolyhedronSort> polyhedronSort;
};

