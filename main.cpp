#include "interface.hpp"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");

    std::shared_ptr<idrawer::IDrawer> drawer = selectDrawer();

    selectShape(drawer);

    drawer->Show_Screen();

    return 0;
}

