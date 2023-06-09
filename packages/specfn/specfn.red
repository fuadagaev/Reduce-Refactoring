module specfn;  % Special functions package for REDUCE.

% Author:  Chris Cannam, Sept-Nov 1992.
%          Winfried Neun, Nov 1992 ...
%          contribution from various authors ...

% Redistribution and use in source and binary forms, with or without
% modification, are permitted provided that the following conditions are met:
%
%    * Redistributions of source code must retain the relevant copyright
%      notice, this list of conditions and the following disclaimer.
%    * Redistributions in binary form must reproduce the above copyright
%      notice, this list of conditions and the following disclaimer in the
%      documentation and/or other materials provided with the distribution.
%
% THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
% AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
% THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
% PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNERS OR
% CONTRIBUTORS
% BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
% CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
% SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
% INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
% CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
% ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
% POSSIBILITY OF SUCH DAMAGE.
%

% $Id$

%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     Please report bugs to Winfried Neun,                       %
%                           Konrad-Zuse-Zentrum                  %
%                              fuer Informationstechnik Berlin,  %
%                           Heilbronner Str. 10                  %
%                           10711 Berlin - Wilmersdorf           %
%                           Federal Republic of Germany          %
%     or by email, neun@sc.ZIB-Berlin.de                         %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %
%                                                                %
%     This package provides algebraic and numeric                %
%     manipulations upon various special functions:              %
%                                                                %
%              -- Bernoulli Numbers                              %
%              -- Gamma Function                                 %
%              -- Pochhammer Notation                            %
%              -- Digamma (Psi) Function and Derivatives         %
%              -- Riemann Zeta Function                          %
%              -- Bessel Functions J, Y, I and K                 %
%              -- Airy Functions                                 %
%              -- Hankel Functions H1 and H2                     %
%              -- Kummer Hypergeometric Functions M and U        %
%              -- Struve, Lommel and Whittaker Functions         %
%              -- Integral funtions, Si, Ci, s_i (=si), Ei,...   %
%              -- Simplification of Factorials                   %
%              -- Solid and Spherical Harmonics                  %
%
%     accessible through the new operators Bernoulli, Gamma,     %
%     Pochhammer, Psi, Polygamma, Zeta, BesselJ, BesselY,        %
%     BesselI, BesselK, Hankel1, Hankel2, KummerM, KummerU,      %
%     AiryAi, AiryBi, AiryAiPrime, AiryBiPrime,                  %
%     Beta, StruveL, StruveH, Lommel1, Lommel2, WhittakerM       %
%     and WhittakerW, with the new switch SaveSFs.               %
%                                                                %
%  ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  %


create!-package ('(specfn sfconsts sfgen sfbern dilog sfbinom sfpolys
                   sfsums simpfact harmonic jsymbols recsimpl sfint
		  ),
                 '(contrib specfn));

exports sq2bf!*, c!:prec!:;

switch savesfs=on;


%symbolic inline procedure mksq!:new u;
%  !*p2q(car fkern(u) .* 1);

symbolic fluid '(bernoulli!-alist sf!-alist !*savesfs);

symbolic ( bernoulli!-alist := nil );
symbolic ( sf!-alist        := nil );

symbolic inline procedure sq2bf!*(x);
   (if fixp x then i2bf!: x
      else ((if car y neq '!:rd!: then retag cdr !*rn2rd y
               else retag cdr y) where y = !*a2f x));

symbolic smacro procedure c!:prec!:;
   !:bprec!:;


% These functions are needed in other modules.
%  complex!*on!*switch and complex!*off!*switch return t iff the
%  switch complex was already in the correct position

algebraic procedure complex!*on!*switch;
  symbolic 
    if not !*complex then <<(onoff('complex,t) where !*msg := nil); nil>>
     else t;

algebraic procedure complex!*off!*switch;
   if symbolic !*complex then
      if symbolic !*msg then
         << off msg; off complex; on msg >>
      else off complex
   else t;

% complex!*restore!*switch takes the value returned by complex!*on!*switch or
%  complex!*off!*switch and restore the switch complex to its former value,
%  i.e. the switch is flipped if the argument is nil

algebraic procedure complex!*restore!*switch(fl);
  symbolic
    begin scalar !*msg;
      if not fl then onoff('complex,not !*complex)
    end;

%algebraic operator besselJ,besselY,besselI,besselK,hankel1,hankel2;
%algebraic (operator kummerM, kummerU, struveh, struvel
%                  ,lommel1, lommel2 ,whittakerm, whittakerw,
%                   Airy_Ai, Airy_Bi,Airy_AiPrime,Airy_biprime);

defautoload_operator(BesselJ,specbess);
defautoload_operator(BesselY,specbess);
defautoload_operator(BesselI,specbess);
defautoload_operator(BesselK,specbess);
defautoload_operator(hankel1,specbess);
defautoload_operator(hankel2,specbess);
defautoload_operator(KummerM,specbess);
defautoload_operator(KummerU,specbess);
defautoload_operator(StruveH,specbess);
defautoload_operator(StruveL,specbess);
defautoload_operator(lommel1,specbess);
defautoload_operator(lommel2,specbess);
defautoload_operator(WhittakerM,specbess);
defautoload_operator(WhittakerW,specbess);
defautoload_operator(Airy_Ai,specbess);
defautoload_operator(Airy_Bi,specbess);
defautoload_operator(Airy_Aiprime,specbess);
defautoload_operator(Airy_Biprime,specbess);

%defautoload_operator(gamma,sfgamma);
%defautoload_operator(igamma,sfgamma);
%defautoload_operator(polygamma,sfgamma);
%defautoload_operator(psi,sfgamma);
%defautoload_operator(ibeta,sfgamma);
%defautoload_operator(beta,sfgamma);
%defautoload_operator(pochhammer,sfgamma);
%defautoload_operator(zeta,sfgamma);

endmodule;

end;




