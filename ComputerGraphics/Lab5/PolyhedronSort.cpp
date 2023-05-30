#include "PolyhedronSort.h"

PolyhedronSort::PolyhedronSort(PolyhedronGeneratorSettings& settings)
{
	generatorSettings = settings;	
}

QScopedPointer<QVector<PolyhedronSort::Triangle>> PolyhedronSort::sortFacesByZ()
{
	return QScopedPointer<QVector<Triangle>>();
}

void PolyhedronSort::setGeneratorSettings(PolyhedronGeneratorSettings& settings)
{

}

PolyhedronSort::PolyhedronGeneratorSettings& PolyhedronSort::getGeneratorSettings()
{
	return generatorSettings;
}

void PolyhedronSort::generatePolyhedrons()
{
	for (int i = 0; i < generatorSettings.polyhedronCount; i++)
	{
		QScopedPointer<Polyhedron> polyhedron(new Polyhedron);
	}
}

