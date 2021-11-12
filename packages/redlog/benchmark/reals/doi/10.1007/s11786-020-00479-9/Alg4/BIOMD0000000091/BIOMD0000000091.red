off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 401*x1*x14 - 25000000000000*x1*x3 - 2500000000000*x1*x4 + 50000000000000*x11 + 200000*x14*x5 + 50000000000*x2 + 500000*x5, 500*x1*x3 - x2,  - 50000*x1*x3 + 100*x2 - x3**2 - 10000*x3*x7 + x3 + 50*x6 + 100*x7,  - 500000000*x1*x4 + 200*x13*x8 - 6*x14*x4 - x4**2 - x4*x9 + x4 + 100*x5, 25000000*x1*x4 - 2*x14*x5 - 5*x5,  - 5*x10*x6 + 8*x11 + 10000*x3*x7 - 50*x6, x3**2 - 20000*x3*x7 - x3 + 100*x6 - 100*x7,  - 5*x13*x8 + x14*x5 + 2500000, x4**2 + 2*x4*x9 - x4,  - 5*x10*x6 + 8*x11, 5*x10*x6 - 8*x11, 1,  - x13 + 100,  - 401*x1*x14 - 30000*x14*x4 - 200000*x14*x5 - 1000000000*x14 + 600000000000*x15, 401*x1*x14 + 30000*x14*x4 + 200000*x14*x5 + 1000000000*x14 - 600000000000*x15, 0};

classifyComponents {basis};

end;
