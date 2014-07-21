#ifndef main_view_hpp_20140721_1044_48
#define main_view_hpp_20140721_1044_48

#include "mvc.hpp"
#include "window.hpp"

class MainView : public virtual View {
public:
  MainView();
  virtual ~MainView();
private:
  std::unique_ptr<BasicWindow> main_window_;
  std::unique_ptr<BasicWindow> status_bar_;
  bool v_open() override;
  bool v_close() override;
};

#endif//main_view_hpp_20140721_1044_48
