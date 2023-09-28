#include "string.h"

#include <algorithm>
#include <cassert>

namespace technikum
{
    void strcpy(const char* source, char* destination)
    {
        assert(source != nullptr && destination != nullptr);

        unsigned int i;
        for (i = 0; source[i] != '\0'; i++)
        {
            destination[i] = source[i];
        }
        // Do not forget to add the terminating null character!
        destination[i] = '\0';
    }

    unsigned int strlen(const char* str)
    {
        assert(str != nullptr);

        unsigned int i;
        for (i = 0; str[i] != '\0'; i++) {} // Do not count the terminating null character!
        return i;
    }

    string::string()
    {
        size_ = 0;
        capacity_ = string::kMinimumCapacity;
        str_ = new char[capacity_];
        strcpy("", str_);
    }

    string::string(const char* str)
    {
        size_ = strlen(str);
        capacity_ = std::max(size_ + 1, string::kMinimumCapacity);
        str_ = new char[capacity_];
        strcpy(str, str_);
    }

    string::string(const string& str)
        : string(str.c_str())
    {

    }

    string::string(string&& str) noexcept
    {
        // TODO: Implement move constructor
    }

    string::~string()
    {
        assert(str_ != nullptr);

        delete[] str_;
    }

    void string::reserve(unsigned int capacity)
    {
        // If we want to reserve less characters than our string currently holds do nothing.
        if (capacity <= size_) return;

        // Do not reserve less than the minimum capacity.
        capacity = std::max(capacity, string::kMinimumCapacity);

        assert(str_ != nullptr);

        // Temporarily store our string
        string temp(str_);
        // Free the allocated memory.
        delete[] str_;
        // Update capacity_.
        capacity_ = capacity;
        // Allocate new memory with size of capacity.
        str_ = new char[capacity];
        // Copy the temp string back.
        strcpy(temp.c_str(), str_);
    }

    unsigned int string::capacity() const
    {
        return capacity_;
    }

    void string::append(const string& other)
    {
        append(other.c_str());
    }

    void string::append(const char* other)
    {
        // Do nothing if other length is 0.
        unsigned int otherLength = strlen(other);
        if (otherLength == 0) return;

        // Reserve enough space for str_ + other + \0.
        unsigned int thisLength = length();
        reserve(thisLength + otherLength + 1);

        unsigned int i, j;
        // Insert other starting at the \0 position of this string.
        for (i = thisLength, j = 0; j != otherLength; i++, j++)
        {
            str_[i] = other[j];
        }
        str_[i] = '\0';
    }

    const char* string::c_str() const
    {
        return str_;
    }

    unsigned int string::length() const
    {
        return size();
    }

    unsigned int string::size() const
    {
        return size_;
    }

    std::ostream& operator<<(std::ostream& os, const string& str)
    {
        os << str.str_;
        return os;
    }

    string& string::operator=(const string& str)
    {
        // TODO: Implement copy assignment
    }

    string& string::operator=(string&& str) noexcept
    {
        // TODO: Implement move assignment
    }

};  // technikum