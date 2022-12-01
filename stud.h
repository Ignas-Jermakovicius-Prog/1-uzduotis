#pragma once
#include "build_lib.h";
using namespace std;

struct stud {
    string Vard, Pav;
    vector<int> paz;
    int egz;
    float gal;
    float med;
    bool operator==(const struct stud& v) const {
        return v.Vard == Vard && v.Pav == Pav && v.gal == gal;
    }
};