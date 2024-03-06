%% Function to define top platform and returns coordinate of top spherical joints

function Top_matrix = top(q_EE)
    [~, ~, r_P, gamma_P, ~, ~, ~]=structure();
    %% Transformation matrix of End-effector (Top frame) WRT Base frame
    R=Rx(q_EE(6))*Ry(q_EE(5))*Rz(q_EE(4));  % Taking roll about Z, pitch about Y and yaw about X (See my IKin convention)
%     T=[R(1,:),q_EE(1);R(2,:),q_EE(2);R(3,:),q_EE(3);0,0,0,1];
    T=[R, q_EE(1:3); 0,0,0,1];

    %% Defining complete top platform

    % Defining the first top spherical vertex 
    t1 = zeros(3,1);
    t1(2) = -r_P*cos(gamma_P);
    t1(3) = -r_P*sin(gamma_P);
    
    
    % Remaining 2-6 rotation-anchor points
    t2=Rx(-2*gamma_P)*t1;
    t3=Rx(-2*pi/3)*t1;
    t4=Rx(-2*pi/3)*t2;
    t5=Rx(-2*pi/3)*t3;
    t6=Rx(-2*pi/3)*t4;

    t1=T*[t1;1];
    t2=T*[t2;1];
    t3=T*[t3;1];
    t4=T*[t4;1];
    t5=T*[t5;1];
    t6=T*[t6;1];       
    
    Top_matrix = [t1(1:3), t2(1:3), t3(1:3), t4(1:3), t5(1:3), t6(1:3)];
end