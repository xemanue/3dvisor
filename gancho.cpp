#include "gancho.h"

_gancho::_gancho()
{
	sphere.generate(9);
}

void _gancho::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);

	// CARGA
	glPushMatrix();
	glTranslatef(0, -0.125, 0);		// Abajo la mitad de lo que mide el gancho
									//								     0.25
	carga.draw(modo);
	glPopMatrix();

	// GANCHO
	glPushMatrix();
	glTranslatef(0, 0.25, 0);		// Arriba la mitad de lo que mide la carga
									//								     0.5
	glScalef(0.25, 0.25, 0.25);
	sphere.draw(modo, 0.5, 0.5, 0.5);
	glPopMatrix();
		
	/* CUBO_PRUEBA
	glPushMatrix();
	glScalef(1, 0.75, 1);
	cube.draw(modo);
	glPopMatrix();
	*/
}