#ifndef CABLE_H
#define CABLE_H

#include "gancho.h"
#include "cilinder.h"

class _cable
{
private:
	_gancho gancho;			// CARGA, GANCHO
	_cilinder cilinder;		// CABLE
	// _cube cube;			// CUBO_PRUEBA

public:
	_cable();
	void draw(_draw_mode modo);
};

#endif // CABLE_H
