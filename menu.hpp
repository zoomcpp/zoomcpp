#ifndef menu_hpp_20140721_1446_20
#define menu_hpp_20140721_1446_20

#include "command.hpp"
#include "types.hpp"

#include <iostream>
#include <vector>
using namespace std;

struct MenuItem {
  int hotkey = 0;
  string name;
  string description;
  string help_text;
  uptr<Command> command;
};

struct Menu {
  std::vector<MenuItem> items;
};

int menu_show(Menu& menu) {
  // iterate through the menu items
  for(auto& item : menu.items) {
    cout << "[" << (char)item.hotkey << "]";
  }
  return 0;
}

#endif//menu_hpp_20140721_1446_20
