#ifndef signal2_hpp_20140720_1427_58
#define signal2_hpp_20140720_1427_58

#include <functional>
#include <memory>
#include <list>

template<class>
class Slot;

template<class R, class...Args>
class Slot<R(Args...)> {
public: 
  typedef R result_type;
  typedef std::function<R(Args...)> slot_fn_type;
  
  typedef std::shared_ptr<slot_fn_type> slot_sptr_type;
  typedef std::weak_ptr<slot_fn_type> slot_wptr_type;

  Slot(slot_fn_type sfn) : slot_sptr_(std::make_shared<slot_fn_type>(sfn)) {
  }

  slot_wptr_type connect() const {
    return slot_wptr_type(slot_sptr_);
  }
  result_type accept(slot_fn_type& m) {
    return (*slot_sptr_)(m);
  }
private:
  slot_sptr_type slot_sptr_;
};

template<class>
class Signal;

template<class R, class...Args>
class Signal<R(Args...)> {
public:
  typedef std::function<R(Args...)> slot_fn_type;
  typedef Slot<R(Args...)> slot_type;
  typedef typename slot_fn_type::result_type result_type;

  typedef std::shared_ptr<slot_fn_type> slot_sptr_type;
  typedef std::weak_ptr<slot_fn_type> slot_wptr_type;

  typedef std::list<slot_wptr_type> slot_list_type;

  void connect(const slot_type& slot) {
    slot_list_.push_back(slot.connect());
  }

  slot_list_type& slot_list() { return slot_list_; }

  const slot_list_type& slot_list() const { return slot_list_; }
  
  result_type raise(Args&&...args) const;

private:
  slot_list_type slot_list_;
};

template<class R, class...Args>
typename Signal<R(Args...)>::result_type Signal<R(Args...)>::raise(Args&&...args) const {
  auto iter = slot_list().begin();
  if(iter != slot_list().end()) {
    do {
      auto slot_wptr = (*iter);
      auto slot_sptr = slot_wptr.lock();
      auto slot_fn = *slot_sptr;
      ++iter;
      // the "if" clause here is necessary if R == 'void'
      if(iter == slot_list().end()) {
        // will work even if R == 'void'
        return slot_fn(std::forward<Args>(args)...);
      } else {
        // not the last slot in the list, so we don't return anything anyway
        slot_fn(std::forward<Args>(args)...);
      }
    } while(true);
  }
  return result_type();
}

#endif//signal2_hpp_20140720_1427_58
