#include "Game.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>

Game::Game()
    : score(0),
      rng(std::chrono::system_clock::now().time_since_epoch().count()) {
  std::uniform_int_distribution<int> dist(5, 15);
  int n = dist(rng);
  generateRandomClients(n);
}

void Game::generateRandomClients(int n) {
  std::vector<std::string> races = {"человек", "эльф", "дварф", "орк"};
  std::vector<std::string> roles = {"воин", "маг", "жрец", "плут"};

  std::uniform_int_distribution<int> distRace(0, races.size() - 1);
  std::uniform_int_distribution<int> distRole(0, roles.size() - 1);

  for (int i = 1; i <= n; ++i) {
    std::string race = races[distRace(rng)];
    std::string role = roles[distRole(rng)];

    clients.push_back(i, race, role);
  }
}

std::vector<std::string> Game::generateItemOptions(const Client& client) {
  std::vector<std::string> correct =
      items.getCorrectItems(client.getRace(), client.getRole());

  std::uniform_int_distribution<int> distCorrect(0, correct.size() - 1);
  std::string chosenCorrect = correct[distCorrect(rng)];

  std::vector<std::string> wrong =
      items.getWrongItems(client.getRace(), client.getRole(), 2);

  std::vector<std::string> options = {chosenCorrect, wrong[0], wrong[1]};

  std::shuffle(options.begin(), options.end(), rng);

  return options;
}

void Game::play() {
  while (!clients.isEmpty()) {
    Client* client = clients.pop_front();

    std::cout << "Клиент #" << client->getId() << ": " << client->getRace()
              << " - " << client->getRole() << "\n";

    std::vector<std::string> options = generateItemOptions(*client);

    for (int i = 0; i < options.size(); ++i) {
      std::cout << i + 1 << ") " << options[i] << "\n";
    }

    int choice;
    std::cout << "Выберите предмет (1-3): ";
    std::cin >> choice;

    std::vector<std::string> correct =
        items.getCorrectItems(client->getRace(), client->getRole());

    if (choice >= 1 && choice <= 3 &&
        std::find(correct.begin(), correct.end(), options[choice - 1]) !=
            correct.end()) {
      std::cout << "Правильно! +10 очков.\n";
      score += 10;
    } else {
      std::cout << "Неправильно! -5 очков.\n";
      score -= 5;
    }

    displayScore();
    delete client;
    std::cout << "----------------------\n";
  }

  endGame();
}

void Game::displayScore() const {
  std::cout << "Текущий счёт: " << score << "\n";
}

void Game::endGame() const {
  std::cout << "Игра окончена! Итоговый счёт: " << score << "\n";
}
