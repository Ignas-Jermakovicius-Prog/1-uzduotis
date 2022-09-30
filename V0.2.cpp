#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <iterator>
#include <stdlib.h>
#include "readFile.h"
#include "printStudent.h"

using namespace std;

int main()
{
    int pazkiek;
    vector<stud> S;
    readFile(S, &pazkiek);
    printStudent(S, pazkiek);
    system("pause");
    return 0;
}