// #include <iostream>
// #include <ginac/ginac.h>
#include "R.h"
using namespace std;
using namespace GiNaC;

// matrix Rx(symbol th){
// 	matrix rotx = {
// 	    {1,  0,                 0},
// 	    {0,  cos(th),    -sin(th)},
// 	    {0,  sin(th),     cos(th)},
// 	    };

// 	return rotx;
// }

// matrix Ry(symbol th){
// 	matrix rotx = {
// 	    {cos(th),   0,     sin(th)},
// 	    {0,         1,    -sin(th)},
// 	    {-sin(th),  0,     cos(th)},
// 	    };

// 	return rotx;
// }

// matrix Rz(symbol th){
// 	matrix rotx = {
// 	    {cos(th),   -sin(th),     0},
// 	    {-sin(th),  cos(th),      0},
// 	    {0,         0,            1},
// 	    };

// 	return rotx;
// }

// matrix Rx(float th){
// 	matrix rotx = {
// 	    {1,  0,                 0},
// 	    {0,  cos(th),    -sin(th)},
// 	    {0,  sin(th),     cos(th)},
// 	    };

// 	return rotx;
// }

// matrix Ry(float th){
// 	matrix rotx = {
// 	    {cos(th),   0,     sin(th)},
// 	    {0,         1,    -sin(th)},
// 	    {-sin(th),  0,     cos(th)},
// 	    };

// 	return rotx;
// }

// matrix Rz(float th){
// 	matrix rotx = {
// 	    {cos(th),   -sin(th),     0},
// 	    {-sin(th),  cos(th),      0},
// 	    {0,         0,            1},
// 	    };

// 	return rotx;
// }

matrix Rx(ex th){
	matrix rotx = {
	    {1,  0,                 0},
	    {0,  evalf(cos(th)),    evalf(-sin(th))},
	    {0,  evalf(sin(th)),    evalf(cos(th))},
	    };

	return rotx;
}

matrix Ry(ex th){
	matrix roty = {
	    {evalf(cos(th)),   0,     evalf(sin(th))},
	    {0,         1,    		 0},
	    {evalf(-sin(th)),  0,     evalf(cos(th))},
	    };

	return roty;
}

matrix Rz(ex th){
	matrix rotz = {
	    {evalf(cos(th)),   evalf(-sin(th)),     0},
	    {evalf(sin(th)),   evalf(cos(th)),      0},
	    {0,         0,            1},
	    };

	return rotz;
}

// int main(){
// 	symbol th("θ");
// 	// matrix R = Rx(th);
// 	// matrix R = Ry(th);
// 	// matrix R = Rz(th);
// 	cout<<Rx(th)<<endl;
// 	cout<<Ry(th)<<endl;
// 	cout<<Rz(th)<<endl;
// 	// cout<<R<<endl;
// 	// cout<<R<<endl;
// }