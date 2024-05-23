## Jacobian-Computation: Real-Time Dynamics for a 6DOF RSS Manipulator

This repository houses a C++ implementation for calculating the real-time dynamics of a 6DOF RSS (Rotational Spherical Spherical) manipulator using symbolic computation with GiNaC.

### Introduction

Controlling a complex robotic arm with six degrees of freedom requires efficient computation of its dynamics. This project focuses on simplifying and solving the symbolic Jacobian matrices, which are crucial yet computationally intensive components for real-time control.

### Overview

The workflow involves the following steps:

1. **User Input:** Provide MATLAB code describing the manipulator's structure, including its base, top, and inverse kinematics.
2. **Conversion:** Manually convert the MATLAB code into C++ code compatible with GiNaC, a powerful library for symbolic mathematics. ([https://www.ginac.de/](https://www.ginac.de/))
3. **Simplification:** GiNaC simplifies the complex symbolic expressions, significantly accelerating real-time computations.
4. **Dynamics Calculation:** Once simplified, the Jacobian matrices are computed and solved quickly, with results saved to `output.txt`.

### Behind the Scenes

This project is a collaborative effort:

* **Mathematical Research and MATLAB Kinematics:** Provided by Himanshu Varshney, PhD student at ISM Dhanbad's Robotics Lab. ([https://www.linkedin.com/in/himanshu-varshney/](https://www.linkedin.com/in/himanshu-varshney/))
* **GiNaC Implementation and C++ Coding:** Developed by Karan Pratap Shaw.

### Project Structure

The repository contains the following files:

* **matlab:** Contains the original MATLAB code for the manipulator's structure and inverse kinematics.
* **G.cpp, G.h, G.txt:** Files related to the GiNaC implementation for the Jacobian matrix.
* **G_Jacobian.cpp, G_Jacobian.h:** Files for computing the Jacobian matrix using GiNaC.
* **Gsolve.cpp:** Solves the simplified Jacobian expressions and outputs the results to `output.txt`.
* **R.cpp, R.h, R.o:** Files for the rotation matrices.
* **base.cpp, base.h, base.o:** Files for the manipulator's base.
* **inv_kine_sym.cpp, inv_kine_sym.h, inv_kine_sym.o:** Files for the inverse kinematics calculations.
* **jacobian.cpp, jacobian.h, jacobian.py:** Files for the Jacobian matrix calculations.
* **solve.cpp, solve_expressions.cpp, solved.cpp, solver.cpp:** Files related to solving the equations.
* **struc.cpp, struc.h, struc.o:** Files for the manipulator's structure.
* **test.cpp:** Test file for the code.
* **top.cpp, top.h, top.o:** Files for the manipulator's top.
* **output.txt:** File containing the calculated Jacobian values.

### Getting Started

1. **Install GiNaC:** Follow the instructions on the GiNaC website ([https://www.ginac.de/](https://www.ginac.de/)) to install the library.
2. **Compile the code:** Use a C++ compiler to compile the code.
3. **Run the code:** Execute the compiled code to calculate the Jacobian matrix and output the results to `output.txt`.

### Contributions

Feel free to contribute to the repository with suggestions, improvements, or bug fixes. You can also reach out to Karan Pratap Shaw or Santanu Basu Ray for any questions or discussions.

### Acknowledgements

This project wouldn't have been possible without the valuable contributions of [Himanshu Varshney](https://www.linkedin.com/in/himanshu-varshney/) (Senior Research Fellow @ ISM Dhanbad): Provided manipulator kinematic and dynamic model and code and MATLAB code. The credits to the research and mathematics of this project goes solely and directly to him. 

Only the GiNaC implementation was done by me

### License

This project is licensed under the GNU Lesser General Public License v2.1. See the LICENSE file for more details.
