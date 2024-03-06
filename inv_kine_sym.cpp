// #include <iostream>
// #include <ginac/ginac.h>
// #include "struc.h"
// #include "base.h"
// #include "top.h"
// #include "R.h"
#include "inv_kine_sym.h"
using namespace std::chrono;
using namespace GiNaC;

matrix T(ex alp, ex a, ex th, ex d){
	matrix Qk = {
		{evalf(cos(th)),          evalf(-sin(th)),         0,         evalf(a)},
		{evalf(sin(th)*cos(alp)), evalf(cos(th)*cos(alp)), evalf(-sin(alp)), 0},
		{evalf(sin(th)*sin(alp)), evalf(cos(th)*sin(alp)), evalf(cos(alp)),  evalf(d)},
		{0,                0,                0,         1}
	};

	return Qk;
}

matrix invT(matrix T){
	matrix R(3, 3);
	R(0, 0) = evalf(T(0, 0));
	R(0, 1) = evalf(T(0, 1));
	R(0, 2) = evalf(T(0, 2));
	R(1, 0) = evalf(T(1, 0));
	R(1, 1) = evalf(T(1, 1));
	R(1, 2) = evalf(T(1, 2));
	R(2, 0) = evalf(T(2, 0));
	R(2, 1) = evalf(T(2, 1));
	R(2, 2) = evalf(T(2, 2));

	matrix P(3, 1);
	P(0, 0) = evalf(T(0, 3));
	P(1, 0) = evalf(T(1, 3));
	P(2, 0) = evalf(T(2, 3));

	matrix iT(4, 4);
 
	iT(0, 0) = evalf(R(0, 0));
	iT(0, 1) = evalf(R(1, 0));
	iT(0, 2) = evalf(R(2, 0));
	iT(1, 0) = evalf(R(0, 1));
	iT(1, 1) = evalf(R(1, 1));
	iT(1, 2) = evalf(R(2, 1));
	iT(2, 0) = evalf(R(0, 2));
	iT(2, 1) = evalf(R(1, 2));
	iT(2, 2) = evalf(R(2, 2));

	iT(0, 3) = evalf(-(R(0, 0)*P(0, 0))-(R(1, 0)*P(1, 0))-(R(2, 0)*P(2, 0)));
	iT(1, 3) = evalf(-(R(0, 1)*P(0, 0))-(R(1, 1)*P(1, 0))-(R(2, 1)*P(2, 0)));
	iT(2, 3) = evalf(-(R(0, 2)*P(0, 0))-(R(1, 2)*P(1, 0))-(R(2, 2)*P(2, 0)));

	iT(3, 0) = 0;
	iT(3, 1) = 0;
	iT(3, 2) = 0;
	iT(3, 3) = 1;

	return iT;
}

