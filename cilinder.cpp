#include "cilinder.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cilinder::_cilinder(float Size)
{
	// Puntos generatriz.
	generators.resize(4);

	generators[0] = _vertex3f(0, -Size/2, 0);
	generators[1] = _vertex3f(Size/2, -Size/2, 0);
	generators[2] = _vertex3f(Size/2, Size/2, 0);
	generators[3] = _vertex3f(0, Size/2, 0);
}
