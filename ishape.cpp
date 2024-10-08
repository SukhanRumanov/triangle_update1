#include "Ishape.hpp"
#include "idrawer.hpp"

namespace ishape {

    Point::Point() {
        this->x = 0;
        this->y = 0;
    }

    Point::Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool checkError(Point num1, Point num2) {
        return (num1.x == num2.x && num1.y == num2.y);
    }

    std::vector<Point> Shape::GetCoords() {
        if (checkError) {
            return this->points;
        }
    }

    Triangle::Triangle(Point p1, Point p2, Point p3) {
        this->points.push_back(p1);
        this->points.push_back(p2);
        this->points.push_back(p3);
    }


    void Triangle::Draw(idrawer::IDrawer& drawer) {
        drawer.Draw_Line(this->points[0], this->points[1]);
        drawer.Draw_Line(this->points[1], this->points[2]);
        drawer.Draw_Line(this->points[0], this->points[2]);
    }

    Circle::Circle(Point centr, int radius) {
        this->points.push_back(centr);
        this->radius = radius;
    }

    void Circle::Draw(idrawer::IDrawer& drawer) {
        drawer.DrawCircle(points[0], radius);
    }
};



