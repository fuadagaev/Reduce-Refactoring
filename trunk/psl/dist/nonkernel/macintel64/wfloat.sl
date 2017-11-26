%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         PXNK:WFLOAT.SL
% Description:  Interface to foreign floating point functions.             
% Author:       RAM, HP/FSD                                                
% Created:      27-Feb-84                                                  
% Modified:     29-Oct-84 09:06:40 (Vicki O'Day)
% Mode:         Lisp                                                       
% Package:                                                                 
% Status:       Experimental (Do Not Distribute)                           
%
% (c) Copyright 1983, Hewlett-Packard Company, see the file
%            HP_disclaimer at the root of the PSL file tree
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions
%
% 04-Apr-87 (Leigh Stoller)
%  Added support for 68020 IEEE negitive zero test. See $pnk/arithmetic.sl.
% 29-Oct-86 (Leigh Stoller)
%  Removed definition of writefloat. It has been returned to write-float.sl.
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

(fluid '(**neg-zero** **neg-one** fp-except-mode*))

(off echo)

(de *fp-check-for-exceptions (fn flags)
  (unless (or (eq 0 fp-except-mode*)
	      (eq 0 (*float-get-except-flags flags)))
    (*float-clear-all-except)
    (stderror (bldmsg "Floating point error in %w" fn))))

(de *wfloat (x y)
  (uxfloat x y))

(de *fplus2 (x y z)
 (when (and (eq (uxplus2 x y z) 0) (not (eq fp-except-mode* 0)))
      (stderror "Floating point error in fplus2")))

(de *fdifference (x y z)
 (when (and (eq (uxdifference x y z) 0) (not (eq fp-except-mode* 0)))
      (stderror "Floating point error in fdifference")))

(de *ftimes2 (x y z)
  (when (and (eq (uxtimes2 x y z) 0) (not (eq fp-except-mode* 0)))
     (stderror "Floating point error in ftimes2")))

(de *fquotient (x y z)
  (when (and (eq (uxquotient x y z) 0) (not (eq fp-except-mode* 0)))
     (stderror "Floating point error in fquotient")))

(de *fsqrt (x y)
  (when (and (eq (uxsqrt x y) 0) (not (eq fp-except-mode* 0)))
     (stderror "Floating point error in fsqrt")))

(de *fgreaterp (x y)
  (uxgreaterp x y 't 'nil))

(de *flessp (x y)
  (uxlessp x y 't 'nil))

(de *wfix (x)
  (uxfix x))

(de *fassign (x y)
  (uxassign x y))

(de *doubletofloat (x y)
  (uxdoubletofloat (inf x) (inf y)))

% These two statements must be at the end of the file because times2, and
% thus *ftimes2, must be defined before it is used.

%(loadtime (progn
%	    (setq **neg-one** -1.0)
%	    (setq **neg-zero** (times2 **neg-one** 0.0))))

(de *floattodouble (x y)
  (uxfloattodouble (inf x) (inf y)))
