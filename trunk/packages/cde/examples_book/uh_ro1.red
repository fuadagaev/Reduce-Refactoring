% Universal Hierarchy equation: recursion operator for symmetries
% 2017-10-06

% Author: Raffaele Vitolo

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

% $Id: $


load_package cde;

% Initialization of the jet environment of the differential equation.
indep_var:={t,x,y}$
dep_var:={u}$
odd_var:={q,r}$
total_order:=6$
% names for output of the state of cde and results of computations
statename:="uh_ro1_state.red"$
resname:="uh_ro1_res.red"$

% Initialization of the differential equation.

% Even equation
principal_der:={u_2y}$
de:={u_t*u_xy - u_y*u_tx}$

% Nonlocal variable
rt:=q_y - u_t*q_x + u_tx*q$
ry:= - u_y*q_x + u_xy*q$

% Odd equation
principal_odd:={q_2y,r_t,r_y}$
de_odd:={q_t*u_xy + u_t*q_xy - q_y*u_tx - u_y*q_tx,rt,ry}$

% Calling cde's main routine
cde({indep_var,dep_var,odd_var,total_order},
   {principal_der,de,principal_odd,de_odd})$

% We define the linearization operator `ell_uh'
mk_cdiffop(ell_uh,1,{1},1);
for all psi let
  ell_uh(1,1,psi) = td(psi,y,2) - u_t*td(psi,x,y) + u_y*td(psi,x,t)
     - u_xy*td(psi,t) + u_tx*td(psi,y);

ell_uh(1,1,r);

;end;
