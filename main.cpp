#include <memory>
template<class T>
using sptr = std::shared_ptr<T>;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>

class Command {
public:
  bool commit() { return v_commit(); }
  bool undo() { return v_undo(); }
  bool redo() { return v_redo(); }
  bool is_undoable() { return v_is_undoable(); }
private:
  virtual bool v_commit() = 0;
  virtual bool v_undo() = 0;
  virtual bool v_redo() = 0;
  virtual bool v_is_undoable() { return false; }
};

class MenuItem {
public:
  MenuItem(const int& htk, const string& n, const string& d, const string& hlp)
  : hotkey_(htk), name_(n), description_(d), help_(hlp) {
  }

  MenuItem(const int& htk, const string& n, const string& d)
  : MenuItem(htk, n, d, "") {
  }

  MenuItem(const int& htk, const string& n) : MenuItem(htk, n, "", "") {
  }

  const int& hotkey() const { return v_hotkey(); }
  
  const string& name() const { return v_name(); }
  
  const string& description() const { return v_description(); }
  
  const string& help() const { return v_help(); }



private:
  int hotkey_;
  const int& v_hotkey() const { return hotkey_; }

  string name_;
  const string& v_name() const { return name_; }

  string description_;
  const string& v_description() const { return name_; }

  string help_;
  const string& v_help() const { return help_; }
};

class AnyMenu {
public:
  typedef std::vector<sptr<MenuItem>> item_array_type;
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


int main() {
  return 0;
}
