// #include <iostream>
// #include <ginac/ginac.h>
// #include "struc.h"
// #include "R.h"
#include "top.h"
using namespace std;
using namespace GiNaC;

matrix simplifyt(matrix b){
	for(short int i=0; i<3; i++){
		for(short int j=0; j<3; j++)
			b(i, j) = evalf(b(i, j));
	}
	return b;
}

matrix top(matrix q_EE){
	lst st = struc();

	// Transformation matrix of End-effector (Top frame) WRT Base frame
    matrix R=(Rx(q_EE[5]).mul(Ry(q_EE[4]))).mul(Rz(q_EE[3]));  // Taking roll about Z, pitch about Y and yaw about X (See my IKin convention)
    // T=[R(1,:),q_EE(1);R(2,:),q_EE(2);R(3,:),q_EE(3);0,0,0,1];
    matrix T={{R[0], R[1], R[2], q_EE[0]}, {R[3], R[4], R[5], q_EE[1]}, {R[6], R[7], R[8], q_EE[2]}, {0,0,0,1}};
    // cout<<T<<endl;

    R = simplifyt(R);
    T = simplifyt(T);

    // cout<<R[0]<<endl;
    // cout<<R[1]<<endl;
    // cout<<R[2]<<endl;
    // cout<<R[3]<<endl;
    // cout<<R[4]<<endl;
    // cout<<R[5]<<endl;
    // cout<<R[6]<<endl;
    // cout<<R[7]<<endl;
    // cout<<R[8]<<endl;

    // Defining complete top platform

    // Defining the first top spherical vertex 
    matrix t1 = matrix(3,1);
    t1[0] = 0;
    t1[1] = evalf(-st[2]*cos(st[3]));
    t1[2] = evalf(-st[2]*sin(st[3]));

    // Remaining 2-6 rotation-anchor points
    matrix t2 = Rx(-2*st[3]).mul(t1);
	matrix t3 = Rx(-2*Pi/3).mul(t1);
	matrix t4 = Rx(-2*Pi/3).mul(t2);
	matrix t5 = Rx(-2*Pi/3).mul(t3);
	matrix t6 = Rx(-2*Pi/3).mul(t4);

	t1 = T.mul({{t1[0]}, {t1[1]}, {t1[2]}, {1}});
	t1 = {{evalf(t1[0])}, {evalf(t1[1])}, {evalf(t1[2])}};
	t2 = T.mul({{t2[0]}, {t2[1]}, {t2[2]}, {1}});
	t2 = {{evalf(t2[0])}, {evalf(t2[1])}, {evalf(t2[2])}};
	t3 = T.mul({{t3[0]}, {t3[1]}, {t3[2]}, {1}});
	t3 = {{evalf(t3[0])}, {evalf(t3[1])}, {evalf(t3[2])}};
	t4 = T.mul({{t4[0]}, {t4[1]}, {t4[2]}, {1}});
	t4 = {{evalf(t4[0])}, {evalf(t4[1])}, {evalf(t4[2])}};
	t5 = T.mul({{t5[0]}, {t5[1]}, {t5[2]}, {1}});
	t5 = {{evalf(t5[0])}, {evalf(t5[1])}, {evalf(t5[2])}};
	t6 = T.mul({{t6[0]}, {t6[1]}, {t6[2]}, {1}});
	t6 = {{evalf(t6[0])}, {evalf(t6[1])}, {evalf(t6[2])}};


	
	matrix top_matrix = {{t1}, {t2}, {t3}, {t4}, {t5}, {t6}};
	
    return top_matrix;
}

// int main(){
// 	matrix q = {{0.8}, {0.0}, {0.0}, {0.0}, {0.0}, {0.0}};
// 	matrix m = top(q);
// 	cout<<m[0]<<endl;
// 	cout<<m[1]<<endl;
// 	cout<<m[2]<<endl;
// 	cout<<m[3]<<endl;
// 	cout<<m[4]<<endl;
// 	cout<<m[5]<<endl;

// 	return 0;
// }