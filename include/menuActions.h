#ifndef _MENUACTIONS_H_
#define _MENUACTIONS_H_

#include "gui.h"
#include "MicroInstruction.h"
#include "MicroProcessor.h"
#include <ctype.h>
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int built;
PangoFontDescription* font_desc;
void newFile(GtkWidget*, gpointer);
void openFile(GtkWidget*, gpointer);
void saveFile(GtkWidget*, gpointer);
void buildMenu(GtkWidget*, gpointer);
void runMenu(GtkWidget*, gpointer);
void singleStepMenu(GtkWidget*, gpointer);
void convertMenu(GtkWidget*, gpointer);
void aboutDialog(GtkWidget*, gpointer);

#endif
