// #include <iostream>
// #include <cmath>
// #include <ginac/ginac.h>
#include "struc.h"
using namespace std;
using namespace GiNaC;

// Function to convert degrees to radians
float deg2rad(float degrees) {
    return degrees * M_PI / 180.0;
}

lst struc(){
	// Base platform parameters

    // Radius of circle made by base plotform rotation anchors
    float r_B = 0.52280841;
    // Half of angle made between 1 and 2 rotation anchors (my convention)
    float gamma_B = deg2rad(34.62433818);

	// Top platform parameters

    // Radius of circle made by top plotform spherical joint anchors
    float r_P = 0.46509452;
    // Half of angle made between 1 and 2 spherical anchors (my convention)
    float gamma_P = deg2rad(55.06623734);
	
	// Individual joints parameter

    // Angle made from z axis (Base frame) to axis of rotation of joint (z axis of joints)
    lst gamma = {deg2rad(150), deg2rad(-150), deg2rad(30), deg2rad(90), deg2rad(-90), deg2rad(-30)};
    // gamma = deg2rad([-120, -60, 120, 180, 0, 60]);

	// Individual legs parameter
    float a1 = 0.120; // Length of first link of the leg
    float a2 = 0.850; // Length of second link of the leg

    lst l = {r_B, gamma_B, r_P, gamma_P, gamma, a1, a2};

    return l;
}

// int main(){
// 	lst l = struc();
// 	cout<<l<<endl;

// 	return 0;
// }