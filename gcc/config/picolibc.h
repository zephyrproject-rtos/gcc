/* Configuration common to all targets running Picolibc.
   Copyright (C) 2023 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   Under Section 7 of GPL version 3, you are granted additional
   permissions described in the GCC Runtime Library Exception, version
   3.1, as published by the Free Software Foundation.

   You should have received a copy of the GNU General Public License and
   a copy of the GCC Runtime Library Exception along with this program;
   see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
   <http://www.gnu.org/licenses/>.  */

#ifdef IN_GPP
#define PICOLIBC_LD "picolibcpp.ld"
#define PICOLIBC_BEGIN " crtbegin%O%s"
#define PICOLIBC_END   "crtend%O%s"
#else
#define PICOLIBC_LD "picolibc.ld"
#define PICOLIBC_BEGIN ""
#define PICOLIBC_END   ""
#endif

#undef  LIB_SPEC
#define LIB_SPEC "%{!T:-T" PICOLIBC_LD "} --start-group -lc %{-oslib=*:-l%*} %(libgcc) --end-group"

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "%{-crt0=*:crt0-%*%O%s; :crt0%O%s}" PICOLIBC_BEGIN

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC PICOLIBC_END

#define EH_TABLES_CAN_BE_READ_ONLY 1
