function [r_B, gamma_B, r_P, gamma_P, gamma, a1, a2]=structure()

%% Base platform parameters

    % Radius of circle made by base plotform rotation anchors
    r_B = 0.52280841;
    % Half of angle made between 1 and 2 rotation anchors (my convention)
    gamma_B = deg2rad(34.62433818);

%% Top platform parameters

    % Radius of circle made by top plotform spherical joint anchors
    r_P = 0.46509452;
    % Half of angle made between 1 and 2 spherical anchors (my convention)
    gamma_P = deg2rad(55.06623734);

%% Individual joints parameter

    % Angle made from z axis (Base frame) to axis of rotation of joint (z axis of joints)
    gamma = deg2rad([150, -150, 30, 90, -90, -30]);
%     gamma = deg2rad([-120, -60, 120, 180, 0, 60]);

%% Individual legs parameter

    a1 = 0.120; % Length of first link of the leg
    a2 = 0.850; % Length of second link of the leg