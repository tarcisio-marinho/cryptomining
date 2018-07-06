#ifndef BASE_64
#define BASE_64
#include <string>
#include <iostream>
#include <vector>

class Base64{
public:
    static std::string base64_encode(const std::string &in);
    static std::string base64_decode(const std::string &in);
};

#endif
