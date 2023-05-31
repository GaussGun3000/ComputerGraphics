#pragma once
#include <qsharedpointer.h>
#include <qvector.h>
#include "Polyhedron.h"
#include <qvector3d.h>
#include <qcolor.h>

class PolyhedronSort
{
public:
	struct PolyhedronGeneratorSettings
	{
		PolyhedronGeneratorSettings() :
			max_vertices(6), max_faces(6), min_vertices(5), min_faces(4), polyhedronCount(4) {}
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
		Triangle(QVector3D p1, QVector3D p2, QVector3D p3, QColor color): p1(p1), p2(p2), p3(p3), color(color){}
		QVector3D p1;
		QVector3D p2;
		QVector3D p3;
		QColor color;

		bool operator<(const Triangle& rhs) {
			float avgZ1 = (this->p1.z() + this->p2.z() + this->p3.z()) / 3.0f;
			float avgZ2 = (rhs.p1.z() + rhs.p2.z() + rhs.p3.z()) / 3.0f;
			return avgZ1 < avgZ2;
		}
	};

	PolyhedronSort();
	PolyhedronSort(PolyhedronGeneratorSettings& settings);
	QVector<Triangle> getFacesSortedByZ();
	void setGeneratorSettings(PolyhedronGeneratorSettings& settings);
	PolyhedronGeneratorSettings& getGeneratorSettings();
	bool isReady();


private:
	//fields
	QVector<QSharedPointer<Polyhedron>> polyhedronVector;
	PolyhedronGeneratorSettings generatorSettings;
	static const QVector<QColor> colorPool;

	//methods
	void generatePolyhedrons();

};