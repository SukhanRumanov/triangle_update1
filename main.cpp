#include "ishape.hpp"
#include "idrawer.hpp"

int main() {
    ishape::Point p1(10, 5);
    ishape::Point p2(40, 5);
    ishape::Point p3(25, 20);

    ishape::Triangle triangle(p1, p2, p3);

    ishape::Point center(25, 25);
    ishape::Circle circle(center, 10);

    idrawer::ConsoleDrawer consoleDrawer;
    //idrawer::RaylibDrawer raylibDrawer;

    triangle.Draw(consoleDrawer);

    //circle.Draw(consoleDrawer);

    consoleDrawer.Show_Screen();

    //raylibDrawer.Show_Screen();


    return 0;
}

