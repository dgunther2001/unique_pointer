#include <iostream>

template <typename T>
class unique_pointer {
private:
    T* wrapped_ptr;

public:
    unique_pointer(T* wrapped_ptr = nullptr) : wrapped_ptr(wrapped_ptr) {}

    unique_pointer(const unique_pointer<T>& another_pointer) = delete; // NO COPY CONSTRUCTOR
    unique_pointer& operator= (const unique_pointer<T>& another_pointer) = delete; // NO REASSIGNMENT OPERATOR

    unique_pointer(unique_pointer<T>&& another_pointer) {
        wrapped_ptr = another_pointer.wrapped_ptr;
        another_pointer.wrapped_ptr = nullptr;
    }

    unique_pointer& operator= (unique_pointer<T>&& another_pointer) {
        if (this != &another_pointer) { // validate that the pointer is not being set to itself
            if (wrapped_ptr != nullptr) { // if the data is non-null, then deallocate it before assigning the new pointer
                delete wrapped_ptr;
            }
            wrapped_ptr = another_pointer.wrapped_ptr;
            another_pointer.wrapped_ptr = nullptr;
        }

        return *this;
    }

    T* operator->() {
        return wrapped_ptr;
    }

    T operator*() {
        return *wrapped_ptr;
    }

    T* get() {
        return wrapped_ptr;
    }

    void reset(T* new_wrapped_ptr = nullptr) {
        if (wrapped_ptr != nullptr) {
            delete wrapped_ptr;
        }
        wrapped_ptr = new_wrapped_ptr;
    }

    ~unique_pointer() {
        if (wrapped_ptr != nullptr) {
            delete wrapped_ptr;
            wrapped_ptr = nullptr;
        }
    }



};
