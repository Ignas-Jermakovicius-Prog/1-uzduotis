#include "build.lib.h"
#include "readprint.h"

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