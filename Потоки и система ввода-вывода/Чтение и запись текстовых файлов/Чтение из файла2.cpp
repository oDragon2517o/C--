#include <iostream>
#include <fstream>
#include <vector>

struct Point
{
    Point(double x, double y) : x{x}, y{y} {}
    double x;
    double y;
};
int main()
{
    std::vector<Point> points{Point{0, 0}, Point{4, 5}, Point{-5, 7}};

    std::ofstream out("points.txt");

    if (out.is_open())
    {
        // записываем все объекты Point в файл
        for (const Point &point : points)
        {
            out << point.x << " " << point.y << std::endl;
        }
    }
    out.close();

    std::vector<Point> new_points;
    std::ifstream in("points.txt"); // окрываем файл для чтения
    if (in.is_open())
    {
        double x, y;
        while (in >> x >> y)
        {
            new_points.push_back(Point{x, y});
        }
    }
    in.close();

    for (const Point &point : new_points)
    {
        std::cout << "Point X: " << point.x << "\tY: " << point.y << std::endl;
    }
}