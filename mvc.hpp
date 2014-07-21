#ifndef mvc_hpp_20140721_1345_00
#define mvc_hpp_20140721_1345_00

class MVC {
public:
  bool open() { return v_open(); }
  bool close() { return v_close(); }
private:
  virtual bool v_open() = 0;
  virtual bool v_close() = 0;
};

class Model : public virtual MVC {
};

class Controller : public virtual MVC {
};

class View : public virtual MVC {
};


#endif//mvc_hpp_20140721_1345_00
