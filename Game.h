#pragma once
#include <random>
#include <vector>

#include "ClientList.h"
#include "Items.h"

class Game {
 private:
  ClientList clients;
  Items items;
  int score;
  static constexpr int CORRECT_SCORE = 10;
  static constexpr int WRONG_SCORE = 5;
  static constexpr int MIN_CLIENTS = 5;
  static constexpr int MAX_CLIENTS = 15;
  static constexpr int OPTIONS_COUNT = 3;
  static constexpr int WRONG_ITEMS_COUNT = 2;

  std::default_random_engine rng;

 public:
  Game();

  void generateRandomClients(int n);
  std::vector<std::string> generateItemOptions(const Client& client);

  void play();
  void displayScore() const;
  void endGame() const;
};
