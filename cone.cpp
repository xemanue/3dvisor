#include "cone.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_cone::_cone(float Size)
{
	// Puntos generatriz.
	generators.resize(3);

	generators[0] = _vertex3f(0, -Size/2, 0);
	generators[1] = _vertex3f(Size/2, -Size/2, 0);
	generators[2] = _vertex3f(0, Size/2, 0);
}
