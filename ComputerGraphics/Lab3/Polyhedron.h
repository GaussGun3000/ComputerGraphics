#pragma once
#include <qvector.h>
#include <qvector3d.h>

class Triangle {
public:
    Triangle(const QVector3D& v1, const QVector3D& v2, const QVector3D& v3)
        : vertices{ v1, v2, v3 } {}

    const QVector3D& operator[](int i) const { return vertices[i]; }
    QVector3D& operator[](int i) { return vertices[i]; }

private:
    QVector3D vertices[3];
};

class Polyhedron {
public:
    Polyhedron(QVector<QVector3D> vertices, QVector<QVector<int>> faces)
        : vertices(vertices), faces(faces) {}

    void generateRandomPolyhedron();

    QVector<QVector3D> getVertices() const { return vertices; }
    QVector<Triangle> getMesh() const;


private:
    QVector<QVector3D> vertices;
    QVector<QVector<int>> faces;
    const uint32_t VERT_COUNT = 16;
};




