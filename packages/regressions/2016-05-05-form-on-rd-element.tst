
% Found by Kostas Oikonomou

on rounded$
procedure ab(eps);
   begin;
      ierr := mat((2.11),(1.18),(0.004));
      select(ierr(~i,1) <= eps, for i := 1:3 collect i);
      % select(ierr(~i,1) <= 1e-5, for i := 1:3 collect i);
   end$

ab(1e-5);

end;
