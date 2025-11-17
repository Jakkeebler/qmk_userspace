// Copyright 2022 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// Serial communication settings
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1
#define SERIAL_USART_PIN_SWAP
#define USART_TX_PAL_MODE 2
#define USART_RX_PAL_MODE 2
#define SERIAL_USART_SPEED 921600

// RP2040 specific settings
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED_MASK 0U

// Pointing device configuration
#define POINTING_DEVICE_ROTATION_180_RIGHT
#define POINTING_DEVICE_ROTATION_90
#define POINTING_DEVICE_INVERT_X
#define POINTING_DEVICE_INVERT_Y
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_DEFAULT_LAYER 3
#define POINTING_DEVICE_TASK_THROTTLE_MS 1
#define PMW33XX_CS_PIN GP2
#define PMW33XX_CPI 2000

// SPI configuration for pointing device
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23

// Split pointing device configuration
#define SPLIT_POINTING_ENABLE
#define POINTING_DEVICE_COMBINED
#define POINTING_DEVICE_LEFT
#define POINTING_DEVICE_RIGHT

// OLED configuration
#ifdef OLED_ENABLE
#    define I2C_DRIVER I2CD1
#    define I2C1_SDA_PIN GP26
#    define I2C1_SCL_PIN GP27
#    define OLED_DISPLAY_128X32
#    define SPLIT_OLED_ENABLE
#    define OLED_TIMEOUT 32000
#    define OLED_FADE_OUT
#    define OLED_FADE_OUT_INTERVAL 8
#endif

// WPM calculation
#ifdef WPM_ENABLE
#    define SPLIT_WPM_ENABLE
#endif

// Mechanical locking support
#define LOCKING_SUPPORT_ENABLE
#define LOCKING_RESYNC_ENABLE

// Permissive hold for dual-function keys
#define PERMISSIVE_HOLD
