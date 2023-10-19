#pragma once

namespace technikum
{

template <typename T, typename CustomDeleter = std::default_delete<T>>
class unique_ptr
{
public:
    explicit unique_ptr(T* ptr = nullptr, CustomDeleter deleter = CustomDeleter()) : ptr_(ptr) , deleter_(deleter) {}

    // Unique pointer does not need copy constructor and assignment since ownership should change on assingment.
    unique_ptr(const unique_ptr& other) = delete;

    // Move constructor.
    unique_ptr(unique_ptr&& other) noexcept
        : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }
    
    ~unique_ptr() { deleter_(ptr_); }

    // Unique pointer doesn't copy constructor and assignment since ownership should change on assingment.
    unique_ptr& operator=(const unique_ptr& other) = delete;

    // Move assignment operator
    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        // Change ownership.
        if (this != &other)
        {
            delete ptr_;
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

        return *this;
    }

    T& operator*() { return *ptr_; }
    T* operator->() { return ptr_; }
    operator bool() const { return ptr_ != nullptr; }

    T* Release()
    {
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void Reset()
    {
        deleter_(ptr_);
        // Multiple deletes could lead to unexpected behaviour if not set to nullptr afterwards.
        ptr_ = nullptr;  // https://stackoverflow.com/questions/1931126/is-it-good-practice-to-null-a-pointer-after-deleting-it
    }

    void Swap(unique_ptr& other)
    {
        T* temp = ptr_;
        ptr_ = other.ptr_;
        other.ptr_ = temp;
    }

    void Swap(T* other)
    {
        T temp = *ptr_;
        *ptr_ = *other;
        *other = temp;
    }
    
    // For testing purposes.
    T* get() const { return ptr_; }
    
private:
    T* ptr_;
    CustomDeleter deleter_;
};

}