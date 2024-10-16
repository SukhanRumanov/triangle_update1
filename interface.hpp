#pragma once
#include "ishape.hpp"
#include "idrawer.hpp"
#include <memory>
//#include "raylib" 

std::shared_ptr<idrawer::IDrawer> selectDrawer();

void selectShape(std::shared_ptr<idrawer::IDrawer> drawer);
