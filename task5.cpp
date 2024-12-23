#include <iostream>
#include <cmath>
#include "headLr7.h"

int killer(int *&rab, int death);
int analyzeResults(int *rabik);
int findbochka(int *&rabik, int count);

int main()
{   std::string s;
    int x, i = 1;
    do {vvoddec(s);
    x=std::stoi(s);} while (x<=0 || x>240);
    // std::cout << "otravite bochky: " << '\n';
    // std::cin >> x;

    const int numRabs = 5;
    const int numBottles = 120;

    int **rabs = new int *[numRabs];
    for (int i = 0; i < numRabs; ++i)
    {
        rabs[i] = new int[numBottles]{0};
    }

    int r[numRabs] = {0}; // Индексы для каждого раба

    while (i <= 80)
    {
        for (; r[0] < 16; i++, r[0]++)
            rabs[0][r[0]] = i;
        for (; r[1] < 16; i++, r[1]++)
            rabs[1][r[1]] = i;
        for (; r[2] < 16; i++, r[2]++)
            rabs[2][r[2]] = i;
        for (; r[3] < 16; i++, r[3]++)
            rabs[3][r[3]] = i;
        for (; r[4] < 16; i++, r[4]++)
            rabs[4][r[4]] = i;
    }
    //std::cout << "i:" << i << '\n';
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
    }

    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[2][r[2]++] = i;
    }

    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[3][r[3]++] = i;
    }

    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[4][r[4]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[3][r[3]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[4][r[4]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[2][r[2]++] = i;
        rabs[4][r[4]++] = i;
    }
    for (int j = 0; j < 8; ++i, ++j)
    {
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }
    //std::cout << "i:" << i << '\n';
    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[3][r[3]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[2][r[2]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 4; ++i, ++j)
    {
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 2; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
    }

    for (int j = 0; j < 2; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 2; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[1][r[1]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 2; ++i, ++j)
    {
        rabs[0][r[0]++] = i;
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }

    for (int j = 0; j < 2; ++i, ++j)
    {
        rabs[1][r[1]++] = i;
        rabs[2][r[2]++] = i;
        rabs[3][r[3]++] = i;
        rabs[4][r[4]++] = i;
    }
    // std::cout << "i:" << i << '\n';
    // for (int j = 0; j < r[0]; ++j)
    //     std::cout << rabs[0][j] << " ";
    // std::cout << std::endl;
    // std::cout << '\n';
    // for (int j = 0; j < r[1]; ++j)
    //     std::cout << rabs[1][j] << " ";
    // std::cout << std::endl;
    // std::cout << '\n';
    // for (int j = 0; j < r[2]; ++j)
    //     std::cout << rabs[2][j] << " ";
    // std::cout << std::endl;
    // std::cout << '\n';
    // for (int j = 0; j < r[3]; ++j)
    //     std::cout << rabs[3][j] << " ";
    // std::cout << std::endl;
    // std::cout << '\n';
    // for (int j = 0; j < r[4]; ++j)
    //     std::cout << rabs[4][j] << " ";
    // std::cout << std::endl;

    int *rabik = new int[numRabs];
    rabik[0] = killer(rabs[0], x);
    rabik[1] = killer(rabs[1], x);
    rabik[2] = killer(rabs[2], x);
    rabik[3] = killer(rabs[3], x);
    rabik[4] = killer(rabs[4], x);
    for (int i = 0; i < 5; i++)
    {
        std::cout << rabik[i] << '\n';
    }
    int count = 0;
    for (int i = 0; i < 5; ++i)
    {
        if (rabik[i] == 1)
            ++count;
    }
    std::cout << "count: " << count << '\n';
    int l = 0, rr = 0;

    //0 killed 
    if (count==0) {
        l=212; rr=240;
        for (int bottle = 0; bottle <= 30; ++bottle)
        {
            if (bottle & (1 << 0))
            {
                rabs[0][bottle] = bottle;
            }
            if (bottle & (1 << 1))
            {
                rabs[1][bottle] = bottle;
            }
            if (bottle & (1 << 2))
            {
                rabs[2][bottle] = bottle;
            }
            if (bottle & (1 << 3))
            {
                rabs[3][bottle] = bottle;
            }
            if (bottle & (1 << 4))
            {
                rabs[4][bottle] = bottle;
            }
        }
        int death=x-l;
        //std::cout << "death " << death << '\n';
        rabik[0] = killer(rabs[0], death);
        rabik[1] = killer(rabs[1], death);
        rabik[2] = killer(rabs[2], death);
        rabik[3] = killer(rabs[3], death);
        rabik[4] = killer(rabs[4], death);
        std::cout << "bochka: " << findbochka(rabik, 5)+l << '\n';
    }

    //1 killed
    if (count == 1)
    {
        int index = 0;
        for (int i = 0; i < 5; ++i)
        {
            if (rabik[i] == 1)
            index = i;
        }
        l = 16 * index;
        rr = 16 * (index + 1);
        for (int bottle = 0; bottle < 16; ++bottle)
        {
            if (bottle & (1 << 0))
            {
                rabs[0][bottle] = bottle;
            }
            if (bottle & (1 << 1))
            {
                rabs[1][bottle] = bottle;
            }
            if (bottle & (1 << 2))
            {
                rabs[2][bottle] = bottle;
            }
            if (bottle & (1 << 3))
            {
                rabs[3][bottle] = bottle;
            }
        }
        //std::cout << l << " " << rr << '\n';
        int death=x-l;
        //std::cout << "death " << death << '\n';
        rabik[0] = killer(rabs[0], death);
        rabik[1] = killer(rabs[1], death);
        rabik[2] = killer(rabs[2], death);
        rabik[3] = killer(rabs[3], death);
        int bochka = 0;
        // for (int j = 0; j < 4; ++j)
        // {
        //     if (rabik[j] == 1)
        //     {
        //         bochka += pow(2, j);
        //        // std::cout << bochka << '\t';
        //     }
        // }
        std::cout <<"bochka " << findbochka(rabik, 5-count) + l<< std::endl;
    }

    //2 killed
    if (count == 2)
    {
        l = 81;
        rr = 88;
        int f = 1;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5; i2++)
            {
                if (rabik[i1] && rabik[i2])
                {
                    f = 0;
                    break;
                }
                l += 8;
                rr += 8;
            }
        }
        std::cout << "l= " << l << '\n';
        for (int bottle = 0; bottle < 8; ++bottle)
        {
            if (bottle & (1 << 0))
            {
                rabs[0][bottle] = bottle;
            }
            if (bottle & (1 << 1))
            {
                rabs[1][bottle] = bottle;
            }
            if (bottle & (1 << 2))
            {
                rabs[2][bottle] = bottle;
            }
        }
        rabik[0] = killer(rabs[0], x - l);
        rabik[1] = killer(rabs[1], x - l);
        rabik[2] = killer(rabs[2], x - l);

        std::cout << "bochka: " << findbochka(rabik, 5-count)+l << '\n';


        for (int i = 0; i < numRabs; ++i)
        {
            delete[] rabs[i];
        }
        delete[] rabs;
        delete[] rabik;
        return 0;
    }

    //3 killed
    if (count == 3)
    {
        int f = 1;
        l = 161;
        rr = 164;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5 && f; i2++)
            {
                for (int i3 = i2 + 1; i3 < 5; i3++)
                {
                    if (rabik[i1] && rabik[i2] && rabik[i3])
                    {
                        f = 0;
                        break;
                    }
                    l += 4;
                    rr += 4;
                }
            }
        }
        std::cout << "l " << l << " r " << rr << '\n';
         for (int bottle = 0; bottle < 4; ++bottle)
        {
            if (bottle & (1 << 0))
            {
                rabs[0][bottle] = bottle;
            }
            if (bottle & (1 << 1))
            {
                rabs[1][bottle] = bottle;
            }}
        rabik[0] = killer(rabs[0], x - l);
        rabik[1] = killer(rabs[1], x - l);
        std::cout << "bochka: " << findbochka(rabik, 5-count) << " "<< findbochka(rabik, 5-count) + l<< '\n';
    }

    //4 killed
    if (count == 4)
    {
        int f = 1;
        l = 201;
        rr = 202;
        for (int i1 = 0; i1 < 5 && f; i1++)
        {
            for (int i2 = i1 + 1; i2 < 5 && f; i2++)
            {
                for (int i3 = i2 + 1; i3 < 5 && f; i3++)
                {
                    for (int i4 = i3 + 1; i4 < 5; i4++)
                    {
                        if (!rabik[i1] && !rabik[i2] && !rabik[i3] && !rabik[i4])
                        {
                            f = 0;
                            break;
                        }
                        l += 2;
                        rr += 2;
                    }
                }
            }
        }
        std::cout << "l " << l << " r " << rr << '\n';
        rabik[0] = killer(rabs[0], x - l);
        if (rabik[0]==1) std::cout << "bochka: " << l << '\n';
    }

    for (int i = 0; i < numRabs; ++i)
    {
        delete[] rabs[i];
    }
    delete[] rabs;
    delete[] rabik;

    return 0;
}

int killer(int *&rab, int death)
{
    for (int i = 0; i < 120; ++i)
    {
        if (rab[i] == death)
        {
            return 1; // Возвращаем 1, если найдено совпадение
        }
    }
    return 0; // Возвращаем 0, если совпадений не найдено
}

int analyzeResults(int *rabik)
{
    int poisonedBottle = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (rabik[i] == 1)
        {
            poisonedBottle |= (1 << i);
            std::cout << poisonedBottle;
        }
    }
    return poisonedBottle;
}

int findbochka(int *&rabik, int count) {
     int bochka = 0;
        for (int j = 0; j < count; ++j)
        {
            if (rabik[j] == 1)
            {
                bochka += pow(2, j);
               // std::cout << bochka << '\t';
            }
        }
       return bochka;
}