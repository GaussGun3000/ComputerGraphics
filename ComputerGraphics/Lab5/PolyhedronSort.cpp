#include "PolyhedronSort.h"

PolyhedronSort::PolyhedronSort(PolyhedronGeneratorSettings& settings)
{
	generatorSettings = settings;
	generatePolyhedrons();
}

QVector<PolyhedronSort::Triangle> PolyhedronSort::sortFacesByZ()
{
	for (const auto& polyhedron : polyhedronVector)
	{

	}
	return QVector<Triangle>();
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

void PolyhedronSort::generatePolyhedrons()
{
	for (int i = 0; i < generatorSettings.polyhedronCount; i++)
	{
		QScopedPointer<Polyhedron> polyhedron(new Polyhedron(generatorSettings.max_vertices,
															 generatorSettings.max_faces,
															 generatorSettings.min_vertices,
															 generatorSettings.min_faces));
		polyhedronVector.push_back(polyhedron);
	}
}

