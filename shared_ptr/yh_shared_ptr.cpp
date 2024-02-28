#include "yh_shared_ptr.h"

template<typename T>
class YHSharedPtr {
 public:
  YHSharedPtr();
  YHSharedPtr(const YHSharedPtr& sp);
  YHSharedPtr(yh_shared_ptr&& sp);
  void reset();
  void reset(T* ptr);
  T* get();
  int use_count();
  ~YHSharedPtr();
 private:
  T* data_ptr_;
  int* ref_count;
};


