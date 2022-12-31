#include "carga.h"

_carga::_carga()
{}

void _carga::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);

	glPushMatrix();
	glScalef(1, 0.5, 1);
	cubo.draw(modo, 0.3137, 0.2549, 0.1765);
	glPopMatrix();
}