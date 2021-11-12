off rlabout;

symbolic (infile "../../SUPPORT/real.red" where !*output=nil);
symbolic (infile "../../SUPPORT/strings.red" where !*output=nil);

basis := { - 32000000000*x1*x3 - 230000000000*x1*x5 + 31*x2 + 31*x4, 32000000000*x1*x3 - 31*x2,  - 32000000000*x1*x3 + 31*x2 - 4400000000*x3*x4 - 130000000000*x3*x6 - 230000000*x3*x7, 230000000000*x1*x5 + 190000*x10 - 100000000000*x11*x4 + 42000*x12 - 500000000000*x27*x4 - 2300000*x29*x4 - 220000000000*x4*x6 - 250000000000*x4*x9 - 31*x4 + 10500*x8,  - 230000000000*x1*x5 + 4400000000*x3*x4 + 130000000000*x3*x6 + 230000000*x3*x7 + 31*x4, 475000*x10 + 142500000*x13*x9 + 205000*x18 - 10000000000000*x22*x6 + 5000*x23 - 22500000000*x26*x6 + 9*x27 - 37500000*x29*x6 - 550000000000*x4*x6, 7500*x14*x6 + 15000000*x23*x25 - 7100*x29*x7, 500000000*x4*x9 - 141*x8,  - 2850000*x13*x9 - 50000000000*x17*x9 + x18 - 12500000000*x4*x9 + 525*x8,  - 32000000000000*x10*x26 - 1900000*x10 + 11*x28 + 2200000000000*x4*x6 + 600000*x8,  - 50000000*x11*x4 + 12*x12, 50000000*x11*x4 - 21*x12, 1800*x12 - 10000000000*x13*x16 - 490000*x13*x29 + 6*x17 + x18,  - 100000000*x14*x23 - 7500*x14*x6 + 103*x24,  - 20000000*x15*x7,  - 10000000000*x13*x16 + 20000000000*x15*x7 - 6*x16 + 5*x17 + 22000000*x19*x20, 10000000000*x13*x16 - 100000000000*x17*x9 - 6*x17 + 8201*x18, 50000000000*x17*x9 - 4101*x18, 6*x16 + x17 + x18 - 22000000*x19*x20, 6*x16 + x17 + x18 - 22000000*x19*x20,  - 3000000*x21*x25 - 20000000*x21*x7, 15000000*x21*x25 + 100000000*x21*x7 - 2000000000*x22*x6 + x23,  - 1000000000*x14*x23 + 4000000000*x22*x6 - 2*x23 + 1665*x24, 200000000*x14*x23 - 333*x24,  - 30000000*x23*x25 + 127*x24 - 14200*x25*x29,  - 32000000000000*x10*x26 - 90000000000*x26*x6 + 36*x27 + 11*x28, 22500000000*x26*x6 - 1250000000000*x27*x4 - 9*x27, 32000000000000*x10*x26 + 5000000000000*x27*x4 - 11*x28,  - 490*x13*x29 - 7100*x25*x29 - 230*x29*x4 - 1500*x29*x6 - 7100*x29*x7, 1500*x29*x6, 7100*x25*x29, 490*x13*x29, 7100*x29*x7, 230*x29*x4};

classifyComponents {basis};

end;
