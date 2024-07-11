#include <iostream>

class Point
{
public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void showCoords()
    {
        std::cout << "Point x: " << this->x << "\t y: " << y << std::endl;
    }

private:
    int x;
    int y;
};

int main()
{
    Point p1{20, 50};
    p1.showCoords();
}