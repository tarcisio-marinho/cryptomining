#include "../headers/rsa.h"

RSA::RSA(){
    generate_keys();
    srand (static_cast <unsigned> (time(0)));
}

int RSA::get_private_key(){



}


std::vector<int> RSA::get_public_keys(){
    
}


std::vector<int> RSA::chy(std::string, int e, int n){
    

}


std::string RSA::unchy(std::string, int n, int d){
    
}


void RSA::generate_keys(){
    this->p = generate_prime();
    this->q = generate_prime();
}





int RSA::totient(int n){
    if(isprime(n)){
        return n - 1;
    }
}


bool RSA::isprime(int n){
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}


int RSA::generate_e(int n){
    while(true){
        // -1 + static_cast <int> (rand()) /( static_cast <int> (RAND_MAX/(1-(-1))));
        int e = RANDOM(2, LIMITE);
        if(this->mdc(n, e) == 1){
            return e;
        }
    }
}

int RSA::mdc(int x, int y){
    int rest = 1;
    while(y != 0){
        rest = x%y;
        x = y;
        y = rest;
    }
    return x;
}


int RSA::generate_prime(int size=2048){
    while(true){
        int x = RANDOM(1, 100); // 2^2048 standart
        if(isprime(x)){
            return x;
        }
    }
}


int RSA::mod(int x, int y){
    if(x < y){
        return x;
    }
    return x%y;
}


int RSA::private_key(int tot, int e){
    int d = 0;
    while(mod(d*e, tot) != 1){
        d++;
    }
    return d;
}

