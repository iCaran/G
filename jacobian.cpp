#include "jacobian.h"

using namespace std;
using namespace GiNaC;

matrix jacobian(matrix func, matrix X){
	short int m = func.nops(), n = X.nops();
	matrix J(m, n);

	for(short int i=0; i<m; i++){
		for(short int j=0; j<n; j++){
			J(i, j) = evalf(func[i].diff(ex_to<symbol>(X[j])));
		}
	}

	return J;
}