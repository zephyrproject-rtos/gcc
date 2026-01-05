/* GCC option-handling definitions for the Renesas RX processor.
   Copyright (C) 2008-2024 Free Software Foundation, Inc.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef RX_OPTS_H
#define RX_OPTS_H

enum rx_cpu_types
{
  RX13T,
  RX230,
  RX71M,
  RX72T,
  RX64M,
  RX600,
  RX610,
  RX66T,
  RX200,
  RX100,
  RX140,
  RX_CPUUNINIT
};
enum rx_tfu_versions
{
  RX_TFUV1,
  RX_TFUV2,
  RX_TFUVUNINIT
};
enum rx_isa_versions
{
  RX_ISAV1,
  RX_ISAV2,
  RX_ISAV3,
  RX_ISAUNINIT
};

enum rx_tfu_types
{
  RX_INTRINSIC,
  RX_MATHLIB,
  RX_TFUUNINIT
};

#endif
