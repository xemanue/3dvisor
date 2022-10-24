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
	Tab_widget->setMaximumWidth(250);
	Tab_widget->addTab(Tab1, "Objeto");
	Tab_widget->addTab(Tab2, "Navegación");

	// Dropdown menu.
	Combo_tab1 = new QComboBox;
	connect(Combo_tab1, SIGNAL(currentIndexChanged(int)), this, SLOT(object_changed_slot(int)));
	Combo_tab1->addItem("Tetrahedro");
	Combo_tab1->addItem("Cubo");
	Combo_tab1->addItem("Cono");
	Combo_tab1->addItem("Cilindro");
	Combo_tab1->addItem("Esfera");
	Combo_tab1->addItem("Elegir...");

	// Label para el objeto cargado.
	Labelo_tab1 = new QLabel;
	Labelo_tab1->setText("Ningún objeto cargado.");
	Labelo_tab1->setStyleSheet(QStringLiteral("QLabel{color: #CC6666}"));

	// Boton para descargar objeto.
	Boton_tab1 = new QPushButton("Descargar objeto", this);
	connect(Boton_tab1, SIGNAL(clicked()), this, SLOT(unload_clicked()));
	Boton_tab1->setEnabled(false);

	// Checkbox.
	Checkbox1_tab1 = new QCheckBox;
	connect(Checkbox1_tab1, SIGNAL(stateChanged(int)), this, SLOT(point_mode_slot(int)));
	Checkbox2_tab1 = new QCheckBox;
	connect(Checkbox2_tab1, SIGNAL(stateChanged(int)), this, SLOT(line_mode_slot(int)));
	Checkbox3_tab1 = new QCheckBox;
	connect(Checkbox3_tab1, SIGNAL(stateChanged(int)), this, SLOT(fill_mode_slot(int)));
	Checkbox4_tab1 = new QCheckBox;
	connect(Checkbox4_tab1, SIGNAL(stateChanged(int)), this, SLOT(chess_mode_slot(int)));

	// Label points.
	QLabel *Labelp_tab1 = new QLabel;
	Labelp_tab1->setText("Puntos");

	// Label lines.
	QLabel *Labell_tab1 = new QLabel;
	Labell_tab1->setText("Lineas");

	// Label fill.
	QLabel *Labelf_tab1 = new QLabel;
	Labelf_tab1->setText("Relleno");

	// Label chess.
	QLabel *Labelc_tab1 = new QLabel;
	Labelc_tab1->setText("Ajedrez");

	// Layout horizontal.
	QHBoxLayout *Horizontal_frame = new QHBoxLayout;
	Horizontal_frame->setContentsMargins(1, 1, 1, 1);

	// Otro layout horizontal.
	QHBoxLayout *Horizontal_main = new QHBoxLayout(Central_widget);

	// Layouts para las pestañas.
	QGridLayout *Grid_tab1 = new QGridLayout;
	QGridLayout *Grid_tab2 = new QGridLayout;
	Grid_tab1->setAlignment(Qt::AlignTop | Qt::AlignTop);
	Grid_tab2->setAlignment(Qt::AlignTop | Qt::AlignTop);

	// Se añade el marco al layout.
	Horizontal_main->addWidget(Framed_widget);
	Horizontal_main->addWidget(Tab_widget);

	// Se añade el GL-widget al layout
	Horizontal_frame->addWidget(GL_widget);

	// Se le añaden el dropdown y las checkbox al layout.
	Grid_tab1->addWidget(Combo_tab1, 0, 0);
	Grid_tab1->addWidget(Labelo_tab1, 1, 0);
	Grid_tab1->addWidget(Boton_tab1, 2, 0);
	Grid_tab1->addWidget(Labelp_tab1, 3, 0);
	Grid_tab1->addWidget(Checkbox1_tab1, 3, 1);
	Grid_tab1->addWidget(Labell_tab1, 4, 0);
	Grid_tab1->addWidget(Checkbox2_tab1, 4, 1);
	Grid_tab1->addWidget(Labelf_tab1, 5, 0);
	Grid_tab1->addWidget(Checkbox3_tab1, 5, 1);
	Grid_tab1->addWidget(Labelc_tab1, 6, 0);
	Grid_tab1->addWidget(Checkbox4_tab1, 6, 1);

	// Se le asigna el layout al marco.
	Framed_widget->setLayout(Horizontal_frame);

	// Se asigna el layout al widget central.
	Central_widget->setLayout(Horizontal_main);

	// Se le asignan los layouts a las pestañas.
	Tab1->setLayout(Grid_tab1);
	Tab2->setLayout(Grid_tab2);

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

	resize(1050,800);

	for (auto widget : findChildren<QWidget*>())
		if (!qobject_cast<_gl_widget*>(widget)) widget->setFocusPolicy(Qt::NoFocus);
}

void _window::point_mode_slot(int state)
{
	GL_widget->toggle_point_mode(state);
}

void _window::line_mode_slot(int state)
{
	GL_widget->toggle_line_mode(state);
}

void _window::fill_mode_slot(int state)
{
	GL_widget->toggle_fill_mode(state);
}

void _window::chess_mode_slot(int state)
{
	GL_widget->toggle_chess_mode(state);
}

void _window::object_changed_slot(int index)
{
	if (index == 5)
	{
		QString archivo_path = QFileDialog::getOpenFileName(this, "Elige el archivo...", "./models", "*.ply");
		QFileInfo *info = new QFileInfo(archivo_path);
		QString archivo_name = info->fileName();

		Boton_tab1->setEnabled(true);

		Labelo_tab1->setText("Cargado " + archivo_name);
		Labelo_tab1->setStyleSheet(QStringLiteral("QLabel{color: #33CC66}"));

		GL_widget->change_object_to_ply(archivo_path);
	}

	else
	{
		GL_widget->change_object(index);
	}
}

void _window::unload_clicked()
{
	GL_widget->unload_ply();

	Boton_tab1->setEnabled(false);

	Labelo_tab1->setText("Ningún objeto cargado.");
	Labelo_tab1->setStyleSheet(QStringLiteral("QLabel{color: #CC6666}"));
}

void _window::toggled_point_mode(int state)
{
	Checkbox1_tab1->blockSignals(true);
	Checkbox1_tab1->setChecked(state);
	Checkbox1_tab1->blockSignals(false);
}

void _window::toggled_line_mode(int state)
{
	Checkbox2_tab1->blockSignals(true);
	Checkbox2_tab1->setChecked(state);
	Checkbox2_tab1->blockSignals(false);
}

void _window::toggled_fill_mode(int state)
{
	Checkbox3_tab1->blockSignals(true);
	Checkbox3_tab1->setChecked(state);
	Checkbox3_tab1->blockSignals(false);

	if (Checkbox4_tab1->isChecked() == true)
	{
		Checkbox4_tab1->blockSignals(true);
		Checkbox4_tab1->setChecked(!state);
		Checkbox4_tab1->blockSignals(false);
	}
}

void _window::toggled_chess_mode(int state)
{
	Checkbox4_tab1->blockSignals(true);
	Checkbox4_tab1->setChecked(state);
	Checkbox4_tab1->blockSignals(false);

	if (Checkbox3_tab1->isChecked() == true)
	{
		Checkbox3_tab1->blockSignals(true);
		Checkbox3_tab1->setChecked(!state);
		Checkbox3_tab1->blockSignals(false);
	}
}

void _window::changed_object(int index)
{
	Combo_tab1->blockSignals(true);
	Combo_tab1->setCurrentIndex(index);
	Combo_tab1->blockSignals(false);
}
