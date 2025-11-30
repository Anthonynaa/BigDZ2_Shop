#include "Items.h"

#include <algorithm>
#include <chrono>
#include <random>

Items::Items() {
  correctItems[{"человек", "воин"}] = {"стальной меч", "латный доспех", "щит"};
  correctItems[{"человек", "маг"}] = {"лазурный посох", "книга заклинаний",
                                      "магическа€ шл€па"};
  correctItems[{"человек", "плут"}] = {"дерев€нна€ бита", "темный капюшон",
                                       "ботинки скорости"};
  correctItems[{"человек", "жрец"}] = {"церковный посох", "бела€ роба",
                                       "свиток молитв"};
  correctItems[{"эльф", "воин"}] = {"длинный лук", "лезвие эльфов",
                                    "легка€ брон€"};
  correctItems[{"эльф", "маг"}] = {"магический посох", "свиток огн€",
                                   "эльфийский амулет"};
  correctItems[{"эльф", "жрец"}] = {"св€щенный талисман", "амулет природы",
                                    "свиток исцелени€"};
  correctItems[{"эльф", "плут"}] = {"отравленные кинжалы", "плащ теней",
                                    "ловушка дл€ врага"};
  correctItems[{"дварф", "воин"}] = {"боевой топор", "молот гномов",
                                     "руническа€ брон€"};
  correctItems[{"дварф", "маг"}] = {"свиток каменного щита",
                                    "посох землетр€сений", "книга заклинаний"};
  correctItems[{"дварф", "жрец"}] = {"св€щенный молот", "амулет горного духа",
                                     "свиток исцелени€"};
  correctItems[{"дварф", "плут"}] = {"короткий топор с ловушкой", "брон€ теней",
                                     "скрытный капюшон"};

  correctItems[{"орк", "воин"}] = {"огромный боевой топор", "железна€ брон€",
                                   "шлем разрушител€"};
  correctItems[{"орк", "маг"}] = {"свиток огненного шквала", "шаманский посох",
                                  "амулет силы"};
  correctItems[{"орк", "жрец"}] = {"тотем исцелени€", "амулет крови",
                                   "свиток €рости"};
  correctItems[{"орк", "плут"}] = {"зазубренные кинжалы", "отравленные стрелы",
                                   "шкура вепр€"};
}

vector<string> Items::getCorrectItems(const string& race,
                                      const string& role) const {
  auto it = correctItems.find({race, role});
  if (it != correctItems.end()) {
    return it->second;
  }
  return {};
}

vector<string> Items::getWrongItems(const string& race, const string& role,
                                    int count) const {
  vector<string> allItems;

  for (const auto& pair : correctItems) {
    if (pair.first != std::make_pair(race, role)) {
      allItems.insert(allItems.end(), pair.second.begin(), pair.second.end());
    }
  }

  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(allItems.begin(), allItems.end(),
               std::default_random_engine(seed));

  if (allItems.size() > count) {
    allItems.resize(count);
  }

  return allItems;
}
