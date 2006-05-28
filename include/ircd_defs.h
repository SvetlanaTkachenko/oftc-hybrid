/*
 *  ircd-hybrid: an advanced Internet Relay Chat Daemon(ircd).
 *  ircd_defs.h: A header for ircd global definitions.
 *
 *  Copyright (C) 2002 by the past and present ircd coders, and others.
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
 *  $Id$
 */

/*
 * NOTE: NICKLEN and TOPICLEN do not live here anymore. Set it with configure
 * Otherwise there are no user servicable part here. 
 *
 */
 /* ircd_defs.h - Global size definitions for record entries used
 * througout ircd. Please think 3 times before adding anything to this
 * file.
 */
#ifndef INCLUDED_ircd_defs_h
#define INCLUDED_ircd_defs_h

/* Right out of the RFC */
#define IRCD_BUFSIZE    512     /* WARNING: *DONT* CHANGE THIS!!!!         */
#define PORTNAMELEN 6  /* ":31337" */

#define REALLEN         50
#define KILLLEN         90
#define CHANNELLEN      200 
#define REASONLEN       120
#define KICKLEN         160
#define AWAYLEN         160

/* 23+1 for \0 */
#define KEYLEN          24
#define OPERNICKLEN     NICKLEN*2 /* Length of OPERNICKs. */

#define USERHOST_REPLYLEN       (NICKLEN+HOSTLEN+USERLEN+5)

#define PLATFORMLEN     200     /* platform string used in info response */

#ifdef _WIN32
#define _UTSNAME_LENGTH 65
#define _UTSNAME_NODENAME_LENGTH _UTSNAME_LENGTH
#define _UTSNAME_DOMAIN_LENGTH _UTSNAME_LENGTH
struct utsname
{
  char sysname[_UTSNAME_LENGTH];
  char nodename[_UTSNAME_NODENAME_LENGTH];
  char release[_UTSNAME_LENGTH];
  char version[_UTSNAME_LENGTH];
  char machine[_UTSNAME_LENGTH];
  char domainname[_UTSNAME_DOMAIN_LENGTH];
};
int uname (struct utsname *);
#endif

#define REJECT_HOLD_TIME GlobalSetOptions.rejecttime

#endif /* INCLUDED_ircd_defs_h */
