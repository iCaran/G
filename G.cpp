#include "G.h"

using namespace std;
using namespace GiNaC;

int main(){
	auto startTime = high_resolution_clock::now();

	symbol a("a"), b("b"), c("c"), d("d"), e("e"), f("f");
	matrix q = {{a}, {b}, {c}, {d}, {e}, {f}};
	matrix th = inv_kine_sym(q);
	Digits = 2;
	matrix G = jacobian(th, q);
	// for(short int i=0; i<21; i++){
	// 	cout<<G[i]<<endl<<endl;
	// }
	// cout<<G.rows()<<endl<<endl;
	// cout<<G.cols()<<endl<<endl;

	short int angles[] = {1, 7, 10, 13, 16, 19}; 
	ofstream outputFile("Gsolve.cpp");
	outputFile << "#include <iostream>" << "\n";
	outputFile << "#include <cmath>" << "\n";
	outputFile << "#include <chrono>" << "\n\n";
	outputFile << "using namespace std;" << "\n";
	outputFile << "using namespace std::chrono;" << "\n\n";
	outputFile << "void Gsolve(float a=0.8, float b=0.0, float c=0.0, float d=0.0, float e=0.0, float f=0.0) {" << "\n\n";
	for (short int i=0; i<6; i++){
		// if (i==3 || i==4 || i==5)
		// 	continue;
		for(short int j=0; j<6; j++){
			// cout<<G(i, j)<<endl<<endl;		
			outputFile << "\tfloat th" << angles[i] << "_" << j+1 << " = " << csrc_float << G(angles[i], j) << ";\n\n";
			outputFile << "\tcout << th" << angles[i] << "_" << j+1 << " << \"\\t\";\n\n";
		}
		outputFile << "\tcout << endl;\n\n";
	}
	outputFile << "}" << "\n\n";
	outputFile << "int main(int argc, char* argv[]) {" << "\n";
	outputFile << "\tauto startTime = high_resolution_clock::now();" << "\n\n";
	outputFile << "\tGsolve(stof(argv[1]), stof(argv[2]), stof(argv[3]), stof(argv[4]), stof(argv[5]), stof(argv[6]));\n\n";
	outputFile << "\tauto endTime = high_resolution_clock::now();" << "\n\n";
	outputFile << "\tauto elapsedTime = duration_cast<microseconds>(endTime - startTime).count();" << "\n\n";
	outputFile << "\tfloat elapsedTimeSeconds = static_cast<double>(elapsedTime) / 1000000.0;" << "\n\n";
	outputFile << "\tcout << \"\\nElapsed Time: \" << elapsedTimeSeconds << \" seconds\" << endl;" << "\n\n";
	outputFile << "\treturn 0;\n";
	outputFile << "}\n";

	auto endTime = high_resolution_clock::now();
	auto elapsedTime = duration_cast<microseconds>(endTime - startTime).count();
	float elapsedTimeSeconds = static_cast<double>(elapsedTime) / 1000000.0;
	cout << "Elapsed Time: " << elapsedTimeSeconds << " seconds" << endl;
	return 0;
}