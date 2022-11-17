#include "rev_object3d.h"
#include <math.h>


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _rev_object::generate(unsigned int n)
{
	// Se guardan los puntos de las tapas en un vector aparte

	unsigned int i = 0;

	while (i < perfil.size())
	{
		if (perfil[i]._0 == 0 && perfil[i]._2 == 0)
		{
			tapas.push_back(perfil[i]);
			perfil.erase(perfil.begin() + i);
		}

		else
		{
			i++;
		}
	}

	// Solo permitimos objetos con una o dos tapas

	if (tapas.size() > 2)
	{
		cerr << "ERROR: Los objetos con más de dos tapas no son compatibles." << endl;
		exit(1);
	}

	// Generamos los vertices por revolucion y añadimos los de las tapas al final

	Vertices.resize(n*perfil.size() + tapas.size());
	int k = 0;

	for (unsigned int i = 0; i < n; i++)
	{
		for (unsigned long j = 0; j < perfil.size(); j++)
		{
			float x = perfil[j].x * cos(i*2*M_PI/n) + perfil[j].z * sin(i*2*M_PI/n);
			float y = perfil[j].y;
			float z = -perfil[j].x * sin(i*2*M_PI/n) + perfil[j].z * cos(i*2*M_PI/n);

			Vertices[k++] = _vertex3f(x, y, z);
		}
	}

	for (unsigned int i = 0; i < tapas.size(); i++)
	{
		Vertices[k++] = tapas[i];
	}

	// Generamos los triangulos

	Triangles.resize(2*n*(perfil.size()-1) + n*tapas.size());
	k = 0;
	
	for (unsigned int j = 0; j < n; j++)
	{
		for (unsigned int i = 0; i < perfil.size() - 1; i++)
		{
			Triangles[k++] = _vertex3ui(i+perfil.size()*j, (i+perfil.size()*(j+1))%(n*perfil.size()), (i+j*perfil.size())+1);
			Triangles[k++] = _vertex3ui(i+perfil.size()*j+1, (i+perfil.size()*(j+1))%(n*perfil.size()), (i+perfil.size()*(j+1)+1)%(n*perfil.size()));
		}

		if (tapas.size() == 1)
		{
			Triangles[k++] = _vertex3ui(Vertices.size() - 1, ((j+1)*perfil.size())%(n*perfil.size()), j*perfil.size());
		}

		else if (tapas.size() == 2)
		{
			Triangles[k++] = _vertex3ui(Vertices.size() - 2, ((j+1)*perfil.size())%(n*perfil.size()), j*perfil.size());
			Triangles[k++] = _vertex3ui(Vertices.size() - 1, (j+1)*perfil.size()-1, ((j+2)*perfil.size()-1)%(n*perfil.size()));
		}
	}
}
