/*
  fan_control.c - fan control methods
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

#include "grbl.h"


void fan_init()
{
  FAN_DDR |= (1 << FAN_BIT); // Configure as output pin
  fan_stop();
}


// Returns current fan output state. Overrides may alter it from programmed state.
uint8_t fan_get_state()
{
  uint8_t cl_state = FAN_STATE_DISABLE;
  if (bit_istrue(FAN_PORT,(1 << FAN_BIT))) {
    cl_state |= FAN_STATE_ENABLE;
  }
  return(cl_state);
}


// Directly called by fan_init(), fan_set_state(), and mc_reset(), which can be at
// an interrupt-level. No report flag set, but only called by routines that don't need it.
void fan_stop()
{
  FAN_PORT &= ~(1 << FAN_BIT);
}


// Main program only. Immediately sets fan running state,
// if enabled. Also sets a flag to report an update to a fan state.
// Called by fan toggle override, parking restore, parking retract, sleep mode, g-code
// parser program end, and g-code parser fan_sync().
void fan_set_state(uint8_t mode)
{
  if (sys.abort) { return; } // Block during abort.

	if (mode & FAN_ENABLE) {
		FAN_PORT |= (1 << FAN_BIT);
	} else {
		FAN_PORT &= ~(1 << FAN_BIT);
	}

  sys.report_ovr_counter = 0; // Set to report change immediately
}


// G-code parser entry-point for setting fan state. Forces a planner buffer sync and bails
// if an abort or check-mode is active.
void fan_sync(uint8_t mode)
{
  if (sys.state == STATE_CHECK_MODE) { return; }
  protocol_buffer_synchronize(); // Ensure fan turns on when specified in program.
  fan_set_state(mode);
}
