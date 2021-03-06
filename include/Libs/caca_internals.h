/*
 *  libcaca       ASCII-Art library
 *  Copyright (c) 2002, 2003 Sam Hocevar <sam@zoy.org>
 *                All Rights Reserved
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA
 */

/** \file caca_internals.h
 *  \version \$Id: caca_internals.h 250 2004-01-18 04:01:32Z sam $
 *  \author Sam Hocevar <sam@zoy.org>
 *  \brief The \e libcaca private header.
 *
 *  This header contains the private types and functions used by \e libcaca.
 */

#ifndef __CACA_INTERNALS_H__
#define __CACA_INTERNALS_H__

/* Graphics driver */
enum caca_driver
{
#if defined(USE_CONIO)
    CACA_DRIVER_CONIO = 1,
#endif
#if defined(USE_NCURSES)
    CACA_DRIVER_NCURSES = 2,
#endif
#if defined(USE_SLANG)
    CACA_DRIVER_SLANG = 3,
#endif
#if defined(USE_X11)
    CACA_DRIVER_X11 = 4,
#endif
#if defined(USE_WIN32)
    CACA_DRIVER_WIN32 = 5,
#endif
    CACA_DRIVER_NONE = 0
};

/* Timer structure */
#define CACA_TIMER_INITIALIZER { 0, 0 }
struct caca_timer
{
    int last_sec, last_usec;
};

extern enum caca_driver _caca_driver;

/* Initialisation functions */
extern int _caca_init_graphics(void);
extern int _caca_end_graphics(void);
extern int _caca_init_bitmap(void);
extern int _caca_end_bitmap(void);

/* Timer functions */
extern void _caca_sleep(unsigned int);
extern unsigned int _caca_getticks(struct caca_timer *);

/* Cached screen size */
extern unsigned int _caca_width;
extern unsigned int _caca_height;
extern int _caca_resize;
extern int _caca_resize_event;

/* Internal libcaca features */
extern enum caca_feature _caca_background;
extern enum caca_feature _caca_dithering;
extern enum caca_feature _caca_antialiasing;

#if defined(USE_X11)
#include <X11/Xlib.h>
extern Display *x11_dpy;
extern Window x11_window;
extern Pixmap x11_pixmap;
extern GC x11_gc;
extern long int x11_event_mask;
extern int x11_font_width, x11_font_height;
extern unsigned int x11_new_width, x11_new_height;
#endif

#if defined(USE_WIN32)
#include <windows.h>
extern HANDLE win32_hin, win32_hout;
#endif

#endif /* __CACA_INTERNALS_H__ */
