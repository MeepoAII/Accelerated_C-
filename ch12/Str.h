#ifndef GUARD_STR_H
#define GUARD_STR_H

#include "Vec.h"

#include <iostream>
#include <cstring>

class Str {
public:
    typedef Vec<char>::size_type size_type;
    Str() {}
    Str(size_type n, char c):data(n, c){};
    Str(const char* cp) {
        std::copy(cp, cp+std::strlen(cp), std::back_inserter(data));
    }
    template<class In> Str(In b, In e) {
        std::copy(b, e, std::back_inserter(data));
    }

    size_type size() const { return data.size(); }

    char& operator[](size_type i) { return data[i]; }
    const char& operator[](size_type i) const { return data[i]; }

private:
    Vec<char> data;
};

#endif // GUARD_STR_H