//#includes
#include "menu.hpp"
#include <cstdlib>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//#types
#include "ptr_types.hpp"

//#prototypes
int main_menu_show();

//#structs


//#definitions
int main() {
  // start with the main menu
  return main_menu_show();
};

int main_menu_show() {
  Menu menu;
  menu_show(menu); 
  return EXIT_SUCCESS;
}
