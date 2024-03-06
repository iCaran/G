function th = inv_kine_sym(thi)

    digits(4);

    [~, ~, ~, gamma_P, gamma, a1, a2]=structure();

    Base_matrix = base();   % Base rotation-anchor points (R)
    Top_matrix = top(thi); % Top spherical joint (SM)

    th=sym(zeros(21,1));
    %% First 3 angles of all the 6 legs
    k=0;
    for i = 1:6
        if i==1
            k = 1;
        elseif i==2
            k = 7;
        else
            k = k+3;
        end
        
        R_2_SM = Rx(-gamma(i))*(Top_matrix(:,i)-Base_matrix(:,i));  % R to SM vector in R frame (i.e., frame {1})
        disp(['Simplifying th', num2str(k+2)]);
        th(k+2) = simplify(-asin(R_2_SM(3)/a2));  % Theta i3

        a2_dash = a2*cos(th(k+2));  % Projection of connecting rod on XZ plane of frame {3}
        disp(['Simplifying th', num2str(k+1)]);
        th(k+1) = simplify(-acos((R_2_SM(1)^2 + R_2_SM(2)^2 - a1^2 - a2_dash^2)/(2*a1*a2_dash)));  % Theta i2
        
        A1=a1 + a2_dash*cos(th(k+1));
        A2=a2_dash*sin(th(k+1));
        A=sqrt(A1^2 + A2^2);
        psi=atan2(A2,A1);
        disp(['Simplifying th', num2str(k)]);
        th(k)= simplify(pi/2 - acos(R_2_SM(2)/A)-psi);        % Theta i1
    end

    %% 3 top spherical joint's angles of 1st leg (last 3 angles of 1st leg)
    T01=T(gamma(1), 0, th(1), 0);   T01(1:3,4)=Base_matrix(:,1);
    T12=T(0, 0.12, th(2), 0);
    T23=T(-pi/2, 0, th(3), 0);
    T6EE=T(pi/2-gamma_P,0,0,0);
    T0EE=[Rx(thi(6))*Ry(thi(5))*Rz(thi(4)),thi(1:3); 0,0,0,1];

    T456_n=invT(T01*T12*T23)*T0EE*invT(T6EE);
    th(4)=atan2(T456_n(3,3),T456_n(1,3));
    th(5)=-1*acos(T456_n(2,3));
    th(6)=atan2(T456_n(2,2),-1*T456_n(2,1));

    %% Required functions
    function Qk=T(alp,a,th,d)
        alp=alp/pi;
        Qk=vpa([cos(th),                -sin(th),           0,              a;
            sin(th)*cospi(alp),   cos(th)*cospi(alp),   -sinpi(alp),    0;
            sin(th)*sinpi(alp),   cos(th)*sinpi(alp),   cospi(alp),     d;
            0,                    0,                    0,              1],4);
    end

    function iT=invT(T)
        R=T(1:3,1:3);
        p=T(1:3,4);
        iT=[R',-R'*p;0,0,0,1];
    end

end

