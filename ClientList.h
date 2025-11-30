#pragma once
#include "Client.h"

class ClientList {
 private:
  Client* head;
  Client* tail;

 public:
  ClientList();

  bool isEmpty() const;
  void push_back(int id, const std::string& race, const std::string& role);
  Client* pop_front();
  ~ClientList();
};
