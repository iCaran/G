#ifndef INV_KINE_SYM_H
#define INV_KINE_SYM_H

#include <iostream>
#include <ginac/ginac.h>
#include "struc.cpp"
#include "R.cpp"
#include "top.cpp"
#include "base.cpp"
#include <fstream> // Include the fstream library for file operations
// #include <ctime>
#include <chrono>

GiNaC::matrix inv_kine_sym(GiNaC::matrix thi);

#endif // INV_KINE_SYM_H