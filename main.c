#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {
  screen s;
  color c;
 
	c.red = 0;
	c.green = 0;
	c.blue = MAX_COLOR;
  
  clear_screen(s);

	int i;
	for (i = 1; i < XRES; i++){
		draw_line(XRES / 2, YRES / 2, XRES % i, i, s, c);
		draw_line(XRES / 2, YRES / 2, i, YRES % i, s, c);
		draw_line(XRES / 2, YRES / 2, XRES - XRES % i, YRES - i, s, c);
		draw_line(XRES / 2, YRES / 2, XRES - i, YRES - YRES % i, s, c);
		c.red = (c.red + 1) % MAX_COLOR;
	}

	save_extension(s, "lines.png");
	display(s);
	
	return 0;
}  
