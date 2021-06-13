#include <stdlib.h>
#include "tomu.h"

#define COLR(x) x*4-21
#define INIT_EXT_PAIR(x) init_extended_pair(x, x, 0)



void tomu_init() {
	start_color();

	for(int i = 1; i <= TOMU_NUM_COLORS+1; i++) {
		INIT_EXT_PAIR(i);
	}

	init_extended_color(TOMU_COLOR_RED, COLR(255), COLR(50), COLR(50));
	init_extended_color(TOMU_COLOR_ORANGE, COLR(255), COLR(150), COLR(50));
	init_extended_color(TOMU_COLOR_YELLOW, COLR(255), COLR(255), COLR(50));
	init_extended_color(TOMU_COLOR_GREEN, COLR(50), COLR(255),COLR(50));
	init_extended_color(TOMU_COLOR_CYAN, COLR(50), COLR(240), COLR(255));
	init_extended_color(TOMU_COLOR_BLUE, COLR(50), COLR(120), COLR(255));
	init_extended_color(TOMU_COLOR_PURPLE, COLR(150), COLR(50), COLR(255));
	init_extended_color(TOMU_COLOR_PINK, COLR(255), COLR(50), COLR(120));
	init_extended_color(TOMU_COLOR_CUTE_PINK, COLR(255), COLR(120), COLR(200));
	init_extended_color(TOMU_COLOR_WHITE, COLR(255), COLR(255), COLR(255));
	init_extended_color(TOMU_COLOR_BLACK, COLR(20), COLR(20), COLR(20));
	init_extended_color(TOMU_COLOR_DARK, COLR(100), COLR(100), COLR(100));
	init_extended_color(TOMU_COLOR_DARK_2, COLR(50), COLR(50), COLR(50));
	init_extended_color(TOMU_COLOR_DIM_RED, COLR(190), COLR(80), COLR(80));
	init_extended_color(TOMU_COLOR_DIM_BLUE, COLR(80), COLR(80), COLR(140));
	init_extended_color(TOMU_COLOR_DIM_GREEN, COLR(80), COLR(150), COLR(80));
	init_extended_color(TOMU_COLOR_DIM_WHITE, COLR(200), COLR(200), COLR(200));
	init_extended_color(TOMU_COLOR_BROWN, COLR(180), COLR(110), COLR(80));
	assume_default_colors(COLOR_WHITE, COLOR_BLACK);
}

void tomu_bg(int color) {
	assume_default_colors(COLOR_WHITE, color);
}

void tomu_draw_box(WINDOW* win, int x, int y, int w, int h, char c, int color, int attr, int fill) {
	wattron(win, COLOR_PAIR(color) | attr);

	mvwvline(win, y, x,   c, h);
	mvwvline(win, y, x+w, c, h);
	mvwhline(win, y,     x+1, c, w-1);
	mvwhline(win, y+h-1, x+1, c, w-1);

	if(fill) {
		for(int i = y+1; i < y+h-1; i++) {
			mvwhline(win, i, x+1, c, w-1);
		}
	}

	wattroff(win, COLOR_PAIR(color) | attr);
}

void tomu_draw_line(WINDOW* win, int x0, int y0, int x1, int y1, char c, int color, int attr) {
	int width = x1-x0;
	int height = y1-y0;
	int dx0 = 0;
	int dy0 = 0;
	int dx1 = 0;
	int dy1 = 0;

	dx1 = dx0 = (width < 0) ? -1 : 1;
	dy0 = (height < 0) ? -1 : 1;

	int aw = abs(width);
	int ah = abs(height);
	int longest = aw;
	int shortest = ah;
    
	if(longest < shortest) {
		longest = ah;
		shortest = aw;
		dy1 = (height < 0) ? -1 : 1;
		dx1 = 0;
	}
	
	int numerator = longest >> 1;
	wattron(win, COLOR_PAIR(color) | attr);
	
	for(int i = 0; i < longest; i++) {
		mvwaddch(win, y0, x0, c);
		
		numerator += shortest;
		if(numerator > longest) {
			numerator -= longest;
			x0 += dx0;
			y0 += dy0;
		}
		else {
			x0 += dx1;
			y0 += dy1;
		}
	}
	
	wattroff(win, COLOR_PAIR(color) | attr);
}


