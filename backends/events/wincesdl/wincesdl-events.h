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

#ifndef BACKENDS_EVENTS_SDL_WINCE_H
#define BACKENDS_EVENTS_SDL_WINCE_H

#include "backends/events/sdl/sdl-events.h"

extern bool _isSmartphone;

class WINCESdlEventSource : public SdlEventSource {
public:
	WINCESdlEventSource();

	void loadDeviceConfiguration();

	// Overloaded from SDL backend (toolbar handling)
	bool pollEvent(Common::Event &event);
	// Overloaded from SDL backend (mouse and new scaler handling)
	void fillMouseEvent(Common::Event &event, int x, int y);

	void swap_freeLook();

protected:

private:
	int mapKeyCE(SDLKey key, SDLMod mod, Uint16 unicode, bool unfilter);

	// Keyboard tap
	int _tapX;
	int _tapY;
	long _tapTime;

	bool _closeClick;           // flag when taps are spatially close together
	bool _rbutton;              // double tap -> right button simulation
	bool _freeLook;             // freeLook mode (do not send mouse button events)

};

#endif /* BACKENDS_EVENTS_SDL_WINCE_H */