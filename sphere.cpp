#include "sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(float Size, unsigned int res)
{
	// Puntos generatriz.
	generators.resize(res);
	int k = 0;

	for (float i = 0; i < M_PI; i += M_PI/res)
	{
		float x = Size*cos(i) * cos(i) - Size*sin(i) * sin(i);
		float y = Size*cos(i) * sin(i) + Size*sin(i) * cos(i);
		float z = 0;

		generators[k++] = _vertex3f(x, y, z);
	}
}
