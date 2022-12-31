#include "cable.h"

_cable::_cable()
{
	cilinder.generate(9);
}

void _cable::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);
	
	// CARGA, GANCHO
	glPushMatrix();
	glTranslatef(0, -0.625, 0);		// Abajo la mitad de lo que mide el cable
									//								    1.25
	gancho.draw(modo);
	glPopMatrix();

	// CABLE
	glPushMatrix();
	glTranslatef(0, 0.375, 0);		// Arriba la mitad de lo que mide carga + gancho
									//								   0.5     0.25
	glScalef(0.1, 1.25, 0.1);
	cilinder.draw(modo, 0.749, 0.749, 0.749);
	glPopMatrix();
	
	/* CUBO_PRUEBA
	glPushMatrix();
	glScalef(1, 2, 1);
	cube.draw(modo);
	glPopMatrix();
	*/
}
