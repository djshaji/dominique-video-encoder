/*
 *      video.c
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

#include "video.h"

DominiqueStreamObject object ;

GtkWidget * dominique_encode_video_new ( GtkWidget * parent )
{
	GtkNotebook * notebook = gtk_notebook_new () ;
	GtkWidget * vbox = gtk_vbox_new ( no, 10 ) ;
	
	GtkFrame * frame69 = gtk_frame_new ( "Choose input and output files" ) ;
	GtkTable * table69 = gtk_vbox_new ( no, 5 ) ;
	
	gtk_container_add ( frame69, table69 ) ;
	gtk_box_pack_start ( vbox, notebook, yes, yes, 10 ) ;
	gtk_notebook_append_page ( notebook, frame69, gtk_label_new ( "File" )) ;
	
	GtkLabel * label69 = gtk_label_new ( "Choose input file ..." ) ;
	GtkLabel * label70 = gtk_label_new ( "Choose output file ..." ) ;
	
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

	//gtk_table_attach ( table69, open, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;
	//gtk_table_attach ( table69, save, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 10, 5 ) ;


	GtkFrame * frame = gtk_frame_new ( "Video options" ) ;
	//gtk_box_pack_start ( vbox, frame, no, no, 2 ) ;
	gtk_notebook_append_page ( notebook, frame, gtk_label_new ( "Video" )) ;
	
	GtkTable * table = gtk_table_new ( 8, 6, false ) ;
	gtk_container_add ( frame, table ) ;
	
	GtkSpinButton * spin1 = gtk_spin_button_new_with_range ( 32.0, 8000.0, 1.0 ) ;
	gtk_spin_button_set_value ( spin1, DEFAULT_VIDEO_BITRATE ) ;
	GtkLabel * label1 = gtk_label_new ( "Bitrate" ) ;
	
	GtkComboBox * combo1 = gtk_combo_box_new_text () ;
	GtkLabel * label2 = gtk_label_new ( "Codec" ) ;
	
	GtkLabel * info1 = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( info1, true ) ;
	
	gint i = 0 ;
	while ( dominique_video_codecs [i] != null )
	{
		gtk_combo_box_append_text ( combo1, dominique_video_codecs [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo1, DEFAULT_VIDEO_CODEC ) ;
	
	gtk_table_attach ( table, label1, 4, 5, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;
	gtk_table_attach ( table, spin1, 6, 7, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	
	gtk_table_attach ( table, label2, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;
	gtk_table_attach ( table, combo1, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	
	gtk_table_attach ( table, info1, 0, 7, 2, 5, GTK_FILL, GTK_FILL, 10, 5 ) ;

	GtkLabel * label3 = gtk_label_new ( "Aspect ratio" ) ;
	GtkComboBox * combo2 = gtk_combo_box_new_text () ;
	
	i = 0 ;
	while ( dominique_video_aspect_ratio [i] != null )
	{
		gtk_combo_box_append_text ( combo2, dominique_video_aspect_ratio [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo2, 0 ) ;
	
	//gtk_table_attach ( table, label3, 8, 9, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	//gtk_table_attach ( table, combo2, 10, 11, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ; 
	
	GtkLabel * label4 = gtk_label_new ( "Resize" ) ;
	GtkComboBox * combo3 = gtk_combo_box_new_text () ;

	i = 0 ;
	while ( dominique_video_resize [i] != null )
	{
		gtk_combo_box_append_text ( combo3, dominique_video_resize [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo3, 0 ) ;
	
	//gtk_table_attach ( table, label4, 8, 9, 2, 3, GTK_FILL, GTK_FILL, 10, 5 ) ;
	//gtk_table_attach ( table, combo3, 10, 11, 2, 3, GTK_FILL, GTK_FILL, 10, 5 ) ; 	
	
	GtkLabel * label5 = gtk_label_new ( "Post processor" ) ;
	GtkComboBox * combo4 = gtk_combo_box_new_text () ;
	
	i = 0 ;
	while ( dominique_video_pp [i] != null )
	{
		gtk_combo_box_append_text ( combo4, dominique_video_pp [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo4, 0 ) ;
	//gtk_table_attach ( table, label5, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 5, 5 ) ;
	//gtk_table_attach ( table, combo4, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 10, 5 ) ; 
	
	GtkSpinButton * spin2 = gtk_spin_button_new_with_range ( 1.0, 6.0, 1.0 ) ;
	GtkLabel * label6 = gtk_label_new ( "Filter strength" ) ;
	
	//gtk_table_attach ( table, label6, 4, 5, 2, 3, GTK_FILL, GTK_FILL, 5, 5 ) ;
	//gtk_table_attach ( table, spin2, 6, 7, 2, 3, GTK_FILL, GTK_FILL, 10, 5 ) ; 
	
	GtkFrame * frame2 = gtk_frame_new ( "Audio options" ) ;
	//gtk_box_pack_start ( vbox, frame2, no, no, 5 ) ;
	gtk_notebook_append_page ( notebook, frame2, gtk_label_new ( "Audio" )) ;
	
	GtkTable * table2 = gtk_table_new ( 8, 6, false ) ;
	gtk_container_add ( frame2, table2 ) ;
	
	GtkSpinButton * spin3 = gtk_spin_button_new_with_range ( 32.0, 8000.0, 1.0 ) ;
	gtk_spin_button_set_value ( spin3, DEFAULT_AUDIO_BITRATE ) ;
	GtkLabel * label7 = gtk_label_new ( "Bitrate" ) ;
	
	GtkComboBox * combo5 = gtk_combo_box_new_text () ;
	GtkLabel * label8 = gtk_label_new ( "Codec" ) ;
	
	i = 0 ;
	while ( dominique_audio_codecs [i] != null )
	{
		gtk_combo_box_append_text ( combo5, dominique_audio_codecs [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo5, DEFAULT_AUDIO_CODEC ) ;
	
	gtk_table_attach ( table2, label7, 4, 5, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	gtk_table_attach ( table2, spin3, 6, 7, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;
	
	gtk_table_attach ( table2, label8, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	gtk_table_attach ( table2, combo5, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;
	
	GtkLabel * info2 = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( info2, true ) ;
	gtk_table_attach ( table2, info2, 0, 7, 2, 5, GTK_FILL, GTK_FILL, 10, 5 ) ;

	GtkFrame * frame3 = gtk_frame_new ( "Misc options" ) ;
	//gtk_box_pack_start ( vbox, frame3, no, no, 5 ) ;
	gtk_notebook_append_page ( notebook, frame3, gtk_label_new ( "Misc" )) ;
	
	GtkTable * table3 = gtk_table_new ( 8, 6, false ) ;
	gtk_container_add ( frame3, table3 ) ;

	GtkLabel * label9 = gtk_label_new ( "Container format" ) ;
	GtkComboBox * combo6 = gtk_combo_box_new_text () ;

	i = 0 ;
	while ( dominique_container_formats [i] != null )
	{
		gtk_combo_box_append_text ( combo6, dominique_container_formats [i] ) ;
		i ++ ;
	}
	
	gtk_combo_box_set_active ( combo6, 0 ) ;
	
	gtk_table_attach ( table3, label9, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 5, 5 ) ;
	gtk_table_attach ( table3, combo6, 2, 3, 0, 1, GTK_FILL, GTK_FILL, 10, 5 ) ;		
	
	GtkLabel * info3 = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( info3, true ) ;
	gtk_table_attach ( table3, info3, 0, 7, 2, 5, GTK_FILL, GTK_FILL, 10, 5 ) ;

	GtkVBox * vbox1 = gtk_vbox_new ( no, 5 ) ;
	GtkHBox * hbox1 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_end ( vbox1, hbox1, no, no, 5 ) ;
	gtk_notebook_append_page ( notebook, vbox1, gtk_label_new ( "Encode !" )) ;
	
	GtkButton * encode = gtk_button_new () ;
	gtk_button_set_label ( encode, "Encode" ) ;
	gtk_button_set_image ( encode, gtk_image_new_from_stock ( 	GTK_STOCK_OK,
																GTK_ICON_SIZE_BUTTON )) ;
	
	gtk_box_pack_end ( hbox1, encode, no, no, 5 ) ;
	
	GtkButton * cancel = gtk_button_new_from_stock ( GTK_STOCK_STOP ) ;
	gtk_widget_set_size_request ( cancel, 96, 32 ) ;
	gtk_box_pack_end ( hbox1, cancel, no, no, 2 ) ;
	gtk_widget_set_size_request ( encode, 96, 32 ) ;
	
	g_signal_connect ( cancel, "clicked", dominique_encode_video_cancel, null ) ;
	gtk_widget_set_sensitive ( cancel, false ) ;
	
	GtkHBox * hbox2 = gtk_hbox_new ( no, 10 ) ;
	
	GtkProgressBar * bar = gtk_progress_bar_new () ;
	gtk_widget_set_size_request ( bar, 300, 24 ) ;
	gtk_box_pack_start ( hbox2, bar, yes, no, 5 ) ;
	
	GtkLabel * display = gtk_label_new ( null ) ;
	gtk_label_set_line_wrap ( display, true ) ;
	
	GtkScrolledWindow * sw = gtk_scrolled_window_new ( null, null ) ;
	gtk_scrolled_window_add_with_viewport ( sw, display ) ;
	
	GtkWidget * hbox7 = gtk_hbox_new ( no, 5 ) ;
	gtk_box_pack_start ( vbox1, hbox7, no, no, 5 ) ;
	gtk_box_pack_start ( hbox7, sw, yes, yes, 5 ) ;
	gtk_box_pack_start ( vbox1, hbox2, no, no, 10 ) ;
	gtk_scrolled_window_set_policy ( sw, GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC ) ;
	
	object.window = parent ;
	object.display = display ;
	object.vcodec = combo1 ;
	object.vbitrate = spin1 ;
	object.aspect = combo2 ;
	object.resize = combo3 ;
	object.pp = combo4 ;
	object.pp_strength = spin2 ; 
	object.acodec = combo5 ; 
	object.abitrate = spin3 ; 
	object.format = combo6 ;
	object.vbox = vbox ;
	object.bar = bar ;
	object.cancel = cancel ;
	object.encode = encode ;
	object.input = entry1 ;
	object.output = entry2 ;
	
	g_signal_connect ( encode, "clicked", dominique_encode_video, & object ) ;
	
	g_signal_connect_after ( combo1, "changed", dominique_set_video_info, info1 ) ;
	g_signal_connect_after ( combo5, "changed", dominique_set_audio_info, info2 ) ;
	g_signal_connect_after ( combo6, "changed", dominique_set_container_info, info3 ) ;
	
	GtkHBox * hbox3 = gtk_hbox_new ( no, 5 ) ;
	GtkButton * close = gtk_button_new_from_stock ( GTK_STOCK_QUIT ) ;
	g_signal_connect_swapped ( close, "clicked", dominique_quit, parent ) ;
	gtk_widget_set_size_request ( close, 96, 32 ) ;
	
	gtk_box_pack_end ( hbox3, close, no, no, 2 ) ;
	gtk_box_pack_start ( vbox, hbox3, no, no, 2 ) ;
	
	dominique_set_audio_info ( combo5, info2 ) ;
	dominique_set_video_info ( combo1, info1 ) ;
	dominique_set_container_info ( combo6, info3 ) ;
	
	dominique_config_load () ;
	return vbox ;
}

void dominique_encode_video ( DominiqueStreamObject * object1 )
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
			
	gchar * format = gtk_combo_box_get_active_text ( object.format ) ;
	gchar * filename2 = null ;
	
	gchar * extension = april_malloc_sprintf ( ".%s", format ) ;
	if ( strstr ( filename21, extension ) == null )
		filename2 = april_malloc_sprintf ( "%s%s", filename21, extension ) ;
	else
		filename2 = g_strdup ( filename21 ) ;
	
	g_free ( extension ) ;

	if ( april_file_exists ( filename2 ))
	{
		if ( ! april_message_box_yes_no ( "Output file exists ! Overwrite ?" ))
		{
			g_free ( filename2 ) ;
			return ;
		}
	}	

	if ( current_file )
		g_free ( current_file ) ;
	
	current_file = g_strdup ( filename2 ) ;
	
	gchar * vcodec = gtk_combo_box_get_active_text ( object.vcodec ) ;
	if ( experimental_warning )
	{
		if ( strstr ( vcodec, "snow" ))
		{
			april_message_box_warning ( "The video codec you have chosen is experimental\n"
										"and the resulting file may not be playable with\n"
										"future MPlayer versions !\n\n"
										"And, it needs not be said that this codec will\n"
										"probably not be playable on other media players\n"
										"as well." ) ;
		}
		
		experimental_warning = false ;
	}
	
	gchar * pp = gtk_combo_box_get_active_text ( object.pp ) ;
	gchar * resize = gtk_combo_box_get_active_text ( object.resize ) ;
	gchar * aspect = gtk_combo_box_get_active_text ( object.aspect ) ;
	
	gint vbitrate = gtk_spin_button_get_value_as_int ( object.vbitrate ) ;
	gint pp_strength = gtk_spin_button_get_value_as_int ( object.pp_strength ) ;
	
	gchar * acodec = gtk_combo_box_get_active_text ( object.acodec ) ;
	gint abitrate = gtk_spin_button_get_value_as_int ( object.abitrate ) ;
	
	gchar * command1 = april_malloc_sprintf (
		"mencoder \"%s\" -ovc lavc -oac lavc -lavcopts vcodec=%s:vbitrate=%d:acodec=%s:abitrate=%d -of lavf -o \"%s\" > /tmp/dominique.tmp",
		filename1, vcodec, vbitrate, acodec, abitrate, filename2 ) ;
	
	gtk_widget_set_sensitive ( object.cancel, true ) ;
	gtk_widget_set_sensitive ( object.encode, false ) ;
	
	april_update_gui () ;
	dominique_encode_video_encode ( command1 ) ;
	//april_message_box_info ( command1 ) ;
	//april_spawn_wait_for ( "Encoding video", command1 ) ;
	
	g_free ( vcodec ) ;
	g_free ( pp ) ;
	g_free ( resize ) ;
	g_free ( aspect ) ;
	g_free ( acodec ) ;
	g_free ( format ) ;
	g_free ( filename2 ) ;
	g_free ( command1 ) ;
	
	gtk_widget_set_sensitive ( object.cancel, false ) ;
	gtk_widget_set_sensitive ( object.encode, true ) ;
	
	//gtk_label_set_label ( object.display, " " ) ;
}

void dominique_encode_set_file ( GtkWidget * widget, shagpointer data )
{
	GtkFileChooserAction action ;
	if ( strstr ( gtk_button_get_label ( widget ), GTK_STOCK_OPEN ))
		action = GTK_FILE_CHOOSER_ACTION_OPEN ;
	else
		action = GTK_FILE_CHOOSER_ACTION_SAVE ;
	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose file ...",
																	gtk_widget_get_toplevel ( widget ),
																	action,
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

void dominique_encode_video_encode ( gchar * command )
{
	GError * error = null ;
	//g_spawn_command_line_async ( command, & error ) ;
	april_spawn_async ( command ) ;
	
	if ( error )
	{
		april_message_box_error ( error -> message ) ;
		return ;
	}
	
	gtk_progress_bar_set_fraction ( object.bar, 0.0 ) ;
	april_update_gui () ;
	
	while ( april_check_bin_status ( "mencoder" ))
	{
		gchar * filename = april_file_get_contents ( "/tmp/dominique.tmp" ) ;
		gtk_label_set_label ( object.display, ( "%s", g_strrstr ( filename, "Pos" ))) ;
	
		april_update_gui () ;
		gtk_progress_bar_set_fraction ( object.bar, dominique_encode_get_progress ( filename )) ;
		
		g_free ( filename ) ;
		april_sleep () ;
	}
	
	gtk_progress_bar_set_fraction ( object.bar, 1.0 ) ;
	april_update_gui () ;
	
	dominique_encode_shew_result ( object.window ) ;
}

void dominique_quit ( GtkWidget * window )
{
	if ( april_message_box_yes_no ( "Are you sure you want to quit ?" ))
	{
	
		dominique_config_save () ;	
		gtk_widget_destroy ( window ) ;
	}
}

void dominique_encode_video_cancel ( GtkWidget * widget )
{
	if ( ! april_message_box_yes_no ( "Are you sure you want to cancel ?" ))
		return ;
	
	april_kill ( "mencoder" ) ;
}

gdouble dominique_encode_get_progress ( gchar * status )
{
	gchar * str = g_strrstr ( status, "f (" ) ;
	if ( str == null )
		return 0 ;
	
	gchar * stat = strchr ( str, '(' ) ;
	if ( stat == null )
		return 0 ;
		
	gchar ** vector = g_strsplit ( stat, "(", -1 ) ;
	gdouble progress = 0 ;
	
	gchar * tmp = null ;
	if ( vector [0] != null )
		if ( vector [1] != null )
			//if ( vector [2] != null )
				tmp = g_strdup ( vector [1] ) ;

	if ( tmp )
	{
		if ( strchr ( tmp, '%' ))
		{
			gchar ** vector2 = g_strsplit ( tmp, "%", -1 ) ;
			progress = atoi ( vector2 [0] ) ;
			
			g_strfreev ( vector2 ) ;
			g_free ( tmp ) ;
		}
	}
	
	g_strfreev ( vector ) ;
	return progress / 100.0 ;
}	
	
void dominique_encode_shew_result ( GtkWidget * window )
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

void dominique_play ( gchar * filename )
{
	gchar * command = g_strdup_printf ( "mplayer \"%s\"", filename ) ;
	april_spawn_async ( command ) ;
	
	g_free ( command ) ;
}

void dominique_set_audio_info ( GtkWidget * widget, GtkLabel * info )
{
	gint codec = gtk_combo_box_get_active ( widget ) ;
	gtk_label_set_label ( info, dominique_audio_codecs_info [codec] ) ;
}

void dominique_set_video_info ( GtkWidget * widget, GtkLabel * info )
{
	gint codec = gtk_combo_box_get_active ( widget ) ;
	gtk_label_set_label ( info, dominique_video_codecs_info [codec] ) ;
}

void dominique_set_container_info ( GtkWidget * widget, GtkLabel * info )
{
	gint codec = gtk_combo_box_get_active ( widget ) ;
	gtk_label_set_label ( info, dominique_container_formats_info [codec] ) ;
}

void dominique_encode_set_input_file ( GtkWidget * widget, shagpointer data )
{	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose a file ...",
																	gtk_widget_get_toplevel ( widget ),
																	GTK_FILE_CHOOSER_ACTION_OPEN,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_CANCEL,
																	GTK_STOCK_OPEN,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	gchar * new = gtk_entry_get_text ( object.input ) ;
	if ( new != null )
	{
		gchar * dirname = g_path_get_dirname ( new ) ;
		gtk_file_chooser_set_current_folder ( dialog, dirname ) ;
		
		g_free ( dirname ) ;
	}
	
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

void dominique_encode_set_output_file ( GtkWidget * widget, shagpointer data )
{	
	GtkFileChooserDialog * dialog = gtk_file_chooser_dialog_new ( 	"Choose a file ...",
																	gtk_widget_get_toplevel ( widget ),
																	GTK_FILE_CHOOSER_ACTION_SAVE,
																	GTK_STOCK_CANCEL,
																	GTK_RESPONSE_CANCEL,
																	GTK_STOCK_SAVE,
																	GTK_RESPONSE_ACCEPT,
																	null ) ;
	
	gchar * new = gtk_entry_get_text ( object.output ) ;
	if ( new != null )
	{
		gchar * dirname = g_path_get_dirname ( new ) ;
		gtk_file_chooser_set_current_folder ( dialog, dirname ) ;
		
		g_free ( dirname ) ;
	}

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

void dominique_config_save ( void )
{
	if ( dominique_config == null )
		return ;
		
	if ( ! april_file_exists ( dominique_config ))
	{
		gchar * command = g_strdup_printf ( "touch %s", dominique_config ) ;
		system ( command ) ;
		
		g_free ( command ) ;
	}
	
	april_key_file_set_int ( dominique_config, "audio", "bitrate", gtk_spin_button_get_value_as_int ( object.abitrate )) ;
	april_key_file_set_int ( dominique_config, "audio", "codec", gtk_combo_box_get_active ( object.acodec )) ;

	april_key_file_set_int ( dominique_config, "video", "bitrate", gtk_spin_button_get_value_as_int ( object.vbitrate )) ;
	april_key_file_set_int ( dominique_config, "video", "codec", gtk_combo_box_get_active ( object.vcodec )) ;
	april_key_file_set_int ( dominique_config, "other", "container", gtk_combo_box_get_active ( object.format )) ;
}

void dominique_config_load ( void )
{
	dominique_config = g_build_filename ( g_getenv ( "HOME" ), ".dominique", null ) ;

	gint abitrate = april_key_file_get_int ( dominique_config, "audio", "bitrate" ) ;
	if ( abitrate > 32 )
		gtk_spin_button_set_value ( object.abitrate, abitrate ) ;
	
	gint acodec = april_key_file_get_int ( dominique_config, "audio", "codec" ) ;
	if ( acodec >= 0 )
		gtk_combo_box_set_active ( object.acodec, acodec ) ;
	
	gint vbitrate = april_key_file_get_int ( dominique_config, "video", "bitrate" ) ;
	if ( vbitrate > 32 )
		gtk_spin_button_set_value ( object.vbitrate, vbitrate ) ;
	
	gint vcodec = april_key_file_get_int ( dominique_config, "video", "codec" ) ;
	if ( vcodec >= 0 )
		gtk_combo_box_set_active ( object.vcodec, vcodec ) ;

	gint format = april_key_file_get_int ( dominique_config, "other", "container" ) ;
	if ( format >= 0 )
		gtk_combo_box_set_active ( object.format, format ) ;

}
	
	
