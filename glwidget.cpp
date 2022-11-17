/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include "glwidget.h"
#include "window.h"

using namespace std;
using namespace _gl_widget_ne;
using namespace _colors_ne;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_gl_widget::_gl_widget(_window *Window1):Window(Window1)
{
	setMinimumSize(300, 300);
	setFocusPolicy(Qt::StrongFocus);
}


/*****************************************************************************//**
 * Evento tecla pulsada
 *
 *
 *
 *****************************************************************************/

void _gl_widget::keyPressEvent(QKeyEvent *Keyevent)
{
	switch (Keyevent->key())
	{
	case Qt::Key_1: Object = OBJECT_TETRAHEDRON; Window->changed_object(0); break;
	case Qt::Key_2: Object = OBJECT_CUBE; Window->changed_object(1); break;
	case Qt::Key_3: Object = OBJECT_CONE; Window->changed_object(2); break;
	case Qt::Key_4: Object = OBJECT_CILINDER; Window->changed_object(3); break;
	case Qt::Key_5: Object = OBJECT_SPHERE; Window->changed_object(4); break;
	case Qt::Key_6: Object = OBJECT_PLY; break;

	case Qt::Key_P: toggle_point_mode(Draw_point ? Qt::Checked : Qt::Unchecked); Window->toggled_point_mode(Draw_point); break;
	case Qt::Key_L: toggle_line_mode(Draw_line ? Qt::Checked : Qt::Unchecked); Window->toggled_line_mode(Draw_line); break;
	case Qt::Key_F: toggle_fill_mode(Draw_fill ? Qt::Checked : Qt::Unchecked); Window->toggled_fill_mode(Draw_fill); break;
	case Qt::Key_C: toggle_chess_mode(Draw_chess ? Qt::Checked : Qt::Unchecked); Window->toggled_chess_mode(Draw_chess); break;

	case Qt::Key_Left: Observer_angle_y -= ANGLE_STEP; break;
	case Qt::Key_Right: Observer_angle_y += ANGLE_STEP; break;
	case Qt::Key_Up: Observer_angle_x -= ANGLE_STEP; break;
	case Qt::Key_Down: Observer_angle_x += ANGLE_STEP; break;
	case Qt::Key_PageUp: Observer_distance *= 1.2; break;
	case Qt::Key_PageDown: Observer_distance /= 1.2; break;
	}

	update();
}


/*****************************************************************************//**
 * Limpiar ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::clear_window()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de proyeccion
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_projection()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// formato(x_minimo, x_maximo, y_minimo, y_maximo, Front_plane, Back_plane)
	// Front_plane > 0 && Back_plane > PlanoDelantero
	glFrustum(X_MIN, X_MAX, Y_MIN, Y_MAX, FRONT_PLANE_PERSPECTIVE, BACK_PLANE_PERSPECTIVE);
}



/*****************************************************************************//**
 * Funcion para definir la transformación de vista (posicionar la camara)
 *
 *
 *
 *****************************************************************************/

void _gl_widget::change_observer()
{
	// posicion del observador
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -Observer_distance);
	glRotatef(Observer_angle_x, 1, 0, 0);
	glRotatef(Observer_angle_y, 0, 1, 0);
}


/*****************************************************************************//**
 * Funcion que dibuja los objetos
 *
 *
 *
 *****************************************************************************/

void _gl_widget::draw_objects()
{
	Axis.draw_line();

	if (Draw_point)
	{
		glPointSize(5);
		glColor3fv((GLfloat *) &BLACK);

		switch (Object)
		{
		case OBJECT_TETRAHEDRON: Tetrahedron.draw_point(); break;
		case OBJECT_CUBE: Cube.draw_point(); break;
		case OBJECT_CONE: Cone.draw_point(); break;
		case OBJECT_CILINDER: Cilinder.draw_point(); break;
		case OBJECT_SPHERE: Sphere.draw_point(); break;
		case OBJECT_PLY: Ply.draw_point(); break;
		default: break;
		}
	}

	if (Draw_line)
	{
		glLineWidth(3);
		glColor3fv((GLfloat *)&MAGENTA);

		switch (Object)
		{
		case OBJECT_TETRAHEDRON: Tetrahedron.draw_line(); break;
		case OBJECT_CUBE: Cube.draw_line(); break;
		case OBJECT_CONE: Cone.draw_line(); break;
		case OBJECT_CILINDER: Cilinder.draw_line(); break;
		case OBJECT_SPHERE: Sphere.draw_line(); break;
		case OBJECT_PLY: Ply.draw_line(); break;
		default: break;
		}
	}

	if (Draw_fill)
	{
		glColor3fv((GLfloat *)&BLUE);

		switch (Object)
		{
		case OBJECT_TETRAHEDRON: Tetrahedron.draw_fill(); break;
		case OBJECT_CUBE: Cube.draw_fill(); break;
		case OBJECT_CONE: Cone.draw_fill(); break;
		case OBJECT_CILINDER: Cilinder.draw_fill(); break;
		case OBJECT_SPHERE: Sphere.draw_fill(); break;
		case OBJECT_PLY: Ply.draw_fill(); break;
		default: break;
		}
	}

	if (Draw_chess)
	{
		switch (Object)
		{
		case OBJECT_TETRAHEDRON: Tetrahedron.draw_chess(); break;
		case OBJECT_CUBE: Cube.draw_chess(); break;
		case OBJECT_CONE: Cone.draw_chess(); break;
		case OBJECT_CILINDER: Cilinder.draw_chess(); break;
		case OBJECT_SPHERE: Sphere.draw_chess(); break;
		case OBJECT_PLY: Ply.draw_chess(); break;
		default: break;
		}
	}
}



