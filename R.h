#ifndef R_H
#define R_H

#include <iostream>
#include <ginac/ginac.h>

// GiNaC::matrix Rx(GiNaC::symbol th);
// GiNaC::matrix Ry(GiNaC::symbol th);
// GiNaC::matrix Rz(GiNaC::symbol th);

// GiNaC::matrix Rx(float th);
// GiNaC::matrix Ry(float th);
// GiNaC::matrix Rz(float th);

GiNaC::matrix Rx(GiNaC::ex th);
GiNaC::matrix Ry(GiNaC::ex th);
GiNaC::matrix Rz(GiNaC::ex th);

#endif // R_H