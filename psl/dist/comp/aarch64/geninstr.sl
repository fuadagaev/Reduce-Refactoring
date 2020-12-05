%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         GENINSTR
% Description:  armv8/aarch64 Generate instruction set
% Author:       Rainer Sch�pf
% Created:
% Modified:
% Mode:         Lisp
% Package:
% Status:       Open Source: BSD License
%
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
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Revisions:
%
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
% Note form of DefOpcode, similar to DefAnyreg or DefCmacro
%      A trailing OpFailure will be appended unless (T is used)
%      Currently TESTs require arguments and explicit AND
 
% (DefOpCode OP (ARGS)
%   ( (tests) (actions))
%   ( (tests) (actions))
% ....
% )
 
(fluid '(lengthfunctions))
(setq lengthfunctions
      '((OP-reg-imm8 . lth-reg-imm8 )
%	(OP-regn-imm8 . lth-regn-imm8 )
%	(OP-regd-imm8 . lth-regd-imm8 )
	(OP-reg-shifter . lth-reg-shifter )
%	(OP-regn-shifter . lth-regn-shifter )
%	(OP-regd-shifter . lth-regd-shifter )
	(OP-reg3 . lth-reg3)
	(OP-mul3 . lth-mul3)
	(OP-mul4 . lth-mul4)
	(OP-ld-st . lth-ld-st)
	(OP-ld-st-misc . lth-ld-st-misc)
	(OP-ldm-stm . lth-ldm-stm)
	(OP-streg . lth-streg)
	(OP-clz . lth-clz)
	(OP-branch-imm . lth-branch-imm)
	(OP-branch-reg . lth-branch-reg)
	(OP-mov-imm16 . lth-mov-imm16)
	(OP-reg-imm16 . lth-reg-imm16)
	(OP-reg-imm12 . lth-reg-imm12)	
	(OP-reg-logical . lth-reg-logical)
	(OP-reg-regsp . lth-reg-regsp)
	(OP-regsp-reg . lth-regsp-reg)
	(OP-reg-reg . lth-reg-reg)
	(OP-reg-extended . lth-reg-extended)
	(OP-reg2 . lth-reg2)
	(OP-reg3-lsb . lth-reg3-lsb)
	(OP-ldp . ltzh-ldp)
      ))
 
(load strings compiler)
(DE SORT (LST FN)
   (PROG (TREE)
      (COND ((OR (NULL LST) (NULL (CDR LST))) (RETURN LST)))
      (SETQ TREE (LIST (CAR LST) NIL))
      (WHILE (PAIRP (SETQ LST (CDR LST))) (TREEADD (CAR LST) TREE FN))
      (RETURN (TREE2LIST TREE NIL))))
(DE TREE2LIST (TREE LST)
   (COND
      ((NULL TREE) LST)
      (T (TREE2LIST
	    (CADR TREE)
	    (CONS (CAR TREE) (TREE2LIST (CDDR TREE) LST)))) ))
(DE TREEADD (ITEM NODE FN)
   (COND
      ((APPLY FN (list ITEM (CAR NODE)))
	 (COND
	    ((CADR NODE) (TREEADD ITEM (CADR NODE) FN))
	    (T (RPLACA (CDR NODE) (LIST ITEM NIL)))) )
      ((CDDR NODE) (TREEADD ITEM (CDDR NODE) FN))
      (T (RPLACD (CDR NODE) (LIST ITEM NIL)))) )
 
% instructions are generated by a patterns:
%
% each instruction ID has a slot INSTRCASES where the different
% possible cases are collected. When all instructions are complete,
% the final defOpCode calls are generated from these slots
 
