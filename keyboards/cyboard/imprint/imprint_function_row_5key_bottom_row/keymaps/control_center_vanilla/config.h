#pragma once

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// Keyboard-level sets 1ms (1000Hz) which saturates the split serial link.
// 20ms (50Hz) is plenty smooth for trackball cursor movement and halves
// the pointing transaction rate vs 10ms, reducing blinks during trackball use.
#undef POINTING_DEVICE_TASK_THROTTLE_MS
#define POINTING_DEVICE_TASK_THROTTLE_MS 33

// Boost split serial speed for more timing margin.
#define SERIAL_USART_SPEED 921600
