/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  stdinc.h: Pull in all of the necessary system headers
 *
 *  Copyright (C) 2002 Aaron Sethman <androsyn@ratbox.org>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307
 *  USA
 *
 * $Id$
 *
 */

#ifndef STDINC_H /* prevent multiple #includes */
#define STDINC_H

#ifndef IN_AUTOCONF
#ifdef _WIN32
#include "config-win32.h"
#else
#include "config.h"
#endif
#endif

#include "defaults.h"

#ifdef _WIN32
#define inline
#define _WINSOCKAPI_
typedef int bool;
#define true 1
#define false 0
#define snprintf _snprintf
#ifdef IN_MODULE
#define extern __declspec(dllimport)
#else
#define extern __declspec(dllexport)
#endif
#define export __declspec(dllexport)
#endif

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#ifndef _WIN32
#include <stdbool.h>
#endif
#include <errno.h>

#ifdef HAVE_STRTOK_R
# define strtoken(x, y, z) strtok_r(y, z, x)
#endif

#include <sys/types.h>

#ifdef HAVE_CRYPT_H
#include <crypt.h>
#endif

#include <uv.h>
#undef ECHO // this is pulled in from uv, bleh

#ifdef HAVE_LIBCRYPTO
#include <openssl/ssl.h>
#include <openssl/err.h>
#endif

#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <fcntl.h>

#include <stdarg.h>
#include <signal.h>
#include <ctype.h>

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#endif

#ifndef _WIN32
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/file.h>
#endif

#include <limits.h>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SYS_RESOURCE_H
#include <sys/resource.h>
#endif

#include <sys/stat.h>
#ifdef HAVE_SYS_WAIT_H
#include <sys/wait.h>
#endif

#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif

#ifdef PATH_MAX
#define HYB_PATH_MAX PATH_MAX
#else
#define HYB_PATH_MAX 4096
#endif

#if 0 && __GNUC__
#define AFP(a,b) __attribute__((format (printf, a, b)))
#else
#define AFP(a,b)
#endif

#endif
