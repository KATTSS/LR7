#include <iostream>
#include "headLr7.h"

std::string transform(std::string &dec, std::string &base, std::string &numbers);
int main()
{
    long long base_of_count_raz = 0;
    std::string base = vvodunsignedint(base_of_count_raz);
    // std::cout << base_of_count;
    std::string numbers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (std::stol(base) < 25)
    {
        numbers.erase(std::stol(base), 26 - std::stol(base));
    }
    std::cout << numbers << '\n';
    std::string dec1, dec2;
    vvoddec(dec1);
    vvoddec(dec2);
    // dec1 = to_new_base(dec1, base, numbers);
    // dec2 = to_new_base(dec2, base, numbers);
    std::string transformed = transform(dec1, base, numbers);
    std::cout << dec1 << " " << dec2 << '\n'
              << "transformed: " << transformed << '\n';

    return 0;
}

std::string transform(std::string &dec, std::string &base, std::string &numbers)
{
    long long basesize = base.length();
    long long decsize = dec.length();
    long long baseinl = std::stol(base);
    long long count = 0;
    std::string transformed, letterview;
    if (decsize < basesize)
        transformed = numbers[0] + (count + '0');
    std::string chastnoye;
    while (dec.length() > 0)
    {
        long long temp = 1;
        while (temp != 0)
        {
            std::string s_temp = dec.substr(0, basesize);
            temp = std::stol(s_temp);
            if (temp < baseinl && dec.length() > basesize)
            {
                s_temp.erase(0);
                s_temp = dec.substr(0, basesize + 1);
                temp = std::stol(s_temp);
            }
            std::cout << "s_temp on iteration: " << s_temp << '\n';
            //
            dec.erase(0, s_temp.length());
            std::cout << "dec after removing on iteration: " << dec << '\n';
            s_temp = std::to_string((temp % baseinl)); // остаток при делении конкретной састи числе, который переходит в следующий шаг
            int ostatok = temp % baseinl;
            dec.insert(0, s_temp);
            std::cout << "new dec ob iteration: " << dec << '\n';
            temp /= baseinl;
            std::cout << "temp after del: " << temp << '\n';
            if (temp == 0)
            {
                transformed.insert(0, s_temp); // записывем последний остаток в итоговое трансформированное число
                while (ostatok > 25)
                {
                    letterview.insert(0, 1, numbers[25]);
                    letterview.insert(1, 1, (count + '0'));
                    ostatok-=25;
                }
                letterview.insert(0, 1, numbers[ostatok]);
                letterview.insert(1, 1, (count + '0'));
                ++count;
            }
            else
                chastnoye.append(std::to_string(temp)); // записываем в частное результат интового деления (потом частное должно снова перейти в дек)
            std::cout << "chastnoye on iteration: " << chastnoye << '\n';
        }
        dec.erase(0);
        dec.insert(0, chastnoye);
        std::cout << "\nnext etap for dec: " << dec << '\n'
                  << '\n';
        chastnoye.erase(0);
       
    }
    std::cout << "letters equivalent: " << letterview;
    return transformed;
}