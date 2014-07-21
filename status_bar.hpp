#ifndef status_bar_hpp_20140720_2338_14
#define status_bar_hpp_20140720_2338_14

#include "signal.hpp"
#include "error.hpp"

#include <amp/pimpl.hpp>

class Menu;
class AnyStatusBar {
public:
  enum class Status {
    Ok,
    Fail
  };
  AnyStatusBar() : error(*this, Status::Ok) {
  }
  virtual ~AnyStatusBar() {
  }
  Error<AnyStatusBar, Status> error;
  AnyStatusBar& refresh()          { 
    v_refresh(); 
    return *this; 
  }
  AnyStatusBar& set_menu(std::shared_ptr<Menu>& m)  { 
    v_set_menu(m); 
    return *this; 
  }
private:
  virtual void v_refresh() = 0;
  virtual void v_set_menu(std::shared_ptr<Menu>&) = 0;
};

class StatusBar : public AnyStatusBar {
private:
  StatusBar();
  virtual ~StatusBar();
  void v_refresh() override;
  void v_set_menu(std::shared_ptr<Menu>&) override;
public:
  struct P;
  std::unique_ptr<P> impl_;
};


#endif//status_bar_hpp_20140720_2338_14
