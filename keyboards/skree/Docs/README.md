# Skree DualTB5x6OLED - QMK Userspace

This is a vanilla QMK conversion of the Skree Custom DualTB5x6OLED keyboard, originally configured for Vial QMK.

## Features

- **Dual PMW3360 Trackballs**: Left and right trackball support with independent CPI settings
- **Drag Scroll Mode**: Convert trackball movement to scroll wheel functionality
- **Sniping Mode**: Lower DPI mode for precise pointer control
- **OLED Displays**: 128x32 OLEDs on both halves showing layer status, WPM, and logo
- **RGB Lighting**: 58 WS2812 LEDs (29 per half) with multiple effects
- **Split Keyboard**: Serial communication between halves via RP2040
- **Auto Mouse Layer**: Automatically switch to mouse layer on trackball movement
- **Encoder Support**: Optional encoder with layer-specific functionality

## Keyboard Specifications

- **MCU**: RP2040
- **Matrix**: 10 rows × 6 columns (5×6 per half)
- **Split**: Serial USART at 921600 baud
- **Bootloader**: RP2040 with double-tap reset
- **Layout**: 60 keys in ergonomic split configuration

## Setup Instructions

### 1. Install QMK CLI

```bash
python3 -m pip install --user qmk
```

### 2. Set Up QMK Userspace

```bash
# Clone your userspace repository (this directory)
# Navigate to your userspace directory
cd dualtb5x6oled_userspace

# Set QMK userspace path
qmk config user.overlay_dir="$(pwd)"
```

### 3. Compile the Firmware

```bash
qmk compile -kb skree/trackball/dualtb5x6oled -km default
```

Or using the build targets defined in qmk.json:

```bash
qmk userspace-compile
```

### 4. Flash the Firmware

```bash
qmk flash -kb skree/trackball/dualtb5x6oled -km default
```

## Customization

### Editing Your Keymap

The keymap is located at:
```
keyboards/skree/trackball/dualtb5x6oled/keymaps/default/keymap.c
```

Edit this file to customize your key layout, layers, and functionality.

### Layer Definitions

- **Layer 0 (_QWERTY)**: Base QWERTY layout
- **Layer 1 (_LOWER)**: Numbers, symbols, and navigation
- **Layer 2 (_RAISE)**: Function keys and media controls
- **Layer 3 (_MOUSE)**: Trackball controls, DPI adjustment, and sniping mode

### Trackball Features

#### Custom Keycodes

The keyboard includes these trackball-specific keycodes from `trackball.h`:

- `DPI_MOD` / `DPI_RMOD`: Cycle pointer DPI up/down
- `S_D_MOD` / `S_D_RMOD`: Cycle sniping DPI up/down
- `SNIPING`: Toggle sniping mode (lower DPI for precision)
- `DRGSCRL`: Toggle drag scroll mode
- `DPI_RESET`: Reset DPI to default
- `AUTO_MS_TOG`: Toggle auto mouse layer

#### Trackball Configuration

Left trackball is configured for drag-scroll at `CHARYBDIS_DRAGSCROLL_DPI` (defined in trackball.c).
Right trackball is set to 2000 CPI.

You can adjust these in `pointing_device_init_user()` in your keymap.

### RGB Lighting

RGB lighting is enabled with these effects:
- Breathing
- Rainbow Mood
- Rainbow Swirl
- Snake
- Knight
- Christmas
- Static Gradient
- RGB Test
- Alternating
- Twinkle

Control RGB with keycodes like `RGB_TOG`, `RGB_MOD`, `RGB_HUI`, etc.

### OLED Displays

- **Left OLED**: Shows current layer, WPM, and keyboard LED status
- **Right OLED**: Displays custom logo with scrolling effect

Customize the OLED display in the `oled_task_user()` function.

## Key Differences from Vial Version

This conversion removes Vial-specific features:

- ❌ No Vial GUI configuration support
- ❌ No dynamic keymap loading via Vial
- ❌ Removed `VIAL_ENABLE`, `VIA_ENABLE`, `VIAL_INSECURE`
- ❌ Removed `VIAL_KEYBOARD_UID` and unlock combo configuration

All other features (trackballs, OLEDs, RGB, encoders) work identically.

## File Structure

```
dualtb5x6oled_userspace/
├── qmk.json                              # Userspace configuration
├── README.md                             # This file
└── keyboards/
    └── skree/
        └── trackball/
            ├── trackball.h                # Trackball feature header
            ├── trackball.c                # Trackball feature implementation
            └── dualtb5x6oled/
                ├── config.h               # Keyboard configuration
                ├── info.json              # Keyboard metadata
                ├── rules.mk               # Build rules
                ├── dualtb5x6oled.h        # Layout definition
                ├── dualtb5x6oled.c        # Keyboard source
                └── keymaps/
                    └── default/
                        ├── keymap.c       # Your keymap
                        ├── config.h       # Keymap config
                        └── rules.mk       # Keymap rules
```

## Troubleshooting

### Compilation Errors

If you encounter compilation errors:

1. Make sure QMK firmware is up to date: `qmk update`
2. Verify your userspace path: `qmk config user.overlay_dir`
3. Check that all required files are present

### Pointing Device Issues

If trackballs aren't working:

1. Verify SPI pins in `config.h` match your hardware
2. Check `POINTING_DEVICE_COMBINED` is enabled
3. Ensure `pointing_device_driver = pmw3360` in `rules.mk`

### OLED Not Working

1. Verify I2C pins (`GP26` and `GP27`) are correct
2. Check `OLED_ENABLE = yes` in `rules.mk`
3. Ensure `OLED_DRIVER = ssd1306`

## Resources

- [QMK Documentation](https://docs.qmk.fm/)
- [QMK Userspace Guide](https://docs.qmk.fm/#/newbs_external_userspace)
- [Pointing Device Documentation](https://docs.qmk.fm/#/feature_pointing_device)
- [OLED Driver Documentation](https://docs.qmk.fm/#/feature_oled_driver)
- [Split Keyboard Documentation](https://docs.qmk.fm/#/feature_split_keyboard)

## License

This firmware is based on QMK Firmware and inherits the GPL-2.0-or-later license.

The trackball code is adapted from the Charybdis keyboard by Christopher Courtney (Drashna Jael're).
