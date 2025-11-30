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

  std::default_random_engine rng;

 public:
  Game();

  void generateRandomClients(int n);
  std::vector<std::string> generateItemOptions(const Client& client);

  void play();
  void displayScore() const;
  void endGame() const;
};
