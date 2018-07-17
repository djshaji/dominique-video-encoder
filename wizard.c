/*
 *      wizard.c
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

#include "wizard.h"

GtkWidget * dominique_wizard_new ( GtkWindow * parent )
{
	GtkWidget * vbox = gtk_vbox_new ( no, 5 ) ;
	GtkWidget * master = gtk_hbox_new ( no, 10 ) ;
	
	GtkImage * image = gtk_image_new_from_stock ( GTK_STOCK_MEDIA_PAUSE, GTK_ICON_SIZE_DIALOG ) ;
	GtkVBox * header = gtk_vbox_new ( no, 5 ) ;
	GtkLabel * lab = gtk_label_new ( null ) ;
	gtk_label_set_angle ( lab, 90.0 ) ;
	gtk_label_set_markup ( lab, "<span size=\"large\"><b>Dominique</b></span>" ) ;
	
	gtk_box_pack_start ( master, header, no, no, 5 ) ;
	gtk_box_pack_start ( header, image, no, no, 40 ) ;
	gtk_box_pack_start ( header, lab, no, no, 5 ) ;
	gtk_box_pack_start ( master, vbox, yes, no, 5 ) ;
	
	GtkLabel * label = gtk_label_new ( null ) ;
	gtk_label_set_markup ( label,
		"<span size=\"large\"><b>Welcome to the Dominique Wizard !</b></span>\n\n"
		"This wizard will help you convert your videos into another\n"
		"format, or split your videos into pictures, or take out\n"
		"sound from a video file.\n\n"
		"What do you want to do ?" ) ;
		
	gtk_box_pack_start ( vbox, label, no, no, 5 ) ;
	
	GtkFrame * frame = gtk_frame_new ( "Choose a task" ) ;
	gtk_box_pack_start ( vbox, frame, yes, no, 5 ) ;
	
	GtkVBox * vbox1 = gtk_vbox_new ( no, 2 ) ;
	gtk_container_add ( frame, vbox1 ) ;
	
	GSList * group = null ;
	GtkRadioButton * task1 = gtk_radio_button_new_with_label ( group, "Encode a video file" ) ;
	group = gtk_radio_button_get_group ( task1 ) ;
	GtkRadioButton * task2 = gtk_radio_button_new_with_label ( group, "Extract audio from video" ) ;
	group = gtk_radio_button_get_group ( task2 ) ;
	GtkRadioButton * task3 = gtk_radio_button_new_with_label ( group, "Split a video into pictures" ) ;
	group = gtk_radio_button_get_group ( task3 ) ;
	GtkRadioButton * task4 = gtk_radio_button_new_with_label ( group, "Cut a time-based portion of a video" ) ;
	group = gtk_radio_button_get_group ( task4 ) ;
	GtkRadioButton * task5 = gtk_radio_button_new_with_label ( group, "Encode audio to Ogg Vorbis" ) ;
	group = gtk_radio_button_get_group ( task4 ) ;
	
	gtk_box_pack_start ( vbox1, task1, no, no, 2 ) ;
	gtk_box_pack_start ( vbox1, task2, no, no, 2 ) ;
	gtk_box_pack_start ( vbox1, task3, no, no, 2 ) ;
	gtk_box_pack_start ( vbox1, task4, no, no, 2 ) ;
		
	GtkHSeparator * spacer2 = gtk_hseparator_new () ;
	gtk_box_pack_start ( vbox1, spacer2, no, no, 2 ) ;
	gtk_box_pack_start ( vbox1, task5, no, no, 2 ) ;
	
	GtkHSeparator * spacer1 = gtk_hseparator_new () ;
	gtk_box_pack_start ( vbox, spacer1, no, no, 5 ) ;
	
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_start ( vbox, hbox1, no, no, 5 ) ;
	
	/*
	GtkButton * yea = gtk_button_new () ;
	gtk_button_set_label ( yea, "Naach basanti !" ) ;
	gtk_button_set_image ( yea, gtk_image_new_from_stock ( GTK_STOCK_SORT_DESCENDING , GTK_ICON_SIZE_BUTTON )) ;
	g_signal_connect_swapped ( yea, "clicked", dominique_weee, parent ) ;
	
	*/
	
	
	GtkButton * next = gtk_button_new () ;
	gtk_button_set_label ( next, "Next" ) ;
	gtk_button_set_image ( next, gtk_image_new_from_stock ( GTK_STOCK_GO_FORWARD, GTK_ICON_SIZE_BUTTON )) ;
	gtk_box_pack_end ( hbox1, next, no, no, 5 ) ;
	
	GtkButton * back = gtk_button_new_from_stock ( GTK_STOCK_GO_BACK ) ;
	gtk_box_pack_end ( hbox1, back, no, no, 5 ) ;
	gtk_widget_set_sensitive ( back, false ) ;
	
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_CANCEL ) ;
	gtk_box_pack_start ( hbox1, cancel, no, no, 5 ) ;
	g_signal_connect_swapped ( cancel, "clicked", dominique_quit, parent ) ;
	//gtk_box_pack_start ( hbox1, yea, no, no, 5 ) ;

	wizard_object.back = back ;
	wizard_object.next = next ;
	wizard_object.window = parent ;
	wizard_object.radio1 = task1 ;
	wizard_object.radio2 = task2 ;
	wizard_object.radio3 = task3 ;
	wizard_object.radio4 = task4 ;
	wizard_object.radio5 = task5 ;
	
	g_signal_connect ( next, "clicked", gtk_main_quit, null ) ;
	
	gtk_widget_show_all ( master ) ;
	return master ;
}

