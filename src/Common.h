/******************************************************************************
 **  Copyright (c) Raoul Hecky. All Rights Reserved.
 **
 **  Calaos is free software; you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation; either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Calaos is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Foobar; if not, write to the Free Software
 **  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 **
 ******************************************************************************/
#ifndef COMMON_H
#define COMMON_H

#include <QtCore>

#define MOOLTIPASS_VENDORID     0x16D0
#define MOOLTIPASS_PRODUCTID    0x09A0

#define qToChar(s) s.toLocal8Bit().constData()
#define qToUtf8(s) s.toUtf8().constData()

class Common
{
public:
    static void installMessageOutputHandler();

    Q_ENUMS(MPStatus)
    typedef enum
    {
        NoCardInserted = 0,
        Locked = 1,
        LockedScreen = 3,
        Unlocked = 5,
        UnkownSmartcad = 9,
    } MPStatus;
    QHash<MPStatus, QString> MPStatusString = {
        { NoCardInserted, QObject::tr("No card inserted") },
        { Locked, QObject::tr("Mooltipass locked") },
        { LockedScreen, QObject::tr("Mooltipass locked, unlocking screen") },
        { Unlocked, QObject::tr("Mooltipass unlocked") },
        { UnkownSmartcad, QObject::tr("Unknown smartcard inserted") }
    };
};

Q_DECLARE_METATYPE(Common::MPStatus)

#endif // COMMON_H
