#pragma once
#include <math.h>
#include <cstdarg>
typedef struct { float x, y; } vec;
typedef struct { vec p0, p1, dir; } seg;
typedef struct { int n; vec *vertices; seg *edges; } polygon; // Assumption: Simply connected => chain vertices together

vec v(float x, float y);
float dot(vec a, vec b);
float distance_line_point(vec l1, vec l2, vec p);
vec normalize(vec v);
vec project(vec input, vec onto);
vec perp(vec v);
seg segment(vec p0, vec p1);
polygon new_polygon(int nvertices, vec *vertices);
polygon Polygon(int nvertices, ...);
void breakdown_polygon(polygon* p);
float* project(polygon a, vec axis);
int contains(float n, float* range);
int overlap(float* a_, float* b_);
bool sat(polygon a, polygon b);