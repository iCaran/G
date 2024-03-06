%% Function to define base platform and returns coordinate of base rotation-achor points

function Base_matrix = base()
    [r_B, gamma_B, ~, ~, ~, ~, ~]=structure();

    %% Defining complete base platform
    
    % Defining the first rotation-anchor point
    b1 = zeros(3,1);
    b1(2) = -r_B*cos(gamma_B);
    b1(3) = -r_B*sin(gamma_B);

    % Remaining 2-6 rotation-anchor points
    b2=Rx(-2*gamma_B)*b1;
    b3=Rx(-2*pi/3)*b1;
    b4=Rx(-2*pi/3)*b2;
    b5=Rx(-2*pi/3)*b3;
    b6=Rx(-2*pi/3)*b4;
    
    Base_matrix = [b1,b2,b3,b4,b5,b6];
end