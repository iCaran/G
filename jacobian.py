from sympy.matrices import Matrix, zeros
from sympy.core.function import diff
from sympy.abc import rho, phi
from sympy import sin, cos, pprint

def jacobian(func,X):
    if func.shape[0] == 1:
        m = func.shape[1]
    elif func.shape[1] == 1:
        m = func.shape[0]
    else:
        raise TypeError("``func`` must be a row or a column matrix")

    if X.shape[0] == 1:
        n = X.shape[1]
    elif X.shape[1] == 1:
        n = X.shape[0]
    else:
        raise TypeError("X must be a row or a column matrix")

    ## m is the number of functions and n is the number of variables - computing the Jacobian is now easy:
    # 1st way of doing - simple in python with sympy but may not be in C++
    # return Matrix(m,n,lambda j, i: func[j].diff(X[i]))

    # 2nd way of doing - implementable in C++
    J = zeros(m,n)
    for i in range(m):
        for j in range(n):
            # pprint(func[i].diff(X[j]))
            J[i,j] = func[i].diff(X[j])
    return J


if __name__=="__main__":
    # func = Matrix([rho*cos(phi)])
    func = Matrix([rho*cos(phi), rho*sin(phi), rho**2])
    print('func = ')
    pprint(func)
    X = Matrix([rho, phi])
    print('X = ')
    pprint(X)
    J = jacobian(func, X)
    print('J = ')
    pprint(J)