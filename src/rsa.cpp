#include "../headers/rsa.h"

int RSA::totient(int n){
    if(prime(n)){
        return n - 1;
    }
}


bool RSA::prime(int n){
    int i = 1, times = 0;

    while(i <= n){
        if(n%i == 0){
            times++;
        }
        i++;
    }

    if(times == 2){
        return true;
    }
    return false;
}


int RSA::generate_e(int n){
    while(true){
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


int RSA::generate_prime(){
    while(true){
        int x = RANDOM(1, 100); // 2^2048 standart
        if(prime(x)){
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


std::vector<int> RSA::chy(std::string, int e, int n){
    
}


std::string RSA::unchy(std::string, int n, int d){
    
}
