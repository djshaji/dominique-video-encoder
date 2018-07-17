/*
 *      extract.h
 *
 *      Copyright 2008 Shaji <djshaji@gmail.com>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */


#include <april/april.h>
#include "video.h"

GtkWidget * dominique_extractor_new ( GtkWidget * parent ) ;
void dominique_extractor_set_input_file ( GtkWidget * widget, shagpointer data ) ;
void dominique_extractor_set_output_file ( GtkWidget * widget, shagpointer data ) ;

typedef struct _DominiqueExtractorObject {
	GtkWidget * input ;
	GtkWidget * output ;
	GtkWidget * window ;
	GtkWidget * bar ;
	GtkWidget * encode ;
	GtkWidget * cancel ;
	GtkWidget * close ;
	GtkWidget * display ;
	GtkWidget * check1 ;
	GtkWidget * spin ;
	GtkWidget * check2 ;
} DominiqueExtractorObject ;

static DominiqueExtractorObject extractor_object ;
void dominique_extractor_extract ( void ) ;

void dominique_extractor_shew_result ( GtkWidget * window ) ;
void dominique_play_audio ( gchar * filename ) ;
void dominique_extractor_cancel ( void ) ;
gchar * dominique_extractor_get_modline ( void ) ;

static gboolean extractor_tip = true ;
void dominique_extractor_tip ( void ) ;
