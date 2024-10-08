#pragma once
#include <iostream>
#include <vector>

namespace idrawer {
    class IDrawer;
}

namespace ishape {

    class Point {
    public:
        int x;
        int y;

        Point();
        Point(int x, int y);
    };

    class Shape {
    protected:
        std::vector<Point> points;
    public:

        std::vector<Point> GetCoords();
        virtual void Draw(idrawer::IDrawer& dr) = 0;

    };

    class Triangle :public Shape
    {
    public:
        Triangle(Point p1, Point p2, Point p3);
        virtual void Draw(idrawer::IDrawer& dr);

    };

    class Circle :public Shape
    {
    private:
        int radius;
    public:
        Circle(Point centr, int radius);
        virtual void Draw(idrawer::IDrawer& dr);
    };
};
