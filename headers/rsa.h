#ifndef RSA_H
#define RSA_H

#include<vector>
#include<string>

class RSA{
public:
    int totient(int n);
    bool prime(int n);
    int generate_e(int n);
    int mdc(int x, int y);
    int generate_prime();
    int mod(int x, int y);
    int private_key(int tot, int e);
    std::vector<int> chy(std::string, int e, int n);
    std::string unchy(std::string, int n, int d);
private:

}


#endif