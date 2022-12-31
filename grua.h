#ifndef GRUA_H
#define GRUA_H

#include "cabina.h"

class _grua
{
private:
	_cabina cabina;			// CARGA, GANCHO, CABLE, BRAZO_HOR, BRAZO_VER, CABINA
	_cilinder cilinder;		// BASE
	// _cube cube;			// CUBO_PRUEBA

public:
	_grua();
	void draw(_draw_mode modo);
};

#endif // GRUA_H
