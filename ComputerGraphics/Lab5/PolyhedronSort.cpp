#include "PolyhedronSort.h"


PolyhedronSort::PolyhedronSort()
{
}

PolyhedronSort::PolyhedronSort(PolyhedronGeneratorSettings& settings)
{
	generatorSettings = settings;
	generatePolyhedrons();
}

QVector<PolyhedronSort::Triangle> PolyhedronSort::getFacesSortedByZ()
{
	QVector<Triangle> faces;
	for (const auto& polyhedron : polyhedronVector)
	{
		auto polyhedronFaces = polyhedron->getFaces();
		auto polyhedronVertices = polyhedron->getVertices();
		for (const auto& face : polyhedronFaces)
		{
			Triangle triangle(polyhedronVertices.at(face.vertexIndices.at(0)),
						  polyhedronVertices.at(face.vertexIndices.at(1)),
						  polyhedronVertices.at(face.vertexIndices.at(2)));
			faces.append(triangle);
		}
	}
	std::sort(faces.begin(), faces.end());
	return faces;
}

void PolyhedronSort::setGeneratorSettings(PolyhedronGeneratorSettings& settings)
{
	generatorSettings = settings;
	generatePolyhedrons();
}

PolyhedronSort::PolyhedronGeneratorSettings& PolyhedronSort::getGeneratorSettings()
{
	return generatorSettings;
}

bool PolyhedronSort::isReady()
{
	return !polyhedronVector.isEmpty();
}

void PolyhedronSort::generatePolyhedrons()
{
	polyhedronVector.clear();
	for (int i = 0; i < generatorSettings.polyhedronCount; i++)
	{
		QSharedPointer<Polyhedron> polyhedron(new Polyhedron(generatorSettings.max_vertices,
															 generatorSettings.max_faces,
															 generatorSettings.min_vertices,
															 generatorSettings.min_faces));
		polyhedronVector.append(polyhedron);
	}
}

