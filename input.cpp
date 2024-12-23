#include <iostream>
#include <string>
#include <cmath>
#include "headLr7.h"
int vvodbin(std::string &s)
{
    int size;
    do
    {
        std::cout << "vvedite stroky:" << '\n';
        std::getline(std::cin, s);
        size = s.length();
    } while (s.find_first_not_of("10") != std::string::npos);
    return size;
}

void negativvobratnyy(std::string &s, int size)
{
    if (s.find('1', 1) == std::string::npos)
    {
        for (int i = 1; i < size; ++i)
        {
            if (s.at(i) == '0')
            {
                s.insert(i, "1");
                s.erase(i + 1, 1);
            }
        }
        return;
    }
    invertion(s);
    if (s.at(size - 1) == '0')
    {
        s.at(size - 1) = '1';
    }
    else
    {
        int i = size;
        while (s.at(i) != '0')
        {
            s.at(i) = '0';
            --i;
        }
        s.at(i) = '1';
    }
    invertion(s);
}
void invertion(std::string &s)
{
    int size = s.length();
    for (int i = 1; i < size; ++i)
    {
        if (s.at(i) == '0')
        {
            s.insert(i, "1");
            s.erase(i + 1, 1);
        }
        else
        {
            s.insert(i, "0");
            s.erase(i + 1, 1);
        }
    }
}
void vvoddec(std::string &s)
{
    // int size;
    do
    {
        do
        {
            std::cout << "vvedite chislo:" << '\n';
            std::getline(std::cin, s);
            // size = s.length();
        } while (s.find_first_not_of("-0123456789") != std::string::npos);
    } while (s.find('-', 1) != std::string::npos);
}

std::string in_binary_by_del(std::string s)
{
    std::string trans;
    if (s.at(0) == '-')
    {
        trans = '1';
        s.erase(0, 1);
    }
    else
        trans = '0';
    long long r = s.length() - 1;
    while (!s.empty())
    {
        std::string new_s;
        int carry = 0;
        for (char c : s)
        {
            int num = carry * 10 + (c - '0');
            carry = num % 2;
            new_s += (num / 2) + '0';
        }

        if (carry == 0)
        {
            trans.insert(1, "0");
        }
        else
        {
            trans.insert(1, "1");
        }

        while (!new_s.empty() && new_s[0] == '0')
        {
            new_s.erase(0, 1);
        }

        s = new_s;
    }
    return trans;
}

void straight_into_odd(std::string &s)
{
    if (s.at(0) == '0')
        return;
    long long size = s.length();
    for (int i = 1; i < size; i++)
    {
        if (s[i] == '0')
            s.insert(i, "1");
        else
            s.insert(i, "0");
        s.erase(i + 1, 1);
    }
}

std::string sum_two_strings(std::string &s1, std::string &s2)
{
    long long size1 = s1.length();
    long long size2 = s2.length();

    std::string min;
    std::string max;
    if (size1 <= size2)
    {
        min = s1;
        max = s2;
    }
    else
    {
        min = s2;
        max = s1;
    }

    min.insert(0, std::abs(size1 - size2), '0');
    std::cout << "min: " << min << '\n'
              << "max: " << max << '\n';
    std::string sum;
    char prev = '0';
    for (long long i = std::max(size1, size2) - 1; i >= 0; --i)
    {
        if (min[i] == '0' && max[i] == '0' && prev == '0')
            sum.insert(0, "0");
        else if (min[i] == '0' && max[i] == '0' && prev == '1')
        {
            sum.insert(0, "1");
            prev = '0';
        }
        else if (min[i] == '0' && max[i] == '1' && prev == '0')
            sum.insert(0, "1");
        else if (min[i] == '1' && max[i] == '0' && prev == '0')
            sum.insert(0, "1");
        else if (min[i] == '1' && max[i] == '1' && prev == '0')
        {
            sum.insert(0, "0");
            prev = '1';
        }
        else if (min[i] == '1' && max[i] == '0' && prev == '1')
        {
            sum.insert(0, "0");
        }
        else if (min[i] == '0' && max[i] == '1' && prev == '1')
        {
            sum.insert(0, "0");
        }
        else if (min[i] == '1' && max[i] == '1' && prev == '1')
        {
            sum.insert(0, "1");
        }
        std::cout << sum << '\n';
    }
    if (prev != '0')
        sum_num_and_string(sum, prev);
    return sum;
}
void sum_num_and_string(std::string &s1, char prev)
{
    for (long long i = s1.length() - 1; prev != '0'; --i)
    {
        if (s1[i] == '0' && prev == '1')
        {
            s1[i] = '1';
            prev = '0';
        }
        if (s1[i] == '1' && prev == '1')
            s1[i] = '0';
    }
}

