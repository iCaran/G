#ifndef JACOBIAN_H
#define JACOBIAN_H

#include <iostream>
#include <ginac/ginac.h>

GiNaC::matrix jacobian(GiNaC::matrix func, GiNaC::matrix X);

#endif // JACOBIAN_H