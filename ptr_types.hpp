#ifndef ptr_types_hpp_20140721_1500_10
#define ptr_types_hpp_20140721_1500_10

#include <memory>

template<class T>
using sptr = std::shared_ptr<T>;

template<class T>
using uptr = std::unique_ptr<T>;

template<class T>
using wptr = std::weak_ptr<T>;


#endif//ptr_types_hpp_20140721_1500_10
