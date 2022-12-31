#ifndef GANCHO_H
#define GANCHO_H

#include "carga.h"
#include "sphere.h"

class _gancho
{
private:
	_carga carga;			// CARGA
	_sphere sphere;			// GANCHO
	// _cube cube;			// CUBO_PRUEBA

public:
	_gancho();
	void draw(_draw_mode modo);
};

#endif // GANCHO_H
