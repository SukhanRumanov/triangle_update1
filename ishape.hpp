#pragma once
#include <iostream>
#include <vector>
#include "idrawer.hpp"

namespace ishape {

    class Point {
    public:
        int x;
        int y;

        Point();
        Point(int x, int y);
    };

    class IShape {
    public:
        virtual ~IShape() = default;
        virtual void Draw(idrawer::IDrawer& dr) = 0;        
        virtual std::vector<Point> GetCoords() const = 0;    
    };

    class Shape : public IShape {
    protected:
        std::vector<Point> points; 
    public:
        std::vector<Point> GetCoords() const override {
            return points;
        }
    };
    class Triangle : public Shape {
    public:
        Triangle(Point p1, Point p2, Point p3);
        void Draw(idrawer::IDrawer& dr) override;
    };

    class Circle : public Shape {
    private:
        int radius; 
    public:
        
        Circle(Point center, int radius);
        void Draw(idrawer::IDrawer& dr) override;
    };

    void DrawShapes(const std::vector<IShape*>& shapes, idrawer::IDrawer& drawer);

}
