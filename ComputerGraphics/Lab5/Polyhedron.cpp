#include <qpolygon.h>
#include <qrandom.h>
#include "Polyhedron.h"


QVector3D Polyhedron::border = QVector3D(8, 8, 8);

Polyhedron::Polyhedron()
{
    random(6, 6, 5, 5);
}

Polyhedron::Polyhedron(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces)
{
    random(max_vertices, max_faces, min_vertices, min_faces);
}

QVector<QVector3D>& Polyhedron::getVertices()
{
    return vertices;
}

QVector<Polyhedron::Face>& Polyhedron::getFaces()
{
    return faces;
}

void Polyhedron::random(uint32_t maxVertices, uint32_t maxFaces, uint32_t minVertices, uint32_t minFaces) 
{
    this->vertices.clear();
    this->faces.clear();
    QRandomGenerator randomGenerator;
    uint32_t numVertices = randomGenerator.bounded(minVertices, maxVertices + 1);
    uint32_t numFaces = randomGenerator.bounded(minFaces, maxFaces + 1);

    for (uint32_t i = 0; i < numVertices; i++)
    {
        float x = randomGenerator.bounded(border.x() * 2) - border.x();
        float y = randomGenerator.bounded(border.y() * 2) - border.y();
        float z = randomGenerator.bounded(border.z() * 2) - border.z();
        QVector3D vertex = QVector3D(x, y, z);
        this->vertices.append(vertex);
    }

    for (uint32_t i = 0; i < numFaces; ++i) 
    {
        Face face;
        uint32_t vertexIndex = -1;
        do {
            face.vertexIndices.clear();
            for (int j = 0; j < 3; ++j)
            {
                do 
                    vertexIndex = randomGenerator.bounded(numVertices);
                while (face.vertexIndices.contains(vertexIndex));
                face.vertexIndices.append(vertexIndex);
            }
        } while (findFace(face));
        this->faces.append(face);
    }
}

bool Polyhedron::findFace(const Face& face) const 
{
    for (const Face& existingFace : faces) 
    {
        if (existingFace.vertexIndices.contains(face.vertexIndices[0]) &&
            existingFace.vertexIndices.contains(face.vertexIndices[1]) &&
            existingFace.vertexIndices.contains(face.vertexIndices[2]))

            return true;
    }
    return false; 
}