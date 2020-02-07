# GSoC Project Exercise: GJK implementation for VecGeom

The exercise for this project consists in implementing two
small functions that will be needed for the implementation
of the GJK algorithm. I have created two isolated classes,
`point` and `vector`, a main program to help checking the
results, and a skeleton for the functions that you need to
implement. Please implement the body of the two functions,
`closest_point_triangle` and `closest_point_tetrahedron`.
These functions should return the closest point to the origin
given points A, B, and C for a triangle and A, B, C, and D,
for a tetrahedron. Feel free to implement helper functions
to make the code cleaner. My solution, which I will use to
check your implementation, uses two helper functions. The
file `main.cc` defines a simple test triangle and tetrahedron
that you can use to test your functions during development.
Please send your solution to us via email as soon as you are
ready. You can send a full tarball or just the `closest.cc`
file with your implementation.

Important: *do not fork this repository on GitHub* and *do
not send your solution as a pull request*.

Thank you very much, and good luck!
