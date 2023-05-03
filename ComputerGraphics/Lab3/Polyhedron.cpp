#include "Polyhedron.h"
#include <QRandomGenerator>
#include <QVector3D>


void Polyhedron::generateRandomPolyhedron()
{
    // generate random vertex coordinates
    for (int i = 0; i < VERT_COUNT; ++i) {
        qreal x = qrand() % 100;
        qreal y = qrand() % 100;
        qreal z = qrand() % 100;
        vertices.append(QVector3D(x, y, z));
    }

    // generate random faces from vertex indices
    for (int i = 0; i < VERT_COUNT; ++i) 
    {
        for (int j = i + 1; j < VERT_COUNT; ++j) 
        {
            for (int k = j + 1; k < VERT_COUNT; ++k) 
            {
                QVector3D v1 = vertices[i];
                QVector3D v2 = vertices[j];
                QVector3D v3 = vertices[k];
                QVector3D normal = QVector3D::normal(v2 - v1, v3 - v1).normalized();
                qreal dist = QVector3D::dotProduct(normal, v1);
                bool isFront = true;
                QVector<int> indices{ i, j, k };
                for (int l = 0; l < VERT_COUNT; ++l) {
                    if (l == i || l == j || l == k)
                        continue;
                    qreal distToPlane = QVector3D::dotProduct(normal, vertices[l]) - dist;
                    if (distToPlane > 0) {
                        isFront = false;
                        break;
                    }
                    indices.append(l);
                }
                if (isFront)
                    faces.append(indices);
            }
        }
    }
}

QVector<Triangle> Polyhedron::getMesh() const
{
    QVector<Triangle> triangles;

    for (const QVector<int>& face : faces) {
        int numVertices = face.size();

        // Generate triangles for the face
        for (int i = 1; i < numVertices - 1; ++i) {
            int v0 = face[0];
            int v1 = face[i];
            int v2 = face[i + 1];

            triangles.append(Triangle(vertices[v0], vertices[v1], vertices[v2]));
        }
    }

    return triangles;
}