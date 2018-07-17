/*
 *      vorbis.c
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

#include "vorbis.h"

GtkWidget * dominique_vorbis_new ( GtkWidget * parent )
{
	GtkWidget * vbox = gtk_vbox_new ( no, 5 ) ;
	GtkWidget * master = gtk_hbox_new ( yes, 10 ) ;
	
	gtk_box_pack_start ( master, vbox, yes, no, 5 ) ;
	
	GtkFrame * frame69 = gtk_frame_new ( "Choose input and output files" ) ;
	GtkTable * table69 = gtk_vbox_new ( no, 5 ) ;
	
	gtk_container_add ( frame69, table69 ) ;
	gtk_box_pack_start ( vbox, frame69, no, no, 10 ) ;
	
	GtkLabel * label69 = gtk_label_new ( "Choose input audio file ..." ) ;
	GtkLabel * label70 = gtk_label_new ( "Choose output audio file ..." ) ;
	
	gtk_label_set_line_wrap ( label69, true ) ;
	gtk_label_set_line_wrap ( label70, true ) ;

	GtkEntry * entry1 = gtk_entry_new () ;
	GtkEntry * entry2 = gtk_entry_new () ;
	
	GtkButton * open = gtk_button_new () ;
	GtkButton * save = gtk_button_new () ;
	
	gtk_button_set_label ( open, "Browse" ) ;
	gtk_button_set_label ( save, "Browse" ) ;
	
	gtk_button_set_image ( open, gtk_image_new_from_stock ( GTK_STOCK_DIRECTORY, GTK_ICON_SIZE_BUTTON )) ;
	gtk_button_set_image ( save, gtk_image_new_from_stock ( GTK_STOCK_DIRECTORY, GTK_ICON_SIZE_BUTTON )) ;
	
	g_signal_connect ( open, "clicked", dominique_vorbis_set_input_file, entry1 ) ;
	g_signal_connect ( save, "clicked", dominique_vorbis_set_output_file, entry2 ) ;
	
	gtk_box_pack_start ( table69, label69, no, no, 5 ) ;
	GtkHBox * hbox72 = gtk_hbox_new ( no, 5 ),
			* hbox73 = gtk_hbox_new ( no, 5 ) ;
	
	gtk_box_pack_start ( hbox72, entry1, yes, yes, 5 ) ;
	gtk_box_pack_start ( hbox72, open, no, no, 5 ) ;
	
	gtk_box_pack_start ( hbox73, entry2, yes, yes, 5 ) ;
	gtk_box_pack_start ( hbox73, save, no, no, 5 ) ;
	
	gtk_box_pack_start ( table69, hbox72, no, no, 5 ) ;
	
	gtk_box_pack_start ( table69, label70, no, no, 5 ) ;
	gtk_box_pack_start ( table69, hbox73, no, no, 5 ) ;
	
	GtkHBox * hbox4 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_start ( vbox, hbox4, no, no, 2 ) ;
	
	GSList * group = null ;
	GtkRadioButton * radio1 = gtk_radio_button_new_with_label ( group, "Quality" ) ;
	group = gtk_radio_button_get_group ( radio1 ) ;
	GtkRadioButton * radio2 = gtk_radio_button_new_with_label ( group, "Bitrate" ) ;
	group = gtk_radio_button_get_group ( radio2 ) ;
	
	GtkSpinButton * spin1 = gtk_spin_button_new_with_range ( 0.0, 9.0, 0.1 ) ;
	gtk_spin_button_set_value ( spin1, 3.0 ) ;
	
	GtkSpinButton * spin2 = gtk_spin_button_new_with_range ( 48.0, 320.0, 1.0 ) ;
	gtk_spin_button_set_value ( spin2, 160 ) ;
	
	GtkVSeparator * spacer1 = gtk_vseparator_new () ;
	gtk_box_pack_start ( hbox4, radio1, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, spin1, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, spacer1, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, radio2, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, spin2, no, no, 5 ) ;
	
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_end ( vbox, hbox1, no, no, 5 ) ;
	
	GtkButton * encode = gtk_button_new () ;
	gtk_button_set_label ( encode, "Encode !" ) ;
	gtk_button_set_image ( encode, gtk_image_new_from_stock ( 	GTK_STOCK_OK,
																GTK_ICON_SIZE_BUTTON )) ;
	
	
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_STOP ) ;
	gtk_widget_set_size_request ( cancel, 96, 32 ) ;
	gtk_widget_set_size_request ( encode, 96, 32 ) ;
	
	g_signal_connect_swapped ( cancel, "clicked", dominique_vorbis_cancel, "oggenc" ) ;
	g_signal_connect ( encode, "clicked", dominique_vorbis_encode, null ) ;
	gtk_widget_set_sensitive ( cancel, false ) ;

	GtkButton * close = gtk_button_new_from_stock ( GTK_STOCK_CLOSE ) ;
	g_signal_connect_swapped ( close, "clicked", dominique_quit, parent ) ;
	
	gtk_box_pack_end ( hbox1, close, no, no, 2 ) ;
	gtk_widget_set_size_request ( close, 96, 32 ) ;
	gtk_box_pack_end ( hbox1, cancel, no, no, 2 ) ;
	gtk_box_pack_end ( hbox1, encode, no, no, 5 ) ;
	
	GtkHBox * hbox2 = gtk_hbox_new ( no, 5 ) ;
	GtkProgressBar * bar = gtk_progress_bar_new () ;
	gtk_widget_set_size_request ( bar, 300, 24 ) ;
	
	gtk_box_pack_start ( vbox, hbox2, no, no, 5 ) ;
	gtk_box_pack_start ( hbox2, bar, no, no, 5 ) ;
	
	GtkLabel * display = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( display, true ) ;
	
	GtkScrolledWindow * sw = gtk_scrolled_window_new ( null, null ) ;
	gtk_scrolled_window_add_with_viewport ( sw, display ) ;
	
	GtkWidget * hbox7 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_start ( vbox, hbox7, no, no, 5 ) ;
	gtk_box_pack_start ( hbox7, sw, yes, yes, 5 ) ;
	gtk_scrolled_window_set_policy ( sw, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC ) ;

	vorbis_object.display = display ;
	vorbis_object.input = entry1 ;
	vorbis_object.output = entry2 ;
	vorbis_object.bar = bar ;
	vorbis_object.window = parent ;
	vorbis_object.encode = encode ;
	vorbis_object.cancel = cancel ;
	vorbis_object.close = close ;
	vorbis_object.spin1 = spin1 ;
	vorbis_object.spin2 = spin2 ;
	vorbis_object.radio1 = radio1 ;
	vorbis_object.radio2 = radio2 ;
	
	g_signal_connect ( radio1, "toggled", dominique_vorbis_select_mode, spin2 ) ;
	g_signal_connect ( radio2, "toggled", dominique_vorbis_select_mode, spin1 ) ;
	gtk_toggle_button_toggled ( radio1 ) ;
	
	gtk_widget_show_all ( master ) ;
	return master ;
}
	
void dominique_vorbis_set_input_file ( GtkWidget * widget, shagpointer data )
{	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose a file ...",
																	gtk_widget_get_toplevel ( widget ),
																	GTK_FILE_CHOOSER_ACTION_OPEN,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_CANCEL,
																	GTK_STOCK_OPEN,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	GtkFileFilter * filter = gtk_file_filter_new () ;
	gtk_file_filter_add_mime_type ( filter, "audio/*" ) ;
	
	gtk_file_filter_set_name ( filter, "Audio files" ) ;
	gtk_file_chooser_add_filter ( dialog, filter ) ;
	
	GtkFileFilter * filter2 = gtk_file_filter_new () ;
	gtk_file_filter_add_pattern ( filter2, "*" ) ;
	
	gtk_file_filter_set_name ( filter2, "All files" ) ;
	gtk_file_chooser_add_filter ( dialog, filter2 ) ;

	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_ACCEPT )
	{
		gchar * filename = gtk_file_chooser_get_filename ( dialog ) ;
		gtk_entry_set_text ( data, filename ) ;
		
		g_free ( filename ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

void dominique_vorbis_set_output_file ( GtkWidget * widget, shagpointer data )
{	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose a file ...",
																	gtk_widget_get_toplevel ( widget ),
																	GTK_FILE_CHOOSER_ACTION_SAVE,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_CANCEL,
																	GTK_STOCK_SAVE,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	GtkFileFilter * filter = gtk_file_filter_new () ;
	gtk_file_filter_add_mime_type ( filter, "application/ogg" ) ;
	
	gtk_file_filter_set_name ( filter, "Ogg vorbis files" ) ;
	gtk_file_chooser_add_filter ( dialog, filter ) ;
	
	GtkFileFilter * filter2 = gtk_file_filter_new () ;
	gtk_file_filter_add_pattern ( filter2, "*" ) ;
	
	gtk_file_filter_set_name ( filter2, "All files" ) ;
	gtk_file_chooser_add_filter ( dialog, filter2 ) ;

	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_ACCEPT )
	{
		gchar * filename = gtk_file_chooser_get_filename ( dialog ) ;
		gtk_entry_set_text ( data, filename ) ;
		
		g_free ( filename ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

void dominique_vorbis_encode ( void )
{
	gchar * filename1 = gtk_entry_get_text ( vorbis_object.input ) ;
	if ( ! april_file_exists ( filename1 ))
	{
		april_message_box_info ( "Select input file first !" ) ;
		return ;
	}
	
	gchar * filename21 = gtk_entry_get_text ( vorbis_object.output ) ;
	if ( filename21 == null )
	{
		april_message_box_info ( "Select output file first !" ) ;
		return ;
	}
	
	if ( april_file_exists ( filename21 ))
	{
		if ( ! april_message_box_yes_no ( "Output file exists ! Overwrite ?" ))
			return ;
	}	
		
	gchar * filename2 = null ;	
	if ( g_strrstr ( filename21, ".ogg" ) == null )
		filename2 = april_malloc_sprintf ( "%s.ogg", filename21 ) ;
	else
		filename2 = g_strdup ( filename21 ) ;		
		
	if ( current_file )
		g_free ( current_file ) ;
	
	current_file = g_strdup ( filename2 ) ;
	
	gchar * command = null ;
	if ( gtk_toggle_button_get_active ( vorbis_object.radio1 ))
		command = g_strdup_printf (
			"oggenc;-q;%f;-o;%s;%s",
			gtk_spin_button_get_value ( vorbis_object.spin1 ),
			filename2,
			filename1
			) ;
	else
		command = g_strdup_printf (
			"oggenc;-b;%d;-o;%s;%s",
			gtk_spin_button_get_value_as_int ( vorbis_object.spin2 ),
			filename2,
			filename1
			) ;	
	
	gtk_widget_set_sensitive ( vorbis_object.cancel, true ) ;
	gtk_widget_set_sensitive ( vorbis_object.encode, false ) ;
	gtk_widget_set_sensitive ( vorbis_object.close, false ) ;
	april_update_gui () ;
	
	dominique_vorbis_encode_file ( command ) ;

	gtk_widget_set_sensitive ( vorbis_object.cancel, false ) ;
	gtk_widget_set_sensitive ( vorbis_object.encode, true ) ;
	gtk_widget_set_sensitive ( vorbis_object.close, true ) ;
	
	gtk_progress_bar_set_fraction ( vorbis_object.bar, 0.0 ) ;
	april_update_gui () ;
	
	g_free ( filename2 ) ;
	g_free ( command ) ;
	
	dominique_vorbis_shew_result ( vorbis_object.window ) ;
}

gboolean dominique_vorbis_encode_file ( gchar * command )
{
	gint pid = 0, stdin = 0, stdout = 0, stderr = 0 ;
	GError * error = null ;
	
	gchar ** vector = g_strsplit ( command, ";", -1 ) ;
	gboolean result = false ;
	
	result = g_spawn_async_with_pipes ( null, vector, null, G_SPAWN_SEARCH_PATH,
										null, null, & pid, & stdin, & stdout,
										& stderr, & error ) ;
	
	if ( error )
		april_message_box_error ( error -> message ) ;
		
	File *fd = fdopen ( stderr, "r" ) ;
	if ( fd == null )
		april_message_box_warning ( "Cannot open file descriptor !" ) ;
	
	gchar message [200] ;
	fgets ( & message, 199, fd ) ;
	
	gtk_label_set_label ( vorbis_object.display, message ) ;
	april_update_gui () ;
	
	while ( april_check_bin_status ( vector [0] ))
	{
		gchar message [200] ;
		fflush ( fd ) ;
		fgets ( & message, 32, fd ) ;
		
		gtk_label_set_label ( vorbis_object.display, message ) ;
		gtk_progress_bar_set_fraction ( vorbis_object.bar, dominique_vorbis_get_progress ( & message )) ;
		
		april_update_gui () ;
		april_sleep () ;
		
		fflush ( fd ) ;
		fgets ( & message, 32, fd ) ;
		fgets ( & message, 32, fd ) ;
	}
	
	g_strfreev ( vector ) ;
	fclose ( fd ) ;
	
	g_spawn_close_pid ( pid ) ;
	return result ;
}

gchar * dominique_vorbis_get_modline ( const gchar * message )
{
	gchar ** vector = g_strsplit ( message , " ", -1 ) ;
	gchar * mod = g_strdup ( vector [0] ) ;
	
	g_strfreev ( vector ) ;
	return mod ;
}

gdouble dominique_vorbis_get_progress ( gchar * message )
{
	gchar ** vector = g_strsplit ( message, "[", -1 ) ;
	gdouble progress = 0.0 ;
	
	if ( vector [1] != null )
	{
		gchar ** vector2 = g_strsplit ( vector [1], "%", -1 ) ;
		if ( vector2 [0] != null )
			progress = atoi ( vector2 [0] ) ;
		
		g_strfreev ( vector2 ) ;
	}
	
	g_strfreev ( vector ) ;
	return progress / 100 ;
}

void dominique_vorbis_shew_result ( GtkWidget * window )
{
	gdk_beep () ;
	GtkDialog * dialog = gtk_dialog_new_with_buttons ( 	"Encoding process completed !",
														window,
														GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
														GTK_STOCK_MEDIA_PLAY,
														GTK_RESPONSE_OK,
														GTK_STOCK_CLOSE,
														GTK_RESPONSE_ACCEPT,
														null ) ;
	
	GtkHBox * hbox = gtk_hbox_new ( no, 5 ) ;
	
	GtkLabel * label = gtk_label_new ( null ) ;
	gtk_label_set_markup ( label, "<span size=\"large\">Finished encoding audio !</span>" ) ;
	
	gtk_box_pack_start ( dialog -> vbox, label, no, no, 5 ) ;
	gtk_box_pack_start ( dialog -> vbox, hbox, yes, yes, 5 ) ;
	
	gtk_widget_show_all ( dialog -> vbox ) ;
	//gtk_widget_set_size_request ( dialog, 550, 300 ) ;
	
	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_OK )
	{
		dominique_play_audio ( current_file ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

void dominique_vorbis_cancel ( void )
{
	if ( april_message_box_yes_no ( "Are you sure you want to cancel ?" ))
		april_kill ( "oggenc" ) ;
}

void dominique_vorbis_select_mode ( GtkWidget * widget, shagpointer data )
{
	gtk_widget_set_sensitive ( vorbis_object.spin1, true ) ;
	gtk_widget_set_sensitive ( vorbis_object.spin2, true ) ;
	
	gtk_widget_set_sensitive ( data, false ) ;
	april_update_gui () ;
}
