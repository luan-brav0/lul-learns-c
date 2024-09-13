#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

#define X_MAX 320
#define Y_MAX 200
#define Min(a, b) ((a) < (b) ? (a) : (b))
#define Max(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int x;
    int y;
} Point;

typedef struct {
    Point botLeft;
    Point topRight;
} Rectangle;

const Point origin = { 0, 0 };

const Point maxPoints = { X_MAX, Y_MAX};

const Rectangle screen = { origin, maxPoints };

double distance(Point* p1, Point* p2) {
    Point diff = { p2->x - p1->x, p2->y - p1->y };
    return sqrt(((double)diff.x*diff.x) + ((double)diff.y*diff.y));
}

void sumPoints(Point* p1, Point* p2) {
    p1->x += p2->x;
    p1->y += p2->y;
    return;
}

bool isInRectangle(Point* p, Rectangle* r) {
    return p->x > r->botLeft.x && p->x < r->topRight.x
        && p->y > r->botLeft.y && p->y < r->topRight.y;
}

void swap(int* a, int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    return;
}

void makeCanonical(Rectangle* r) {
    if (r->botLeft.x > r->topRight.x)
        swap(&(r->botLeft.x), &(r->topRight.x));
    if (r->botLeft.y > r->topRight.y)
        swap(&(r->botLeft.y), &(r->topRight.y));
    return;
}

int main(int argc, char* argv[]) {
    Rectangle rect = { {22, 33}, {2, 3} }, *pRect = &rect;
    makeCanonical(pRect);
    assert(rect.botLeft.x <= rect.topRight.x && rect.botLeft.y <= rect.topRight.y);

    Point point = { 10, 20 }, *pPoint = &point;
    assert(isInRectangle(pPoint, pRect));
    return 0;
}