matrix inv_kine_sym(matrix thi){
	lst st = struc();

	matrix Base_matrix = base(); // Base rotation-anchor points (R)
	matrix Top_matrix = top(thi); // Top spherical joint (SM)

	matrix th(21, 1);

	// First 3 angles of all the 6 legs
	short int k = 0;
	for(short int i=0; i<6; i++){
		if (i == 0)
			k = 0;
		else if (i == 1)
			k = 6;
		else
			k = k+3;

		matrix Bi = matrix(3, 1);
		matrix Ti = matrix(3, 1);

		try{
			Bi[0] = Base_matrix[i][0];
			Bi[1] = Base_matrix[i][1];
			Bi[2] = Base_matrix[i][2];
			// cout<<Bi<<endl;
			Ti[0] = Top_matrix[i][0];
			Ti[1] = Top_matrix[i][1];
			Ti[2] = Top_matrix[i][2];
		} catch (exception &p) {
			cout<<"error!"<<endl;
			cerr << p.what() << endl;
		}

		matrix R_2_SM = Rx(-st[4][i]).mul(Ti.sub(Bi)); // R to SM vector in R frame (i.e., frame {1})
		th[k+2] = evalf(-asin(R_2_SM[2]/st[6])); // Theta i3

		ex a2_dash = st[6]*cos(th[k+2]); // Projection of connecting rod on XZ plane of frame {3}
		th[k+1] = evalf(-acos((pow(R_2_SM[0], 2) + pow(R_2_SM[1], 2) - pow(st[5], 2) - pow(a2_dash, 2)) / (2 * st[5] * a2_dash))); // Theta i2

		ex A1 = evalf(st[5] + a2_dash * cos(th[k+1]));
		// cout<<A1<<endl;
		ex A2 = evalf(a2_dash * sin(th[k+1]));
		// cout<<A2<<endl;
		ex A = evalf(sqrt(pow(A1, 2) + pow(A2, 2)));
		// cout<<A<<endl;
		ex psi = evalf(atan2(A2, A1));
		// cout<<psi<<endl;
		//th[k] = evalf((Pi/2 )- acos(R_2_SM[1] / A) - psi); // Theta i1
		th[k] = evalf((Pi/2 )- acos(R_2_SM[1] / A) - psi); // Theta i1

	}

	// 3 top spherical joint's angles of 1st leg (last 3 angles of 1st leg)
	matrix T01 = T(st[4][0], 0, th[0], 0);
	T01(0, 3) = Base_matrix[0][0];
	T01(1, 3) = Base_matrix[1][0];
	T01(2, 3) = Base_matrix[2][0];
	matrix T12 = T(0, 0.12, th[1], 0);
	matrix T23 = T(-M_PI/2, 0, th[2], 0);
	matrix T6EE = T(M_PI/2-st[3], 0, 0, 0);

	matrix Rxyz = (Rx(thi[5]).mul(Ry(thi[4]))).mul(Rz(thi[3]));
	matrix T0EE = {
		{evalf(Rxyz(0, 0)), evalf(Rxyz(0, 1)), evalf(Rxyz(0, 2)), thi[0]},
		{evalf(Rxyz(1, 0)), evalf(Rxyz(1, 1)), evalf(Rxyz(1, 2)), thi[1]},
		{evalf(Rxyz(2, 0)), evalf(Rxyz(2, 1)), evalf(Rxyz(2, 2)), thi[2]},
		{0,          0,          0,          1}
	};

	matrix T456_n = (invT((T01.mul(T12)).mul(T23)).mul(T0EE)).mul(invT(T6EE));
	th[3] = evalf(atan2(T456_n(2, 2), T456_n(0, 2)));
	th[4] = evalf(-1*acos(T456_n(1, 2)));
	th[5] = evalf(atan2(T456_n(1, 1), -1*T456_n(1, 0)));

	return th;
}

// int main(){
// 	// // Record the start time
//     // time_t startTime;
//     // time(&startTime);

//     // Record the start time
//     auto startTime = high_resolution_clock::now();

// 	ofstream outputFile("output.txt");

// 	// matrix q = {{0.8}, {0.0}, {0.0}, {0.0}, {0.0}, {0.0}};
// 	//matrix q = {{0.9}, {0.0}, {0.0}, {0.0}, {0.0}, {0.0}};

// 	symbol a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
// 	matrix q = {{a}, {b}, {c}, {d}, {e}, {f}};
// 	matrix th = inv_kine_sym(q);
// 	Digits = 2;
// 	for(int i=0; i<21; i++)
// 	{
// 		// ex result = th[i];
// 		ex result = evalf(th[i]);
// 		cout<<result<<endl<<endl;
// 		// Write the result to the txt file
//         outputFile << csrc_float << result << "\n";
// 	}

// 	// cout<<endl<<acos(0)<<endl;
// 	// cout<<acos(1)<<endl;

// 	// matrix T = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
// 	// matrix iT = invT(T);

// 	// cout<<iT<<endl;

// 	outputFile.close();

// 	// // Record the end time
//     // time_t endTime;
//     // time(&endTime);

//     // Record the end time
//     auto endTime = high_resolution_clock::now();

//     // // Calculate and print the elapsed time
//     // double elapsedTime = difftime(endTime, startTime);
//     // cout << "Elapsed Time: " << elapsedTime << " seconds" << endl;

//     // Calculate and print the elapsed time in microseconds
//     auto elapsedTime = duration_cast<microseconds>(endTime - startTime).count();
//     // cout << "Elapsed Time: " << elapsedTime << " microseconds" << endl;
//     float elapsedTimeSeconds = static_cast<double>(elapsedTime) / 1000000.0;
//     cout << "Elapsed Time: " << elapsedTimeSeconds << " seconds" << endl;

// 	return 0;
// }