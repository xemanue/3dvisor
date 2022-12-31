#include "brazo.h"

_brazo::_brazo()
{
	cilinder.generate(3);
}

void _brazo::draw(_draw_mode modo)
{
	glMatrixMode(GL_MODELVIEW);

	// CARGA, GANCHO, CABLE
	glPushMatrix();
	glTranslatef(1, 0.125, 0);		// Abajo mitad brazo - mitad vacio = 0.0625
									//				 1           0.25
									// arriba mitad diferencia vertical + mitad brazo
	cable.draw(modo);
	glPopMatrix();

	// BRAZO_HOR
	glPushMatrix();
	glTranslatef(0, 1.375, 0);		// Arriba mitad carga gancho cable - mitad vacio = 1.3125
									//				 0.5   0.25  1.25		   0.25
									// arriba mitad diferencia vertical + mitad brazo
	glRotatef(90, 0, 0, 1);
	glScalef(1, 3, 1);
	cilinder.draw(modo, 1, 0.7529, 0);
	glPopMatrix();
	
	// BRAZO_VER
	glPushMatrix();
	glTranslatef(-1.25, -0.375, 0);		// Arriba mitad carga gancho cable - mitad vacio
											// 		   0.5  0.25  1.25			 0.25
											// abajo mitad brazo
	glScalef(1, 3, 1);
	cilinder.draw(modo, 1, 0.7529, 0);
	glPopMatrix();
	
	/* CUBO_PRUEBA_1
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glScalef(3, 2.75, 1);
	cube.draw(modo);
	glPopMatrix();
	*/
	
	/* CUBO_PRUEBA_2
	glPushMatrix();
	glScalef(3, 3.75, 1);
	cube.draw(modo);
	glPopMatrix();
	*/
}
