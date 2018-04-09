#ifndef RSA_H
#define RSA_H

#include<vector>
#include<string>
#include <math.h>
#include <iostream>

typedef unsigned long int long_int;

class RSA{
public:
    RSA();
    long_int get_private_key();
    std::vector<long_int> get_public_keys();
    std::vector<long_int> chy(std::string, int e, int n);
    std::string unchy(std::string, int n, int d);

private:
    void generate_keys();
    long_int generate_private_key(long_int tot, long_int e);
    bool isprime(int n);
    long_int totient(long_int n);
    long_int generate_prime();
    long_int RSA::generate_random(int from = 2, int to=pow(2,1024));
    int generate_e(long_int toti_n);
    int mdc(int x, int y);
    long_int mod(long_int x, long_int y);

    long_int p, q, n, toti_n, e, d;
}


#endif