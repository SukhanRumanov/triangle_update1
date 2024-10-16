#pragma once
#include <iostream>
#include <vector>  

namespace ishape {
    class Point;
}

namespace idrawer {

    class IDrawer {
    public:
        virtual void Show_Screen() const = 0;
        virtual void Draw_Line(ishape::Point& p1, ishape::Point& p2) = 0;
        virtual void DrawCircle(ishape::Point& center, int radius) = 0;
        virtual void DrawPoint(ishape::Point& p) = 0;
    };

    class BasicDrawer : public IDrawer {
    protected:
        static const int Len = 50;
        char canvas[Len][Len];

    public:
        BasicDrawer();
        virtual void Show_Screen() const override;
        virtual void Draw_Line(ishape::Point& p1, ishape::Point& p2) override;
        virtual void DrawPoint(ishape::Point& p) override;
    };

    class ConsoleDrawer : public BasicDrawer {
    public:
        ConsoleDrawer();
        void Show_Screen() const override;
        void Draw_Line(ishape::Point& p1, ishape::Point& p2) override;
        void DrawCircle(ishape::Point& center, int radius) override;
    };

    // Закомментирован для Raylib
    /*class RaylibDrawer : public BasicDrawer {
    public:
        RaylibDrawer();
        ~RaylibDrawer();
        void Show_Screen() const override;
    };*/
}
