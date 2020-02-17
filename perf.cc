
#include "point.h"
#include "vector.h"
#include "closest.h"

#include <chrono>
#include <random>
#include <iostream>

using namespace std::chrono;

template <class unit = nanoseconds>
class timer {
  using clock = high_resolution_clock;

public:
  timer() : t_start(), t_stop() { start(); }

  void reset() { start(); }

  void start() { t_start = clock::now(); }

  double elapsed()
  {
    t_stop = clock::now();
    return duration_cast<unit>(t_stop - t_start).count();
  }

private:
  high_resolution_clock::time_point t_start, t_stop;
};

int main(int argc, char **argv)
{
	int N = atoi(argv[1]);

	std::default_random_engine g(1);
	std::uniform_real_distribution<float> dist(-10.0f, 10.0f);

	point *a, *b, *c, *d, *closest_tri, *closest_tetra;

	a = new point[N];
	b = new point[N];
	c = new point[N];
	d = new point[N];
	closest_tri   = new point[N];
	closest_tetra = new point[N];

	for (int i = 0; i < N; ++i) {
		a[i] = point(dist(g), dist(g), dist(g));
		b[i] = point(dist(g), dist(g), dist(g));
		c[i] = point(dist(g), dist(g), dist(g));
		d[i] = point(dist(g), dist(g), dist(g));
	}


	timer<> t;

	for (int i = 0; i < N; ++i)
		closest_tri[i] = closest_point_triangle(a[i], b[i], c[i]);

	std::cout << "t_tri   = " << t.elapsed() * 1.0e-6 << "ms\n";

	t.reset();

	for (int i = 0; i < N; ++i)
		closest_tetra[i] = closest_point_tetrahedron(a[i], b[i], c[i], d[i]);

	std::cout << "t_tetra = " << t.elapsed() * 1.0e-6 << "ms\n";

	std::cout << closest_tri[N-1][0] << "\n";
	std::cout << closest_tetra[N-1][0] << "\n";

	return 0;
}