/*****************************************************************************//**
 * Evento de dibujado
 *
 *
 *
 *****************************************************************************/

void _gl_widget::paintGL()
{
	clear_window();
	change_projection();
	change_observer();
	draw_objects();
}


/*****************************************************************************//**
 * Evento de cambio de tamaño de la ventana
 *
 *
 *
 *****************************************************************************/

void _gl_widget::resizeGL(int Width1, int Height1)
{
	glViewport(0, 0, Width1, Height1);
}


/*****************************************************************************//**
 * Inicialización de OpenGL
 *
 *
 *
 *****************************************************************************/

void _gl_widget::initializeGL()
{
	const GLubyte *strm;

	strm = glGetString(GL_VENDOR);
	std::cerr << "Vendor: " << strm << "\n";

	strm = glGetString(GL_RENDERER);
	std::cerr << "Renderer: " << strm << "\n";

	strm = glGetString(GL_VERSION);
	std::cerr << "OpenGL Version: " << strm << "\n";

	if (strm[0] == '1')
	{
		std::cerr << "Only OpenGL 1.X supported!\n";
		exit(-1);
	}

	strm = glGetString(GL_SHADING_LANGUAGE_VERSION);
	std::cerr << "GLSL Version: " << strm << "\n";

	int Max_texture_size = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &Max_texture_size);
	std::cerr << "Max texture size: " << Max_texture_size << "\n";

	//------------------------------------------------------------------
	// Inicializacion de objetos

	Cone.generate(n_rev);
	Cilinder.generate(n_rev);
	Sphere.generate(n_rev);

	//------------------------------------------------------------------

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);

	Observer_angle_x = 0;
	Observer_angle_y = 0;
	Observer_distance = DEFAULT_DISTANCE;

	Draw_point = false;
	Draw_line = false;
	Draw_fill = false;
	Draw_chess = false;
}

void _gl_widget::toggle_point_mode(int state)
{
	Draw_point = !Draw_point;
	Window->toggled_point_mode(state);

	update();
}

void _gl_widget::toggle_line_mode(int state)
{
	Draw_line = !Draw_line;
	Window->toggled_line_mode(state);

	update();
}

void _gl_widget::toggle_fill_mode(int state)
{
	Draw_fill = !Draw_fill;
	Window->toggled_fill_mode(state);

	if (Draw_chess)
	{
		Draw_chess = !Draw_chess;
		Window->toggled_chess_mode(Draw_chess);
	}

	update();
}

void _gl_widget::toggle_chess_mode(int state)
{
	Draw_chess = !Draw_chess;
	Window->toggled_chess_mode(state);

	if (Draw_fill)
	{
		Draw_fill = !Draw_fill;
		Window->toggled_fill_mode(Draw_fill);
	}

	update();
}

void _gl_widget::change_object(int index)
{
	switch(index)
	{
	case 0: Object = OBJECT_TETRAHEDRON; break;
	case 1: Object = OBJECT_CUBE; break;
	case 2: Object = OBJECT_CONE; break;
	case 3: Object = OBJECT_CILINDER; break;
	case 4: Object = OBJECT_SPHERE; break;
	}

	draw_objects();
}

void _gl_widget::change_object_to_ply(QString archivo)
{
	Object = OBJECT_PLY;

	if (file_loaded)
	{
		Ply.close();
	}

	Ply.open(archivo.toStdString());
	file_loaded = true;

	draw_objects();
}

void _gl_widget::unload_ply()
{
	Ply.close();
}
