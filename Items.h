#pragma once
#include <map>
#include <string>
#include <utility>
#include <vector>
using std::map;
using std::pair;
using std::string;
using std::vector;

class Items {
 private:
  map<pair<string, string>, vector<string>> correctItems;

 public:
  Items();

  vector<string> getCorrectItems(const string& race, const string& role) const;

  vector<string> getWrongItems(const string& race, const string& role,
                               int count) const;
};
