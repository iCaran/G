function rotx=Rx(th)
    th=th/pi;
    rotx = [
            1,  0,          0;
            0,  cospi(th),    -sinpi(th);
            0,  sinpi(th),    cospi(th)
            ];
end
