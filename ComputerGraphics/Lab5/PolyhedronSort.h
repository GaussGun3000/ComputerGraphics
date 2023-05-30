#pragma once
#include <qscopedpointer.h>
#include <qvector.h>
#include "Polyhedron.h"

class PolyhedronSort
{
public:
	struct PolyhedronGeneratorSettings
	{
		PolyhedronGeneratorSettings() :
			max_vertices(6), max_faces(6), min_vertices(5), min_faces(5), polyhedronCount(3) {}
		PolyhedronGeneratorSettings(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces, uint32_t count): 
			max_vertices(max_vertices), max_faces(max_faces), min_vertices(min_vertices), min_faces(min_faces), polyhedronCount(count) {}

		uint32_t polyhedronCount;
		uint32_t max_vertices;
		uint32_t max_faces;
		uint32_t min_vertices;
		uint32_t min_faces;
	};
	struct Triangle
	{
		QVector3D p1;
		QVector3D p2;
		QVector3D p3;
	};

	PolyhedronSort(PolyhedronGeneratorSettings& settings);
	QScopedPointer<QVector<Triangle>> sortFacesByZ();
	void setGeneratorSettings(PolyhedronGeneratorSettings& settings);
	PolyhedronGeneratorSettings& getGeneratorSettings();


private:
	//fields
	QVector<QScopedPointer<Polyhedron>> polyhedrons;
	PolyhedronGeneratorSettings generatorSettings;
	//methods
	void generatePolyhedrons();

};