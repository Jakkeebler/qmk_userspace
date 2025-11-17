# QMK Userspace Complete Guide

This guide covers everything you need to know about using QMK Userspace for developing, compiling, and flashing your custom keyboards.

## Table of Contents
- [What is QMK Userspace?](#what-is-qmk-userspace)
- [Initial Setup](#initial-setup)
- [Building Firmware](#building-firmware)
- [Flashing Firmware](#flashing-firmware)
- [Developing Keyboards](#developing-keyboards)
- [Customizing Keymaps](#customizing-keymaps)
- [Advanced Features](#advanced-features)
- [Troubleshooting](#troubleshooting)
- [Reference](#reference)

---

## What is QMK Userspace?

QMK Userspace is a system that allows you to maintain your custom keyboards, keymaps, and configurations **outside** of the main QMK firmware repository. This means:

- ✅ No need to fork the entire QMK repository
- ✅ Easy to keep your customizations separate
- ✅ Can update QMK firmware without affecting your configs
- ✅ Simplified version control for your keyboards
- ✅ Works with GitHub Actions for automatic builds

### How It Works

```
qmk_firmware/              ← Main QMK repository
    keyboards/
    layouts/

qmk_userspace/             ← Your repository (this one!)
    keyboards/             ← Your custom keyboards
    layouts/               ← Your custom layouts
    users/                 ← Your user code

When you build:
    QMK overlays your userspace files ON TOP of qmk_firmware
    Your files take precedence!
```

---

## Initial Setup

### Step 1: Install QMK CLI

**Using pip:**
```bash
pip install qmk
```

**Using Python directly:**
```bash
python -m pip install qmk
```

**Verify installation:**
```bash
qmk --version
```

### Step 2: Run QMK Setup

This clones the main QMK firmware repository and sets up dependencies:

```bash
qmk setup
```

**What this does:**
- Clones `qmk/qmk_firmware` to `~/qmk_firmware` (or your chosen location)
- Installs required dependencies
- Sets up your QMK environment

**Choose your QMK location when prompted** (default is usually fine).

### Step 3: Configure Userspace

Navigate to this directory and set it as your userspace overlay:

```bash
cd "C:\Users\Jeron\Documents\Programming\Keyboard\qmk_userspace"
qmk config user.overlay_dir="$(realpath .)"
```

**Verify configuration:**
```bash
qmk config user.overlay_dir
```

Should show: `C:\Users\Jeron\Documents\Programming\Keyboard\qmk_userspace`

### Step 4: Verify Setup

```bash
qmk doctor
```

This checks that everything is installed correctly.

---

## Building Firmware

### Method 1: Build All Targets (Recommended)

Your `qmk.json` file defines which keyboards to build:

```bash
qmk userspace-compile
```

This builds everything in your `build_targets` list.

### Method 2: Build Specific Keyboard

```bash
qmk compile -kb <keyboard> -km <keymap>
```

**Examples:**
```bash
# Build the dualtb5x6oled with default keymap
qmk compile -kb skree/trackball/dualtb5x6oled -km default

# Build with a custom keymap
qmk compile -kb skree/trackball/dualtb5x6oled -km my_custom_layout
```

### Method 3: Using Make (Alternative)

```bash
make <keyboard>:<keymap>
```

**Examples:**
```bash
make skree/trackball/dualtb5x6oled:default
```

### Build Output

Compiled firmware is placed in:
```
.build/
```

For RP2040 boards (like dualtb5x6oled):
```
.build/skree_trackball_dualtb5x6oled_default.uf2
```

### Build Options

**Clean build:**
```bash
qmk clean
qmk compile -kb skree/trackball/dualtb5x6oled -km default
```

**Verbose output:**
```bash
qmk compile -kb skree/trackball/dualtb5x6oled -km default --verbose
```

**Parallel compilation:**
```bash
qmk compile -kb skree/trackball/dualtb5x6oled -km default -j 8
```

---

## Flashing Firmware

### Method 1: Auto-Flash (Easiest)

```bash
qmk flash -kb <keyboard> -km <keymap>
```

**Example:**
```bash
qmk flash -kb skree/trackball/dualtb5x6oled -km default
```

**Process:**
1. Firmware is compiled
2. QMK waits for bootloader
3. Put your keyboard in bootloader mode
4. Firmware automatically flashes

### Method 2: Manual Flash

**For RP2040 boards (like dualtb5x6oled):**

1. **Build the firmware:**
   ```bash
   qmk compile -kb skree/trackball/dualtb5x6oled -km default
   ```

2. **Enter bootloader mode:**
   - Press reset button twice quickly (within 500ms)
   - OR hold BOOT button while plugging in USB

3. **RP2040 appears as USB drive** (RPI-RP2)

4. **Copy the .uf2 file:**
   ```bash
   # Windows
   copy .build\skree_trackball_dualtb5x6oled_default.uf2 E:\

   # Linux/Mac
   cp .build/skree_trackball_dualtb5x6oled_default.uf2 /media/RPI-RP2/
   ```

5. **Keyboard reboots automatically** with new firmware

### Method 3: Flash Both Halves (Split Keyboards)

For split keyboards like the dualtb5x6oled, you need to flash both halves:

1. **Flash left half:**
   - Connect left half via USB
   - Enter bootloader mode
   - Flash firmware

2. **Flash right half:**
   - Connect right half via USB
   - Enter bootloader mode
   - Flash firmware

Both halves use the same firmware file!

### Entering Bootloader Mode

**RP2040 (dualtb5x6oled):**
- Double-tap reset button (within 500ms)
- Appears as USB drive: RPI-RP2

**ATmega32U4:**
- Press reset button
- OR use bootloader key combination in keymap

**STM32:**
- Hold BOOT button, press RESET
- OR use DFU mode

### Troubleshooting Flash Issues

**Keyboard not detected:**
```bash
# Check connected devices
qmk list-keyboards

# Check bootloader
qmk doctor
```

**Wrong bootloader:**
Check `rules.mk` for correct bootloader setting:
```makefile
BOOTLOADER = rp2040  # For RP2040 boards
```

---

## Developing Keyboards

### Directory Structure

```
keyboards/
└── your_manufacturer/
    └── your_keyboard/
        ├── config.h           # Hardware configuration
        ├── info.json          # Keyboard metadata
        ├── rules.mk           # Build rules and features
        ├── your_keyboard.h    # Layout macros
        ├── your_keyboard.c    # Keyboard implementation
        ├── readme.md          # Documentation
        └── keymaps/
            ├── default/
            │   ├── keymap.c   # Default keymap
            │   ├── config.h   # Keymap-specific config
            │   └── rules.mk   # Keymap-specific rules
            └── custom/
                └── ...
```

### Creating a New Keymap

**Using QMK CLI:**
```bash
qmk new-keymap -kb skree/trackball/dualtb5x6oled -km my_new_keymap
```

**Manually:**
1. Copy an existing keymap folder
2. Rename it
3. Edit `keymap.c`

### Adding a Keyboard to Build Targets

**Using QMK CLI:**
```bash
qmk userspace-add -kb skree/trackball/dualtb5x6oled -km default
```

**Manually edit qmk.json:**
```json
{
    "userspace_version": "1.0",
    "build_targets": [
        ["skree/trackball/dualtb5x6oled", "default"],
        ["planck/rev6", "my_layout"],
        ["crkbd/rev1", "default"]
    ]
}
```

### Removing from Build Targets

```bash
qmk userspace-remove -kb skree/trackball/dualtb5x6oled -km default
```

### Listing Build Targets

```bash
qmk userspace-list
```

---

## Customizing Keymaps

### Basic Keymap Structure

```c
#include QMK_KEYBOARD_H

// Define layers
#define _BASE 0
#define _LOWER 1
#define _RAISE 2

// Layer keys
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_5x6(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                          LOWER,   KC_SPC,  KC_BSPC, RAISE
    ),
    // More layers...
};
```

### Common Keycodes

**Basic Keys:**
- `KC_A` through `KC_Z` - Letters
- `KC_1` through `KC_0` - Numbers
- `KC_ENT` - Enter
- `KC_ESC` - Escape
- `KC_BSPC` - Backspace
- `KC_TAB` - Tab
- `KC_SPC` - Space

**Modifiers:**
- `KC_LSFT` / `KC_RSFT` - Shift
- `KC_LCTL` / `KC_RCTL` - Control
- `KC_LALT` / `KC_RALT` - Alt
- `KC_LGUI` / `KC_RGUI` - Windows/Command key

**Layer Keys:**
- `MO(layer)` - Momentary layer (hold)
- `TG(layer)` - Toggle layer
- `LT(layer, kc)` - Layer tap (hold for layer, tap for key)
- `TO(layer)` - Switch to layer

**Special:**
- `_______` - Transparent (use key from lower layer)
- `XXXXXXX` - Blocked (no key)
- `KC_TRNS` - Same as `_______`
- `KC_NO` - Same as `XXXXXXX`

### Modifier Keys

**Mod-Tap (MT):**
```c
// Tap for key, hold for modifier
MT(MOD_LSFT, KC_A)    // Shift when held, A when tapped
LSFT_T(KC_A)          // Same as above (shorthand)
LCTL_T(KC_ESC)        // Control when held, Escape when tapped
```

**One-Shot Modifiers:**
```c
OSM(MOD_LSFT)  // Next key will be shifted
OSL(_LOWER)    // Next key will be on LOWER layer
```

### Custom Keycodes

```c
enum custom_keycodes {
    MY_MACRO = SAFE_RANGE,
    MY_OTHER_KEY
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MY_MACRO:
            if (record->event.pressed) {
                SEND_STRING("Hello World!");
            }
            return false;
        default:
            return true;
    }
}
```

### Combos

Enable in `rules.mk`:
```makefile
COMBO_ENABLE = yes
```

Define in `keymap.c`:
```c
enum combos {
    JK_ESC
};

const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};

combo_t key_combos[] = {
    [JK_ESC] = COMBO(jk_combo, KC_ESC),
};
```

### Tap Dance

Enable in `rules.mk`:
```makefile
TAP_DANCE_ENABLE = yes
```

Define in `keymap.c`:
```c
enum {
    TD_ESC_CAPS
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_ESC_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

// Use in keymap:
TD(TD_ESC_CAPS)
```

---

## Advanced Features

### OLED Displays

Enable in `rules.mk`:
```makefile
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
```

Configure in `config.h`:
```c
#define OLED_DISPLAY_128X32
#define OLED_TIMEOUT 30000
```

Implement in `keymap.c`:
```c
#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Render layer info
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower\n"), false);
            break;
    }

    // Render WPM
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), ' '), false);

    return false;
}
#endif
```

### RGB Lighting

Enable in `rules.mk`:
```makefile
RGBLIGHT_ENABLE = yes
```

Configure in `info.json` or `config.h`:
```c
#define RGBLIGHT_LED_COUNT 58
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
```

Control with keycodes:
- `RGB_TOG` - Toggle on/off
- `RGB_MOD` / `RGB_RMOD` - Cycle effects
- `RGB_HUI` / `RGB_HUD` - Adjust hue
- `RGB_SAI` / `RGB_SAD` - Adjust saturation
- `RGB_VAI` / `RGB_VAD` - Adjust brightness

### Encoders

Enable in `rules.mk`:
```makefile
ENCODER_ENABLE = yes
ENCODER_MAP_ENABLE = yes
```

Define in `keymap.c`:
```c
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] = { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
};
#endif
```

### Pointing Devices (Trackballs/Trackpads)

Enable in `rules.mk`:
```makefile
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360  # or cirque_pinnacle_i2c, etc.
```

Configure in `config.h`:
```c
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 3
#define PMW33XX_CPI 2000
```

Custom handling:
```c
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    // Modify mouse report
    return mouse_report;
}
```

### Split Keyboards

Enable in `rules.mk`:
```makefile
SPLIT_KEYBOARD = yes
```

Configure in `config.h`:
```c
// Serial communication
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_SPEED 921600

// Hand detection
#define SPLIT_HAND_PIN GP28
// OR
#define EE_HANDS  // Store in EEPROM
```

### Macros

Simple macros:
```c
case MY_MACRO:
    if (record->event.pressed) {
        SEND_STRING("text to type");
    }
    return false;
```

Complex macros with delays:
```c
case MY_MACRO:
    if (record->event.pressed) {
        SEND_STRING("username");
        tap_code(KC_TAB);
        wait_ms(100);
        SEND_STRING("password");
        tap_code(KC_ENT);
    }
    return false;
```

### Leader Key

Enable in `rules.mk`:
```makefile
LEADER_ENABLE = yes
```

Configure in `config.h`:
```c
#define LEADER_TIMEOUT 300
#define LEADER_PER_KEY_TIMING
```

Use in `keymap.c`:
```c
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_F)) {
        SEND_STRING("Firefox");
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        SEND_STRING(SS_LCTL("c"));
    }
}
```

---

## Configuration Files

### config.h (Keyboard Level)

Hardware and feature configuration:

```c
#pragma once

// Matrix configuration
#define MATRIX_ROWS 10
#define MATRIX_COLS 6

// Pin configuration
#define MATRIX_COL_PINS { GP10, GP9, GP11, GP12, GP13, GP14 }
#define MATRIX_ROW_PINS { GP18, GP21, GP17, GP20, GP15 }
#define DIODE_DIRECTION COL2ROW

// Debouncing
#define DEBOUNCE 5

// USB settings
#define USB_POLLING_INTERVAL_MS 1

// OLED
#ifdef OLED_ENABLE
#    define OLED_DISPLAY_128X32
#    define OLED_TIMEOUT 32000
#endif

// RGB
#ifdef RGBLIGHT_ENABLE
#    define RGBLIGHT_LED_COUNT 58
#    define RGBLIGHT_MAX_BRIGHTNESS 120
#endif
```

### info.json (Keyboard Metadata)

Modern QMK uses `info.json` for most configuration:

```json
{
    "manufacturer": "Your Name",
    "keyboard_name": "My Keyboard",
    "maintainer": "your_github_username",
    "bootloader": "rp2040",
    "processor": "RP2040",
    "diode_direction": "COL2ROW",
    "features": {
        "bootmagic": true,
        "extrakey": true,
        "mousekey": true,
        "nkro": true,
        "rgblight": true
    },
    "matrix_pins": {
        "cols": ["GP10", "GP9", "GP11", "GP12", "GP13", "GP14"],
        "rows": ["GP18", "GP21", "GP17", "GP20", "GP15"]
    },
    "usb": {
        "device_version": "1.0.0",
        "pid": "0x0001",
        "vid": "0x1234"
    },
    "layouts": {
        "LAYOUT": {
            "layout": [
                {"matrix": [0, 0], "x": 0, "y": 0},
                {"matrix": [0, 1], "x": 1, "y": 0}
            ]
        }
    }
}
```

### rules.mk (Build Configuration)

Feature flags and compiler options:

```makefile
# MCU settings
MCU = RP2040
BOOTLOADER = rp2040

# Core features
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes

# Hardware features
RGBLIGHT_ENABLE = yes
OLED_ENABLE = yes
ENCODER_ENABLE = yes
POINTING_DEVICE_ENABLE = yes

# Drivers
OLED_DRIVER = ssd1306
POINTING_DEVICE_DRIVER = pmw3360
SERIAL_DRIVER = vendor

# Firmware size optimization
LTO_ENABLE = yes
```

---

## Troubleshooting

### Build Errors

**"Unknown keyboard":**
```bash
# Check userspace is configured
qmk config user.overlay_dir

# Should show your userspace path
# If not, set it:
qmk config user.overlay_dir="$(realpath .)"
```

**"Missing dependencies":**
```bash
qmk setup
```

**"Firmware too large":**
Add to `rules.mk`:
```makefile
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
```

Or disable features:
```makefile
RGBLIGHT_ENABLE = no
OLED_ENABLE = no
```

### Flash Errors

**Bootloader not detected:**
- Verify correct bootloader in `rules.mk`
- Check USB cable
- Try different USB port
- Manually enter bootloader mode

**Flash fails midway:**
- Bad USB cable
- Insufficient power
- Try with powered USB hub

### Runtime Issues

**Keys not working:**
- Check `MATRIX_ROWS` and `MATRIX_COLS`
- Verify pin configuration
- Check `DIODE_DIRECTION`
- Test with QMK Configurator test mode

**Split not communicating:**
- Check TRRS cable
- Verify serial pins
- Check handedness detection
- Flash both halves

**OLED blank:**
- Check I2C pins
- Verify OLED driver
- Check power connections

**RGB not working:**
- Verify data pin
- Check LED count
- Verify WS2812 driver
- Reduce brightness

---

## Reference

### Useful Commands

```bash
# Setup and configuration
qmk setup                    # Initial QMK setup
qmk config -a                # Show all config
qmk doctor                   # Check environment

# Userspace management
qmk config user.overlay_dir="$(realpath .)"
qmk userspace-add -kb <kb> -km <km>
qmk userspace-remove -kb <kb> -km <km>
qmk userspace-list
qmk userspace-compile

# Building
qmk compile -kb <kb> -km <km>
qmk compile -kb <kb> -km <km> --clean
qmk compile -kb <kb> -km <km> -j 8
qmk clean

# Flashing
qmk flash -kb <kb> -km <km>

# Information
qmk list-keyboards
qmk list-keymaps -kb <kb>
qmk info -kb <kb>
qmk info -kb <kb> -l        # Show layouts

# Utility
qmk new-keymap -kb <kb> -km <km>
qmk format-c <file>
qmk lint -kb <kb> -km <km>
```

### File Locations

| File | Location |
|------|----------|
| QMK Firmware | `~/qmk_firmware` (default) |
| Your Userspace | `user.overlay_dir` |
| Build output | `.build/` |
| QMK config | `~/.config/qmk/qmk.ini` |

### Important Links

- **QMK Documentation:** https://docs.qmk.fm/
- **QMK Configurator:** https://config.qmk.fm/
- **QMK Discord:** https://discord.gg/qmk
- **Keycodes Reference:** https://docs.qmk.fm/#/keycodes
- **GitHub Actions:** https://github.com/qmk/qmk_userspace

### Common Features Reference

| Feature | rules.mk | config.h Defines |
|---------|----------|-----------------|
| RGB Lighting | `RGBLIGHT_ENABLE = yes` | `RGBLIGHT_LED_COUNT` |
| RGB Matrix | `RGB_MATRIX_ENABLE = yes` | `RGB_MATRIX_LED_COUNT` |
| OLED | `OLED_ENABLE = yes` | `OLED_DISPLAY_128X32` |
| Encoders | `ENCODER_ENABLE = yes` | N/A |
| Pointing Device | `POINTING_DEVICE_ENABLE = yes` | `PMW33XX_CS_PIN` |
| Audio | `AUDIO_ENABLE = yes` | `AUDIO_PIN` |
| Split | `SPLIT_KEYBOARD = yes` | `SOFT_SERIAL_PIN` |
| Tap Dance | `TAP_DANCE_ENABLE = yes` | N/A |
| Combos | `COMBO_ENABLE = yes` | `COMBO_COUNT` |
| Leader | `LEADER_ENABLE = yes` | `LEADER_TIMEOUT` |

---

## Tips and Best Practices

### Development Workflow

1. **Make small changes** - Test one feature at a time
2. **Use version control** - Commit working configurations
3. **Test thoroughly** - Flash to actual hardware
4. **Document changes** - Comment your code
5. **Keep backups** - Save working .uf2 files

### Performance Optimization

```makefile
# Reduce firmware size
LTO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no

# Faster scanning
DEBOUNCE = 5  # Lower = faster, less reliable

# USB polling
USB_POLLING_INTERVAL_MS = 1  # Lower = more responsive
```

### Battery-Powered Keyboards

```makefile
# Reduce power consumption
SLEEP_LED_ENABLE = yes
RGBLIGHT_MAX_BRIGHTNESS = 120  # Lower brightness
OLED_TIMEOUT = 30000  # Turn off OLED
```

### Debugging

Enable in `rules.mk`:
```makefile
CONSOLE_ENABLE = yes
```

Use in code:
```c
#include "print.h"

void keyboard_post_init_user(void) {
    debug_enable = true;
    debug_matrix = true;
}

// Print debug info
uprintf("Value: %d\n", some_value);
dprintf("Debug: %s\n", "message");
```

View output with QMK Toolbox or `hid_listen`.

---

## Quick Reference for dualtb5x6oled

### Build & Flash
```bash
cd "C:\Users\Jeron\Documents\Programming\Keyboard\qmk_userspace"
qmk flash -kb skree/trackball/dualtb5x6oled -km default
```

### Enter Bootloader
- Double-tap reset button (within 500ms)
- Appears as RPI-RP2 USB drive

### Features
- Dual PMW3360 trackballs
- 128x32 OLEDs on both halves
- 58 RGB LEDs (29 per side)
- Encoder support
- Split via serial (921600 baud)

### Custom Keycodes
- `DPI_MOD` / `DPI_RMOD` - Adjust pointer DPI
- `SNIPING` - Toggle sniping mode
- `DRGSCRL` - Toggle drag scroll
- `AUTO_MS_TOG` - Toggle auto mouse layer

### Files to Edit
- Keymap: `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/keymap.c`
- Config: `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/config.h`
- Rules: `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/rules.mk`

---

*Last updated: 2025-11-17*
