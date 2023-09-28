#pragma once

#include <iostream>

namespace technikum
{

/// <summary>
/// Copies the source string to the destination string.
/// </summary>
void strcpy(const char* source, char* destination);
/// <summary>
/// Returns the length of the string without the null-terminator '\0'.
/// </summary>
unsigned int strlen(const char* str);

class string
{
public:
    string();

    string(const char* str);
    string(const string& str);
    // noexcept performs a compile-time check that returns true if an expression is declared to not throw any exceptions.
    string(string&& str) noexcept;  // TODO: Implement move constructor
    ~string();
    
    void reserve(unsigned int capacity);  // capacity does not include \0 !
    unsigned int capacity() const;

    void append(const string& other); // Optional TODO: Return the string instance to allow this method to be chained together.
    void append(const char* other);   // Example usage would be s1.append(s2).append(s3)

    const char* c_str() const;
    unsigned int length() const;
    unsigned int size() const;

    constexpr static unsigned int kMinimumCapacity = 16;  // Length would be -1 because of \0

    friend std::ostream& operator<<(std::ostream& os, const string& str);
    string& operator =(const string& str);  // TODO: Implement copy assignment
    string& operator =(string&& str) noexcept;  // TODO: Implement move assignment

private:
    char* str_ = nullptr;
    unsigned int size_;
    unsigned int capacity_;
};

};  // technikum