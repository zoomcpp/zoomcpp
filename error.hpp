#ifndef error_hpp_20140721_0002_29
#define error_hpp_20140721_0002_29

template<class T, class U>
class Error {
public:
  typedef T owner_type;
  typedef U value_type;
 
  Error(owner_type& o, const value_type& v) : owner_(o), value_(v) {
  }

  Error(owner_type& o) : owner_(o), value_() {
  };

  void set(const value_type& v) {
    value_ = v;
  }
  
  const value_type& value() const {
    return value_;
  }
  
  owner_type& owner() { return owner_; }
  const owner_type& owner() const { return owner_; }

  owner_type& result(const value_type& v) {
    this->set(v);
    return owner();
  }

  owner_type& get(value_type& v) { 
    v = value(); 
    return owner();
  }

  const value_type& operator()() const {
    return value();
  }

private:
  owner_type& owner_;
  value_type value_;
};


#endif//error_hpp_20140721_0002_29
