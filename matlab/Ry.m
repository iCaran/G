function roty=Ry(th)
    th=th/pi;
    roty = [
            cospi(th),    0,  sinpi(th);
            0,          1,  0;
            -sinpi(th),   0,  cospi(th)
            ];
end
