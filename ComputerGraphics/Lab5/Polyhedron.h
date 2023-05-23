#include <cstdint>


class Polyhedron
{
public:
	Polyhedron();
private:
	void random(uint32_t max_vertices, uint32_t max_faces, uint32_t min_vertices, uint32_t min_faces);
};