/*
This file is part of yvEncryptedChat
yvEncryptedChat is an IM program that provides secure chats. 
Copyright (C) 2016  yvbbrjdr

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef ECHO_H
#define ECHO_H

#include "../plugin.h"

class Echo : public QObject,public Plugin {
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "Echo")
    Q_INTERFACES(Plugin)
public:
    Echo();
    void Init(PluginManager *manager);
    void Destroy(PluginManager *manager);
};

#endif // ECHO_H
