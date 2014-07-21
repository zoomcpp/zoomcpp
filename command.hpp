#ifndef command_hpp_20140719_1600_25
#define command_hpp_20140719_1600_25

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


#endif//command_hpp_20140719_1600_25
