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
}

void octant1(int x0, int y0, int x1, int y1, screen s, color c){
  int x = x0;
  int y = y0;
}

