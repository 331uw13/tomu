#ifndef TOMU_H
#define TOMU_H

#include <ncurses.h>


#define TOMU_COLOR_RED       1
#define TOMU_COLOR_ORANGE    2
#define TOMU_COLOR_YELLOW    3
#define TOMU_COLOR_GREEN     4
#define TOMU_COLOR_CYAN      5
#define TOMU_COLOR_BLUE      6
#define TOMU_COLOR_PURPLE    7
#define TOMU_COLOR_PINK      8
#define TOMU_COLOR_CUTE_PINK 9   // uwu
#define TOMU_COLOR_WHITE     10
#define TOMU_COLOR_BLACK     11
#define TOMU_COLOR_DARK      12
#define TOMU_COLOR_DARK_2    13  // darker dark color.. idk? lol.
#define TOMU_COLOR_DIM_RED   14
#define TOMU_COLOR_DIM_BLUE  15
#define TOMU_COLOR_DIM_GREEN 16
#define TOMU_COLOR_DIM_WHITE 17
#define TOMU_COLOR_BROWN     18

#define TOMU_NUM_COLORS  18


void tomu_init();

void tomu_bg(int color);
void tomu_draw_box  (WINDOW* win, int x,  int y,  int w,  int h,  char c, int color, int attr, int fill);
void tomu_draw_line (WINDOW* win, int x0, int y0, int x1, int y1, char c, int color, int attr);







#endif
