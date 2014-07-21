#ifndef menu_hpp_20140720_2315_21
#define menu_hpp_20140720_2315_21

#include <string>
using std::string;

#include <vector>

#include <memory>
template<class T>
using sptr = std::shared_ptr<T>;

class MenuItem {
public:
  const int& hotkey() const { return v_hotkey(); }
  const string& name() const { return v_name(); }
  const string& description() const { return v_description(); }
  const string& help() const { return v_help(); }
  const Menu& submenu() const { return v_submenu(); }
private:
  virtual const int& v_hotkey() const = 0;
  virtual const string& v_name() const = 0;
  virtual const string& v_description() const = 0;
  virtual const string& v_help() const = 0; 
};

class BasicMenuItem : public virtual MenuItem {
public:
  BasicMenuItem(const int& htk, const string& n, const string& d, const string& hlp)
  : hotkey_(htk), name_(n), description_(d), help_(hlp) {
  }

  BasicMenuItem(const int& htk, const string& n, const string& d)
  : BasicMenuItem(htk, n, d, "") {
  }

  BasicMenuItem(const int& htk, const string& n) : BasicMenuItem(htk, n, "", "") {
  }

private:
  int hotkey_;
  const int& v_hotkey() const override { return hotkey_; }

  string name_;
  const string& v_name() const override { return name_; }

  string description_;
  const string& v_description() const override { return name_; }

  string help_;
  const string& v_help() const override { return help_; }
};

class AnyMenu {
public:
  typedef std::vector<sptr<BasicMenuItem>> item_array_type;
  const item_array_type& items() const { return v_items(); }
private:
  virtual const item_array_type& v_items() const;
};

class Menu : public virtual AnyMenu {
public:
private:
  item_array_type items_;
  const item_array_type& v_items() const override { return items_; }
};


#endif//menu_hpp_20140720_2315_21
