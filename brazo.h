#ifndef BRAZO_H
#define BRAZO_H

#include "cable.h"

class _brazo
{
private:
	_cable cable;			// CARGA, GANCHO, CABLE
	_cilinder cilinder;		// BRAZO_HOR, BRAZO_VER
	// _cube cube;			// CUBO_PRUEBA_1, CUBO_PRUEBA_2

public:
	_brazo();
	void draw(_draw_mode modo);
};

#endif // BRAZO_H
