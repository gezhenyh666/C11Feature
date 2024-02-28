#ifndef _YH_SHARED_PTR_H
#define _YH_SHARED_PTR_H

template<typename T>
class YHSharedPtr {
 public:
  YHSharedPtr() = default;
  explicit YHSharedPtr(T* ptr = nullptr) : data_ptr_(ptr) {
    if (data_ptr_) {
      ref_count_ = new int(1);
    } else {
      ref_count_ = new int(0);
    }
  }

  YHSharedPtr(const YHSharedPtr& sp) : data_ptr_(sp.data_ptr_), ref_count_(sp.ref_count_) {
    if (ref_count_) {
      ++(*ref_count_);
    }
  }

  YHSharedPtr(yh_shared_ptr&& sp);
  void reset() {
    if (data_ptr_) {
      --(*ref_count_);
    }
  }
  void reset(T* ptr) {
    data_ptr_ = ptr;
    if (data_ptr_) {
      ref_count_ = new int(1);
    } else {
      ref_count_ = new int(0);
    }
  }

  T* get() {
    return data_ptr_;
  }

  int use_count() {
    return *ref_count_;
  }

  ~YHSharedPtr() {
    if(*ref_count_ == 0) {
      delete data_ptr_;
      delete ref_count_;
    }
  }
 private:
  T* data_ptr_ = nullptr;
  int* ref_count_ = nullptr;
};

#endif // _YH_SHARED_PTR_H
