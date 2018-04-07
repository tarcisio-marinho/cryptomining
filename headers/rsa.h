#ifndef RSA_H
#define RSA_H

#include<vector>
#include<string>

int totient(int n);
int prime(int n);
int generate_e(int n);
int generate_prime();
int mod(int x, int y);
int private_key(int tot, int e);
std::vector<int> chy(std::string, int e, int n);
std::string unchy(std::string, int n, int d);


#endif