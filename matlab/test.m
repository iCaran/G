function G = test()
    %#codegen
    coder.cinclude('jacobian.h');
    
    % syms q [6,1] real;
    q = [0.8, 0.0, 0.0, 0.0, 0.0, 0.0];
    % digits(4);
    % th = vpa(inv_kine_sym(q),4);
    th = zeros(21, 1);
    
    G = coder.ceval('jacobian', th);
end