off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 83*x1*x2 + 250000000000000000*x7,  - 83*x1*x2 - 10000000000000000*x2 + 250000000000000000*x7 + 100000000000000000000,  - x3*x7 + 100000*x4*x5, x3*x7 - 100000*x4*x5,  - 100*x4*x5 + 11*x6, x3*x7 - 11000*x6, 83*x1*x2 - 350000000000000000*x7};

classifyComponents {basis};

end;
