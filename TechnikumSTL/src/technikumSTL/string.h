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
    friend std::ostream& operator<<(std::ostream& os, const string& str);

public:
    string();
    string(const string& str);
    string(const char* str);
    ~string();
    
    void reserve(unsigned int capacity);  // capacity does not include \0 !
    unsigned int capacity() const;

    void append(const string& other);
    void append(const char* other);

    const char* c_str() const;
    unsigned int length() const;
    unsigned int size() const;

    constexpr static unsigned int kMinimumCapacity = 16;  // Length would be -1 because of \0

private:
    char* str_ = nullptr;
    unsigned int size_;
    unsigned int capacity_;
};

};  // technikum