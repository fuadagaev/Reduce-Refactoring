%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:TIMC.SL
% Description:  Get run time in milliseconds.                              
% Author:       Leigh Stoller
% Created:      22-Dec-86
% Package:      
% RCS $Header: $
%
% (c) Copyright 1986, University of Utah.
% (c) Copyright 1984, Hewlett-Packard Company, all rights reserved.        
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Revisions:
%
% 22-Dec-86 (Leigh Stoller)
%  Copied from vax nonkernel directory.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(compiletime (load sys-macros))
(on fast-integers)

(declare-warray timebuffer size 4)

% Get run-time in milliseconds. Left in for compatability
(de time () 
  (sys2int (timc)))

% Returns time in 1/1020'ths of a second.
% Change the 17 to a 20 in Europe for 50hz operation.

(de timc ()
  (external_timc timebuffer)
  (wtimes2 (wgetv timebuffer 0) 10))

(off fast-integers)
