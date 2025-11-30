#include <iostream>

#include "Game.h"

int main() {
  setlocale(LC_ALL, "");
  std::cout << "Добро пожаловать в Магический магазин Аркадии!\n";
  std::cout << "-------------------------------\n";

  Game game;
  game.play();

  return 0;
}
