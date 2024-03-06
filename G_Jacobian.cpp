#include "G_Jacobian.h"
using namespace GiNaC;

void G_Jacobian(matrix q){
	matrix th = inv_kine_sym(q);
	matrix G(21, 6);

	for(short int i=0; i<6; i++){
		
	}
}