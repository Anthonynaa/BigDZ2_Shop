#include "ClientList.h"

#include <iostream>

ClientList::ClientList() : head(nullptr), tail(nullptr) {}

bool ClientList::isEmpty() const { return head == nullptr; }

void ClientList::push_back(int id, const std::string& race,
                           const std::string& role) {
  Client* newNode = new Client(id, race, role);

  if (isEmpty()) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }
}

Client* ClientList::pop_front() {
  if (isEmpty()) return nullptr;

  Client* temp = head;

  if (head == tail) {
    head = tail = nullptr;
  } else {
    head = head->next;
    head->prev = nullptr;
  }

  return temp;
}

ClientList::~ClientList() {
  while (!isEmpty()) {
    Client* client = pop_front();
    delete client;
  }
}
