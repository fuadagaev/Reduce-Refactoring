off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 100000000*x1*x2 - 400*x1 + 21*x4,  - 100000000*x1*x2 + 400*x1 + 129*x4, 200*x1 + 27*x4, 4000000*x1*x2 - 3*x4};

classifyComponents {basis};

end;
