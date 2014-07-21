#ifndef main_window_hpp_20140721_0951_16
#define main_window_hpp_20140721_0951_16


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
  template<class...Args>
  Window(const int& row, const int& col, const int& height, const int& width) {
    handle_ = newwin(height, width, row, col);
    if(handle_ == nullptr) {
      throw std::runtime_error("ncurses could not create window");
    }
  }

  virtual ~Window() {
    delwin(handle_);
  }
private:
  WINDOW* handle_;
  virtual void* v_handle() { return handle_; }
};


class MainWindow {
  
};


#endif//main_window_hpp_20140721_0951_16
