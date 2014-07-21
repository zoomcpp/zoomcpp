#include "status_bar.hpp"
#include <curses.h>


struct StatusBar::P {
  WINDOW* window;
  std::weak_ptr<Menu> menu_wptr;
};

StatusBar::StatusBar() {
  int screen_height;
  int screen_width;
  getmaxyx(stdscr, screen_height, screen_width);
  
  int statusbar_height = 1;
  int statusbar_width = screen_width;
  int statusbar_row = screen_height;
  int statusbar_col = 0;
  if((impl_->window = newwin(statusbar_height, statusbar_width, statusbar_row, statusbar_col)) == nullptr) {
    throw std::runtime_error("ncurses could not create status bar window");
  };
  
}

StatusBar::~StatusBar() {
  delwin(impl_->window);
}

void StatusBar::v_refresh() {
}


void StatusBar::v_set_menu(std::shared_ptr<Menu>& m) {
  impl_->menu_wptr = m;
}