void dominique_wizard ( void )
{
	GtkWindow * window = gtk_window_new ( GTK_WINDOW_TOPLEVEL ) ;
	GtkWidget * task = dominique_wizard_new ( window ) ;
	
	gtk_window_set_type_hint ( window, GDK_WINDOW_TYPE_HINT_DIALOG ) ;
	gtk_container_add ( window, task ) ;
	
	april_connect_default_signals ( window ) ;
	gtk_widget_show_all ( window ) ;
	
	gtk_main () ;
	
	if ( ! GTK_IS_WINDOW ( window ))
		return ;

	if ( gtk_toggle_button_get_active ( wizard_object.radio1 ))
	{
		gtk_widget_destroy ( task ) ;
		
		task = dominique_encode_video_new ( window ) ;
		gtk_container_add ( window, task ) ;
	}
	else if ( gtk_toggle_button_get_active ( wizard_object.radio2 ))
	{
		gtk_widget_destroy ( task ) ;
		
		task = dominique_extractor_new ( window ) ;
		gtk_container_add ( window, task ) ;
	}
	else if ( gtk_toggle_button_get_active ( wizard_object.radio3 ))
	{
		gtk_widget_destroy ( task ) ;
		
		task = dominique_mtp_new ( window ) ;
		gtk_container_add ( window, task ) ;
	}
	else if ( gtk_toggle_button_get_active ( wizard_object.radio4 ))
	{
		gtk_widget_destroy ( task ) ;
		
		task = dominique_capo_new ( window ) ;
		gtk_container_add ( window, task ) ;
	}
	else if ( gtk_toggle_button_get_active ( wizard_object.radio5 ))
	{
		gtk_widget_destroy ( task ) ;
		
		task = dominique_vorbis_new ( window ) ;
		gtk_container_add ( window, task ) ;
	}
			
	gtk_widget_show_all ( window ) ;
	gtk_main () ;
}
	
void dominique_weee ( GtkWindow * window )
{
	static gint counter = 0 ;
	counter ++ ;
	
	if ( counter == 3 )
	{
		april_message_box_info ( 	"Abe ab kitna nachayga ? Ab basanti ki\n"
									"woh umar nahi rahi. Jodon mein dard\n"
									"shuru ho gaya hai." ) ;
		return ;
	}
	
	gint x = 0, x2 = 0, y = 0, y2 = 0, x3 = 0, y3 = 0 ;
	gtk_window_get_position ( window, & x, & y ) ;
	
	gint i = 0;
	for ( i = x ; i < x + 100 ; i = i + 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		g_usleep ( 100 ) ;
	}
	
	x2 = i ;
	
	for ( i = x2 ; i > x - 100 ; i = i - 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		//g_usleep ( 100 ) ;
	}
	
	for ( i = x - 100 ; i < x + 75 ; i = i + 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		g_usleep ( 100 ) ;
	}
	
	x2 = i ;
	
	for ( i = x + 75 ; i > x - 75 ; i = i - 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		//g_usleep ( 100 ) ;
	}

	for ( i = x - 75 ; i < x + 50 ; i = i + 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		g_usleep ( 100 ) ;
	}
	
	x2 = i ;
	
	for ( i = x + 50 ; i > x - 25 ; i = i - 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		//g_usleep ( 100 ) ;
	}

	for ( i = x - 25 ; i < x ; i = i + 5 )
	{
		gtk_window_move ( window, i, y ) ;
		april_update_gui () ;
		
		g_usleep ( 100 ) ;
	}
	
	gtk_window_move ( window, x, y ) ;
	april_update_gui () ;

	return ;
}
