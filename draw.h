#ifndef DRAW_H
#define DRAW_H

void draw_line(int x0, int y0, int x1, int y1, screen s, color c);

double slope(int x0, int y0, int x1, int y1);

void octant1(int x0, int y0, int x1, int y1, screen s, color c);

void octant2(int x0, int y0, int x1, int y1, screen s, color c);

#endif
