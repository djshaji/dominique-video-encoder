/*
 *      extract.c
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

#include "extract.h"

GtkWidget * dominique_extractor_new ( GtkWidget * parent )
{
	GtkWidget * vbox = gtk_vbox_new ( no, 5 ) ;
	GtkWidget * master = gtk_hbox_new ( yes, 10 ) ;
	
	gtk_box_pack_start ( master, vbox, yes, no, 5 ) ;
	
	GtkFrame * frame69 = gtk_frame_new ( "Choose input and output files" ) ;
	GtkTable * table69 = gtk_vbox_new ( no, 5 ) ;
	
	gtk_container_add ( frame69, table69 ) ;
	gtk_box_pack_start ( vbox, frame69, no, no, 10 ) ;
	
	GtkLabel * label69 = gtk_label_new ( "Choose input video file ..." ) ;
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
	
	g_signal_connect ( open, "clicked", dominique_extractor_set_input_file, entry1 ) ;
	g_signal_connect ( save, "clicked", dominique_extractor_set_output_file, entry2 ) ;
	
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
	
	GtkCheckButton * check1 = gtk_check_button_new_with_label ( "Use MPlayer audio filters" ) ;
	gtk_box_pack_start ( hbox4, check1, no, no, 5 ) ;
	g_signal_connect ( check1, "toggled", dominique_extractor_tip, null ) ;
	
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_end ( vbox, hbox1, no, no, 5 ) ;
	
	GtkButton * encode = gtk_button_new () ;
	gtk_button_set_label ( encode, "Extract" ) ;
	gtk_button_set_image ( encode, gtk_image_new_from_stock ( 	GTK_STOCK_OK,
																GTK_ICON_SIZE_BUTTON )) ;
	
	
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_STOP ) ;
	gtk_widget_set_size_request ( cancel, 96, 32 ) ;
	gtk_widget_set_size_request ( encode, 96, 32 ) ;
	
	g_signal_connect_swapped ( cancel, "clicked", dominique_extractor_cancel, null ) ;
	g_signal_connect ( encode, "clicked", dominique_extractor_extract, null ) ;
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

	extractor_object.check1 = check1 ;
	extractor_object.display = display ;
	extractor_object.input = entry1 ;
	extractor_object.output = entry2 ;
	extractor_object.bar = bar ;
	extractor_object.window = parent ;
	extractor_object.encode = encode ;
	extractor_object.cancel = cancel ;
	extractor_object.close = close ;
	
	gtk_widget_show_all ( master ) ;
	return master ;
}

void dominique_extractor_set_input_file ( GtkWidget * widget, shagpointer data )
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

void dominique_extractor_set_output_file ( GtkWidget * widget, shagpointer data )
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

void dominique_extractor_extract ( void )
{
	gchar * input = gtk_entry_get_text ( extractor_object.input ) ;
	if ( input == null )
	{
		april_message_box_info ( "No input file selected !" ) ;
		return ;
	}
	
	gchar * output1 = gtk_entry_get_text ( extractor_object.output ) ;
	if ( output1 == null )
	{
		april_message_box_info ( "No output file selected !" ) ;
		return ;
	}
	
	gchar * output = null ;
	if ( g_strrstr ( output1, ".wav" ))
		output = g_strdup ( output1 ) ;
	else
		output = g_strconcat ( output1, ".wav", null ) ;
	
	if ( april_file_exists ( output ))
	{
		if ( ! april_message_box_yes_no ( "Output file already exists ! Overwrite ?" ))
		{
			g_free ( output ) ;
			return ;
		}
	}
	
	if ( current_file )
		g_free ( current_file ) ;
	
	current_file = g_strdup ( output ) ;
	
	gchar * command = g_strdup_printf ( "mplayer -vo null -vc dummy -ao pcm:file=\"%s\" \"%s\" > /tmp/dominique.tmp", output, input ) ;	
	if ( ! gtk_toggle_button_get_active ( extractor_object.check1 ))
	{
		gchar * tmp = g_strconcat ( command, " -af dummy", null ) ;
		g_free ( command ) ;
		
		command = g_strdup ( tmp ) ;
		g_free ( tmp ) ;
	}
	
	april_spawn_async ( command ) ;
	
	gtk_widget_set_sensitive ( extractor_object.cancel, true ) ;
	gtk_widget_set_sensitive ( extractor_object.encode, false ) ;
	gtk_widget_set_sensitive ( extractor_object.close, false ) ;
	april_update_gui () ;

	while ( april_check_bin_status ( "mplayer" ))
	{
		gtk_progress_bar_pulse ( extractor_object.bar ) ;
		gchar * filename = dominique_extractor_get_modline () ;
		gtk_label_set_label ( extractor_object.display, filename ) ;
		
		g_free ( filename ) ;
		april_update_gui () ;
		april_sleep () ;
	}
	
	g_free ( command ) ;
	g_free ( output ) ;

	gtk_widget_set_sensitive ( extractor_object.cancel, false ) ;
	gtk_widget_set_sensitive ( extractor_object.encode, true ) ;
	gtk_widget_set_sensitive ( extractor_object.close, true ) ;
	
	gtk_progress_bar_set_fraction ( extractor_object.bar, 0.0 ) ;
	april_update_gui () ;
	dominique_extractor_shew_result ( extractor_object.window ) ;
	return ;
}
	
void dominique_extractor_shew_result ( GtkWidget * window )
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
	gtk_label_set_markup ( label, "<span size=\"large\">Finished extracting audio !</span>" ) ;
	
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
		dominique_play_audio ( current_file ) ;
	}
	
	gtk_widget_destroy ( dialog ) ;
	return ;
}

void dominique_play_audio ( gchar * filename )
{
	gchar * command = g_strdup_printf ( "gmplayer \"%s\"", filename ) ;
	april_spawn_async ( command ) ;
	
	g_free ( command ) ;
}

void dominique_extractor_cancel ( void )
{
	if ( april_message_box_yes_no ( "Are you sure you want to cancel ?" ))
		april_kill ( "mplayer" ) ;
}

gchar * dominique_extractor_get_modline ( void )
{
	gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
	gchar * str = g_strrstr ( filename, "A: " ) ;
	if ( str == null )
	{
		g_free ( filename ) ;
		return null ;
	}
	
	gchar ** vector = g_strsplit ( str, "%", -1 ) ;
	gchar * mod = g_strdup ( vector [0] ) ;
	
	g_free ( filename ) ;
	g_strfreev ( vector ) ;
	
	return mod ;
}

void dominique_extractor_tip ( void )
{
	if ( extractor_tip )
	{
		april_message_box_info ( 	"Tip !\n\n"
									"To set MPlayer\'s audio filters, use Susie\'s\n"
									"in-built Media Manager extension !" ) ;
		
		extractor_tip = false ;
	}
}
