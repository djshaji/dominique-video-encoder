/*
 *      video.h
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

#define DEFAULT_AUDIO_BITRATE 128
#define DEFAULT_VIDEO_BITRATE 768

/* value in dominique_*_codecs, counting down from 0 ... */
#define DEFAULT_AUDIO_CODEC 3
#define DEFAULT_VIDEO_CODEC 2

GtkWidget * dominique_encode_video_new ( GtkWidget * parent ) ;

static shagpointer dominique = null ;
static gchar * dominique_video_codecs [] = {
	"mpeg1video",
	"mpeg2video",
	"mpeg4",
	"msmpeg4",
	"msmpeg4v2",
	"wmv1",
	"wmv2",
	//"snow",
	"h263p",
	"mjpeg",
	"ljpeg",
	"jpegls",
	"targa",
	"gif",
	"bmp",
	"png",
	"h261",
	"h263",
	"rv10",
	"rv20",
	"huffyuv",
	"asv1",
	"asv2",
	"ffv1",
	"svq1",
	"flv",
	"flashsv",
	"dvvideo",
	"zbmv",
	null
} ;
	
static gchar * dominique_audio_codecs [] = {
	"ac3",
	"flac",
	//"g726",
	//"libamr_nb",
	//"libamr_wb",
	"libfaac",
	//"libgsm",
	//"libgsm_ms",
	"libmp3lame",
	"mp2",
	//"roq_dpcm",
	"sonic",
	"sonicls",
	"vorbis",
	"wmav1",
	"wmav2",
	/* PCM/ADPCM codecs */
	"pcm_s32le",
	"pcm_s32be",
	"pcm_u32le",
	"pcm_u32be",
	"pcm_s24le",
	"pcm_s24be",
	"pcm_u24le",
	"pcm_u24be",
	"pcm_s16le",
	"pcm_s16be",
	"pcm_u16le",
	"pcm_u16be",
	"pcm_s8",
	"pcm_u8",
	"pcm_alaw",
	"pcm_mulaw",
	"pcm_s24daud",
	"pcm_zork",
	"adpcm_ima_qt",
	"adpcm_ima_wav",
	"adpcm_ima_dk3",
	"adpcm_ima_dk4",
	"adpcm_ima_ws",
	"adpcm_ima_smjpeg",
	"adpcm_ima_ms",
	"adpcm_ima_4xm",
	"adpcm_ima_xa",
	"adpcm_ima_ea",
	"adpcm_ima_ct",
	"adpcm_ima_swf",
	"adpcm_ima_yamaha",
	"adpcm_ima_sbpro_4",
	"adpcm_ima_sbpro_3",
	"adpcm_ima_sbpro_2",
	"adpcm_ima_thp",
	"adpcm_ima_adx",
	null
} ;
	
static gchar * dominique_video_aspect_ratio [] = {
	"Autodetect",
	"4:3",
	"16:9",
	"2.33:1",
	"1:1",
	null
} ;

static gchar * dominique_video_resize [] = {
	"128x96",
	"176x144",
	"352x288",
	"704x576",
	"1024x768",
	null
} ;

static gchar * dominique_video_pp [] = {
	"pp",
	"pp7",
	"spp",
	"uspp",
	"fspp",
	"none",
	null
} ;

static gchar * dominique_container_formats [] = {
	"avi",
	"mpg",
	"asf",
	"wav",
	"swf",
	"flv",
	"rm",
	"au",
	"nut",
	"mov",
	"mp4",
	"dv",
	"mkv",
	null
} ;

typedef struct _DominiqueStreamObject {
	/* Video */
	GtkWidget * vcodec ;
	GtkWidget * vbitrate ;
	GtkWidget * pp ;
	GtkWidget * aspect ;
	GtkWidget * pp_strength ;
	GtkWidget * resize ;
	
	/* Audio */
	GtkWidget * acodec ;
	GtkWidget * abitrate ;
	
	/* Container */
	GtkWidget * format ;

	/* Misc */
	GtkWidget * vbox ;
	GtkWidget * bar ;
	GtkWidget * cancel ;
	GtkWidget * encode ;
	GtkWidget * display ;
	GtkWidget * window ;
	
	GtkWidget * input ;
	GtkWidget * output ;
} DominiqueStreamObject ;

void dominique_encode_video ( DominiqueStreamObject * object ) ;
void dominique_encode_set_file ( GtkWidget * widget, shagpointer data ) ;
void dominique_encode_video_encode ( gchar * command ) ;

void dominique_quit ( GtkWidget * window ) ;
void dominique_encode_video_cancel ( GtkWidget * widget ) ;
gdouble dominique_encode_get_progress ( gchar * status ) ;

