#include <math.h>
#include <stdio.h>
#include "graphics.h"

// https://en.wikipedia.org/wiki/Mandelbrot_set#Python_code

const int MAX_ITERATIONS = 500;
const int SCREEN_MIN_X = 0;
const int SCREEN_MAX_X = 300;
const int SCREEN_MIN_Y = 0;
const int SCREEN_MAX_Y = 300;

const double MANDELBROT_MIN_X = -2.0;
const double MANDELBROT_MAX_X = 0.47;
const double MANDELBROT_MIN_Y = -1.12;
const double MANDELBROT_MAX_Y = 1.12;

double scale_x(int x)
{
    double percent = (double)(x - SCREEN_MIN_X) / (double)(SCREEN_MAX_X - SCREEN_MIN_X);
    double result = (MANDELBROT_MAX_X - MANDELBROT_MIN_X) * percent + MANDELBROT_MIN_X;
    return result;
}

double scale_y(int y)
{
    double percent = (double)(y - SCREEN_MIN_Y) / (double)(SCREEN_MAX_Y - SCREEN_MIN_Y);
    double result = (MANDELBROT_MAX_Y - MANDELBROT_MIN_Y) * percent + MANDELBROT_MIN_Y;
    return result;
}

void set_colour_based_on_iteration(int number)
{
    if (number > 255)
    {
        number = 255;
    }

    if (number <= 12)
    {
        setColour(number);
    }
    else
    {
        setRGBColour(number, number, number);
    }
}

void draw_mandelbrot_set()
{
    for (int Py = SCREEN_MIN_Y; Py < SCREEN_MAX_Y; Py++)
    {
        for (int Px = SCREEN_MIN_X; Px < SCREEN_MAX_X; Px++)
        {
            double x0 = scale_x(Px);
            double y0 = scale_y(Py);
            double x = 0.0;
            double y = 0.0;
            int iteration = 0;
            while ((pow(x, 2) + pow(y, 2) < 4.0) && (iteration < MAX_ITERATIONS))
            {
                double xtemp = pow(x, 2) - pow(y, 2) + x0;
                y = 2 * x * y + y0;
                x = xtemp;
                iteration += 1;
            }
            set_colour_based_on_iteration(iteration);
            fillRect(Px, Py, Px, Py);
        }
    }
}

int main()
{
    draw_mandelbrot_set();
    return 0;
}