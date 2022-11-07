#include "rev_object3d.h"
#include <math.h>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _rev_object::generate(unsigned int n)
{
	Vertices.resize(n*generators.size());
	int k = 0;

	for (float i = 0; i < 2*M_PI; i += 2*M_PI/n)
	{
		for (unsigned long j = 0; j < generators.size(); j++)
		{
			float x = generators[j].x * cos(i) + generators[j].z * sin(i);
			float y = generators[j].y;
			float z = -generators[j].x * sin(i) + generators[j].z * cos(i);

			Vertices[k++] = _vertex3f(x, y, z);
		}
	}
	
	Triangles.resize((n*(generators.size()-1))*2);
	k = 0;
	
	for (unsigned int j = 0; j < n; j++)
	{
		for (unsigned int i = 0; i < generators.size() - 1; i++)
		{
			Triangles[k++] = _vertex3ui((i+j*n), (n+i+j*n)%n*generators.size(), (1+i+j*n));
			Triangles[k++] = _vertex3ui((1+i+j*n), (n+i+j*n)%n*generators.size(), (n+1+i+j*n)%n*generators.size());
		}
	}
}
