#ifndef main_window_hpp_20140721_0951_16
#define main_window_hpp_20140721_0951_16

#include <amp/pimpl.hpp>

class Window {
public:
  Window() {}
  virtual ~Window() {}
  void* handle() { return v_handle(); }
private:
  virtual void* v_handle() = 0;
};

class BasicWindow : public virtual Window {
public:
  BasicWindow(const int& row, const int& col, const int& height, const int& width);
  virtual ~BasicWindow();
private:
  struct P;
  amp::pimpl<P> p;
  virtual void* v_handle();
};


class MainWindow {
  
};


#endif//main_window_hpp_20140721_0951_16
