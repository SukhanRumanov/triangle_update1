#include "interface.hpp"
#include <iostream>


std::shared_ptr<idrawer::IDrawer> selectDrawer() {
    int choice;
    std::cout << "Выберите способ рисования:\n";
    std::cout << "1. Консоль\n";
    std::cout << "2. Raylib\n";
    std::cin >> choice;

    if (choice == 1) {
        return std::make_shared<idrawer::ConsoleDrawer>();
    }
    /*
    else if (choice == 2) {
        return std::make_shared<idrawer::RaylibDrawer>();
    }
    */
    else {
        std::cout << "Неверный выбор, по умолчанию выбран ConsoleDrawer\n";
        return std::make_shared<idrawer::ConsoleDrawer>();
    }
}
void selectShape(std::shared_ptr<idrawer::IDrawer> drawer) {
    int choice;
    std::cout << "Выберите фигуру для рисования:\n";
    std::cout << "1. Треугольник\n";
    std::cout << "2. Круг\n";
    std::cin >> choice;

    if (choice == 1) {
        ishape::Point p1(10, 10);
        ishape::Point p2(40, 10);
        ishape::Point p3(25, 40);
        ishape::Triangle triangle(p1, p2, p3);
        triangle.Draw(*drawer);
    }
    else if (choice == 2) {
        ishape::Point center(25, 25);
        int radius = 10;
        ishape::Circle circle(center, radius);
        circle.Draw(*drawer);
    }
    else {
        std::cout << "Неверный выбор!\n";
    }
}
