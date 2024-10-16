#include "ishape.hpp"

namespace ishape {

    Point::Point() : x(0), y(0) {}
    Point::Point(int x, int y) : x(x), y(y) {}

    
    Triangle::Triangle(Point p1, Point p2, Point p3) {
        points.push_back(p1);
        points.push_back(p2);
        points.push_back(p3);
    }

    void Triangle::Draw(idrawer::IDrawer& drawer) {
        drawer.Draw_Line(points[0], points[1]);
        drawer.Draw_Line(points[1], points[2]);  
        drawer.Draw_Line(points[2], points[0]);  
    }

    
    Circle::Circle(Point center, int radius) : radius(radius) {
        points.push_back(center); 
    }

    
    void Circle::Draw(idrawer::IDrawer& drawer) {
        drawer.DrawCircle(points[0], radius);
    }

    
    void DrawShapes(const std::vector<IShape*>& shapes, idrawer::IDrawer& drawer) {
        for (const auto& shape : shapes) {
            shape->Draw(drawer); 
        }
    }

}
