#ifndef initializer_hpp_20140721_0123_37
#define initializer_hpp_20140721_0123_37

template<class T>
class Initializer {
public:
  typedef T value_type;
  typedef std::function<void(value_type&)> value_fn_type;
  typedef std::function<bool(void)> isset_fn_type;
  typedef std::function<bool(void)> isreset_fn_type;
  Initializer(value_fn_type i, value_fn_type r, is_set_fn_type isset_fn, is_reset_fn_type isreset_fn) 
  : init_(i), reset_(r), isset_(isset_fn), isreset_(isreset_fn) {
  }
  Initializer(value_fn_type i, value_fn_type r) 
  : Initializer(i, r, 
    []() { return value_ != 0; }      // isset_fn
    []() { return value_ == 0; }      // isreset_fn
  {
    init_(value_);
  }
  ~Initializer() {
    release_(value_);
  }
  value_type& value() { return value_; }
  const value_type& value() const { return value_; }
  bool is_set() { return isset_(); }
  bool is_reset() { return isreset_(); }
private:
  fn_type init_;
  fn_type release_;
  isset_fn_type isset_;
  isreset_fn_type isreset_;
  value_type value_;
};

#endif//initializer_hpp_20140721_0123_37

