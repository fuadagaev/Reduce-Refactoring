%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% File:         GENINSTR
% Description:  i386 Generate instruction set
% Author:       H. Melenk
% Created:
% Modified:
% Mode:         Lisp
% Package:
% Status:       Open Source: BSD License
%
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
    '((OP-reg-effa . lth-reg-effa)
      (OP-reg-effa-2 . lth-reg-effa-2)
      (OP-xmmreg-effa . lth-xmmreg-effa)
      (Op-imm      . lth-imm)
      (Op-imm-reg  . lth-imm-reg)
      (Op-imm8-reg . lth-imm8-reg )
      (Op-imm-EAX  . lth-imm-EAX)
      (Op-imm-effa . lth-imm-effa)
      (Op-imm8-effa. lth-imm8-effa)
      (Op-mem-EAX  . lth-mem-EAX)
      (Op-push-reg . lth-push-reg)
      (Op-byte     . lth-byte)
      (OP-effa     . lth-effa)
      (OP2-effa    . lth2-effa)
      (Op-mul      . lth-mul)
      (Op-imul     . lth-imul)
      (Op-shift    . lth-shift)
      (Op-shiftimm . lth-shiftimm)
      (Op-dshift   . lth-dshift)
      (Op-dshiftimm. lth-dshiftimm)
      (Op-jump     . lth-jump)
      (Op-jump-effa .lth-jump-effa)
      (Op-jump-short.lth-jump-short) 
      (OP-jump     . lth-jump-long) 
      (Op-ret-n    . lth-ret-n)
      (Op-enter    . lth-enter)
      (OP-INT      . LTH-INT)
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
 
% instructions are generated by a patters:
%
% each instruction ID has a slot INSTRCASES where the different
% possible cases are collected. When all instructions are complete,
% the final defOpCode calls are generated from these slots
 
(fluid '(allInstrs!* allInstrPatterns!* formalParameters!* instr* instrlist!*))
(fluid '(Op-k Op-j-k Op-i-j-k Op-load Op-store Op-immediate-000-k
	 Op-immediate-001-k Op-branch-short Op-branch-long))
 
