#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void draw_line(int x0, int y0, int x1, int y1, screen s, color c){
 if (x0 > x1){
    int tx = x0;
    int ty = y0;
    x0 = x1;
    y0 = y1;
    x1 = tx;
    y1 = ty;
  }
 if (x1 == x0){
	 octant2(x0, y0, x1, y1, s, c);
	 return;
 }
 double m = slope(x0, y0, x1, y1);
 if (m > 1)
	 octant2(x0, y0, x1, y1, s, c);
 else if (m > 0)
	 octant1(x0, y0, x1, y1, s, c);
 else if (m > -1)
	 octant8(x0, y0, x1, y1, s, c);
 else
	 octant7(x0, y0, x1, y1, s, c);

}

double slope(int x0, int y0, int x1, int y1){
	return (double)(y1 - y0) / (x1 - x0);
}

void octant1(int x0, int y0, int x1, int y1, screen s, color c){
	int x = x0; 
	int y = y0;
	int A = y1 - y0;
	int B = -(x1 - x0);
	int d = 2 * A + B; 
	while (x <= x1){
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
	int d = 2 * B + A; 
	while (y <= y1){
		plot(s, c, x, y);
		if (d < 0){
			x += 1;
			d += 2 * A;
		}
		y += 1;
		d += 2 * B;
	}
}

void octant7(int x0, int y0, int x1, int y1, screen s, color c){
	int x = x0;
	int y = y0;
	int A = y1 - y0;
	int B = -(x1 - x0);
	int d = A - 2 * B; 
	while (y >= y1){
		plot(s, c, x, y);
		if (d > 0){
			x += 1;
			d += 2 * A;
		}
		y -= 1;
		d -= 2 * B;
	}
}

void octant8(int x0, int y0, int x1, int y1, screen s, color c){
	int x = x0;
	int y = y0;
	int A = y1 - y0;
	int B = -(x1 - x0);
	int d = 2 * A - B; 
	while (x <= x1){
		plot(s, c, x, y);
		if (d < 0){
			y -= 1;
			d -= 2 * B;
		}
		x += 1;
		d += 2 * A;
	}
}

