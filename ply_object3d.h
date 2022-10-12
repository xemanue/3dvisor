/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2020
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef PLY_OBJECT3D_H
#define PLY_OBJECT3D_H

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include "object3d.h"
#include "vertex.h"

class _ply_object:public _object3D
{
public:
	_ply_object(){};
	int open(const string &File_name);
	void read();
	void close();

private:
	void get_token(std::istringstream &Line_stream1, std::string &Token1);
	bool get_new_line(std::ifstream &File, std::istringstream &Line_stream);

	std::ifstream File;
};

#endif // PLY_OBJECT3D_H
