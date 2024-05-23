# 6DOF RSS Manipulator Dynamics Calculator

This project aims to efficiently compute the dynamics of a 6 degree-of-freedom (DOF) Revolute-Spherical-Spherical (RSS) robotic manipulator in real-time. Computing manipulator dynamics, which involve Jacobian matrices, is computationally intensive. This project leverages symbolic mathematics to simplify the Jacobian expressions upfront, enabling fast real-time dynamics calculations.

## Background

Controlling a sophisticated 6DOF robotic arm performing complex tasks requires solving its dynamics swiftly. However, computing Jacobian matrices symbolically is challenging due to their large size and complexity. This project uses GiNaC, a C++ symbolic manipulation library, to simplify the Jacobian expressions derived from the manipulator's kinematic model.

## Getting Started

1. Provide the manipulator's kinematic model (links, joints etc.) as MATLAB code.

2. The MATLAB code is manually converted to C++ compatible with GiNaC. 

3. GiNaC is used to simplify the symbolic expressions for the Jacobians.

4. Real-time dynamics calculation uses the simplified expressions. Results are saved to output.txt.

## Technology

- GiNaC: Powerful symbolic expression manipulation and simplification.
- C++: Language for implementing kinematics/dynamics algorithms and GiNaC integration.

## Contributors

- [Himanshu Varshney](https://www.linkedin.com/in/himanshu-varshney/) (Senior Research Fellow @ ISM Dhanbad): Provided manipulator kinematic and dynamic model and code and MATLAB code. The credits to the research and mathematics of this project goes directly to him
- Karan Pratap Shaw: Implemented GiNaC integration and C++ code.

## Usage

Build the C++ code and provide input parameters to compute real-time dynamics values. Contact maintainers for guidance.

## Future Work

- Implement MATLAB to C++/GiNaC converter.  
- Optimize real-time dynamics computation further.
- Expand to different manipulator architectures.

Let me know if any part of the README needs more clarification or expansion. The goal is to provide a high-level overview of the project for new visitors.
