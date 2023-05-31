#include "PolyhedronSort.h"


const QVector<QColor> PolyhedronSort::colorPool = 
{
	QColor(Qt::red),
	QColor(Qt::green),
	QColor(Qt::blue),
	QColor(Qt::cyan),
	QColor(Qt::magenta),
	QColor(Qt::yellow),
	QColor("darkorange"),
	QColor("teal"),
	QColor("purple")
};

PolyhedronSort::PolyhedronSort(): generatorSettings(PolyhedronGeneratorSettings())
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
	const uint32_t numColors = colorPool.size();
	int i = 0;
	for (const auto& polyhedron : polyhedronVector)
	{
		uint32_t colorIndex = i % numColors;
		auto polyhedronFaces = polyhedron->getFaces();
		auto polyhedronVertices = polyhedron->getVertices();
		for (const auto& face : polyhedronFaces)
		{
			Triangle triangle(polyhedronVertices.at(face.vertexIndices.at(0)),
							  polyhedronVertices.at(face.vertexIndices.at(1)),
							  polyhedronVertices.at(face.vertexIndices.at(2)),
							  colorPool.at(colorIndex));
			faces.append(triangle);
		}
		i++;
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


