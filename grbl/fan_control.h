/*
  fan_control.h - spindle control methods
  Part of Grbl

  Copyright (c) 2021 Leonardo Figueiro

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef fan_control_h
#define fan_control_h

#define FAN_NO_SYNC     false
#define FAN_FORCE_SYNC  true

#define FAN_STATE_DISABLE   0  // Must be zero
#define FAN_STATE_ENABLE    PL_COND_FLAG_FAN

// Initializes fan control pins.
void fan_init();

// Returns current fan output state. Overrides may alter it from programmed state.
uint8_t fan_get_state();

// Immediately disables fan pins.
void fan_stop();

// Sets the fan pins according to state specified.
void fan_set_state(uint8_t mode);

// G-code parser entry-point for setting fan states. Checks for and executes additional conditions.
void fan_sync(uint8_t mode);

#endif
