#include "countMedian.h"
using namespace std;

float countMedian(vector<int> paz) //funkcija skaiciuojanti mediana
{
    int s = 0;
    for (int i = 0; i < 10; i++)
    {
        if (paz[i] != 0)
        {
            s++;
        }
        if (paz[i] == -1)
        {
            paz[i] = 0;
            s--;
            break;
        }
    }
    if (s % 2 == 0)
    {
        return float(((paz[s / 2 - 1]) + (paz[(s / 2)])) / 2.0);
    }
    else
    {
        return float(paz[(s / 2)]);
    }
}