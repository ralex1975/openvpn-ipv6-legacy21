/*
 *  TAP-Win32 -- A kernel driver to provide virtual tap device functionality
 *               on Windows.  Originally derived from the CIPE-Win32
 *               project by Damion K. Wilson, with extensive modifications by
 *               James Yonan.
 *
 *  All source code which derives from the CIPE-Win32 project is
 *  Copyright (C) Damion K. Wilson, 2003, and is released under the
 *  GPL version 2 (see below).
 *
 *  All other source code is Copyright (C) James Yonan, 2003-2004,
 *  and is released under the GPL version 2 (see below).
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
 *  along with this program (see the file COPYING included with this
 *  distribution); if not, write to the Free Software Foundation, Inc.,
 *  59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

//===============================================
// This file is included both by OpenVPN and
// the TAP-Win32 driver and contains definitions
// common to both.
//===============================================

//=============
// TAP IOCTLs
//=============

#define TAP_CONTROL_CODE(request,method) \
  CTL_CODE (FILE_DEVICE_PHYSICAL_NETCARD | 8000, \
            request, method, FILE_ANY_ACCESS)

#define TAP_IOCTL_GET_LASTMAC           TAP_CONTROL_CODE (0, METHOD_BUFFERED)
#define TAP_IOCTL_GET_MAC               TAP_CONTROL_CODE (1, METHOD_BUFFERED)
#define TAP_IOCTL_SET_STATISTICS        TAP_CONTROL_CODE (2, METHOD_BUFFERED)
#define TAP_IOCTL_GET_VERSION           TAP_CONTROL_CODE (3, METHOD_BUFFERED)
#define TAP_IOCTL_GET_MTU               TAP_CONTROL_CODE (4, METHOD_BUFFERED)
#define TAP_IOCTL_GET_INFO              TAP_CONTROL_CODE (5, METHOD_BUFFERED)
#define TAP_IOCTL_CONFIG_POINT_TO_POINT TAP_CONTROL_CODE (6, METHOD_BUFFERED)
#define TAP_IOCTL_SET_MEDIA_STATUS      TAP_CONTROL_CODE (7, METHOD_BUFFERED)
#define TAP_IOCTL_CONFIG_DHCP_MASQ      TAP_CONTROL_CODE (8, METHOD_BUFFERED)
#define TAP_IOCTL_GET_LOG_LINE          TAP_CONTROL_CODE (9, METHOD_BUFFERED)
#define TAP_IOCTL_CONFIG_DHCP_SET_OPT   TAP_CONTROL_CODE (10, METHOD_BUFFERED)

//=================
// Registry keys
//=================

#define NETCARD_REG_KEY_2000 "SYSTEM\\CurrentControlSet\\Control\\Class\\{4D36E972-E325-11CE-BFC1-08002BE10318}"

#define NETCARD_REG_KEY      "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\NetworkCards"

#define REG_SERVICE_KEY      "SYSTEM\\CurrentControlSet\\Services"

#define REG_CONTROL_NET      "SYSTEM\\CurrentControlSet\\Control\\Network\\{4D36E972-E325-11CE-BFC1-08002BE10318}"

//======================
// Filesystem prefixes
//======================

#define USERMODEDEVICEDIR "\\\\.\\"
#define SYSDEVICEDIR      "\\Device\\"
#define USERDEVICEDIR     "\\??\\"
#define TAPSUFFIX         ".tap"