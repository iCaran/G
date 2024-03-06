#ifndef G_Jacobian_H
#define G_Jacobian_H

#include <iostream>
#include <ginac/ginac.h>
// #include "struc.cpp"
// #include "R.cpp"
// #include "top.cpp"
// #include "base.cpp"
#include "inv_kine_sym.cpp"

// GiNaC::matrix inv_kine_sym(GiNaC::matrix thi);

void G_Jacobian(GiNaC::matrix q);

#endif // G_Jacobian_H