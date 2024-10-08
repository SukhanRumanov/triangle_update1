#include <iostream>
#include <vector>  
//#include "raylib.h"

const int Len = 50;

namespace ishape {
    class Point;
}

namespace idrawer {
    class IDrawer {
    public:
        virtual void Show_Screen() const = 0;
        virtual void Draw_Line(ishape::Point& p1, ishape::Point& p2) = 0;
        virtual void DrawCircle(ishape::Point& center, int radius) = 0;
    };

    class BasicDrawer : public IDrawer {
    protected:
        char canvas[Len][Len];
    };

    class ConsoleDrawer : public BasicDrawer {
    public:
        ConsoleDrawer();
        void Show_Screen() const override;
        void Draw_Line(ishape::Point& p1, ishape::Point& p2) override;
        void DrawCircle(ishape::Point& center, int radius) override;
    };

    /*class RaylibDrawer : public BasicDrawer {
    public:
        RaylibDrawer();
        ~RaylibDrawer();
        void Show_Screen() const override;
    };*/
}
