/*
 *      vorbis.h
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
#include "extract.h"

GtkWidget * dominique_vorbis_new ( GtkWidget * parent ) ;

typedef struct _DominiqueVorbisObject {
	GtkWidget * input ;
	GtkWidget * output ;
	GtkWidget * window ;
	GtkWidget * bar ;
	GtkWidget * encode ;
	GtkWidget * cancel ;
	GtkWidget * close ;
	GtkWidget * display ;
	GtkWidget * spin1 ;
	GtkWidget * spin2 ;
	GtkWidget * radio1 ;
	GtkWidget * radio2 ;
} DominiqueVorbisObject ;

DominiqueVorbisObject vorbis_object ;

void dominique_vorbis_set_input_file ( GtkWidget * widget, shagpointer data ) ;
void dominique_vorbis_set_output_file ( GtkWidget * widget, shagpointer data ) ;
void dominique_vorbis_encode ( void ) ;

gboolean dominique_vorbis_encode_file ( gchar * command ) ;
gchar * dominique_vorbis_get_modline ( const gchar * message ) ;
gdouble dominique_vorbis_get_progress ( gchar * message ) ;
void dominique_vorbis_shew_result ( GtkWidget * window ) ;
void dominique_vorbis_cancel ( void ) ;
void dominique_vorbis_select_mode ( GtkWidget * widget, shagpointer data ) ;