std::string from_bin_to_dec(std::string &s)
{
    long long size = s.length();

    int count = 0, prevcount = 0;
    std::string summ = "0";
    std::string temp = "1";
    for (long long i = size - 1; i >= 0; --i)
    {
        if (s[i] == '1')
        {
            int peren = 0;
            long long tempsize = temp.length() - 1;
            while (prevcount <= count)
            {
                ++prevcount;
                for (long long j = tempsize; j >= 0; --j)
                {
                    int one = (temp[j] - '0') * 2 + peren;
                    peren = 0;
                    if (one > 9)
                    {
                        peren = 1;
                        one -= 10;
                    }
                    temp[j] = one + '0';
                }
            }

            prevcount = count;
            long_sum(summ, temp);
        }
        ++count;
    }
    // if (s[0] == '1')
    //     summ = "-" + summ;
    return summ;
}

void long_sum(std::string &s, std::string &s_temp)
{
    long long s_size = s.length();
    long long temp_size = s_temp.length();
    std::string min;
    std::string max;
    if (s_size <= temp_size)
    {
        min = s;
        max = s_temp;
    }
    else
    {
        min = s_temp;
        max = s;
    }
    min.insert(0, std::abs(s_size - temp_size), '0');
    short prev = 0;
    for (long long i = max.length() - 1; i >= 0; --i)
    {
        short sum = (max[i] - '0') + (min[i] - '0') + prev;
        prev = 0;
        if (sum > 9)
        {
            prev = 1;
            sum -= 10;
        }
        max[i] = '0' + sum;
    }
    s = max;
}

std::string vvodunsignedint(long long &x, int m)
{
    std::string s;
    do
    {
        if (m==1) std::cout << "vvedite osnovanie systemy schislenya:" << '\n';
        if (m==2) std::cout << "otravite bochky: " << '\n';
        std::getline(std::cin, s);
    } while (s.find_first_not_of("0123456789") != std::string::npos || s=="1");
    x = s.length();
    return s;
}
std::string transform(std::string &dec, std::string &base, std::string &numbers, long long baseinl)
{
    long long basesize = base.length();
    long long decsize = dec.length();
    long long count = 0;
    char minus = '0';
    if (dec[0] == '-')
    {
        minus = '-';
        dec.erase(0, 1);
    }
    std::string transformed, letterview;
    if (decsize < basesize)
    {
        transformed = numbers[0] + (count + '0');
    }
    std::string chastnoye;
    while (dec.length() > 0)
    {
        long long temp = 1;
        while (temp != 0)
        {
            std::string s_temp = dec.substr(0, basesize);
            temp = std::stol(s_temp);
            if (temp <= baseinl && dec.length() > basesize)
            {
                s_temp = dec.substr(0, basesize + 1);
                temp = std::stol(s_temp);
            }
            // std::cout << "s_temp on iteration: " << s_temp << '\n';
            dec.erase(0, s_temp.length());
            // std::cout << "dec after removing on iteration: " << dec << '\n';
            s_temp = std::to_string((temp % baseinl)); // Остаток при делении конкретной части числа, который переходит в следующий шаг
            int ostatok = temp % baseinl;
            dec.insert(0, s_temp);
            // std::cout << "new dec on iteration: " << dec << '\n';
            // std::cout << "temp before del: " << temp << '\n';
            temp /= baseinl;
            // std::cout << "temp after del: " << temp << '\n';
            if (temp == 0)
            {
                // std::cout << "ost: " << ostatok << '\n';
                transformed.insert(0, s_temp); // Записываем последний остаток в итоговое трансформированное число
                while (ostatok > numbers.length() - 1)
                {
                    letterview.insert(0, 1, numbers[numbers.length() - 1]);
                    letterview.insert(1, 1, (count + '0'));
                    ostatok -= numbers.length() - 1;
                }
                letterview.insert(0, 1, numbers[ostatok]);
                letterview.insert(1, 1, (count + '0'));
                ++count;
                // std::cout << "letters: " << letterview << '\n';
            }
            else
            {
                chastnoye.append(std::to_string(temp)); // Записываем в частное результат целого деления (потом частное должно снова перейти в dec)
                // std::cout << "chastnoye on iteration: " << chastnoye << '\n';
            }
        }
        dec.erase(0);
        dec.insert(0, chastnoye);
        // std::cout << "\nnext etap for dec: " << dec << '\n' << '\n';
        chastnoye.erase(0);
    }
    // std::cout << "letters equivalent: " << letterview << '\n';
    if (minus == '-')
        letterview.insert(0, 1, minus);
    return letterview;
}

