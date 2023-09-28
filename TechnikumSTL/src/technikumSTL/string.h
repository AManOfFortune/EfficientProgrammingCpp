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
    string(); // Default constructor

    string(const char* str); // Constructor with parameter
    string(const string& str); // Copy constructor
    string(string&& str) noexcept; // Move constructor
    ~string(); // Destructor
    
    void reserve(unsigned int capacity);  // capacity does not include \0 !
    unsigned int capacity() const;

    string& append(const string& other); // Returns the string instance to allow this method to be chained together. Example usage would be s1.append(s2).append(s3)
    string& append(const char* other);

    const char* c_str() const;
    unsigned int length() const;
    unsigned int size() const;

    constexpr static unsigned int kMinimumCapacity = 16;  // Length would be -1 because of \0

    friend std::ostream& operator<<(std::ostream& os, const string& str);
    string& operator =(const string& str); // Copy assignment operator
    string& operator =(string&& str) noexcept; // Move assignment operator

private:
    char* str_ = nullptr;
    unsigned int size_;
    unsigned int capacity_;

    // Helper functions to reduce code duplication in Destructor, Copy/Move constructors & their corresponding operators
    void save_string(const char* str);
    void move_string(string&& str);
    void free_memory();
};

};  // technikum