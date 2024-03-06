function rotz=Rz(th)
    th=th/pi;
    rotz = [
            cospi(th),    -sinpi(th),   0;
            sinpi(th),    cospi(th),    0;
            0,          0,          1
            ];
end
