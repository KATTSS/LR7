#include <iostream>
#include "headLr7.h"
bool kratnost_prostogo (long long num, int d, int s);
int main () {
    std::string nums;
    vvoddec(nums);
    long long num=std::stoll(nums);
    int d1=3, d2=79, d3=151;
    int s1=2, s2=40, s3=76;
    if (kratnost_prostogo(num, d1, s1)==1) std::cout << "Chislo " << num << " kratno " << d1 << '\n';
    if (kratnost_prostogo(num, d2, s2)==1) std::cout << "Chislo " << num << " kratno " << d2 << '\n';
    if (kratnost_prostogo(num, d3, s3)==1) std::cout << "Chislo " << num << " kratno " << d3 << '\n';

    return 0;
}

bool kratnost_prostogo (long long num, int d, int s) {
    while (num>d) {
        if(num & 1) {
            num>>=1;
            num+=s;
        } else num>>=1;
    } 
    std::cout << num << '\n';
    if (num==d) return 1;
    else return 0;
}