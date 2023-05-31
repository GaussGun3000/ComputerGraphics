#pragma once
#include <qvector.h>
#include <qvector3d.h>
#include <qrandom.h>


class Polyhedron
{
public:
	static const QVector3D border;
	struct Face
	{
		QVector<uint32_t> vertexIndices;
	};
	Polyhedron();
	Polyhedron(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces);
	QVector<QVector3D>& getVertices();
	QVector<Face>& getFaces();

private:
	//methods
	void random(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces);

	bool findFace(const Face& face) const;

	//fields
	static QRandomGenerator randomGenerator;
	QVector<QVector3D> vertices;
	QVector<Face> faces;
};