(fluid '(allInstrs!* allInstrPatterns!* formalParameters!* instr* instrlist!*))
 
(setq formalParameters!* '(par1 par2 par3 par4))
 
(ds newInstruction (i) (when (not (memq i allInstrs!*)) (push i allInstrs!*)))


    
(df instr (l)
     (prog (name operands format namelist)
       (setq instr* l)
       (setq name (pop l))
       (setq operands (pop l))
       (setq format (pop l))
       (when (null (assoc format lengthfunctions))
	 (prin2t "unknown format : ") (print format))
       (return (instr1 l name  operands format)))
     )


(de instr1 (l name operands format)
    (prog (gname code n pat)
    % instruction list
       (push (list l name operands format) instrlist*)
       (put name 'argno (length operands))
    % simple instruction
       (newInstruction name)
       (setq code (mkquote l))
       (setq pat (mktest format code operands NIL))
       (push pat (get name 'INSTRCASES))
       (push (subla lengthfunctions pat) (get name 'LENGTHCASES))
       (setq gname name)
       (setq code (cdr l))
       (push (list name (car l) format operands) allInstrPatterns!*)
    %  (set format (cons (mkdisass code name operands) (eval format)))
       (return nil)
))


(de mktest (format code operands rev)
   (prog (params lhs rhs type val)
      (setq params formalParameters!*)
  loop (when (null operands) (go ready))
      (setq type (operandtype (pop operands)))
      (if   (not (eqcar type 'UNQUOTE))
	    (push (append type (list (car params))) lhs)
	    (progn
	       (setq params (cons(cadr type) (cdr params))) % artific. param
	       (setq type '(QUOTE))))
      (if   (not (eqcar type 'EQUAL))
	    (setq rhs(append rhs (list (pop params))))
	    (pop params))
      (go loop)
  ready
     (if (null lhs)(setq lhs '(T)))
     (when rev (setq rhs (reverse  rhs)))
     (return (if (cdr lhs)
		`((and .,(reversip lhs))(,format ,code ., rhs))
		`(,(car lhs)(,format ,code ., rhs))))
    ))

(de operandtype (op)
    (cond ((eqcar op 'QUOTE) (list 'EQUAL op))
	  ((eqcar op 'UNQUOTE) op)
	  ((eq op 'reg)'(REGP))
	  ((eq op 'reg32)'(REG32P))	
	  ((eq op 'reg-or-sp) '(reg-or-sp-p))
	  ((eq op 'reg32-or-sp) '(reg32-or-sp-p))
	  ((eq op 'reg-sp) '(reg-sp-p))
	  ((eq op 'reg32-sp) '(reg32-sp-p))
	  ((eq op 'evenreg)'(evenREGP)) 
	  ((eq op 'streg)'(streg-p))
	  ((eq op 'imm) '(STDIMMEDIATEP))
	  ((eq op 'imm16) '(sixteenbit-p))
	  ((eq op 'imm8-rotated) '(imm8-rotatedp))
	  ((eq op 'imm12-shifted) '(imm12-shiftedp))
	  ((eq op 'imm16-shifted) '(imm16-shiftedp))
	  ((eq op 'imm-logical) '(imm-logical-p))
	  ((eq op 'imm7) '(imm7-p))
	  ((eq op 'simm9) '(simm9-p))
	  ((eq op 'lsb) '(lsb-p))
	  ((eq op 'reg-shifter) '(reg-shifter-p))
	  ((eq op 'reg32-shifter) '(reg32-shifter-p))
	  ((eq op 'reg-extended) '(reg-extended-p))
	  ((eq op 'reg32-extended) '(reg32-extended-p))
	  ((eq op 'reg-offset8) '(reg-offset8-p))
	  ((eq op 'reg-offset12) '(reg-offset12-p))
	  ((eq op 'reglist) '(reglistp))
	  ((eq op 'offset19) '(offset19-p))
	  ((eq op 'offset26) '(offset26-p))
	  ((eq op 'writeback?) '(writeback-p))
	  ((eq op 'pm-reg-shifter) '(pm-reg-shifter-p))
	  ((eq op 'idloc) '(idlocp))
	  ((eq op 'effa) '(EFFAP))
	  ((eq op 'mem) '(MEMORYP))
	  ((eq op 'shortlabel) '(SHORTLABELP))
	  ((eq op 'adr) '(adrp))
	  ((eq op 'indadr) '(indirectadrp))
	  (t (prin2t "unknown operand type during instruction generation:")
	     (prin2t op)
	     (prin2t instr*)
	     (error  nil))))


(de parameterlist (n) (parameterlist1 n formalParameters!*))
 
(de parameterlist1(n l)
   (if (eqn n 0) nil (cons (car l)(parameterlist1(difference n 1)(cdr l)))))
 
% clear all instructions
(de clearInstructions ()
    (setq allInstrPatterns!* nil)
    (mapc allInstrs!* (function(lambda(u)(remprop u 'INSTRCASES))))
    (setq allInstrs!* nil))
 
% make a disassemble-record
(de mkdisass(code gname operands)
    `(,code (NAME . ,gname) (PAT . ,(dissasemblepat operands))))
 
(de dissasemblepat(o)  % special handling for quotes
   (cond ((atom o) o)
	 ((eqcar (car o) 'QUOTE) (cons (cadr (car o)) (cdr o)))
	 ((eqcar (car o) 'UNQUOTE) (cdr o))
	 (T (cons (car o) (dissasemblepat (cdr o))))))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 1st application: generation of defOpcode file
%
 
(de collectInstructions (file)
   (when file (setq file (open file 'OUTPUT)) (wrs file))
   (setq allInstrs!* (sort allInstrs!* (function string-lessp)))
   (mapc allInstrs!* (function makeOneInstruction))
   (when file (wrs nil) (close file)))
 
(de makeOneInstruction (u)
  (prog(v vv)
  (setq v
   `(DefOpcode ,u 
                  ,(parameterlist (get u 'ARGNO))
		 .,(reverse (get u 'INSTRCASES))))
  (eval (list 'pp v))
  
  (setq v
   `(DefOpLength ,u 
                    ,(parameterlist (get u 'ARGNO))
		 .,(reverse (get u 'LENGTHCASES))))
  (eval (list 'pp v))
 (terpri)))
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% 2nd  application: generation of conversion hexcode -> opcode
%

(de displayInstructions(f)
    (prog (u v)
       (setq u (sort instrlist* (function instrcmp)))
       (when f (setq v (wrs (open f 'OUTPUT))))
       (prin2t "   SUN 386 instructions sorted by opcode")
       (prin2t "   =====================================")
       (terpri)
       (mapc u (function printinstr))
       (terpri)(terpri)
       (prin2t "   SUN 386 instructions sorted by name")
       (prin2t "   ===================================")
       (setq u (sort instrlist* (function instrcmpalpha)))
       (mapc u (function printinstr))
       (terpri)

       (when f (wrs v))))
 
(de instrcmp (u v) 
     (or (lessp (caar u)(caar v))
	 (and (equal (caar u)(caar v)) (cdar u)(cdar v)
	      (lessp (cadar u)(cadar v)))))
 
(de instrcmpalpha(u v)
     (or (string-lessp (cadr u) (cadr v))
	 (and (equal (cadr u) (cadr v))
	      (instrcmp u v))))

(de printinstr (l)
	    (prininstrhex (caar l))
    (tab 3) (when (cdar l) (prininstrhex (cadar l))
			   (prin2 " /") (prin2 (land (lsh (cadar l)-3) 7)))
    (tab 10) (prin2 (cadr l))
    (tab 18) (when (caddr l) (prin2l (caddr l)))
    (tab 40) (print (cdddr l)))
 
(de prininstrhex (n)
   (if (eq n 'rex) (prin2 'rex)
      (prininstrhex1 (land 15 (lshift n -4))) (prininstrhex1 (land n 15))))
 
(de prininstrhex1 (n) (prin2 (getv [0 1 2 3 4 5 6 7 8 9 a b c d e f] n)))
 
	      


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%
%% the instructions in the sequence defined by the 
%% Programmer's Reference Manual
%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(clearInstructions)

(instr ADC (reg32 reg32 reg32)     OP-reg3 2#0001101000)
(instr ADC (reg reg reg)           OP-reg3 2#1001101000)
(instr ADCS (reg32 reg32 reg32)    OP-reg3 2#0011101000)
(instr ADCS (reg reg reg)          OP-reg3 2#1011101000)

(instr ADD (reg32-or-sp reg32-or-sp reg32-extended)    OP-reg-extended  2#00001011001)
(instr ADD (reg-or-sp reg-or-sp reg-extended)    OP-reg-extended  2#10001011001)
(instr ADD (reg32-or-sp reg32-or-sp imm12-shifted)   OP-reg-imm12     2#000100010)
(instr ADD (reg-or-sp reg-or-sp imm12-shifted)   OP-reg-imm12     2#100100010)
(instr ADD (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#00001011000)
(instr ADD (reg reg reg-shifter)     OP-reg-shifter   2#10001011000)
(instr ADDS (reg32 reg32-or-sp reg32-extended)    OP-reg-extended  2#00101011001)
(instr ADDS (reg32 reg32-or-sp imm12-shifted)   OP-reg-imm12     2#001100010)
(instr ADDS (reg reg-or-sp imm12-shifted)   OP-reg-imm12     2#101100010)
(instr ADDS (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#00101011000)
(instr ADDS (reg reg reg-shifter)     OP-reg-shifter   2#10101011000)

% ADR
% ADRP

(instr AND (reg32-or-sp reg32 imm-logical)      OP-reg-logical     2#000100100)
(instr AND (reg-or-sp reg imm-logical)      OP-reg-logical     2#100100100)
(instr AND (reg32 reg32 reg32-shifter)      OP-reg-shifter   2#00001010000)
(instr AND (reg reg reg-shifter)      OP-reg-shifter   2#10001010000)
(instr ANDS (reg32 reg32 imm-logical)     OP-reg-logical     2#011100100)
(instr ANDS (reg reg imm-logical)     OP-reg-logical     2#111100100)
(instr ANDS (reg32 reg32 reg32-shifter)     OP-reg-shifter   2#01101010000)
(instr ANDS (reg reg reg-shifter)     OP-reg-shifter   2#11101010000)

% ASR
% ASRV

(instr B.EQ (offset19)    OP-branch-imm19 2#01010100 2#0000)
(instr B.NE (offset19)    OP-branch-imm19 2#01010100 2#0001)
(instr B.CS (offset19)    OP-branch-imm19 2#01010100 2#0010)
(instr B.CC (offset19)    OP-branch-imm19 2#01010100 2#0011)
(instr B.MI (offset19)    OP-branch-imm19 2#01010100 2#0100)
(instr B.PL (offset19)    OP-branch-imm19 2#01010100 2#0101)
(instr B.VS (offset19)    OP-branch-imm19 2#01010100 2#0110)
(instr B.VC (offset19)    OP-branch-imm19 2#01010100 2#0111)
(instr B.HI (offset19)    OP-branch-imm19 2#01010100 2#1000)
(instr B.LS (offset19)    OP-branch-imm19 2#01010100 2#1001)
(instr B.GE (offset19)    OP-branch-imm19 2#01010100 2#1010)
(instr B.LT (offset19)    OP-branch-imm19 2#01010100 2#1011)
(instr B.GT (offset19)    OP-branch-imm19 2#01010100 2#1100)
(instr B.LE (offset19)    OP-branch-imm19 2#01010100 2#1101)
(instr B.AL (offset19)    OP-branch-imm19 2#01010100 2#1111)

(instr B  (offset26)         OP-branch-imm 2#000101)

% BFC
% BFI
% BFM
% BFXIL

(instr BIC  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#00001010001)
(instr BIC  (reg reg reg-shifter)     OP-reg-shifter 2#10001010001)
(instr BICS  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#01101010001)
(instr BICS  (reg reg reg-shifter)     OP-reg-shifter 2#11101010001)

(instr BL  (offset26)        OP-branch-imm 2#100101)

(instr BLR (reg)            OP-branch-reg 2#11010110001)
(instr BR (reg)              OP-branch-reg 2#11010110000)

% CBNZ
% CBZ

% CCMN
% CCMP

% CFINV
% CINC
% CINV

(instr CLS (reg reg)     OP-clz 2#11011010110 2#00000 2#000101)
(instr CLZ (reg reg)     OP-clz 2#11011010110 2#00000 2#000100)

(instr CMN   (reg32-or-sp reg32-extended)        OP-reg-extended 2#00101011001)
(instr CMN   (reg-or-sp reg-extended)        OP-reg-extended 2#10101011001)
(instr CMN   (reg32-or-sp imm12-shifted)        OP-reg-imm12  2#001100010)
(instr CMN   (reg32 imm12-shifted)        OP-reg-imm12  2#101100010)
(instr CMN   (reg32 reg32-shifter)         OP-reg-shifter 2#00101011000)
(instr CMN   (reg reg-shifter)         OP-reg-shifter 2#10101011000)

(instr CMP   (reg32 reg32-extended)        OP-reg-extended 2#01101011000)
(instr CMP   (reg reg-extended)        OP-reg-extended 2#11101011000)
(instr CMP   (reg32 imm12-shifted)        OP-reg-imm12    2#011100010)
(instr CMP   (reg imm12-shifted)        OP-reg-imm12    2#111100010)
(instr CMP   (reg32 reg32-shifter)         OP-reg-shifter 2#01101011000)
(instr CMP   (reg reg-shifter)         OP-reg-shifter 2#11101011000)

% CMPP
% CNEG

% CSEL
% CSET
% CSETM
% CSINC
% CSINV
% CSNEG

(instr EON  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#01001010001)
(instr EON  (reg reg reg-shifter)     OP-reg-shifter 2#11001010001)

(instr EOR  (reg32 reg32 imm-logical)     OP-reg-logical    2#0101001000)
(instr EOR  (reg reg imm-logical)     OP-reg-logical    2#0101001000)
(instr EOR  (reg32 reg32 reg32-shifter)     OP-reg-shifter 2#11001010000)
(instr EOR  (reg reg reg-shifter)     OP-reg-shifter 2#11001010000)

(instr EXTR   (reg32 reg32 reg32 lsb)        OP-reg3-lsb   2#0100100111)
(instr EXTR   (reg reg reg lsb)        OP-reg3-lsb   2#100100111)

% LDP Xt1, Xt2, Xn, #imm7 (post-index)
(instr LDP  (reg32 reg32 reg-or-sp imm7)  OP-ldp  2#0010100011)
(instr LDP  (reg reg reg-or-sp imm7)  OP-ldp  2#1010100011)

% LDP Xt1, Xt2, [Xn, #imm7]! (pre-index)
(instr LDP  (reg32 reg32 reg-or-sp imm7)  OP-ldp  2#0010100111)
(instr LDP  (reg reg reg-or-sp imm7)  OP-ldp  2#1010100111)

% LDP Xt1, Xt2, Xn, #imm7 (signed offset)
(instr LDP  (reg32 reg32 reg-or-sp imm7)  OP-ldp  2#0010100101)
(instr LDP  (reg reg reg-or-sp imm7)  OP-ldp  2#1010100101)

% LDPSW Xt1, Xt2, Xn, #imm7 (post-index)
(instr LDPSW  (reg reg reg-or-sp imm7)  OP-ldp  2#0110100011)

% LDPSW Xt1, Xt2, [Xn, #imm7]! (pre-index)
(instr LDPSW  (reg reg reg-or-sp imm7)  OP-ldp  2#0110100111)

% LDPSW Xt1, Xt2, Xn, #imm7 (signed offset)
(instr LDPSW  (reg reg reg-or-sp imm7)  OP-ldp  2#0110100101)

% LDR Xt, Xn, #simm9
(instr LDR (reg32 reg-or-sp simm9)      OP-ld-st 2#10111000010)
(instr LDR (reg reg-or-sp simm9)      OP-ld-st 2#11111000010)
(instr STR (reg32 reg-or-sp simm9)      OP-ld-st 2#10111000000)
(instr STR (reg reg-or-sp simm9)      OP-ld-st 2#11111000000)
% LDR Xt, <label>
(instr LDR (reg32 imm19)       OP-ld-st 2#00011000)
(instr LDR (reg imm19)       OP-ld-st 2#01011000)
% LDR Xt,[Xn,+/-#imm12]
(instr LDR (reg32 reg-or-sp reg-offset12)   OP-ld-st 2#10111000011)
(instr LDR (reg reg-or-sp reg-offset12)   OP-ld-st 2#11111000011)
(instr STR (reg32 reg-or-sp reg-offset12)   OP-ld-st 2#10111000001)
(instr STR (reg reg-or-sp reg-offset12)   OP-ld-st 2#11111000001)

% LDUR
% LDURB
% LDURH
% LDURSB
% LDURSH
% LDURSW

% LSL
% LSLV
% LSR
% LSRV

(instr MADD   (reg32 reg32 reg32 reg32)  OP-mul4      2#00011011000 0)
(instr MADD   (reg reg reg reg)         OP-mul4      2#10011011000 0)

(instr MSUB   (reg32 reg32 reg32 reg32)  OP-mul4      2#00011011000 1)
(instr MSUB   (reg reg reg reg)         OP-mul4      2#10011011000 1)

(instr MNEG   (reg32 reg32 reg32)    OP-mul3      2#00011011000 1 2#11111)
(instr MNEG   (reg reg reg)         OP-mul3      2#10011011000 1 2#11111)

(instr NEG   (reg reg reg-shifter)     OP-reg-shifter 2#11001011000)
(instr NEGS  (reg reg reg-shifter)     OP-reg-shifter 2#11101011000)

(instr NGC   (reg reg reg-shifter)     OP-reg-shifter 2#11011010000)
(instr NGCS  (reg reg reg-shifter)     OP-reg-shifter 2#11111010000)

(instr ORN   (reg reg reg-shifter)     OP-reg-shifter 2#10101010001)

(instr ORR   (reg reg imm-logical)      OP-reg-logical 2#1011001000)
(instr ORR   (reg reg reg-shifter)     OP-reg-shifter 2#10101010000)

(instr SUB   (reg reg reg-extended)     OP-reg-extended  2#11001011001)
(instr SUB   (reg reg reg-shifter)     OP-reg-shifter  2#11001011000)
(instr SUB   (reg reg imm12-shifted)    OP-reg-imm12     2#110100010)

(instr SBC   (reg reg reg-shifter)     OP-reg-shifter  2#1101101000)

(instr TST   (reg reg-shifter)         OP-reg-shifter 2#1101010000)
(instr TST   (reg imm-logical)         OP-reg-logical   2#11100100)

(instr MOV   (reg32 reg32-sp)              OP-reg-regsp  2#00010000100)
(instr MOV   (reg reg-sp)              OP-reg-regsp  2#10010000100)
(instr MOV   (reg32-sp reg32)              OP-regsp-reg  2#00010000100)
(instr MOV   (reg-sp reg)              OP-regsp-reg  2#10010000100)
(instr MOV   (reg32 reg32)                  OP-reg-reg    2#00101010000)
(instr MOV   (reg reg)                  OP-reg-reg    2#10101010000)
(instr MOV   (reg imm8-rotated)        OP-reg-imm8    2#0011101)
(instr MVN   (reg reg-shifter)         OP-reg-shifter 2#0001111)
(instr MVN   (reg imm12-shifted)        OP-reg-imm12   2#0011111)

(instr MOVN  (reg imm16-shifted)       OP-reg-imm16    2#100100101)
(instr MOVZ  (reg imm16-shifted)       OP-reg-imm16    2#110100101)

(instr SDIV  (reg reg reg)             OP-mul3      2#10011010110 2#000011)
(instr UDIV   (reg reg reg)             OP-mul3      2#10011010110 2#000010)

(instr MUL    (reg reg reg)             OP-mul3      2#10011011000 2#011111)
(instr UMADDL (reg reg reg reg)         OP-mul4      2#10011011101)
(instr UMULL  (reg reg reg)             OP-mul3      2#10011011101 2#011111)
(instr UMULH  (reg reg reg)             OP-mul3      2#10011011110 2#011111)
(instr SMADDL (reg reg reg reg)         OP-mul4      2#10011011001)
(instr SMULL  (reg reg reg)             OP-mul3      2#10011011001 2#011111)
(instr SMULH  (reg reg reg)             OP-mul3      2#10011011010 2#011111)

(instr RBIT   (reg reg)                 OP-reg2      2#11011010110)
(instr RET    ()                 OP-branch-reg    2#11010110010 X30)
(instr RET    (reg)                 OP-branch-reg    2#11010110010)
(instr REV    (reg reg)                 OP-reg2      2#11011010110)


(instr MRS (reg streg)   OP-streg 2#110101010011)
%(instr MSR (MSR *cond*) (streg imm8-rotated) OP-MSR 2#0011001 0  ... ) 
%(instr MSR (MSR *cond*) (streg reg)      OP-MSR 2#0001001 0 2#0000)

(instr LDRB (reg32 reg-offset12)  OP-ld-st 2#00111000010)
(instr STRB (reg32 reg-offset12)  OP-ld-st 2#0100010 0)
(instr LDRB (reg32 pm-reg-shifter)  OP-ld-st 2#0110010 1)
(instr STRB (reg32 pm-reg-shifter)  OP-ld-st 2#0110010 0)

(instr LDRH (reg32 reg-offset8)  OP-ld-st-misc 2#0000010 1 2#1011)
(instr STRH (reg32 reg-offset8)  OP-ld-st-misc 2#0000010 0 2#1011)
(instr LDRH (reg32 pm-reg-shifter)  OP-ld-st-misc 2#0000000 1 2#1011)
(instr STRH (reg32 pm-reg-shifter)  OP-ld-st-misc 2#0000000 0 2#1011)

(instr LDRSB (reg32 reg-offset8)  OP-ld-st-misc 2#0000010 1 2#1101)
(instr LDRSB (reg reg-offset8)  OP-ld-st-misc 2#0000010 1 2#1101)
(instr LDRSB (reg32 pm-reg-shifter)  OP-ld-st-misc 2#0000000 1 2#1101)
(instr LDRSB (reg3 pm-reg-shifter)  OP-ld-st-misc 2#0000000 1 2#1101)
(instr LDRSH (reg reg-offset8)  OP-ld-st-misc 2#0000010 1 2#1111)
(instr LDRSH (reg pm-reg-shifter)  OP-ld-st-misc 2#0000000 1 2#1111)






%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% now we generate the aarch64-inst.dat file
(off usermode) (de linelength (x) 1000)
(reload chars)
(pp nil)
(collectInstructions "aarch64-inst.dat")
% (disassembletables "disasstb")

(exitlisp)
