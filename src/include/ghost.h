#ifndef ANIMATION_H
#define ANIMATION_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define ESC "\x1b"
#define MAX_LINE_LENGTH 256
#define MICROS_PER_FRAME 30000

#define COLOR_RESET "\x1b[0m"
#define COLOR_BLUE "\x1b[34m"

void enable_raw_mode(void);
void disable_raw_mode(void);
void get_terminal_size(int *rows, int *cols);
int kbhit(void);
void move_cursor(int row, int col);
void clear_line_to_end(void);

char **create_buffer(int height, int width);
void free_buffer(char **buffer, int height);

long long get_microseconds(void);

struct termios orig_termios;

#endif
