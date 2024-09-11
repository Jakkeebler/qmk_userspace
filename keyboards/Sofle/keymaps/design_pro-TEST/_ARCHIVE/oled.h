#pragma once

// OLED Function Prototypes
void render_logo(void);
void render_qwerty(void);
void render_illstr(void);
void render_funct(void);
void render_lfthand(void);

void print_status_logo(void);
oled_rotation_t oled_init_user(oled_rotation_t rotation);
bool oled_task_user(void);
