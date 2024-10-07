#include <math.h>
#include <stdio.h>
#include "graphics.h"
#include "2d_vectors.c"
// gcc -o snkwflake koch_snowflake.c graphics.c
// ./snowflake | java -jar drawapp-4.0.jar

void draw_segment(int iterations, vector2 start, vector2 end)
{
    if (iterations == 0)
    {
        drawLine((int)start.x, (int)start.y, (int)end.x, (int)end.y);
        return;
    }

    vector2 movement = multiply(subtract(start, end), 1.0 / 3.0);

    // print statements for debugging except that print statements don't work
    // char c[50];
    // sprintf(c, "%g", movement.x);
    // drawString(c, 0, 0);
    // sprintf(c, "%g", movement.y);
    // drawString(c, 0, 0);

    vector2 p0 = start;
    vector2 p1 = add(p0, movement);
    movement = rotated(movement, -PI / 3.0);
    vector2 p2 = add(p1, movement);
    movement = rotated(movement, PI * 2.0 / 3.0);
    vector2 p3 = add(p2, movement);
    movement = rotated(movement, -PI / 3.0);
    vector2 p4 = add(p3, movement);

    draw_segment(iterations - 1, p0, p1);
    draw_segment(iterations - 1, p1, p2);
    draw_segment(iterations - 1, p2, p3);
    draw_segment(iterations - 1, p3, p4);
}

int main()
{

    const vector2 START_POINT = {100, 200};
    const double MOVE_AMOUNT = 200;
    const int NUM_SIDES = 3;
    const int RECURSION_DEPTH = 5;

    // copy + pasted from draw_polygon.c
    // for the perfect triangle
    
    vector2 turtle_position = START_POINT;
    vector2 turtle_velocity = {MOVE_AMOUNT, 0};

    for (int i = 0; i < NUM_SIDES; i++)
    {
        vector2 new_position = add(turtle_position, turtle_velocity);
        draw_segment(RECURSION_DEPTH, turtle_position, new_position);
        turtle_position = new_position;
        turtle_velocity = rotated(turtle_velocity, 2 * PI / NUM_SIDES);
    }

    return 0;
}