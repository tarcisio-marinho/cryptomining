#ifndef RSA_H
#define RSA_H

#include<vector>
#include<string>

class RSA{
public:
    RSA();
    void generate_keys();
    int get_private_key();
    std::vector<int> get_public_keys();
    std::vector<int> chy(std::string, int e, int n);
    std::string unchy(std::string, int n, int d);

private:
    int private_key(int tot, int e);
    bool isprime(int n);
    int totient(int n);
    int generate_prime(int size=2048);
    int generate_e(int n);
    int mdc(int x, int y);
    int mod(int x, int y);

    int p, q, n, toti_n, e, d;
}


#endif