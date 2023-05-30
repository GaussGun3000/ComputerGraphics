#include <cstdint>
#include <qvector.h>
#include <qvector3d.h>


class Polyhedron
{
public:
	static QVector3D border;
	struct Face
	{
		QVector<uint32_t> vertexIndices;
	};
	Polyhedron();
	QVector<QVector3D>& getVertices();
	QVector<Face>& getFaces();

private:
	//methods
	void random(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces);

	bool findFace(const Face& face) const;

	//fields
	QVector<QVector3D> vertices;
	QVector<Face> faces;
};