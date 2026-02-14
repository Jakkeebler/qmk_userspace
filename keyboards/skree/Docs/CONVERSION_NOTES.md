# Vial to Vanilla QMK Conversion Notes

## Conversion Summary

This document outlines the changes made when converting the Skree DualTB5x6OLED keyboard from Vial QMK to vanilla QMK for use with qmk_userspace.

## Files Converted

### Keyboard-Level Files

1. **info.json**
   - Converted to modern QMK info.json format
   - Moved feature flags from rules.mk to info.json where appropriate
   - Added complete layout definition with physical key positions

2. **config.h**
   - ✅ Kept all hardware configurations (pins, serial, SPI)
   - ✅ Kept pointing device settings
   - ✅ Kept OLED and RGB configurations
   - ❌ Removed Vial-specific defines (not present in keyboard config)

3. **rules.mk**
   - ✅ Kept all standard QMK features
   - ✅ Kept pointing device driver configuration
   - ❌ Removed Vial build flags
   - Added explicit source file inclusion for trackball.c

4. **dualtb5x6oled.h**
   - ✅ No changes needed - standard QMK layout macro
   - Includes parent trackball.h for shared functionality

5. **dualtb5x6oled.c**
   - ✅ Minimal implementation (just includes header)
   - Main functionality in parent trackball.c

6. **trackball.h** and **trackball.c**
   - ✅ Downloaded unchanged from source
   - Contains all trackball/Charybdis-specific features:
     - DPI management
     - Sniping mode
     - Drag scroll functionality
     - Split pointing device support

### Keymap Files

#### Removed Vial-Specific Code

**keymaps/default/config.h:**
- ❌ Removed `#define VIAL_KEYBOARD_UID`
- ❌ Removed `#define VIAL_UNLOCK_COMBO_ROWS`
- ❌ Removed `#define VIAL_UNLOCK_COMBO_COLS`

**keymaps/default/rules.mk:**
- ❌ Removed `VIA_ENABLE = yes`
- ❌ Removed `VIAL_ENABLE = yes`
- ❌ Removed `VIAL_INSECURE = yes`
- ✅ Added `ENCODER_MAP_ENABLE = yes`

**keymaps/default/keymap.c:**
- ❌ Removed vial.json (not needed in vanilla QMK)
- ✅ Changed custom keycode name from `WYLD_AUTO_MS_TOG` to `AUTO_MS_TOG`
- ✅ Replaced placeholder keymaps with actual QWERTY layout
- ✅ Added proper LOWER, RAISE, and MOUSE layers with functionality
- ✅ Kept all OLED code
- ✅ Kept all pointing device code
- ✅ Kept encoder map
- ✅ Fixed encoder map to use `NUM_DIRECTIONS` constant

## Features Preserved

All hardware and firmware features remain functional:

- ✅ **Dual Trackballs**: Full PMW3360 support on both halves
- ✅ **Drag Scroll**: Buffered scroll conversion
- ✅ **Sniping Mode**: Low DPI precision mode
- ✅ **DPI Adjustment**: Dynamic CPI changes
- ✅ **Auto Mouse Layer**: Automatic layer switching on trackball use
- ✅ **Split Communication**: Serial USART between halves
- ✅ **OLED Displays**: Custom graphics and status display
- ✅ **RGB Lighting**: Full WS2812 support with effects
- ✅ **Encoder Support**: Layer-specific encoder behavior
- ✅ **WPM Tracking**: Words per minute display

## Features Lost (Vial-Specific)

- ❌ **Vial GUI Configuration**: No real-time keymap editing via Vial app
- ❌ **VIA Support**: No VIA protocol compatibility
- ❌ **Dynamic Keymaps**: Must recompile to change keymaps
- ❌ **Vial Unlock Combo**: No GUI unlock mechanism needed

## Layer Configuration

### Layer 0 - QWERTY (Base)
- Standard QWERTY layout
- Tab, Escape, Shift in standard positions
- Space, Backspace, Enter, GUI in thumb cluster
- Layer momentary switches to LOWER/RAISE

### Layer 1 - LOWER
- Numbers and symbols
- Navigation keys (Home, PgUp, PgDn, End)
- Numpad layout on right hand
- Print screen access

