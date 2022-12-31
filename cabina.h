#ifndef CABINA_H
#define CABINA_H

#include "brazo.h"

class _cabina
{
private:
	_brazo brazo;		// CARGA, GANCHO, CABLE, BRAZO_HOR, BRAZO_VER
	_cube cube;			// CABINA, CUBO_PRUEBA

public:
	_cabina();
	void draw(_draw_mode modo);
};

#endif // CABINA_H
