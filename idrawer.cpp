#include "idrawer.hpp"
#include "ishape.hpp"
//#include "raylib.h"

namespace idrawer {
    ConsoleDrawer::ConsoleDrawer() {
        for (int i = 0; i < Len; ++i) {
            for (int j = 0; j < Len; ++j) {
                canvas[i][j] = ' ';
            }
        }
    }

    void ConsoleDrawer::Draw_Line(ishape::Point& p1, ishape::Point& p2) {
        int x1 = p1.x, y1 = p1.y;
        int x2 = p2.x, y2 = p2.y;

        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int sx = (x1 < x2) ? 1 : -1;
        int sy = (y1 < y2) ? 1 : -1;
        int err = dx - dy;

        while (true) {
            if (x1 >= 0 && x1 < Len && y1 >= 0 && y1 < Len)
                canvas[y1][x1] = '*';

            if (x1 == x2 && y1 == y2)
                break;

            int e2 = 2 * err;

            if (e2 > -dy) {
                err -= dy;
                x1 += sx;
            }

            if (e2 < dx) {
                err += dx;
                y1 += sy;
            }
        }
    }

    void ConsoleDrawer::DrawCircle(ishape::Point& center, int radius) {
        for (int y = -radius; y <= radius; y++) {
            for (int x = -radius; x <= radius; x++) {
                if (x * x + y * y <= radius * radius) {
                    int draw_x = center.x + x;
                    int draw_y = center.y + y;
                    if (draw_x >= 0 && draw_x < Len && draw_y >= 0 && draw_y < Len) {
                        canvas[draw_y][draw_x] = '*';
                    }
                }
            }
        }
    }

    void ConsoleDrawer::Show_Screen() const {
        for (int i = 0; i < Len; i++) {
            for (int j = 0; j < Len; j++) {
                std::cout << canvas[i][j];
            }
            std::cout << std::endl;
        }
    }


   /* RaylibDrawer::RaylibDrawer() {
        InitWindow(800, 600, "Raylib Drawing Example");
        SetTargetFPS(60);
    }

    RaylibDrawer::~RaylibDrawer() {
        CloseWindow();
    }

    void RaylibDrawer::Show_Screen() const {
        ishape::Point p1(100, 100);
        ishape::Point p2(200, 300);
        ishape::Point p3(300, 100);

        ishape::Point center(400, 300);
        int radius = 50;

        while (!WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawLine(p1.x, p1.y, p2.x, p2.y, BLACK);
            DrawLine(p2.x, p2.y, p3.x, p3.y, BLACK);
            DrawLine(p3.x, p3.y, p1.x, p1.y, BLACK);

            //DrawCircle(center.x, center.y, radius, BLACK);

            EndDrawing();
        }
    }*/

}

