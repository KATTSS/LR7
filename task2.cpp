#include <iostream>
#include "headLr7.h"
int main()
{
    std::string s1;
    // do
    // {
        vvoddec(s1);
    //} while (s1.find('-', 1) != std::string::npos);
    // std::cout << s1 << '\n';

    std::string s2;
    // do
    // {
        vvoddec(s2);
    //} while (s2.find('-', 1) != std::string::npos);
    // std::cout << s2 << '\n';
    std::string trans1 = in_binary_by_del(s1);
    std::string trans2 = in_binary_by_del(s2);
    // transforminbinary(s1);
    std::cout << "s1:" << s1 << " " << trans1 <<'\n';
    // transforminbinary(s2);
    std::cout << "s2:" << s2 << " " << trans2 << '\n';
    straight_into_odd(trans1);
    straight_into_odd(trans2);
    std::cout << "odd trans1: " << trans1 << '\n' << "odd trans2: " << trans2 << '\n';
    std::string sum_in_odd = sum_two_strings(trans1, trans2);
    straight_into_odd(sum_in_odd);
    std::cout << "Sum in Binary: " << sum_in_odd << '\n';
    // std::string sim_in_dec=from_bin_to_dec(sum_in_odd);
    // std::cout << "Sum in Decimal: " << sim_in_dec << '\n';
    return 0;
}