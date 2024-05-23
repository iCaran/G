# 6DOF RSS Manipulator Dynamics Calculator

Welcome to the repository dedicated to real-time dynamics computation for a 6DOF RSS (Rotational Spherical Spherical) Manipulator! This project is born out of the need to handle complex robotic dynamics swiftly, leveraging symbolic computation.

## Introduction

Imagine controlling a sophisticated robotic arm with six degrees of freedom, performing intricate tasks with precision and speed. To achieve this, we need to solve the manipulator’s dynamics efficiently. This project simplifies and solves the symbolic Jacobian matrices, which are critical yet computationally intensive components.

## Overview

Here's the journey:

1. **User Input**: Start with your MATLAB code detailing the manipulator’s structure, including its base, top, and inverse kinematics.
2. **Conversion**: We manually convert this MATLAB code into C++ code compatible with GiNaC, a powerful library for symbolic mathematics. [Learn more about GiNaC](https://www.ginac.de/)
3. **Simplification**: GiNaC helps in simplifying the complex symbolic expressions, making the subsequent real-time computations much faster.
4. **Dynamics Calculation**: Once simplified, the Jacobian matrices are computed and solved quickly, with results saved to `output.txt`.

## Behind the Scenes

This project is a collaborative effort. The mathematical research and MATLAB kinematics were provided by Himanshu Varshney, a PhD student at ISM Dhanbad’s Robotics Lab. The GiNaC implementation and C++ coding were done by me.

## Connect with Us

- **Himanshu Varshney**: [LinkedIn](https://www.linkedin.com/in/himanshu-varshney/)
- **[Karan Pratap Shaw](https://www.linkedin.com/in/karanpratapshaw/) & [Santanu Basu Ray](https://www.linkedin.com/in/santanu-basu-ray/)**: Feel free to contribute to the repository or reach out with suggestions and improvements.
