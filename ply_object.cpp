/*
* Prácticas de IG
* Copyright Domingo Martín Perandrés 2014-218
* dmartin@ugr.es
*
* GPL 3
*/

#include "ply_object3d.h"

using namespace std;

//******************************************************************************
//
//******************************************************************************

int _ply_object::open(const string &File_name)
{
	File.open(File_name.c_str(),ios::in);

	if (File.good())
	{
		read();
		return 1;
	}

	else
	{
		cout << "Error: the file " << File_name << " cannot be opened" << endl;
		return 0;
	}
}

//******************************************************************************
//
//******************************************************************************

void _ply_object::get_token(istringstream &Line_stream1, string &Token1)
{
	getline(Line_stream1, Token1, ' ');
}

//******************************************************************************
//
//******************************************************************************

bool _ply_object::get_new_line(ifstream &File, istringstream &Line_stream)
{
	string Line;

	if (getline(File, Line))
	{
		Line_stream.str(Line);
		Line_stream.seekg(0);
		return true;
	}

	else return false;
}


//******************************************************************************
//
//******************************************************************************

void _ply_object::read()
{
	string Token;
	istringstream Line_stream;

	setlocale(LC_ALL, "C");

	get_new_line(File, Line_stream);
	get_token(Line_stream, Token);

	if (Token == "ply")
	{
		get_new_line(File, Line_stream);
		get_token(Line_stream, Token);

		if (Token == "format")
		{
			get_token(Line_stream, Token);

			if (Token == "ascii")
			{
				do
				{
					get_new_line(File, Line_stream);
					get_token(Line_stream, Token);
				} while (Token != "element");

				get_token(Line_stream, Token);

				if (Token == "vertex")
				{
					get_token(Line_stream, Token);
					Vertices.resize(stoi(Token));

					do
					{
						get_new_line(File, Line_stream);
						get_token(Line_stream, Token);
					} while (Token != "element");

					get_token(Line_stream,Token);

					if (Token == "face")
					{
						get_token(Line_stream, Token);
						Triangles.resize(stoi(Token));

						do
						{
							get_new_line(File, Line_stream);
							get_token(Line_stream, Token);
						} while (Token != "end_header");

						for (unsigned int i = 0; i < Vertices.size(); i++)
						{
							get_new_line(File, Line_stream);

							get_token(Line_stream, Token);
							float x = stof(Token);
							get_token(Line_stream, Token);
							float y = stof(Token);
							get_token(Line_stream, Token);
							float z = stof(Token);

							Vertices[i] = _vertex3f(x, y, z);
						}

						for (unsigned int i = 0; i < Triangles.size(); i++)
						{
							get_new_line(File, Line_stream);
							get_token(Line_stream, Token);

							if (stoi(Token) == 3)
							{
								get_token(Line_stream, Token);
								unsigned int x = stoi(Token);
								get_token(Line_stream, Token);
								unsigned int y = stoi(Token);
								get_token(Line_stream, Token);
								unsigned int z = stoi(Token);

								Triangles[i] = _vertex3ui(x, y, z);
							}
						}
					}

					else
					{
						cerr << "Error: No face element found" << endl;
					}
				}

				else
				{
					cerr << "Error: No vertex element found" << endl;
				}
			}

			else
			{
				cerr << "Error: Only ascii format is allowed" << endl;
			}
		}

		else
		{
			cerr << "Error: No format found" << endl;
		}
	}

	else
	{
		cerr << "Error: The file is not a PLY file" << endl;
	}
}

//******************************************************************************
//
//******************************************************************************

void _ply_object::close()
{
	File.close();
}

