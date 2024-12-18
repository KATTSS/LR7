#include <iostream>
#include "headLr7.h"
//#include "../LR6/headerLR6.h" 
int main () {
    std::string s;
    int size = vvodbin(s);
    std::cout << size << " " << s << '\n';
    
    if (s.at(0)=='0') std::cout << "Chislo v obratnom kode: " << s << '\n';
    else if (s.at(0)=='1' && size>1) 
    negativvobratnyy(s, size);
   
   
    std::cout << s << '\n';
    return 0;
}