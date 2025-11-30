#include "Client.h"

#include <string>

Client::Client(int id, const string& race, const string& role)
    : id(id), race(race), role(role) {
  next = nullptr;
  prev = nullptr;
}

int Client::getId() const { return id; }

const string& Client::getRace() const { return race; }

const string& Client::getRole() const { return role; }
