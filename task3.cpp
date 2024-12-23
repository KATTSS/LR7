#include <iostream>
#include "headLr7.h"


std::string new_sum_in_any_base(std::string &s1, std::string &s2, std::string &numbers, long long baseinl);
std::string my_minus_in_any_base(std::string &s1, std::string &s2, std::string &numbers, long long baseinl);

int main()
{
    long long base_of_count_raz = 0;
    std::string base = vvodunsignedint(base_of_count_raz, 1);
    // std::cout << base_of_count;
    long long baseinl = std::stol(base);
    std::string numbers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (std::stol(base) < 25)
    {
        numbers.erase(std::stol(base), 26 - std::stol(base));
    }
    std::cout << numbers << '\n';
    std::string dec1, dec2;
    vvoddec(dec1);
    vvoddec(dec2);

    std::string transformed1 = transform(dec1, base, numbers, baseinl);
    std::string transformed2 = transform(dec2, base, numbers, baseinl);
    std::cout << dec1 << " " << dec2 << '\n'
              << "transformed1: " << transformed1 << "\ntransformed2: " << transformed2 << '\n';
    std::string sum = new_sum_in_any_base(transformed1, transformed2, numbers, baseinl);
    std::cout << "sum: " << sum << '\n';
    std::cout << "s1: " << transformed1 << "\ns2: " << transformed2 << '\n';
    std::string raznost = my_minus_in_any_base(transformed1, transformed2, numbers, baseinl);
    std::cout << "raznost: " << raznost << '\n';

    return 0;
}


std::string new_sum_in_any_base(std::string &s1, std::string &s2, std::string &numbers, long long baseinl)
{
    std::string min, max, res;
    char minus = '0';
    if (s1[0] == '-' && s2[0] != '-')
    {
        s1.erase(0, 1);
        res = my_minus_in_any_base(s2, s1, numbers, baseinl);
        s1.insert(0, 1, '-');
        return res;
    }
    else if (s2[0] == '-' && s1[0] != '-')
    {
        s2.erase(0, 1);
        res = my_minus_in_any_base(s1, s2, numbers, baseinl);
        s2.insert(0, 1, '-');
        return res;
    }
    else if (s2[0] == '-' && s1[0] == '-')
    {
        minus = '-';
        s1.erase(0, 1);
        s2.erase(0, 1);
    }

    if (s1[1] - '0' >= s2[1] - '0')
    {
        min = s2;
        max = s1;
    }
    else
    {
        min = s1;
        max = s2;
    }

    int difference = (max[1] - '0') - (min[1] - '0');
    int notenough = min[1] - '0';
    while (difference != 0)
    {
        ++notenough;
        min.insert(0, 1, numbers[0]);
        min.insert(1, 1, (notenough + '0'));
        --difference;
    }
    // std::cout << "before sum max: " << max << '\n'
    //           << "min: " << min << '\n';
    long long maxrazrad = max[1] - '0', count = 0;
    long long i = max.length() - 2, j = min.length() - 2;
    short prev = 0;

    while (count <= maxrazrad)
    {
        int sum1 = 0, sum2 = 0;
        sum1 = numbers.find(max[i]);
        if (i >= 1 && max[i + 1] == max[i - 1])
        {
            while (i >= 1 && max[i + 1] == max[i - 1])
            {
                i -= 2;
                sum1 += numbers.find(max[i]);
            }
        }

        sum2 = numbers.find(min[j]);

        if (j >= 1 && min[j + 1] == min[j - 1])
        {
            while (j >= 1 && min[j + 1] == min[j - 1])
            {
                j -= 2;
                sum2 += numbers.find(min[j]);
            }
        }

        int sum = sum1 + sum2 + prev;
        prev = 0;
        if (sum >= baseinl)
        {
            prev = 1;
            sum -= baseinl;
        }

        while (sum > numbers.length() - 1)
        {
            res.insert(0, 1, numbers[numbers.length() - 1]);
            res.insert(1, 1, (count + '0'));
            sum -= numbers.length() - 1;
        }
        res.insert(0, 1, numbers[sum]);
        res.insert(1, 1, (count + '0'));

        i -= 2;
        j -= 2;
        ++count;

        if (i < -1 && j < -1)
        {
            break;
        }
    }

    if (prev != 0)
    {
        res.insert(0, 1, numbers[1]);
        res.insert(1, 1, (count + '0'));
    }
    if (minus == '-')
    {
        s1.insert(0, 1, '-');
        s2.insert(0, 1, '-');
        res.insert(0, 1, minus);
    }
    return res;
}

