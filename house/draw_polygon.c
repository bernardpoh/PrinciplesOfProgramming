#include <math.h>
#include <stdio.h>
#include "graphics.h"
#include "2d_vectors.c"

const vector2 START_POINT = {200, 200};
const double MOVE_AMOUNT = 50;

void draw_polgon(int num_sides)
{
    vector2 turtle_position = START_POINT;
    vector2 turtle_velocity = {MOVE_AMOUNT, 0};

    for (int i=0; i < num_sides; i++) {
        vector2 new_position = add(turtle_position, turtle_velocity);
        drawLine(turtle_position.x, turtle_position.y, new_position.x, new_position.y);
        turtle_position = new_position;
        turtle_velocity = rotated(turtle_velocity, 2*PI/num_sides);
    }
}

int main() {
    draw_polgon(7);
    return 0;
}