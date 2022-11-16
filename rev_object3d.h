#ifndef REV_OBJECT3D_H
#define REV_OBJECT3D_H

#include "object3d.h"

class _rev_object:public _object3D
{
public:
	vector<_vertex3f> perfil;
	vector<_vertex3f> tapas;
	void generate(unsigned int n);
};

#endif // REV_OBJECT3D_H
