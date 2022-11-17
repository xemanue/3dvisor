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

	for (unsigned int i = 0; i < res; i++)
	{
		float x = Size/2*cos(i*M_PI/res);
		float y = Size/2*sin(i*M_PI/res);
		float z = 0;

		perfil[k++] = _vertex3f(x, y, z);
	}

	k = 0;

	Vertices.resize(res);

	for (unsigned int i = 0; i < perfil.size(); i++)
	{
		Vertices[k++] = perfil[i];
	}
}
