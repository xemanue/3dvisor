/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef OBJECT3D_H
#define OBJECT3D_H

#include "basic_object3d.h"

typedef enum {MODE_DRAW_POINT, MODE_DRAW_LINE, MODE_DRAW_FILL, MODE_DRAW_CHESS} _draw_mode;

/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _object3D:public _basic_object3D
{
	public:
	vector<_vertex3ui> Triangles;

	void draw(_draw_mode modo, float r = 1, float g = 0.33, float b = 0.33);
	void draw_line();
	void draw_fill(float r, float g, float b);
	void draw_chess();
};

#endif // OBJECT3D_H