(setq formalParameters!* '(par1 par2 par3))
 
(ds newInstruction (i) (when (not (memq i allInstrs!*)) (push i allInstrs!*)))
 
(df instr (l)
     (prog (name operands format suffix gname group code n pat)
       (setq instr* l)
       (setq l (subla '((/0 . 0)(/1 . 8#10) (/2 . 8#20)
			(/3 . 8#30) (/4 . 8#40) (/5 . 8#50)
			(/6 . 8#60) (/7 . 8#70)) l))
       (setq name (pop l))
       (setq operands (pop l))
       (setq format (pop l))
       (when (null (assoc format lengthfunctions))
	     (prin2t "unknown format : ") (print format))
    % instruction list
       (push (list l name operands format) instrlist*)
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
 
(df insti (l)
  % same as instr, but inverting parameters on the right
     (prog (name operands format suffix gname group code n pat)
       (setq instr* l)
       (setq l (subla '((/0 . 0)(/1 . 8#10) (/2 . 8#20) 
			(/3 . 8#30) (/4 . 8#40) (/5 . 8#50) 
			(/6 . 8#60) (/7 . 8#70)) l))
       (setq name (pop l))
       (setq operands (pop l))
       (setq format (pop l))
       (when (null (assoc format lengthfunctions)) 
	     (prin2t "unknown format : ") (print format))
    % instruction list
       (push (list l name operands format) instrlist*)
    % simple instruction
       (newInstruction name)
       (setq code (mkquote l))
       (setq pat (mktest format code operands T))
       (push pat (get name 'INSTRCASES))
       (push (subla lengthfunctions pat) (get name 'LENGTHCASES))
       (setq gname name)
       (setq code (cdr l))
       (push (list name (car l) format operands) allInstrPatterns!*)
    %  (set format (cons (mkdisass code name operands) (eval format)))
       (return nil)
))

 
(de mktest(format code operands rev)
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
	  ((eq op 'sreg)'(SREGP))
	  ((eq op 'xmmreg)'(xmmregp))
	  ((eq op 'EAX) '(EAXP))
	  ((eq op 'imm) '(STDIMMEDIATEP))
	  ((eq op '!n) '(SMALLIMMEDIATEP))
	  ((eq op 'effa) '(EFFAP))
	  ((eq op 'mem) '(MEMORYP))
	  ((eq op 'shortlabel) '(SHORTLABELP))
	  ((eq op 'adr) '(adrp))
	  ((eq op 'indadr) '(indirectadrp))
	  (t (prin2t "unknown operand type during instruction generation:")
	     (prin2t op)
	     (prin2t instr*)
	     (error  nil))))
 
 
(de parameterlist (n) % (parameterlist1 n formalParameters!*))
		     '(par1 par2))
 
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
  (prog(v)
  (setq v
   `(DefOpcode ,u ,(parameterlist (get u 'ARGNO))
		 .,(reverse (get u 'INSTRCASES))))
  (eval (list 'pp v))
  (setq v
   `(DefOpLength ,u ,(parameterlist (get u 'ARGNO))
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
 
 
%(instr MOV  (mem  EAX)  OP-mem-eax  2#10100001)
%(instI MOV  ( EAX mem)  OP-mem-eax  2#10100011)
(instr MOV  (sreg effa) OP-reg-effa 2#10001100)
(instI MOV  (effa sreg) OP-reg-effa 2#10001110)
(instr MOV  (reg effa)  OP-reg-effa 2#10001001)
(instI MOV  (effa reg)  OP-reg-effa 2#10001011)
%% 64 bit immediate (instr MOV  (imm reg )  OP-imm-reg  2#10111000)
(instr MOV  (imm reg)  OP-imm-reg 2#11000111 2#11000000)
(instr MOV  (imm effa)  OP-imm-effa 2#11000111 2#00000000)
(instI MOV  (adr  reg)  OP-reg-effa 2#10001011)   % added 7-11-89 MUST BE LAST
 
(instr MOVB (reg effa) OP-reg-effa  2#10001000)
(instI MOVB (effa reg) OP-reg-effa  2#10001010)

(instr MOVW (reg effa)  OP-reg-effa-2 16#66 rex 2#10001001)
(instI MOVW (effa reg)  OP-reg-effa-2 16#66 rex 2#10001011)

(instr MOVSX (reg reg) OP-reg-effa-2 2#00001111 rex 2#10111111)  % only reg-reg
(instr MOVZX (reg reg) OP-reg-effa-2 2#00001111 rex 2#10110111)  % only reg-reg
 
(instr PUSH (reg)     OP-push-reg   2#01010000)
(instr PUSH (effa)    OP-effa       2#11111111 2#00110000)
(instr PUSH (imm)     OP-imm        16#68)

(instr POP  (reg)     OP-push-reg   2#01011000)
(instr POP  (effa)    OP-effa       2#10001111 2#00000000)

(instr XCHG  (reg  EAX)  OP-push-reg 2#10010000)
(instI XCHG  ( EAX reg)  OP-push-reg 2#10010000)
(instr XCHG  (effa reg)  OP-reg-effa 2#10000111)
(instI XCHG  (reg effa)  OP-reg-effa 2#10000111)

(instI LEA   (effa reg) OP-reg-effa 2#10001101)
(instI LEA   (adr  reg) OP-reg-effa 2#10001101)

(instr LEAVE ()       OP-byte       16#c9)
(instr ENTER (imm)    OP-enter      16#c8)

(instr CLC ()         OP-byte       2#11111000)
(instr CLD ()         OP-byte       2#11111100)
(instr CLI ()         OP-byte       2#11111010)

(instr CBW ()         OP-byte       16#66 16#98)
(instr CWDE()         OP-byte       16#98)
(instr CDQE()         OP-byte       16#48 16#98)  % with REX prefix

(instr CDQ ()         OP-byte       16#99)
(instr CQTO()         OP-byte       16#48 16#99)
(instr CWD ()         OP-byte       16#66 16#99)  % with operand size prefix

(instr ADD (reg effa) OP-reg-effa  2#00000001)
(instI ADD (effa reg) OP-reg-effa  2#00000011)
(instr ADD (imm  EAX) OP-imm-EAX   2#00000101)
(instr ADD (!n  reg ) OP-imm8-effa 2#10000011 2#00000000)  % r32 + byte
(instr ADD (imm effa) OP-imm-effa  2#10000001 2#00000000)  % r32 + imm32
 
(instr ADC (reg effa) OP-reg-effa  2#00010001) 
(instI ADC (effa reg) OP-reg-effa  2#00010011) 
(instr ADC (imm  EAX) OP-imm-EAX   2#00010101)
(instr ADC (!n  reg ) OP-imm8-effa 2#10000011 2#00010000)   
(instr ADC (imm effa) OP-imm-effa  2#10000001 2#00010000)
  
(instr INC (reg)      OP-push-reg  16#ff 2#11000000)
(instr INC (effa)     OP-effa      16#FF /0) 
 
(instr SUB (reg effa) OP-reg-effa  2#00101001) 
(instI SUB (effa reg) OP-reg-effa  2#00101011) 
(instr SUB (imm  EAX) OP-imm-EAX   2#00101101)
(instr SUB (!n  reg)  OP-imm8-effa 2#10000011 2#00101000)  % r32 - byte
(instr SUB (imm effa) OP-imm-effa  2#10000001 2#00101000)  % r32 - imm32
 
(instr SBB (reg effa) OP-reg-effa  2#00011001)
(instI SBB (effa reg) OP-reg-effa  2#00011011)
(instr SBB (imm  EAX) OP-imm-EAX   2#00011101)
(instr SBB (!n  reg ) OP-imm8-effa 2#10000011 2#00011000) 
(instr SBB (imm effa) OP-imm-effa  2#10000001 2#00011000)
  
(instr DEC (reg)      OP-push-reg  2#01001000) 
(instr DEC (effa)     OP-effa      16#FF /1)
 
(instr SETC (effa)    OP2-effa     16#0F 16#92 /0)
(instr CMP (reg effa) OP-reg-effa  2#00111001)
(instI CMP (effa reg) OP-reg-effa  2#00111011)
(instr CMP (imm  EAX) OP-imm-EAX   2#00111101)
(instr CMP (!n  effa) OP-imm8-effa 2#10000011 2#00111000)
(instr CMP (imm effa) OP-imm-effa  2#10000001 2#00111000)
(instr CMPQ (imm effa) OP-imm-effa  2#10000001 2#00111000)

(instr NEG (reg)      OP-effa      2#11110111 2#00011000)

(instr MUL (effa)     OP-MUL      16#F7 /4)
(instr IMUL(effa)     OP-MUL      16#F7 /5)
(instI IMUL(reg  reg) OP-IMUL     2#00001111 2#10101111)

(instr DIV (effa)     OP-MUL      16#F7 /6)
(instr IDIV(effa)     OP-MUL      2#11110111 2#00111000)

(instr CBW ()         OP-byte     2#10011000)
(instr CWD ()         OP-byte     2#10011001)

(instr ROL ('1 reg)    OP-shift        2#11010001 2#00000000)
(instr ROL ('(reg cl)  reg)  OP-shift  2#11010011 2#00000000) 
(instr ROL (imm reg)  OP-shiftimm      2#11000001 2#00000000)
 
(instr ROR ('1 reg)    OP-shift        2#11010001 2#00001000) 
(instr ROR ('(reg cl)  reg)  OP-shift  2#11010011 2#00001000)  
(instr ROR (imm reg)  OP-shiftimm      2#11000001 2#00001000)

(instr RCL ('1 reg)    OP-shift        2#11010001 2#00010000) 
(instr RCL ('(reg cl)  reg)  OP-shift  2#11010011 2#00010000)  
(instr RCL (imm reg)  OP-shiftimm      2#11000001 2#00010000) 
  
(instr RCR ('1 reg)    OP-shift        2#11010001 2#00011000)  
(instr RCR ('(reg cl)  reg)  OP-shift  2#11010011 2#00011000)   
(instr RCR (imm reg)  OP-shiftimm      2#11000001 2#00011000)  
   
(instr SHL ('1 reg)    OP-shift        2#11010001 2#00100000) 
(instr SHL ('(reg cl)  reg)  OP-shift  2#11010011 2#00100000)  
(instr SHL (imm reg)  OP-shiftimm      2#11000001 2#00100000) 
  
(instr SaL ('1 reg)    OP-shift        2#11010001 2#00100000)  
(instr SaL ('(reg cl)  reg)  OP-shift  2#11010011 2#00100000)   
(instr SaL (imm reg)  OP-shiftimm      2#11000001 2#00100000)  
   
(instr SHR ('1 reg)    OP-shift        2#11010001 2#00101000)  
(instr SHR ('(reg cl)  reg)  OP-shift  2#11010011 2#00101000)   
(instr SHR (imm reg)  OP-shiftimm      2#11000001 2#00101000)  
   
(instr SAR ('1 reg)    OP-shift        2#11010001 2#00111000)   
(instr SAR ('(reg cl)  reg)  OP-shift  2#11010011 2#00111000)    
(instr SAR (imm reg)  OP-shiftimm      2#11000001 2#00111000)   
 
(instr SHLD (imm effa) OP-dshiftimm        2#00001111 2#10100100)
(instr SHLD ('(reg cl)  effa) OP-dshift    2#00001111 2#10100101)
 
(instr SHRD (imm effa) OP-dshiftimm        2#00001111 2#10101100) 
(instr SHRD ('(reg cl)  effa) OP-dshift    2#00001111 2#10101101) 
  
(instI AND  (reg reg)  OP-reg-effa  2#00100011)
(instr AND  (reg effa) OP-reg-effa  2#00100001)
(instI AND  (effa reg) Op-reg-effa  2#00100011)
(instr AND  (imm  EAX) OP-imm-EAX   2#00100101)
(instr AND  (!n  reg)  Op-imm8-effa 2#10000011 2#00100000)
(instr AND  (imm reg)  Op-imm-effa  2#10000001 2#00100000)
    
(instI OR   (reg reg)  OP-reg-effa  2#00001011) 
(instr OR   (reg effa) OP-reg-effa  2#00001001) 
(instI OR   (effa reg) Op-reg-effa  2#00001011) 
(instr OR   (imm  EAX)  OP-imm-EAX  2#00001101)
(instr OR   (!n  reg)  Op-imm8-effa 2#10000011 2#00001000) 
(instr OR   (imm reg)  Op-imm-effa  2#10000001 2#00001000)
    
(instI XOR  (reg reg)  OP-reg-effa  2#00110011)  
(instr XOR  (reg effa) OP-reg-effa  2#00110001)  
(instI XOR  (effa reg) Op-reg-effa  2#00110011)  
(instr XOR  (imm  EAX)  OP-imm-EAX  2#00110101)
(instr XOR  (!n  reg)  Op-imm8-effa 2#10000011 2#00110000)  
(instr XOR  (imm reg)  Op-imm-effa  2#10000001 2#00110000)
     
(instr NOT  (reg)      OP-effa       2#11110111 2#00010000)
     
(instr NOP  ()         OP-byte       16#90)

(instr CALL (indadr)           OP-jump-effa 2#11111111 2#00010000)
(instr CALL (reg)	       OP-jump-effa 2#11111111 2#00010000)
(instr CALL (adr)              OP-jump      16#E8)   
 
(instr JMP  (shortlabel)       OP-jump-short 2#11101011)
(instr JMP  (indadr)           OP-jump-effa 2#11111111 2#00100000)
(instr JMP  (reg)              OP-jump-effa 2#11111111 2#00100000)
(instr JMPL (adr)              OP-jump      16#E9)
(instr JMP  (adr)              OP-jump      16#E9)
% falsch (instr JMP  (effa)             OP-jump-effa 2#11111111 2#00101000)
 
(instr RET  (!n)               OP-ret-n     2#11000010)
(instr IRET ()                 OP-byte      16#cf)
(instr RET  ()                 OP-byte      2#11000011)

(instr JO   (shortlabel)       OP-jump-short 2#01110000)
(instr JOL  (adr)              OP-jump       2#00001111 2#10000000)

(instr JNO   (shortlabel)      OP-jump-short 2#01110001) 
(instr JNOL  (adr)             OP-jump       2#00001111 2#10000001)

(instr JB   (shortlabel)       OP-jump-short 2#01110010) 
(instr JBL  (adr)              OP-jump       2#00001111 2#10000010)
(instr JNAE (shortlabel)       OP-jump-short 2#01110010)  
(instr JNAEL(adr)              OP-jump       2#00001111 2#10000010)

(instr JNB  (shortlabel)       OP-jump-short 2#01110011) 
(instr JNBL (adr)              OP-jump       2#00001111 2#10000011)
(instr JAE  (shortlabel)       OP-jump-short 2#01110011)  
(instr JAEL (adr)              OP-jump       2#00001111 2#10000011) 

(instr JE   (shortlabel)       OP-jump-short 2#01110100) 
(instr JEL  (adr)              OP-jump       2#00001111 2#10000100) 
(instr JZ   (shortlabel)       OP-jump-short 2#01110100)  
(instr JZL  (adr)              OP-jump       2#00001111 2#10000100) 

(instr JNE  (shortlabel)       OP-jump-short 2#01110101) 
(instr JNEL (adr)              OP-jump       2#00001111 2#10000101)
(instr JNZ  (shortlabel)       OP-jump-short 2#01110101)  
(instr JNZL (adr)              OP-jump       2#00001111 2#10000101)


(instr JBE  (shortlabel)       OP-jump-short 2#01110110) 
(instr JBEL  (adr)              OP-jump       2#00001111 2#10000110)
(instr JNA  (shortlabel)       OP-jump-short 2#01110110)  
(instr JNAL (adr)              OP-jump       2#00001111 2#10000110)

(instr JNBE (shortlabel)       OP-jump-short 2#01110111) 
(instr JNBEL(adr)              OP-jump       2#00001111 2#10000111)     
(instr JA   (shortlabel)       OP-jump-short 2#01110111)  
(instr JAL  (adr)              OP-jump       2#00001111 2#10000111)

(instr JS   (shortlabel)       OP-jump-short 2#01111000) 
(instr JSL  (adr)              OP-jump       2#00001111 2#10001000) 
(instr JNS  (shortlabel)       OP-jump-short 2#01111001)  
(instr JNSL (adr)              OP-jump       2#00001111 2#10001001) 
 
(instr JP   (shortlabel)       OP-jump-short 2#01111010)  
(instr JPL  (adr)              OP-jump       2#00001111 2#10001010) 
(instr JPE  (shortlabel)       OP-jump-short 2#01111010)   
(instr JPEL (adr)              OP-jump       2#00001111 2#10001010) 
 
(instr JNP  (shortlabel)       OP-jump-short 2#01111011)  
(instr JNPL (adr)              OP-jump       2#00001111 2#10001011) 
(instr JPO  (shortlabel)       OP-jump-short 2#01111011)   
(instr JPOL (adr)              OP-jump       2#00001111 2#10001011) 

(instr JL   (shortlabel)       OP-jump-short 2#01111100)  
(instr JLL  (adr)              OP-jump       2#00001111 2#10001100)
(instr JNGE (shortlabel)       OP-jump-short 2#01111100)   
(instr JNGEL(adr)              OP-jump       2#00001111 2#10001100)

(instr JNL  (shortlabel)       OP-jump-short 2#01111101)  
(instr JNLL (adr)              OP-jump       2#00001111 2#10001101) 
(instr JGE  (shortlabel)       OP-jump-short 2#01111101)   
(instr JGEL (adr)              OP-jump       2#00001111 2#10001101) 
 
(instr JLE  (shortlabel)       OP-jump-short 2#01111110)  
(instr JLEL (adr)              OP-jump       2#00001111 2#10001110) 
(instr JNG  (shortlabel)       OP-jump-short 2#01111110)   
(instr JNGL (adr)              OP-jump       2#00001111 2#10001110)
 
(instr JNLE (shortlabel)       OP-jump-short 2#01111111)  
(instr JNLEL(adr)              OP-jump       2#00001111 2#10001111)
(instr JG   (shortlabel)       OP-jump-short 2#01111111)   
(instr JGL  (adr)              OP-jump       2#00001111 2#10001111)

(instr JCXZ (shortlabel)       OP-jump-short 2#11100011)
(instr JECXZ (shortlabel)      OP-jump-short 2#11100011)

(instr INT ('3)                OP-byte      2#11001100)
(instr INT (!n)                OP-INT       2#11001101)

(instr SAHF ()                 OP-byte       16#9E)
(instr WAIT ()                 OP-byte       16#9B)

%(instr SETeq (reg)             OP-set        2#00001111 10010100 11000000)
%(instr SETne (reg)             OP-set        2#00001111 10010101 11000000)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Flag control

 (instr PUSHFD()               OP-byte       16#9C)
 (instr POPFD()                OP-byte       16#9D)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%    Segment override prefixes

(instr CS:  ()                 OP-byte       16#2E)
(instr SS:  ()                 OP-byte       16#36)
(instr DS:  ()                 OP-byte       16#3E)
(instr ES:  ()                 OP-byte       16#26)
(instr FS:  ()                 OP-byte       16#64)
(instr GS:  ()                 OP-byte       16#65)

%    REX Prefix for 64 bit mode of instructions

(instr REX  ()                 OP-byte       16#48)

%    Operand and Address size override

(instr OS:  ()                 OP-byte       16#66)
(instr AS:  ()                 OP-byte       16#67)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%   Floating point instructions i80387
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
(instr FCLEX()                 OP-byte     16#9B 16#DB 16#E2)
 

(instr FILD(effa)              OP-effa       16#DB /0) 
(instr FIST(effa)              OP-effa       16#DB /2) 
(instr FISTP(effa)             OP-effa       16#DB /3)
  
(instr FLD(effa)               OP-effa       16#DD /0) 
(instr FST(effa)               OP-effa       16#DD /2) 
(instr FSTP(effa)              OP-effa       16#DD /3)
(instr FNSTSW(effa)	       OP-effa	     16#DD /7)

(instr FLDENV(effa)            OP-effa       16#D9 /4)
(instr FLDCW(effa)             OP-effa       16#D9 /5)
(instr FSTCW(effa)             OP-effa       16#D9 /7)
(instr FSTENV(effa)            OP-effa       16#D9 /6)

(instr FABS ()                 OP-byte       16#D9 16#E1)
 
(instr FADD (effa)             OP-effa       16#DC 0)
(instr FADDP ()                OP-byte       16#DE 16#C1)
 
(instr FCOM (effa)             OP-effa       16#DC /2)
(instr FCOM ()                 OP-byte       16#D8 16#D1)
(instr FCOMP(effa)             OP-effa       16#DC /3)
(instr FCOMP()                 OP-byte       16#D8 16#D9)

 
(instr FDIV (effa)             OP-effa       16#DC /6)
(instr FDIVP()                 OP-byte       16#DE 16#F9) 
  
(instr FDIVR(effa)             OP-effa       16#DC /7)  
(instr FDIVR()                 OP-byte       16#DE 16#F1)

(instr FMUL(effa)              OP-effa       16#DC /1)
(instr FMULP()                 OP-byte       16#DE 16#C9)
 
(instr FSUB(effa)              OP-effa       16#DC /4) 
(instr FSUBP()                 OP-byte       16#DE 16#E9)
 
(instr FSUBR(effa)             OP-effa       16#DC /5)  
(instr FSUBRP()                OP-byte       16#DE 16#E1) 
  
(instr FSIN()                  OP-byte       16#D9 16#fe)
(instr FCOS()                  OP-byte       16#d9 16#ff)
(instr FSQRT()                 OP-byte       16#D9 16#fa)
(instr FPTAN()                 OP-byte       16#d9 16#f2)
(instr FPATAN()                OP-byte       16#d9 16#f3)
(instr FLDLN2()                OP-byte       16#d9 16#ed)
(instr FYl2x()                 OP-byte       16#d9 16#f1)
(instr FLDL2e()                OP-byte       16#d9 16#ea)
(instr F2xm1()                 OP-byte       16#d9 16#f0)
(instr FSTSW ('(reg ax))       OP-byte       16#DF 16#E0)

(instr FLD1()                  OP-byte       16#D9 16#E8)

(instr FBSTP (effa)            OP-effa       16#df /6)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% SSE instructions
%
% opcodes commented out are not tested
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
%(instr MOVUPS(xmmreg xmmreg)   OP-xmmreg-effa   16#0f 16#10)
%(instr MOVUPS(xmmreg reg)	OP-xmmreg-effa	 16#0f 16#10)
%(instr MOVUPS(reg xmmreg)      OP-xmmreg-effa   16#0f 16#11)

%(instr MOVSS(xmmreg xmmreg)    OP-xmmreg-effa   16#f3 16#0f 16#10)
%(instr MOVSS(xmmreg reg)	OP-xmmreg-effa	 16#f3 16#0f 16#10)
%(instr MOVSS(reg xmmreg)       OP-xmmreg-effa   16#f3 16#0f 16#11)

%(instr MOVUPD(xmmreg xmmreg)   OP-xmmreg-effa   16#66 16#0f 16#10)
%(instr MOVUPD(xmmreg reg)	OP-xmmreg-effa	 16#66 16#0f 16#10)
%(instr MOVUPD(reg xmmreg)      OP-xmmreg-effa   16#66 16#0f 16#11)

(instr MOVSD(xmmreg xmmreg)    	OP-xmmreg-effa   16#f2 16#0f 16#11)
(instI MOVSD(effa xmmreg)      	OP-xmmreg-effa   16#f2 16#0f 16#10)
(instr MOVSD(xmmreg effa)      	OP-xmmreg-effa	 16#f2 16#0f 16#11)

%(instr MOVHLPS(xmmreg xmmreg)  OP-xmmreg-reg	 16#0f 16#12)
%(instI MOVLPS(effa xmmreg)     OP-xmmreg-effa   16#0f 16#12)
%(instr MOVLPS(xmmreg effa)     OP-xmmreg-effa	 16#0f 16#13)
%(instI MOVLPD(effa xmmreg)     OP-xmmreg-effa   16#66 16#0f 16#12)
%(instr MOVLPD(xmmreg effa)     OP-xmmreg-effa	 16#66 16#0f 16#13)

%(instr MOVDDUP(xmmreg xmmreg)  OP-xmmreg-effa   16#f2 16#0f 16#12)
%(instI MOVDDUP(effa xmmreg)    OP-xmmreg-effa   16#f2 16#0f 16#12)
%(instr MOVSLDUP(xmmreg xmmreg) OP-xmmreg-effa	 16#f3 16#0f 16#12)
%(instI MOVSLDUP(effa xmmreg)   OP-xmmreg-effa   16#f3 16#0f 16#12)

%(instr UNPCKLPS(xmmreg xmmreg) OP-xmmreg-effa   16#0f 16#14)
%(instI UNPCKLPS(effa xmmreg)   OP-xmmreg-effa   16#0f 16#14)
%(instr UNPCKLPD(xmmreg xmmreg) OP-xmmreg-effa   16#66 16#0f 16#14)
%(instI UNPCKLPD(effa xmmreg)   OP-xmmreg-effa   16#66 16#0f 16#14)

%(instr UNPCKHPS(xmmreg xmmreg) OP-xmmreg-effa   16#0f 16#15)
%(instI UNPCKHPS(effa xmmreg)   OP-xmmreg-effa   16#0f 16#15)
%(instr UNPCKHPD(xmmreg xmmreg) OP-xmmreg-effa   16#66 16#0f 16#15)
%(instI UNPCKHPD(effa xmmreg)   OP-xmmreg-effa   16#66 16#0f 16#15)

%(instr MOVLHPS(xmmreg xmmreg)  OP-xmmreg-effa   16#0f 16#16)
%(instI MOVHPS(effa xmmreg)     OP-xmmreg-effa   16#0f 16#16)
%(instr MOVHPD(xmmreg xmmreg)   OP-xmmreg-effa   16#66 16#0f 16#16)
%(instI MOVSHPDUP(effa xmmreg)  OP-xmmreg-effa	 16#f3 16#0f 16#16)

%(instr MOVHPS(xmmreg effa)	OP-xmmreg-effa	 16#0f 16#17)
%(instr MOVHPD(xmmreg effa)	OP-xmmreg-effa	 16#66 16#0f 16#17)

%(instr MOVAPS(xmmreg effa)	OP-xmmreg-effa	 16#0f 16#28)
%(instI MOVAPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#29)
(instr MOVAPD(xmmreg xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#29)
%(instI MOVAPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#28)
%(instr MOVAPD(xmmreg effa)	OP-xmmreg-effa	 16#66 16#0f 16#29)

%(instr CVTPI2PS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#2a)
%(instr CVTPI2PD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#2a)
%(instr CVTSI2SS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#2a)
%(instr CVTSI2SD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#2a)
(instI CVTSI2SDQ(effa xmmreg)	OP-xmmreg-effa	 16#f2 rex 16#0f 16#2a)

%(instr CVTTPS2PI(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#2c)
%(instr CVTTPD2PI(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#2c)
%(instr CVTTSS2SI(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#2c)
(instI CVTTSD2SI(effa reg)  	OP-xmmreg-effa	 16#f2 rex 16#0f 16#2c)

%(instr CVTPS2PI(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#2d)
%(instr CVTPD2PI(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#2d)
%(instr CVTSS2SI(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#2d)
%(instr CVTSD2SI(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#2d)

(instI UCOMISS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#2e)
(instI UCOMISD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#2e)

(instI COMISS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#2f)
(instI COMISD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#2f)

%(instI SQRTPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#51)
%(instI SQRTPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#51)
%(instI SQRTSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#51)
(instI SQRTSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#51)

%(instI RSQRTPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#52)
%(instI RSQRTSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#52)

%(instI RCPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#53)
%(instI RCSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#53)

%(instI ANDPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#4)
%(instI ANDSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#54)

%(instI ANDNPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#55)
%(instI ANDNSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#55)

%(instI ORPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#56)
%(instI ORSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#56)

%(instI XORPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#57)
%(instI XORSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#57)

%(instI ADDPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#58)
%(instI ADDPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#58)
%(instI ADDSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#58)
(instI ADDSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#58)

%(instI MULPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#51)
%(instI MULPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#59)
%(instI MULSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#59)
(instI MULSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#59)

%(instI CVTPS2PD(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5a)
%(instI CVTPD2PS(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#5a)
%(instI CVTSS2SD(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5a)
%(instI CVTDQ2PS(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#5a)

%(instI CVTPS2DQ(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5b)
%(instI CVTTPS2DQ(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5b)

%(instI SUBPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5c)
%(instI SUBPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#5c)
%(instI SUBSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5C)
(instI SUBSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#5c)

%(instI MINPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5d)
%(instI MINPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#5d)
%(instI MINSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5d)
%(instI MINSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#5d)

%(instI DIVPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5e)
%(instI DIVPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#5e)
%(instI DIVSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5e)
(instI DIVSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#5e)

%(instI MAXPS(effa xmmreg)	OP-xmmreg-effa	 16#0f 16#5f)
%(instI MAXPD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#5f)
%(instI MAXSS(effa xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#5f)
%(instI MAXSD(effa xmmreg)	OP-xmmreg-effa	 16#f2 16#0f 16#5f)

%(instr MOVD(reg xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#6e)
%(instr MOVD(xmmreg reg)	OP-xmmreg-effa	 16#66 16#0f 16#7e)
%(instI MOVD(effa xmmreg)	OP-xmmreg-effa	 16#66 16#0f 16#6e)
%(instr MOVD(xmmreg effa)	OP-xmmreg-effa	 16#66 16#0f 16#7e)

(instI MOVQ(xmmreg xmmreg)	OP-xmmreg-effa	 16#f3 16#0f 16#7e)

(instr MOVQ(reg xmmreg)		OP-xmmreg-effa	 16#66 rex 16#0f 16#6e)
(instr MOVQ(xmmreg reg)		OP-xmmreg-effa	 16#66 rex 16#0f 16#7e)
(instI MOVQ(effa xmmreg)	OP-xmmreg-effa	 16#66 rex 16#0f 16#6e)
(instr MOVQ(xmmreg effa)	OP-xmmreg-effa	 16#66 rex 16#0f 16#7e)

%(instr PAND(xmmreg xmmreg)      OP-xmmreg-effa   16#66 16#0f 16#db)
(instI PAND(effa xmmreg)      	OP-xmmreg-effa   16#66 16#0f 16#db)
(instr PAND(xmmreg effa)      	OP-xmmreg-effa   16#66 16#0f 16#db)

%(instr PANDN(xmmreg xmmreg)     OP-xmmreg-effa   16#66 16#0f 16#df)
(instI PANDN(effa xmmreg)      	OP-xmmreg-effa   16#66 16#0f 16#df)
(instr PANDN(xmmreg effa)      	OP-xmmreg-effa   16#66 16#0f 16#df)

%(instr POR(xmmreg xmmreg)       OP-xmmreg-effa   16#66 16#0f 16#eb)
(instI POR(effa xmmreg)      	OP-xmmreg-effa   16#66 16#0f 16#eb)
(instr POR(xmmreg effa)      	OP-xmmreg-effa   16#66 16#0f 16#eb)

%(instr PXOR(xmmreg xmmreg)      OP-xmmreg-effa   16#66 16#0f 16#ef)
(instI PXOR(effa xmmreg)      	OP-xmmreg-effa   16#66 16#0f 16#ef)
(instr PXOR(xmmreg effa)      	OP-xmmreg-effa   16#66 16#0f 16#ef)

%(instI ANDPD(xmmreg xmmreg)     OP-xmmreg-effa   16#66 16#0f 16#54)
(instI ANDPD(effa xmmreg)       OP-xmmreg-effa   16#66 16#0f 16#54)
(instr ANDPD(xmmreg effa)       OP-xmmreg-effa   16#66 16#0f 16#54)

%(instI ANDNPD(xmmreg xmmreg)    OP-xmmreg-effa   16#66 16#0f 16#55)
(instI ANDNPD(effa xmmreg)      OP-xmmreg-effa   16#66 16#0f 16#55)
(instr ANDNPD(xmmreg effa)      OP-xmmreg-effa   16#66 16#0f 16#55)

%(instI ORPD(xmmreg xmmreg)      OP-xmmreg-effa   16#66 16#0f 16#56)
(instI ORPD(effa xmmreg)        OP-xmmreg-effa   16#66 16#0f 16#56)
(instr ORPD(xmmreg effa)        OP-xmmreg-effa   16#66 16#0f 16#56)

%(instI XORPD(xmmreg xmmreg)     OP-xmmreg-effa   16#66 16#0f 16#57)
(instI XORPD(effa xmmreg)       OP-xmmreg-effa   16#66 16#0f 16#57)
(instr XORPD(xmmreg effa)       OP-xmmreg-effa   16#66 16#0f 16#57)

(instr LDMXCSR(effa)		OP2-effa	 16#0f 16#ae /2)
(instr STMXCSR(effa)		OP2-effa	 16#0f 16#ae /3)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% now we generate the CXINSTR dataset
(off usermode) (de linelength (x) 1000)
(pp nil)
(collectInstructions "mingw-w64-inst.dat")
% (disassembletables "disasstb")
% (displayInstructions "386instrlist")

(exitlisp)
