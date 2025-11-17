# MCU name
MCU = RP2040
BOOTLOADER = rp2040

# Split keyboard
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = vendor

# Features
BOOTMAGIC_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
NKRO_ENABLE = yes

# RGB Lighting
RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor
SLEEP_LED_ENABLE = no

# OLED Display
OLED_ENABLE = yes
OLED_DRIVER = ssd1306
OLED_TRANSPORT = i2c

# WPM tracking
WPM_ENABLE = yes

# Encoder (disabled by default, enable in keymap if needed)
ENCODER_ENABLE = no
ENCODER_MAP_ENABLE = no

# Pointing device
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pmw3360

# I2C for OLED
OPT_DEFS += -DHAL_USE_I2C=TRUE

# Source files
SRC += keyboards/skree/trackball/trackball.c
