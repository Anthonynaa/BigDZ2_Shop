#pragma once
#include <string>
using std::string;

class Client {
 private:
  int id;
  string race;
  string role;

 public:
  Client* next;
  Client* prev;

  Client(int id, const string& race, const string& role);

  int getId() const;
  const string& getRace() const;
  const string& getRole() const;
};
