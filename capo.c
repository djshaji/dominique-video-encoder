/*
 *      capo.c
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

#include "capo.h"

GtkWidget * dominique_capo_new ( GtkWidget * parent )
{
	GtkWidget * vbox = gtk_vbox_new ( no, 5 ) ;
	GtkWidget * master = gtk_hbox_new ( yes, 10 ) ;
	
	gtk_box_pack_start ( master, vbox, yes, no, 5 ) ;
	
	GtkFrame * frame69 = gtk_frame_new ( "Choose input and output files" ) ;
	GtkTable * table69 = gtk_vbox_new ( no, 5 ) ;
	
	gtk_container_add ( frame69, table69 ) ;
	gtk_box_pack_start ( vbox, frame69, no, no, 10 ) ;
	
	GtkLabel * label69 = gtk_label_new ( "Choose input video file ..." ) ;
	GtkLabel * label70 = gtk_label_new ( "Choose output video file ..." ) ;
	
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
	
	g_signal_connect ( open, "clicked", dominique_encode_set_input_file, entry1 ) ;
	g_signal_connect ( save, "clicked", dominique_encode_set_output_file, entry2 ) ;
		
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
	
	GtkLabel * label1 = gtk_label_new ( "From" ) ;
	GtkSpinButton * spin1 = gtk_spin_button_new_with_range ( 0.0, 9000.0, 1.0 ) ;
	
	GtkLabel * label2 = gtk_label_new ( "to" ) ;
	GtkSpinButton * spin2 = gtk_spin_button_new_with_range ( 1.0, 9000.0, 1.0 ) ;

	gtk_box_pack_start ( hbox4, label1, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, spin1, no, no, 5 ) ;
	gtk_box_pack_start ( hbox4, gtk_label_new ( "seconds" ), no, no, 2 ) ;
	
	gtk_box_pack_end ( hbox4, spin2, no, no, 5 ) ;
	gtk_box_pack_end ( hbox4, label2, no, no, 5 ) ;

	GtkHBox * hbox5 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_start ( vbox, hbox5, no, no, 5 ) ;
	
	GtkCheckButton * check1 = gtk_check_button_new_with_label ( "Rebuild index" ) ;
	gtk_box_pack_start ( hbox5, check1, no, no, 5 ) ;
	
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_end ( vbox, hbox1, no, no, 5 ) ;
	
	GtkButton * encode = gtk_button_new () ;
	gtk_button_set_label ( encode, "Split" ) ;
	gtk_button_set_image ( encode, gtk_image_new_from_stock ( 	GTK_STOCK_OK,
																GTK_ICON_SIZE_BUTTON )) ;
	
	
	g_signal_connect ( encode, "clicked", dominique_capo_on_second_fret, null ) ;
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_STOP ) ;
	g_signal_connect_swapped ( cancel, "clicked", dominique_encode_video_cancel, "mencoder" ) ;
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
	mtp_object.check1 = spin1 ;
	mtp_object.spin = spin2 ;
	mtp_object.check2 = check1 ;
	
	object.input = entry1 ;
	object.output = entry2 ;
	object.window = parent ;
	object.bar = bar ;
	object.encode = encode ;
	object.cancel = cancel ;
	object.display = display ;

	gtk_widget_show_all ( master ) ;
	return master ;
}
	
void dominique_capo_on_second_fret ( void )
{
	gchar * filename1 = gtk_entry_get_text ( object.input ) ;
	if ( ! april_file_exists ( filename1 ))
	{
		april_message_box_info ( "Select input file first !" ) ;
		return ;
	}
	
	gchar * filename21 = gtk_entry_get_text ( object.output ) ;
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
	if ( g_strrstr ( filename21, ".avi" ) == null )
		filename2 = g_strdup_printf ( "%s.avi", filename21 ) ;
	else
		filename2 = g_strdup ( filename21 ) ;
	
	if ( current_file )
		g_free ( current_file ) ;
	
	current_file = g_strdup ( filename2 ) ;
	
	gchar * command = g_strdup_printf (
		"mencoder -ovc copy -oac copy -ss %d -endpos %d -o \"%s\" \"%s\" > /tmp/dominique.tmp",
		gtk_spin_button_get_value_as_int ( mtp_object.check1 ),
		gtk_spin_button_get_value_as_int ( mtp_object.spin ) - gtk_spin_button_get_value_as_int ( mtp_object.check1 ),
		filename2,
		filename1
		) ;
	
	if ( gtk_toggle_button_get_active ( mtp_object.check2 ))
	{
		gchar * tmp = g_strconcat ( command, " -forceidx", null ) ;
		g_free ( command ) ;
		
		command = g_strdup ( tmp ) ;
		g_free ( tmp ) ;
	}
	
	april_spawn_async ( command ) ;
	
	gtk_widget_set_sensitive ( mtp_object.cancel, true ) ;
	gtk_widget_set_sensitive ( mtp_object.encode, false ) ;
	gtk_widget_set_sensitive ( mtp_object.close, false ) ;
	
	gtk_progress_bar_set_fraction ( mtp_object.bar, 0.0 ) ;
	april_update_gui () ;
	
	while ( april_check_bin_status ( "mencoder" ))
	{
		gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
		gtk_label_set_label ( mtp_object.display, ( "%s", g_strrstr ( filename, "Pos" ))) ;
	
		april_update_gui () ;
		gtk_progress_bar_set_fraction ( mtp_object.bar, dominique_encode_get_progress ( filename )) ;
		
		g_free ( filename ) ;
		april_sleep () ;
	}
	
	gtk_widget_set_sensitive ( mtp_object.cancel, false ) ;
	gtk_widget_set_sensitive ( mtp_object.encode, true ) ;
	gtk_widget_set_sensitive ( mtp_object.close, true ) ;

	gtk_progress_bar_set_fraction ( mtp_object.bar, 1.0 ) ;
	april_update_gui () ;
	
	g_free ( command ) ;
	g_free ( filename2 ) ;
	
	dominique_capo_shew_result ( mtp_object.window ) ;
}	
	
void dominique_capo_shew_result ( GtkWidget * window )
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
	gtk_label_set_markup ( label, "<span size=\"large\">Finished encoding video !</span>" ) ;
	
	gtk_box_pack_start ( dialog -> vbox, label, no, no, 5 ) ;
	gtk_box_pack_start ( dialog -> vbox, hbox, yes, yes, 5 ) ;

	GtkLabel * display = gtk_label_new ( null ) ;
	GtkScrolledWindow * sw = gtk_scrolled_window_new ( null, null ) ;
	gtk_scrolled_window_add_with_viewport ( sw, display ) ;

	gtk_box_pack_start ( hbox, sw, yes, yes, 5 ) ;
	gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
	gtk_label_set_label ( display, g_strrstr ( filename, "Writing" )) ;
	g_free ( filename ) ;
	
	gtk_widget_show_all ( dialog -> vbox ) ;
	gtk_widget_set_size_request ( dialog, 550, 300 ) ;
	
	if ( gtk_dialog_run ( dialog ) == GTK_RESPONSE_OK )
	{
		dominique_play ( current_file ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

