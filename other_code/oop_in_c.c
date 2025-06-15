#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define nil (void*)0

#define ArrayLength(xs) sizeof(xs)/sizeof((xs)[0])

typedef struct {
    int x;
    int y;
} Point;

Point PointNew(int x, int y){
    Point p;
    
    p.x = x;
    p.y = y;
    
    return p;
}

float Distance(Point self, Point other){
    return hypot(self.x -  other.x, self.y - other.y);
}

typedef struct Shape Shape;

struct Shape{
    float (*Area)(Shape *);
    void (*Print)(Shape *);
};

typedef struct {
    Shape super;
    
    Point tl;
    Point tr;
    Point bl;
    Point br;
} Rectangle;

static float rectangleArea(Shape *_r){
    Rectangle *r = (Rectangle *)_r;

    return Distance(r->tl, r->tr) * Distance(r->tl, r->bl);
}

void rectanglePrint(Shape *_r){
    Rectangle *r = (Rectangle *)_r;
    printf("rectagnle: %f\n", r->super.Area(_r));
}

Rectangle * RectangleNew(Point tl, Point br){
    Rectangle *r;
    
    r = malloc(sizeof(*r));
    assert(r != nil);
    r->tl = tl;
    r->tr = PointNew(br.x, tl.y);
    r->bl = PointNew(tl.x, br.y);
    r->br = br;
    
    r->super.Area = rectangleArea;
    r->super.Print = rectanglePrint;

    return r;
}

typedef struct {
    Shape super;
    
    Point center;
    int r;
} Circle;

float circleArea(Shape *_circle){
    Circle *circle = (Circle *)_circle;
    
    return 3.1415926436*circle->r*circle->r;
}

void circlePrint(Shape *_circle){
    Circle *circle = (Circle *)_circle;
    printf("circle: %f\n", circle->super.Area(_circle));
}

Circle * CircleNew(Point center, int r){
    Circle *circle;
    
    circle = malloc(sizeof(*circle));
    circle->center = center;
    circle->r = r;
    
    circle->super.Area = circleArea;
    circle->super.Print = circlePrint;
    
    return circle;
}

int main(){
    Shape *shapes[2];
    int i;
    
    shapes[0] = (Shape *)RectangleNew(PointNew(1, 2), PointNew(10, 15));
    shapes[1] = (Shape *)CircleNew(PointNew(5, 10), 4);
    
    for (i = 0; i < ArrayLength(shapes); i++) {
        shapes[i]->Print(shapes[i]);
    }
    return 0;
}









