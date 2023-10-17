#pragma once

namespace technikum
{

template <typename T>
class unique_ptr
{
public:
    explicit unique_ptr(T* ptr = nullptr) : ptr_(ptr) {}

    // Anmerkung - Aufgabe 1 War es, Rule of Five zu implementieren, allerdings weiß ich nicht,
    // ob eine Unique Pointer Klasse einen Copy Constructor benötigt, es soll ja nur einen Verweis
    // auf das Datum geben. Weiß also nicht ob alles fertig ist - Raoul.

    // Don't think unique pointer needs copy constructor and assignment since ownership should change on assingment - Raoul.
    unique_ptr(const unique_ptr& other) = delete;

    // Move constructor.
    unique_ptr(unique_ptr&& other) noexcept
        : ptr_(other.ptr_)
    {
        other.ptr_ = nullptr;
    }
    
    ~unique_ptr() { delete ptr_; }

    // Don't think unique pointer needs copy constructor and assignment since ownership should change on assingment - Raoul.
    unique_ptr& operator=(const unique_ptr& other) = delete;

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
        delete ptr_;
        // I think multiple deletes could lead to unexpected behaviour if not set to nullptr afterwards - Raoul.
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

    // TODO 3 Implement custom deleters (Don't know what those are).
    
    // For testing purposes.
    T* get() const { return ptr_; }
    
private:
    T* ptr_;
};

}