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
    string(const string& str);
    string(const char* str);
    ~string();
    
    void reserve(unsigned int size);
    unsigned int capacity() const;

    string& append(const string& str);
    string& append(const char* str);

    const char* c_str() const;
    unsigned int length() const;
    unsigned int size() const;

private:
    char* str_ = nullptr;
};

};  // technikum