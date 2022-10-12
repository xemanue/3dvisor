/*! \file
 * Copyright Domingo Martín Perandres
 * email: dmartin@ugr.es
 * web: http://calipso.ugr.es/dmartin
 * 2003-2019
 * GPL 3
 */


#include <QApplication>
#include <QAction>
#include <QMenuBar>
#include <QFrame>
#include <QComboBox>
#include <QCheckBox>
#include <QLabel>

#include "window.h"
#include "glwidget.h"


/*****************************************************************************//**
 *
 *
 *
 *****************************************************************************/

_window::_window()
{
	QSizePolicy Q(QSizePolicy::Expanding,QSizePolicy::Expanding);

	// Widget central.
	QWidget *Central_widget = new QWidget(this);

	// Marco.
	QFrame *Framed_widget= new QFrame(Central_widget);
	Framed_widget->setSizePolicy(Q);
	Framed_widget->setFrameStyle(QFrame::Panel);
	Framed_widget->setLineWidth(3);

	// Widget OpenGL.
	GL_widget = new _gl_widget(this);
	GL_widget->setSizePolicy(Q);

	// Pestañas.
	QWidget *Tab1 = new QWidget;
	QWidget *Tab2 = new QWidget;

	// Widget de pestañas.
	QTabWidget *Tab_widget = new QTabWidget;
	Tab_widget->setMaximumWidth(200);
	Tab_widget->addTab(Tab1, "Objeto");
	Tab_widget->addTab(Tab2, "Navegación");

	// Dropdown menu.
	QComboBox *Combo_tab1 = new QComboBox;
	Combo_tab1->addItem("Tetrahedro");
	Combo_tab1->addItem("Cubo");
	Combo_tab1->addItem("Cono");
	Combo_tab1->addItem("Cilindro");
	Combo_tab1->addItem("Esfera");
	Combo_tab1->addItem("Elegir...");

	// Checkbox.
	QCheckBox *Checkbox1_tab1 = new QCheckBox;
	QCheckBox *Checkbox2_tab1 = new QCheckBox;
	QCheckBox *Checkbox3_tab1 = new QCheckBox;
	QCheckBox *Checkbox4_tab1 = new QCheckBox;

	// Label para el objeto cargado.
	QLabel *Labelo_tab1 = new QLabel;
	Labelo_tab1->setText("Ningún objeto cargado.");
	Labelo_tab1->setStyleSheet(QStringLiteral("QLabel{color: #CC6666}"));

	// Layout horizontal.
	QHBoxLayout *Horizontal_frame = new QHBoxLayout;
	Horizontal_frame->setContentsMargins(1, 1, 1, 1);

	// Otro layout horizontal.
	QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

	// Layouts para las pestañas.
	QVBoxLayout *Vertical_tab1 = new QVBoxLayout;
	QVBoxLayout *Vertical_tab2 = new QVBoxLayout;
	Vertical_tab1->setAlignment(Qt::AlignTop);
	Vertical_tab2->setAlignment(Qt::AlignTop);

	// Se añade el marco al layout.
	Horizontal_main->addWidget(Framed_widget);
	Horizontal_main->addWidget(Tab_widget);

	// Se añade el GL-widget al layout
	Horizontal_frame->addWidget(GL_widget);

	// Se le añaden el dropdown y las checkbox al layout.
	Vertical_tab1->addWidget(Combo_tab1);
	Vertical_tab1->addWidget(Labelo_tab1);
	Vertical_tab1->addWidget(Checkbox1_tab1);
	Vertical_tab1->addWidget(Checkbox2_tab1);
	Vertical_tab1->addWidget(Checkbox3_tab1);
	Vertical_tab1->addWidget(Checkbox4_tab1);

	// Se le asigna el layout al marco.
	Framed_widget->setLayout(Horizontal_frame);

	// Se asigna el layout al widget central.
	Central_widget->setLayout(Horizontal_main);

	// Se le asignan los layouts a las pestañas.
	Tab1->setLayout(Vertical_tab1);
	Tab2->setLayout(Vertical_tab2);

	// Se establece el widget como principal.
	setCentralWidget(Central_widget);

	// Acciones para el menu "Archivo".
	QAction *Exit = new QAction(QIcon("./icons/exit.png"), tr("&Exit..."), this);
	Exit->setShortcut(tr("Ctrl+Q"));
	Exit->setToolTip(tr("Exit the application"));
	connect(Exit, SIGNAL(triggered()), this, SLOT(close()));

	// Barra de menus.
	QMenu *File_menu = menuBar()->addMenu(tr("&File"));
	File_menu->addAction(Exit);
	File_menu->setAttribute(Qt::WA_AlwaysShowToolTips);

	setWindowTitle(tr("Práctica 1"));

	resize(1000,800);

	for (auto widget : findChildren<QWidget*>())
		if (!qobject_cast<_gl_widget*>(widget)) widget->setFocusPolicy(Qt::NoFocus);
}
