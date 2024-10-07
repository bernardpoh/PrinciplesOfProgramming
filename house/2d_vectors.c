const double PI = 3.14159265359;

#define vector2 struct vector2

vector2
{
    double x;
    double y;
};

vector2 add(vector2 p1, vector2 p2)
{
    return (vector2){p1.x + p2.x, p1.y + p2.y};
}

vector2 subtract(vector2 start, vector2 end)
{
    return (vector2){end.x - start.x, end.y - start.y};
}

vector2 multiply(vector2 v, double n)
{
    return (vector2){v.x * n, v.y * n};
}

double length(vector2 v)
{
    return sqrt(pow(v.x, 2) + pow(v.y, 2));
}

vector2 rotated(vector2 v, double angle)
{
    return (vector2){
        v.x * cos(angle) + v.y * sin(angle),
        v.x * -sin(angle) + v.y * cos(angle)};
}

double angle(vector2 p1, vector2 p2)
{
    return acos((p2.y * p1.y + p2.x * p1.x) / length(p1) * length(p2));
}