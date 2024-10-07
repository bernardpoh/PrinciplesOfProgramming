# include "graphics.h"
# include <math.h>

const double PI = 3.14159265359;

const int START_Y = 100;
const int WAVE_HEIGHT = START_Y/2;
const int WAVELENGTH = 100;
const int REPEATS = 5;
const int PIXELS_PER_UPDATE = 5;
const int NUM_UPDATES = REPEATS * WAVELENGTH / PIXELS_PER_UPDATE;

int main()
{
    int x = 0;
    int y = 0;
    for (int i=0; i < NUM_UPDATES; i++) {
        int new_x = i * PIXELS_PER_UPDATE;
        int new_y = START_Y + WAVE_HEIGHT * sin(2 * PI * x / WAVELENGTH);
        drawLine(x, y, new_x, new_y);
        x = new_x;
        y = new_y;
    }
    return 0;
}