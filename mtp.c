/*
 *      mtp.c
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

#include "mtp.h"

GtkWidget * dominique_mtp_new ( GtkWidget * parent )
{
	GtkWidget * vbox = gtk_vbox_new ( no, 5 ) ;
	GtkWidget * master = gtk_hbox_new ( yes, 10 ) ;
	
	gtk_box_pack_start ( master, vbox, yes, no, 5 ) ;
	
	GtkFrame * frame69 = gtk_frame_new ( "Choose input and output files" ) ;
	GtkTable * table69 = gtk_vbox_new ( no, 5 ) ;
	
	gtk_container_add ( frame69, table69 ) ;
	gtk_box_pack_start ( vbox, frame69, no, no, 10 ) ;
	
	GtkLabel * label69 = gtk_label_new ( "Choose input video file ..." ) ;
	GtkLabel * label70 = gtk_label_new ( "Choose output folder ..." ) ;
	
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
	
	g_signal_connect ( open, "clicked", dominique_mtp_set_input_file, entry1 ) ;
	g_signal_connect ( save, "clicked", dominique_mtp_set_output_file, entry2 ) ;
		
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
	gtk_box_pack_start ( vbox, hbox4, no, no, 5 ) ;
	
	GtkLabel * label = gtk_label_new ( "Frames per second" ) ;
	GtkSpinButton * spin = gtk_spin_button_new_with_range ( 1.0, 30.0, 1.0 ) ;
	
	gtk_box_pack_start ( hbox4, label, no, no, 5 ) ;
	gtk_box_pack_end ( hbox4, spin, no, no, 5 ) ;
	
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_end ( vbox, hbox1, no, no, 5 ) ;
	
	GtkButton * encode = gtk_button_new () ;
	gtk_button_set_label ( encode, "Split" ) ;
	gtk_button_set_image ( encode, gtk_image_new_from_stock ( 	GTK_STOCK_OK,
																GTK_ICON_SIZE_BUTTON )) ;
	
	
	g_signal_connect ( encode, "clicked", dominique_mtp_split, null ) ;
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_STOP ) ;
	g_signal_connect_swapped ( cancel, "clicked", april_kill, "mplayer" ) ;
	gtk_widget_set_size_request ( cancel, 96, 32 ) ;
	gtk_widget_set_size_request ( encode, 96, 32 ) ;
	
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

	mtp_object.input = entry1 ;
	mtp_object.output = entry2 ;
	mtp_object.window = parent ;
	mtp_object.bar = bar ;
	mtp_object.encode = encode ;
	mtp_object.cancel = cancel ;
	mtp_object.display = display ;
	mtp_object.close = close ;
	mtp_object.check1 = spin ;
	
	gtk_widget_show_all ( master ) ;
	return master ;
}
	
void dominique_mtp_set_input_file ( GtkWidget * widget, shagpointer data )
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
	gtk_file_filter_add_mime_type ( filter, "video/*" ) ;
	gtk_file_filter_add_pattern ( filter, "*.3g*" ) ;
	
	gtk_file_filter_set_name ( filter, "Video files" ) ;
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

void dominique_mtp_set_output_file ( GtkWidget * widget, shagpointer data )
{	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose a file ...",
																	gtk_widget_get_toplevel ( widget ),
																	GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_CANCEL,
																	GTK_STOCK_SAVE,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_ACCEPT )
	{
		gchar * filename = gtk_file_chooser_get_filename ( dialog ) ;
		gtk_entry_set_text ( data, filename ) ;
		
		g_free ( filename ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

void dominique_mtp_split ( void )
{
	gchar * input = gtk_entry_get_text ( mtp_object.input ) ;
	if ( input == null )
	{
		april_message_box_info ( "No input file selected !" ) ;
		return ;
	}
	
	gchar * output = gtk_entry_get_text ( mtp_object.output ) ;
	if ( output == null )
	{
		april_message_box_info ( "No output file selected !" ) ;
		return ;
	}
	
	gchar * command = g_strdup_printf ( "mplayer -vf pp -vo jpeg:outdir=\"%s\" \"%s\" -fps %d > /tmp/dominique.tmp", output, input, ( gint ) gtk_spin_button_get_value_as_int ( mtp_object.check1 )) ;	
	april_spawn_async ( command ) ;
	
	gtk_widget_set_sensitive ( mtp_object.cancel, true ) ;
	gtk_widget_set_sensitive ( mtp_object.encode, false ) ;
	gtk_widget_set_sensitive ( mtp_object.close, false ) ;
	april_update_gui () ;

	while ( april_check_bin_status ( "mplayer" ))
	{
		gtk_progress_bar_pulse ( mtp_object.bar ) ;
		gchar * filename = dominique_mtp_get_modline () ;
		gtk_label_set_label ( mtp_object.display, filename ) ;
		
		g_free ( filename ) ;
		april_update_gui () ;
		april_sleep () ;
	}
	
	g_free ( command ) ;

	gtk_widget_set_sensitive ( mtp_object.cancel, false ) ;
	gtk_widget_set_sensitive ( mtp_object.encode, true ) ;
	gtk_widget_set_sensitive ( mtp_object.close, true ) ;
	
	gtk_progress_bar_set_fraction ( mtp_object.bar, 0.0 ) ;
	april_update_gui () ;

	dominique_mtp_shew_result ( mtp_object.window ) ;
	return ;
}

gchar * dominique_mtp_get_modline ( void )
{
	gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
	gchar * str = g_strrstr ( filename, "A: " ) ;
	if ( str == null )
	{
		str = g_strrstr ( filename, "V: " ) ;
		if ( str == null )
		{
			g_free ( filename ) ;
			return null ;
		}
	}
	
	gchar ** vector = g_strsplit ( str, "ct:", -1 ) ;
	gchar * mod = g_strdup ( vector [0] ) ;
	
	g_free ( filename ) ;
	g_strfreev ( vector ) ;
	
	return mod ;
}

void dominique_mtp_shew_result ( GtkWidget * window )
{
	gdk_beep () ;
	GtkDialog * dialog = gtk_dialog_new_with_buttons ( 	"Encoding process completed !",
														window,
														GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
														GTK_STOCK_OPEN,
														GTK_RESPONSE_OK,
														GTK_STOCK_CLOSE,
														GTK_RESPONSE_ACCEPT,
														null ) ;
	
	GtkHBox * hbox = gtk_hbox_new ( no, 5 ) ;
	
	GtkLabel * label = gtk_label_new ( null ) ;
	gtk_label_set_markup ( label, "<span size=\"large\">Finished extracting pictures !</span>" ) ;
	
	gtk_box_pack_start ( dialog -> vbox, label, no, no, 5 ) ;
	gtk_box_pack_start ( dialog -> vbox, hbox, yes, yes, 5 ) ;

	GtkLabel * display = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( display, true ) ;
	
	GtkScrolledWindow * sw = gtk_scrolled_window_new ( null, null ) ;
	gtk_scrolled_window_add_with_viewport ( sw, display ) ;
	
	gtk_box_pack_start ( hbox, sw, yes, yes, 5 ) ;
	gtk_scrolled_window_set_policy ( sw, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC ) ;

	gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
	gtk_label_set_label ( display, filename ) ;
	g_free ( filename ) ;
	
	gtk_widget_show_all ( dialog -> vbox ) ;
	gtk_widget_set_size_request ( dialog, 550, 300 ) ;
	
	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_OK )
	{
		gchar * filename = gtk_entry_get_text ( mtp_object.output ) ;
		gchar * command = g_strdup_printf ( "susie \"%s\"", filename ) ;
		
		april_spawn_async ( command ) ;
		g_free ( command ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}
