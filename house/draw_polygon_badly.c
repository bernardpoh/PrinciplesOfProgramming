# include "graphics.h"
# include <math.h>

const double PI = 3.14159265359;

// gcc -o octagon draw_octagon.c graphics.c
// ./octagon | java -jar drawapp-4.0.jar

void draw_regular_polygon(int sides)
{
    const int START_X = 100;
    const int START_Y = 100;
    const double MOVE_AMOUNT = 50;

    int x = START_X;
    int y = START_Y;

    for (int i=0; i<sides; i++) {
        
        double direction = i * 2*PI/sides;
        
        int new_x = x + MOVE_AMOUNT * cos(direction);
        int new_y = y + MOVE_AMOUNT * sin(direction);
        
        drawLine(x,y, new_x, new_y);
        x = new_x;
        y = new_y;
    }
}

int main()
{
    draw_regular_polygon(7);
    return 0;
}

