/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "object3d.h"

using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_line()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glBegin(GL_TRIANGLES);

	glColor3f(0.1, 0.1, 0.1);

	for (unsigned int i = 0; i < Triangles.size(); i++)
	{
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
	}

	glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_fill()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);

	glColor3f(1, 0.33, 0.33);

	for (unsigned int i = 0; i < Triangles.size(); i++)
	{
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
	}

	glEnd();
}


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

void _object3D::draw_chess()
{
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glBegin(GL_TRIANGLES);

	for (unsigned int i = 0; i < Triangles.size(); i++)
	{
		if (i%2 == 0)
			glColor3f(1, 0.33, 0.33);
		else
			glColor3f(0.33, 1, 0.33);

		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
		glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
	}

	glEnd();
}