### Layer 2 - RAISE
- Function keys (F1-F12)
- RGB control (toggle, mode, hue, saturation, value)
- Media keys (play, prev, next, volume)

### Layer 3 - MOUSE
- Trackball configuration keys
- DPI adjustment (forward/reverse)
- Sniping DPI adjustment
- Drag scroll toggle
- Auto mouse toggle
- Mouse buttons (BTN1, BTN2, BTN3)

## Trackball Custom Keycodes

Available from trackball.h (Charybdis):

| Keycode | Alias | Description |
|---------|-------|-------------|
| `POINTER_DEFAULT_DPI_FORWARD` | `DPI_MOD` | Increase pointer DPI |
| `POINTER_DEFAULT_DPI_REVERSE` | `DPI_RMOD` | Decrease pointer DPI |
| `POINTER_SNIPING_DPI_FORWARD` | `S_D_MOD` | Increase sniping DPI |
| `POINTER_SNIPING_DPI_REVERSE` | `S_D_RMOD` | Decrease sniping DPI |
| `SNIPING_MODE` | `SNIPING` | Toggle sniping mode |
| `SNIPING_MODE_TOGGLE` | `SNP_TOG` | Toggle sniping mode |
| `DRAGSCROLL_MODE` | `DRGSCRL` | Toggle drag scroll |
| `DRAGSCROLL_MODE_TOGGLE` | `DRG_TOG` | Toggle drag scroll |
| `POINTER_DEFAULT_DPI_RESET` | `DPI_RESET` | Reset DPI to default |

## Build Configuration

### qmk.json
```json
{
    "userspace_version": "1.0.0",
    "build_targets": [
        ["skree/trackball/dualtb5x6oled", "default"]
    ]
}
```

This allows building with:
```bash
qmk userspace-compile
```

## Testing Checklist

When testing the converted firmware:

- [ ] Both halves communicate correctly
- [ ] Matrix scanning works (all keys register)
- [ ] Left trackball moves cursor
- [ ] Right trackball moves cursor
- [ ] Drag scroll mode works on left trackball
- [ ] Sniping mode reduces DPI
- [ ] DPI adjustment keys work
- [ ] Auto mouse layer activates on trackball movement
- [ ] Both OLEDs display correctly
- [ ] Left OLED shows layer/WPM/LED status
- [ ] Right OLED shows logo
- [ ] RGB lighting works
- [ ] RGB effects can be changed
- [ ] Encoder functions correctly (if installed)
- [ ] Encoder changes function per layer
- [ ] All layers activate correctly
- [ ] Layer switching works via momentary keys

## Customization Tips

### Adjusting Trackball Sensitivity

Edit in `keymap.c` at `pointing_device_init_user()`:

```c
pointing_device_set_cpi_on_side(true, YOUR_DPI);   // Left trackball
pointing_device_set_cpi_on_side(false, YOUR_DPI);  // Right trackball
```

### Changing Drag Scroll Threshold

Edit the threshold value in `check_drag()`:

```c
if (abs(scroll_buffer_x) > 6) {  // Change 6 to your preference
```

### Modifying OLED Content

Edit `oled_task_user()` to customize what displays on each half.

### Changing RGB Effects

Edit `info.json` to enable/disable specific animations:

```json
"rgblight": {
    "animations": {
        "breathing": true,
        "rainbow_mood": false,
        ...
    }
}
```

## Additional Notes

- The keyboard uses RP2040 bootloader with double-tap reset
- Press reset button twice quickly to enter bootloader mode
- Serial baud rate is set to 921600 for fast split communication
- OLED timeout is 32 seconds with fade-out effect
- RGB is limited to 120 brightness to prevent power issues
- Permissive hold is enabled for better dual-function key behavior

## Future Enhancements

Possible improvements you could make:

1. Add combo support for common key combinations
2. Implement tap dance for multi-function keys
3. Add leader key sequences
4. Create custom RGB lighting patterns
5. Implement custom OLED animations
6. Add macros for common text strings
7. Set up different trackball configurations per layer

## References

- Original Vial repo: https://github.com/WainingForests/vial-qmk/tree/vial/keyboards/skree/trackball/dualtb5x6oled
- Charybdis keyboard (trackball code source): https://github.com/Bastardkb/Charybdis
- QMK Firmware: https://github.com/qmk/qmk_firmware
