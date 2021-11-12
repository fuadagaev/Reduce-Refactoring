off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 23100*x1*x2 - 40000000*x1*x6 - 8660*x1 + 16731*x3 + 9900*x4 + 10000000*x9,  - 23100*x1*x2 - 10000*x2*x6 + 231*x3 + 120000*x5 + 10000000*x8, 23100*x1*x2 - 16731*x3, x2 - x4 + x8,  - x5 + 10, x10*x7 - 5*x6,  - x10*x7 + 5*x6, x2*x6 - 1000*x8, 5000*x1*x6 - 1251*x9,  - x10, 0, 0, 33*x3, 3*x5, 433*x1 + 400*x9, 99*x4, x4, x2 + x8, 0, 0};

classifyComponents {basis};

end;
