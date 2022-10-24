/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QFileDialog>
#include <QDialog>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QGuiApplication>
#include <QComboBox>
#include <QPushButton>
#include <QCheckBox>
#include <QFileDialog>
#include <QFileInfo>


class _gl_widget;


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

class _window : public QMainWindow
{
Q_OBJECT
public:
	_window();
	void toggled_point_mode(int state);
	void toggled_line_mode(int state);
	void toggled_fill_mode(int state);
	void toggled_chess_mode(int state);
	void changed_object(int index);

public slots:
	void point_mode_slot(int state);
	void line_mode_slot(int state);
	void fill_mode_slot(int state);
	void chess_mode_slot(int state);
	void object_changed_slot(int index);
	void unload_clicked();

private:
	_gl_widget *GL_widget;

	QComboBox *Combo_tab1;

	QLabel *Labelo_tab1;

	QPushButton *Boton_tab1;

	QCheckBox *Checkbox1_tab1;
	QCheckBox *Checkbox2_tab1;
	QCheckBox *Checkbox3_tab1;
	QCheckBox *Checkbox4_tab1;

};

#endif
