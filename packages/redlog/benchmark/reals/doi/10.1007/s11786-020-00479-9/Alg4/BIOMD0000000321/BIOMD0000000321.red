off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 211*x1, 15213311*x1 - 28393500*x2, 823*x2 - 120*x3};

classifyComponents {basis};

end;
