# Quick Start Guide

## Initial Setup (First Time Only)

```bash
# 1. Install QMK CLI
pip install qmk

# 2. Set up QMK (if not already done)
qmk setup

# 3. Navigate to this userspace directory
cd dualtb5x6oled_userspace

# 4. Configure QMK to use this as your userspace
qmk config user.overlay_dir="$(pwd)"
```

## Building Firmware

### Option 1: Using qmk.json build targets
```bash
qmk userspace-compile
```

### Option 2: Manual build command
```bash
qmk compile -kb skree/trackball/dualtb5x6oled -km default
```

## Flashing Firmware

### Option 1: Automatic flash
```bash
qmk flash -kb skree/trackball/dualtb5x6oled -km default
```

Then put your keyboard in bootloader mode (double-tap reset button).

### Option 2: Manual flash
1. Build the firmware (see above)
2. Put keyboard in bootloader mode (double-tap reset)
3. Copy the .uf2 file to the RPI-RP2 drive that appears

## Entering Bootloader Mode

The keyboard uses RP2040 with double-tap reset:
1. Press the reset button quickly
2. Press it again within 500ms
3. The keyboard will appear as a USB drive (RPI-RP2)

## Default Layout Reference

### Base Layer (QWERTY)
```
┌────┬────┬────┬────┬────┬────┐              ┌────┬────┬────┬────┬────┬────┐
│ `  │ 1  │ 2  │ 3  │ 4  │ 5  │              │ 6  │ 7  │ 8  │ 9  │ 0  │BSPC│
├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
│Tab │ Q  │ W  │ E  │ R  │ T  │              │ Y  │ U  │ I  │ O  │ P  │ -  │
├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
│Esc │ A  │ S  │ D  │ F  │ G  │              │ H  │ J  │ K  │ L  │ ;  │ '  │
├────┼────┼────┼────┼────┼────┤              ├────┼────┼────┼────┼────┼────┤
│Shft│ Z  │ X  │ C  │ V  │ B  │              │ N  │ M  │ ,  │ .  │ /  │Shft│
└────┴────┼────┼────┼────┼────┼────┐    ┌────┼────┼────┼────┼────┼────┴────┘
          │ [  │ ]  │Spc │Bspc│LOWR│    │RAIS│ Ent│ GUI│ +  │ =  │
          └────┴────┴────┴────┼────┤    ├────┼────┴────┴────┴────┘
                              │RAIS│    │LOWR│
                              └────┘    └────┘
```

### Trackball Controls (Mouse Layer)

**Left Side:**
- Drag Scroll Toggle
- Sniping Mode Toggle
- Auto Mouse Toggle

**Right Side:**
- DPI Reverse / DPI Forward
- Sniping DPI Reverse / Forward
- Drag Scroll Toggle
- Sniping Mode Toggle
- Mouse Buttons (Left, Right, Middle)

## Common Keycodes

### Layer Switching
- `LOWER` - Hold for Lower layer
- `RAISE` - Hold for Raise layer
- Mouse layer activates automatically on trackball movement

### Trackball Features
- `DPI_MOD` / `DPI_RMOD` - Adjust pointer speed
- `SNIPING` - Toggle precision mode
- `DRGSCRL` - Toggle scroll mode
- `AUTO_MS_TOG` - Toggle auto mouse layer

### RGB Lighting
- `RGB_TOG` - Toggle RGB on/off
- `RGB_MOD` - Next RGB effect
- `RGB_HUI/HUD` - Adjust hue
- `RGB_SAI/SAD` - Adjust saturation
- `RGB_VAI/VAD` - Adjust brightness

## Customizing Your Keymap

1. Edit the keymap file:
   ```
   keyboards/skree/trackball/dualtb5x6oled/keymaps/default/keymap.c
   ```

2. Find the layer you want to modify (e.g., `[_QWERTY]`)

3. Change keycodes in the layout

4. Rebuild and flash:
   ```bash
   qmk flash -kb skree/trackball/dualtb5x6oled -km default
   ```

## Troubleshooting

### "Unknown keyboard" error
- Check that `user.overlay_dir` is set correctly: `qmk config user.overlay_dir`
- Make sure you're in the right directory

### Trackballs not working
- Verify both halves are connected and powered
- Check that PMW3360 sensors are properly seated
- Try adjusting CPI values in `pointing_device_init_user()`

### OLEDs blank
- Verify I2C connections (GP26/GP27)
- Check that both OLEDs are properly connected
- Try power cycling the keyboard

### RGB not working
- Check WS2812 connection (GP8)
- Verify RGB is enabled: look for `RGB_TOG` in your keymap
- Try reducing brightness with `RGB_VAD`

### Split communication issues
- Check TRRS cable connection
- Verify both halves are powered
- Try a different TRRS cable
- Check serial pins (GP0/GP1)

## File Locations

| What | Where |
|------|-------|
| Main keymap | `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/keymap.c` |
| Keymap config | `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/config.h` |
| Keymap rules | `keyboards/skree/trackball/dualtb5x6oled/keymaps/default/rules.mk` |
| Keyboard config | `keyboards/skree/trackball/dualtb5x6oled/config.h` |
| Trackball features | `keyboards/skree/trackball/trackball.c` |
| Build output | `.build/` (created after first compile) |

## Next Steps

1. **Test all features** - Try each layer, trackballs, OLED, RGB
2. **Customize keymap** - Edit keymap.c to match your preferences
3. **Adjust trackball** - Fine-tune DPI and scroll sensitivity
4. **Configure RGB** - Set up your preferred lighting effects
5. **Read the docs** - Check README.md and CONVERSION_NOTES.md for details

## Getting Help

- QMK Documentation: https://docs.qmk.fm/
- QMK Discord: https://discord.gg/qmk
- This repo's README.md for detailed information
- CONVERSION_NOTES.md for technical details
