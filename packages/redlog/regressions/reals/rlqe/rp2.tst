% Test rlqe (linear)
% Rectangle Problem

off rlabout;

rlset reals;

rp2 := ex(x1,ex(x2,ex(y1,ex(y2,ex(d2,all(u,all(v,((a > 0 and b > 0 and
d1 > 0 and (true and - d1 + d2 > 0)) and (true and x1 >= 0 and - a + d1
+ x1 <= 0 and y1 >= 0 and - b + d1 + y1 <= 0 and x2 >= 0 and - a + d2 +
x2 <= 0 and y2 >= 0 and - b + d2 + y2 <= 0) and not(false or false or
false or ( - x1 + x2 <= 0 and - d2 + x1 - x2 < 0) and ( - y1 + y2 <= 0
and - d2 + y1 - y2 < 0) or ( - d1 - x1 + x2 <= 0 and d1 - d2 + x1 - x2 <
0) and ( - y1 + y2 <= 0 and - d2 + y1 - y2 < 0) or ( - x1 + x2 <= 0 and
- d2 + x1 - x2 < 0) and ( - d1 - y1 + y2 <= 0 and d1 - d2 + y1 - y2 < 0)
or ( - d1 - x1 + x2 <= 0 and d1 - d2 + x1 - x2 < 0) and ( - d1 - y1 + y2
<= 0 and d1 - d2 + y1 - y2 < 0) or false or (x1 - x2 <= 0 and - d1 - x1
+ x2 < 0) and (y1 - y2 <= 0 and - d1 - y1 + y2 < 0) or ( - d2 + x1 - x2
<= 0 and - d1 + d2 - x1 + x2 < 0) and (y1 - y2 <= 0 and - d1 - y1 + y2 <
0) or (x1 - x2 <= 0 and - d1 - x1 + x2 < 0) and ( - d2 + y1 - y2 <= 0
and - d1 + d2 - y1 + y2 < 0) or ( - d2 + x1 - x2 <= 0 and - d1 + d2 - x1
+ x2 < 0) and ( - d2 + y1 - y2 <= 0 and - d1 + d2 - y1 + y2 < 0) or
false)) and (( - u <= 0 and - a + u < 0) and ( - v <= 0 and - b + v < 0)
impl false or ( - u + x1 <= 0 and - d1 + u - x1 < 0) and ( - v + y1 <= 0
and - d1 + v - y1 < 0) or ( - u + x2 <= 0 and - d2 + u - x2 < 0) and ( -
v + y2 <= 0 and - d2 + v - y2 < 0)))))))))$

rlqe rp2;

end;