std::string my_minus_in_any_base(std::string &str1, std::string &str2, std::string &numbers, long long baseinl)
{
    std::string res;
    if (str1[0] == '-' && str2[0] != '-')
    {
        str1.erase(0, 1);
        res = new_sum_in_any_base(str1, str2, numbers, baseinl);
        res.insert(0, 1, '-');
        str1.insert(0,1,'-');
        return res;
    }
    if (str2[0] == '-' && str1[0] != '-')
    {
        str2.erase(0, 1);
        res = new_sum_in_any_base(str1, str2, numbers, baseinl);
        str2.insert(0,1, '-');
        return res;
    }
    int a=0;
    if (str2[0] == '-' && str1[0] == '-')
    {   a=1;
        str1.erase(0, 1);
        str2.erase(0, 1);
        std::swap(str1, str2);
    }
    std::string s1=str1, s2=str2;
    short znak = 0;
    if (s1[1] - '0' < s2[1] - '0')
    {
        znak = 1;
    }
    if (s1[1] - '0' == s2[1] - '0')
    {
        long long i = 1, j = 1;
        int sum1 = 0, sum2 = 0;
        while (sum1 == sum2)
        {
            if (i < s1.length() - 1 && s1[i + 2] == s1[i])
            {
                while (i <= s1.length() && s1[i + 2] == s1[i])
                {
                    sum1 += numbers.find(s1[i - 1]);
                    i += 2;
                }
            }
            else if (i < s1.length() - 1)
            {
                sum1 = numbers.find(s1[i - 1]);
            }

            if (j < s2.length() - 1 && s2[j + 2] == s2[j])
            {
                while (j < s2.length() - 1 && s2[j + 2] == s2[j])
                {
                    sum2 += numbers.find(s2[j - 1]);
                    j += 2;
                }
            }
            else if (j < s2.length() - 1)
            {
                sum2 = numbers.find(s2[j - 1]);
            }
        }
        if (sum2 > sum1)
            znak = 1;
    }
    if (znak == 1)
    {
        std::swap(s1, s2);
    }
    long long i = s1.length() - 2, j = s2.length() - 2, count = 0;
    while (j >= 0)
    {
        int sum1 = 0, sum2 = 0;
        sum1 = numbers.find(s1[i]);
        if (i >= 1 && s1[i + 1] == s1[i - 1])
        {
            while (i >= 1 && s1[i + 1] == s1[i - 1])
            {
                i -= 2;
                sum1 += numbers.find(s1[i]);
                // sum1 += numbers.find(s1[i]);
            }
        }
        // } else if (i >= 0) {
        //     sum1 = numbers.find(s1[i]);
        // }
        sum2 = numbers.find(s2[j]);
        if (j >= 1 && s2[j + 1] == s2[j - 1])
        {
            while (j >= 1 && s2[j + 1] == s2[j - 1])
            {
                j -= 2;
                sum2 += numbers.find(s2[j]);
                // sum2 += numbers.find(s2[j]);
            }
        }
        // } else if (j >= 0) {
        //     sum2 = numbers.find(s2[j]);
        // }

        long long sum = sum1 - sum2;
        if (sum < 0)
        {
            sum = sum1 + baseinl - sum2;
            int odyn = i - 2;
            while (s1[odyn] == numbers[0])
            {
                s1[odyn] = numbers[numbers.length() - 2];
                odyn -= 2;
            }
            s1[odyn] = numbers[numbers.find(s1[odyn]) - 1];
        }
        while (sum > numbers.length() - 1)
        {
            res.insert(0, 1, numbers[numbers.length() - 1]);
            res.insert(1, 1, (count + '0'));
            sum -= numbers.length() - 1;
        }
        res.insert(0, 1, numbers[sum]);
        res.insert(1, 1, count + '0');
        i -= 2;
        j -= 2;
        ++count;
        if (j < -1)
        {
            break;
        }
    }
    res.insert(0, s1.substr(0, i + 2));
    if (znak == 1)
        res.insert(0, 1, '-');
    if (a==1) {str1.insert(0,1,'-'); str2.insert(0,1,'-');}
    return res;
}