void dominique_play ( gchar * filename ) ;

static gchar * dominique_video_codecs_info [] = {
	"Moving Pictures Experts Group Video 1, used in Video CD\'s and such.",
	"Moving Pictures Experts Group Video 2, used in Video DVD\'s and such.",
	"ISO standard MPEG-4 (DivX, Xvid compatible)",
	"pre-standard MPEG-4 variant by MS, v3 (AKA DivX3)",
	"pre-standard MPEG-4 by MS, v2 (used in old ASF files)",
	"Windows Media Video, version 1 (AKA WMV7)",
	"Windows Media Video, version 2 (AKA WMV8)",
	//"FFmpeg's experimental wavelet-based codec",
	"H.263+",
	"Motion JPEG",
	"lossless JPEG",
	"JPEG LS",
	"Targa image",
	"GIF image",
	"BMP image",
	"PNG image",
	"H.261",
	"H.263",
	"RealVideo 1.0",
	"RealVideo 2.0",
	"lossless compression",
	"ASUS Video v1",
	"ASUS Video v2",
	"FFmpeg\'s lossless video codec",
	"Sorenson video 1",
	"Sorenson H.263 used in Flash Video",
	"Flash Screen Video",
	"Sony Digital Video",
	"FFmpeg\'s experimental wavelet-based codec",
	"Zip Blocks Motion Video",
	null
} ;
	
static gchar * dominique_audio_codecs_info [] = {
	"Dolby Digital (AC-3)",
	"Free Lossless Audio Codec (FLAC)",
	"Advanced Audio Coding (AAC) - using FAAC",
	"MPEG-1 audio layer 3 (MP3) - using LAME",
	"MPEG-1 audio layer 2 (MP2)",
	"experimental FFmpeg lossy codec",
	"experimental FFmpeg lossless codec",
	"Vorbis",
	"Windows Media Audio v1",
	"Windows Media Audio v2",
	"signed 32-bit little-endian",
	"signed 32-bit big-endian",
	"unsigned 32-bit little-endian",
	"unsigned 32-bit big-endian",
	"signed 24-bit little-endian",
	"signed 24-bit big-endian",
	"unsigned 24-bit little-endian",
	"unsigned 24-bit big-endian",
	"signed 16-bit little-endian",
	"signed 16-bit big-endian",
	"unsigned 16-bit little-endian",
	"unsigned 16-bit big-endian",
	"signed 8-bit",
	"unsigned 8-bit",
	"G.711 A-LAW",
	"G.711 μ-LAW",
	"signed 24-bit D-Cinema Audio format",
	"Activision Zork Nemesis",
	"Apple QuickTime",
	"Microsoft/IBM WAVE",
	"Duck DK3",
	"Duck DK4",
	"Westwood Studios",
	"SDL Motion JPEG",
	"Microsoft",
	"4X Technologies",
	"Phillips Yellow Book CD-ROM eXtended Architecture",
	"Electronic Arts",
	"Creative 16->4-bit",
	"Adobe Shockwave Flash",
	"Yamaha",
	"Creative VOC SoundBlaster Pro 8->4-bit",
	"Creative VOC SoundBlaster Pro 8->2.6-bit",
	"Creative VOC SoundBlaster Pro 8->2-bit",
	"Nintendo GameCube FMV THP",
	"Sega/CRI ADX",
	null
} ;

static gchar * dominique_container_formats_info [] = {
	"Audio-Video Interleaved",
	"MPEG-1 and MPEG-2 PS",
	"Advanced Streaming Format",
	"Waveform Audio",
	"Macromedia Flash",
	"Macromedia Flash video",
	"RealMedia",
	"SUN AU",
	"NUT open container (experimental and not yet spec-compliant)",
	"QuickTime",
	"MPEG-4 format",
	"Sony Digital Video container",
	"Matroska open audio/video container",
	null
} ;

void dominique_set_audio_info ( GtkWidget * widget, GtkLabel * info ) ;
void dominique_set_video_info ( GtkWidget * widget, GtkLabel * info ) ;
void dominique_set_container_info ( GtkWidget * widget, GtkLabel * info ) ;

static gboolean experimental_warning = false ;

void dominique_encode_set_input_file ( GtkWidget * widget, shagpointer data ) ;
void dominique_encode_set_output_file ( GtkWidget * widget, shagpointer data ) ;

static gchar * dominique_config = null ;

void dominique_config_save ( void ) ;
void dominique_config_load ( void ) ;

static gchar * current_file = null ;

