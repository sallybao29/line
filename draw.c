#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
 if (x0 > x1){
    int tx = x0;
    int ty = y0;
    x0 = x1;
    y0 = y1;
    x1 = tx;
    y1 = ty;
  }
 int dx = x1 - x0;
 int dy = y1 - y0;
}

void octant1(int x0, int y0, int x1, int y1, screen s, color c){
	int x = x0;
	int y = y0;
	int A = y1 - y0;
	int B = -(x1 - x0);
	int d = 2 * A + B;
	while(x <= x1){
		plot(s, c, x, y);
		if (d > 0){
			y += 1;
			d += 2 * B;
		}
		x += 1;
		d += 2 * A;
	}
}

void octant2(int x0, int y0, int x1, int y1, screen s, color c){
	int x = x0;
	int y = y0;
	int A = y1 - y0;
	int B = -(x1 - x0);
	int d = 2 * A + B;
	while(y <= y1){
		plot(s, c, x, y);
		if (d < 0){
			x += 1;
			d += 2 * A;
		}
		y += 1;
		d += 2 * B;
	}
}
