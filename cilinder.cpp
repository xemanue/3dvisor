#include "cilinder.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cilinder::_cilinder(float Size)
{
	// Puntos generatriz.
	perfil.resize(4);

	perfil[0] = _vertex3f(0, -Size/2, 0);
	perfil[1] = _vertex3f(Size/2, -Size/2, 0);
	perfil[2] = _vertex3f(Size/2, Size/2, 0);
	perfil[3] = _vertex3f(0, Size/2, 0);
}
