/* locatedb.h -- declarations for the locate database
   Copyright (C) 1994 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef _LOCATEDB_H
#define _LOCATEDB_H 1

/* The magic string at the start of a locate database, to make sure
   it's in the right format.  The 02 is the database format version number.
   This string has the same format as a database entry, but you can't
   concatenate databases even if you remove it, since the differential count
   in the first entry of the second database will be wrong.  */
#define LOCATEDB_MAGIC "\0LOCATE02"

/* Common-prefix length differences in the ranges
   0..127, -127..-1 (0x00..0x7f, 0x81..0xff) fit into one byte.
   This value (which is -128) indicates that the difference is
   too large to fit into one byte, and a two-byte integer follows.  */
#define	LOCATEDB_ESCAPE 0x80

/* These are used for old, bigram-encoded databases:  */

/* Means the differential count follows in a 2-byte int instead. */
#define	LOCATEDB_OLD_ESCAPE	30

/* Offset added to differential counts to encode them as positive numbers.  */
#define	LOCATEDB_OLD_OFFSET	14

#endif /* !_LOCATEDB_H */
