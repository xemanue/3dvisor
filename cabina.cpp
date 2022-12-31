#include "cabina.h"

_cabina::_cabina()
{}

void _cabina::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);

	// CARGA, GANCHO, CABLE, BRAZO_HOR, BRAZO_VER
	glPushMatrix();
	glTranslatef(0.75, -0.375, 0);		// Abajo mitad cabina - mitad brazo
										//				1.5			  0.75
	brazo.draw(modo);
	glPopMatrix();

	// CABINA
	glPushMatrix();
	glTranslatef(-1.5, 1.5, 0);			// Arriba mitad carga gancho cable brazo - mitad brazo
										//				 0.5   0.25  1.25  0.75			 0.75
	glScalef(1.5, 1.5, 1.7321);			// z = doble base triangulo en circulo de r 1
	cube.draw(modo, 1, 0.7529, 0);
	glPopMatrix();
	
	/* CUBO_PRUEBA
	glPushMatrix();
	glScalef(4.5, 4.5, 1.7321);
	cube.draw(modo);
	glPopMatrix();
	*/
}

