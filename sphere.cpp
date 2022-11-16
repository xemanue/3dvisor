#include "sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(float Size, unsigned int res)
{
	// Puntos generatriz.
	perfil.resize(res);
	int k = 0;

	for (float i = 0; i < M_PI; i += M_PI/res)
	{
		float x = Size/2*cos(i) * cos(i) - Size/2*sin(i) * sin(i);
		float y = Size/2*cos(i) * sin(i) + Size/2*sin(i) * cos(i);
		float z = 0;

		perfil[k++] = _vertex3f(x, y, z);
	}
}
