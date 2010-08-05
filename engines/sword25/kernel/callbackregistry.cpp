/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * $URL$
 * $Id$
 *
 */

/* 
 * This code is based on Broken Sword 2.5 engine
 *
 * Copyright (c) Malte Thiesen, Daniel Queteschiner and Michael Elsdoerfer
 *
 * Licensed under GNU GPL v2
 *
 */

// Alle Callbackfunktionen die von Objekten gerufen werden, die persistiert werden k�nnen, m�ssen hier registriert werden.
// Beim Speichern wird statt des Pointers der Bezeichner gespeichert. Beim Laden wird der Bezeichner wieder in einen Pointer umgewandelt.
// Diese Klasse f�hrt also so etwas �hnliches wie eine Importtabelle f�r Callback-Funktionen.
//
// Dieses Vorgehen hat mehrere Vorteile:
// 1. Die Speicherst�nde sind plattformunabh�ngig. Es werden keine Pointer auf Funktionen gespeichert, sondern nur Namen von Callbackfunktionen.
//	  Diese k�nnen beim Laden �ber diese Klasse in systemabh�ngige Pointer umgewandelt werden.
// 2. Speicherst�nde k�nnen auch nach einem Engineupdate weiterhin benutzt werden. Beim Erstellen einer neun Binary verschieben sich h�ufig die
//	  Funktionen. Eine Callbackfunktion k�nnte sich also nach einem Update an einer anderen Stelle befinden als davor. Wenn im Spielstand der
//	  Pointer gespeichert war, st�rtzt das Programm beim �ufrufen dieser Callbackfunktion ab. Durch das Aufl�sungverfahren wird beim Laden der
//	  Callbackbezeichner in den neuen Funktionspointer umgewandelt und der Aufruf kann erfolgen.

// -----------------------------------------------------------------------------
// Logging
// -----------------------------------------------------------------------------

#define BS_LOG_PREFIX "CALLBACKREGISTRY"

// -----------------------------------------------------------------------------
// Includes
// -----------------------------------------------------------------------------

#include "sword25/kernel/callbackregistry.h"

namespace Sword25 {

// -----------------------------------------------------------------------------

bool BS_CallbackRegistry::RegisterCallbackFunction(const Common::String &Name, CallbackPtr Ptr) {
	if (Name == "") {
		BS_LOG_ERRORLN("The empty string is not allowed as a callback function name.");
		return false;
	}

	if (FindPtrByName(Name) != 0) {
		BS_LOG_ERRORLN("There is already a callback function with the name \"%s\".", Name.c_str());
		return false;
	}
	if (FindNameByPtr(Ptr) != "") {
		BS_LOG_ERRORLN("There is already a callback function with the pointer 0x%x.", Ptr);
		return false;
	}

	StoreCallbackFunction(Name, Ptr);
	
	return true;
}

// -----------------------------------------------------------------------------

CallbackPtr BS_CallbackRegistry::ResolveCallbackFunction(const Common::String &Name) const {
	CallbackPtr Result = FindPtrByName(Name);

	if (!Result) {
		BS_LOG_ERRORLN("There is no callback function with the name \"%s\".", Name.c_str());
	}

	return Result;
}

// -----------------------------------------------------------------------------

Common::String BS_CallbackRegistry::ResolveCallbackPointer(CallbackPtr Ptr) const {
	const Common::String &Result = FindNameByPtr(Ptr);

	if (Result == "") {
		BS_LOG_ERRORLN("There is no callback function with the pointer 0x%x.", Ptr);
	}

	return Result;
}

// -----------------------------------------------------------------------------

CallbackPtr BS_CallbackRegistry::FindPtrByName(const Common::String &Name) const {
	// Eintrag in der Map finden und den Pointer zur�ckgeben.
	NameToPtrMap::const_iterator It = m_NameToPtrMap.find(Name);
	return It == m_NameToPtrMap.end() ? 0 : It->_value;
}

// -----------------------------------------------------------------------------

Common::String BS_CallbackRegistry::FindNameByPtr(CallbackPtr Ptr) const {
	// Eintrag in der Map finden und den Namen zur�ckgeben.
	PtrToNameMap::const_iterator It = m_PtrToNameMap.find(Ptr);
	return It == m_PtrToNameMap.end() ? "" : It->second;
}

// -----------------------------------------------------------------------------

void BS_CallbackRegistry::StoreCallbackFunction(const Common::String &Name, CallbackPtr Ptr) {
	// Callback-Funktion in beide Maps eintragen.
	m_NameToPtrMap[Name] = Ptr;
	m_PtrToNameMap[Ptr] = Name;
}

} // End of namespace Sword25
