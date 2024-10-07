# include <math.h>
# include "graphics.h"

int main()
{
    for (int i=0; i < 100; i++) {
        drawOval(0,0, i * 10, i * 10);
    }
    return 0;
}