#include "point.h"
#include "vector.h"
#include "closest.h"

#include <cstdio>
#include <cstdlib>

point triangle[3] = {
	{-0.5f, -0.5f, 0.0f },
	{ 0.0f,  0.5f, 0.0f },
	{ 0.5f, -0.5f, 0.0f }
};

point tetrahedron[4] = {
	{ 0.0f, 0.0f, 0.0f },
	{ 1.0f, 0.0f, 0.0f },
	{ 0.0f, 1.0f, 0.0f },
	{ 0.0f, 0.0f, 1.0f },
};

/* print closest point in triangle and tetrahedron to point (x, y, z) */

int main(int argc, char **argv)
{
	if (argc < 4) {
		printf("usage: %s x y z\n", argv[0]);
		return 0;
	}

	float x = std::atof(argv[1]);
	float y = std::atof(argv[2]);
	float z = std::atof(argv[3]);

	point a, b, c, d;
	vector v(x, y, z);

	a = triangle[0] - v;
	b = triangle[1] - v;
	c = triangle[2] - v;
	point p_tri = closest_point_triangle(a, b, c) + v;

	a = tetrahedron[0] - v;
	b = tetrahedron[1] - v;
	c = tetrahedron[2] - v;
	d = tetrahedron[3] - v;
	point p_tetra = closest_point_tetrahedron(a, b, c, d) + v;

	printf("closest point on triangle:    (% f, % f, % f), distance = %f\n",
			p_tri.x, p_tri.y, p_tri.z, norm(p_tri - v));
	printf("closest point on tetrahedron: (% f, % f, % f), distance = %f\n",
			p_tetra.x, p_tetra.y, p_tetra.z, norm(p_tetra - v));
	return 0;
}
