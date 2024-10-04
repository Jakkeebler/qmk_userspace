// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include "quantum.h"
#include "arcboard_mk15.h"

// todo: what in here can be removed??

void          matrix_init_keymap(void);
void          matrix_scan_keymap(void);
layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);

#ifdef SPLIT_KEYBOARD
void matrix_slave_scan_keymap(void);
#endif
