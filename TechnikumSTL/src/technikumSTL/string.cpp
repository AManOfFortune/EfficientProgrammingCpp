#include "string.h"

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
        destination[i] = '\0';
    }

    unsigned int strlen(const char* str)
    {
        assert(str != nullptr);

        unsigned int i;
        for (i = 0; str[i] != '\0'; i++) {}
        return i;
    }

    std::ostream& operator<<(std::ostream& os, const string& str)
    {
        os << str.str_;
        return os;
    }

    string::string(const string& str)
    {

    }

    string::string(const char* str)
    {

    }

    string::~string()
    {

    }

    void string::reserve(unsigned int size)
    {

    }

    unsigned int string::capacity() const
    {
        return 0;
    }

    string& string::append(const string& str)
    {
        return *this;
    }

    string& string::append(const char* str)
    {
        return *this;
    }

    const char* string::c_str() const
    {
        return nullptr;
    }

    unsigned int string::length() const
    {
        return 0;
    }

    unsigned int string::size() const
    {
        return 0;
    }

};  // technikum