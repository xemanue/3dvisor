#include "grua.h"

_grua::_grua()
{
	cilinder.generate(27);
}

void _grua::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);
	
	// CARGA, GANCHO, CABLE, BRAZO_HOR, BRAZO_VER, CABINA
	glPushMatrix();
	glTranslatef(0, 0.125, 0);
	cabina.draw(modo);
	glPopMatrix();

	// BASE
	glPushMatrix();
	glTranslatef(-0.375, -2.25, 0);
	glScalef(2, 0.25, 2);
	cilinder.draw(modo, 1, 0.7529, 0);
	glPopMatrix();
	
	/* CUBO_PRUEBA
	glPushMatrix();
	glScalef(4.5, 4.75, 2);
	cube.draw(modo);
	glPopMatrix();
	*/
}