#include "sphere.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_sphere::_sphere(float Size, unsigned int n_pts)
{
	// Puntos generatriz.
	perfil.resize(n_pts + 1);
	int k = 0;

	_vertex3f punto = {0, -Size/2, 0};

	for (unsigned int i = 0; i <= n_pts; i++)
	{
		float x = punto.x * cos(i*M_PI/n_pts) - punto.y * sin(i*M_PI/n_pts);
		float y = punto.x * sin(i*M_PI/n_pts) + punto.y * cos(i*M_PI/n_pts);
		float z = punto.z;

		perfil[k++] = _vertex3f(x, y, z);
	}
}
