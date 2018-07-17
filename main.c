/*
 *      main.c
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

gint main ( gint argc, gchar * argv [] )
{
	gtk_init ( & argc, & argv ) ;
	g_set_application_name ( "Dominique media encoder" ) ;
	
	dominique_wizard () ;
	return ;
	
	GtkWidget * window = gtk_window_new ( GTK_WINDOW_TOPLEVEL ) ;
	gtk_window_set_type_hint ( window, GDK_WINDOW_TYPE_HINT_DIALOG ) ;
	GtkWidget * table = dominique_encode_video_new ( window ) ;
	
	gtk_container_add ( window, table ) ;
	gtk_widget_show_all ( window ) ;
	
	april_connect_default_signals ( window ) ;
	gtk_main () ;
}
