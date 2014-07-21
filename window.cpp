#include "window.hpp"

#include <curses.h>

struct BasicWindow::P {
  WINDOW* handle;
};

BasicWindow::BasicWindow(const int& row, const int& col, const int& height, const int& width) {
  p->handle = newwin(height, width, row, col);
  if(p->handle == nullptr) {
    throw std::runtime_error("ncurses could not create window");
  }
}

BasicWindow::~BasicWindow() {
  delwin(p->handle);
}

void* BasicWindow::v_handle() {
  return p->handle;
}
