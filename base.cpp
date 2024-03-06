// #include <iostream>
// #include <ginac/ginac.h>
// #include "struc.h"
// #include "R.h"
#include "base.h"
using namespace std;
using namespace GiNaC;
// using namespace base;

matrix simplifyb(matrix b){
	for(short int i=0; i<3; i++){
		for(short int j=0; j<1; j++)
			b(i, j) = evalf(b(i, j));
	}
	return b;
}

matrix base(){
	lst st = struc();
    
    // Defining the first rotation-anchor point
	matrix b1 = matrix(3, 1);
	b1[1] = evalf(-st[0]*cos(st[1]));
	b1[2] = evalf(-st[0]*sin(st[1]));

	// Remaining 2-6 rotation-anchor points
	matrix b2 = (Rx(-2*st[1])).mul(b1);
	matrix b3 = (Rx(-2*Pi/3)).mul(b1);
	matrix b4 = (Rx(-2*Pi/3)).mul(b2);
	matrix b5 = (Rx(-2*Pi/3)).mul(b3);
	matrix b6 = (Rx(-2*Pi/3)).mul(b4);

	b1 = simplifyb(b1);
	b2 = simplifyb(b2);
	b3 = simplifyb(b3);
	b4 = simplifyb(b4);
	b5 = simplifyb(b5);
	b6 = simplifyb(b6);

	matrix base_matrix = {{b1}, {b2}, {b3}, {b4}, {b5}, {b6}};

	// base_matrix = base_matrix.simplify_indexed();

	return base_matrix;

}

// int main(){
// 	matrix m = base();
// 	cout<<m[0]<<endl;
// 	cout<<m[1]<<endl;
// 	cout<<m[2]<<endl;
// 	cout<<m[3]<<endl;
// 	cout<<m[4]<<endl;
// 	cout<<m[5]<<endl;

// 	return 0;
// }