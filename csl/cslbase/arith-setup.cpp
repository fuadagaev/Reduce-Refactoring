// arith-setup.cpp                         Copyright (C) 2022-2022 Codemist

#ifdef ARITHLIB

//
// Setup for the new set of arithmetic operations
//

/**************************************************************************
 * Copyright (C) 2022, Codemist.                         A C Norman       *
 *                                                                        *
 * Redistribution and use in source and binary forms, with or without     *
 * modification, are permitted provided that the following conditions are *
 * met:                                                                   *
 *                                                                        *
 *     * Redistributions of source code must retain the relevant          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer.                                                      *
 *     * Redistributions in binary form must reproduce the above          *
 *       copyright notice, this list of conditions and the following      *
 *       disclaimer in the documentation and/or other materials provided  *
 *       with the distribution.                                           *
 *                                                                        *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS    *
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT      *
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS      *
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE         *
 * COPYRIGHT OWNERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,   *
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,   *
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS  *
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND *
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  *
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF     *
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH   *
 * DAMAGE.                                                                *
 *************************************************************************/

// $Id$


#include "headers.h"
#include "dispatch.h"

LispObject onebool(bool b)
{   return onevalue(b ? lisp_true : nil);
}

static LispObject Nplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

static LispObject Nplus(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Ntimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Ntimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

static LispObject Ntimes(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nexpt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Expt::op(a1, a2));
}

static LispObject Ngcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Ngcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

static LispObject Ngcdn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nlcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

static LispObject Nlcmn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Ndifference(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}

static LispObject Nquotient(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}

static LispObject NCLQuotient(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(CLQuotient::op(a1, a2));
}

static LispObject Nremainder(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Remainder::op(a1, a2));
}

static LispObject Ndivide(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

static LispObject Nadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

static LispObject Nsub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

static LispObject Nonep(LispObject env, LispObject a1)
{   return onebool(Onep::op(a1));
}

static LispObject Nevenp(LispObject env, LispObject a1)
{   return onebool(Evenp::op(a1));
}

static LispObject Noddp(LispObject env, LispObject a1)
{   return onebool(Oddp::op(a1));
}

static LispObject Nzerop(LispObject env, LispObject a1)
{   return onebool(Zerop::op(a1));
}

static LispObject Nminusp(LispObject env, LispObject a1)
{   return onebool(Minusp::op(a1));
}

static LispObject Nminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

static LispObject Nabs(LispObject env, LispObject a1)
{   return onevalue(Abs::op(a1));
}

static LispObject Nreciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

static LispObject Nsqrt(LispObject env, LispObject a1)
{   return onevalue(Sqrt::op(a1));
}

static LispObject Nisqrt(LispObject env, LispObject a1)
{   return onevalue(Isqrt::op(a1));
}

static LispObject Nsquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

static LispObject Nfloat(LispObject env, LispObject a1)
{   return onevalue(Float::op(a1));
}

static LispObject Nfloat(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Float::op(a1, a2));
}

static LispObject Nfix(LispObject env, LispObject a1)
{   return onevalue(Fix::op(a1));
}

static LispObject Ntruncate(LispObject env, LispObject a1)
{   return onevalue(Truncate::op(a1));
}

static LispObject Nfloor(LispObject env, LispObject a1)
{   return onevalue(Floor::op(a1));
}

static LispObject Nceiling(LispObject env, LispObject a1)
{   return onevalue(Ceiling::op(a1));
}

static LispObject Nftruncate(LispObject env, LispObject a1)
{   return onevalue(Ftruncate::op(a1));
}

static LispObject Nffloor(LispObject env, LispObject a1)
{   return onevalue(Ffloor::op(a1));
}

static LispObject Nfceiling(LispObject env, LispObject a1)
{   return onevalue(Fceiling::op(a1));
}

static LispObject Ntruncate(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Truncate::op(a1, a2));
}

static LispObject Nfloor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Floor::op(a1, a2));
}

static LispObject Nceiling(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Ceiling::op(a1, a2));
}

static LispObject Nftruncate(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Ftruncate::op(a1, a2));
}

static LispObject Nffloor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Ffloor::op(a1, a2));
}

static LispObject Nfceiling(LispObject env, LispObject a1,
                            LispObject a2)
{   return onevalue(Fceiling::op(a1,  a2));
}

static LispObject Nfloat128(LispObject env, LispObject a1)
{   return onevalue(Float128::op(a1));
}

static LispObject Nfrexp(LispObject env, LispObject a1)
{   return onevalue(Frexp::op(a1));
}

static LispObject Nldexp(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Ldexp::op(a1, a2));
}

static LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

static LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2,
                            LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

static LispObject Ngreaterp(LispObject env, LispObject a1,
                            LispObject a2,
                            LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

static LispObject Ngeq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

static LispObject Nlessp(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

static LispObject Nleq(LispObject env, LispObject a1, LispObject a2,
                       LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

static LispObject Neqn_a(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(CLEqn::op(a1, a2));
}

static LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(CLEqn::op(a1, a2) && CLEqn::op(a2, a3));
}

static LispObject NCLEqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!CLEqn::op(a1, a2)) return onevalue(nil);
    if (!CLEqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (CLEqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

static LispObject Nneqn(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!Neqn::op(a1, a)) return onevalue(nil);
        if (!Neqn::op(a2, a)) return onevalue(nil);
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!Neqn::op(a, car(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Nlogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nlogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

static LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

static LispObject Nlogand(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nlogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

static LispObject Nlogor(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nlogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

static LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

static LispObject Nlogxor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nlogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

static LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

static LispObject Nlogeqv(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nlognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

static LispObject Nlogcount(LispObject env, LispObject a1)
{   return onevalue(Logcount::op(a1));
}

static LispObject Nleftshift(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

static LispObject Nrightshift(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
}

static LispObject Nmodular_plus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2)
{   return onevalue(ModularPlus::op(a1, a2));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2,
                                LispObject a3)
{   return onevalue(ModularPlus::op(ModularPlus::op(a1, a2), a3));
}

static LispObject Nmodular_plus(LispObject env, LispObject a1,
                                LispObject a2,
                                LispObject a3, LispObject a4plus)
{   LispObject w = ModularPlus::op(ModularPlus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularPlus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nmodular_times(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nmodular_times(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2)
{   return onevalue(ModularTimes::op(a1, a2));
}

static LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3)
{   return onevalue(ModularTimes::op(ModularTimes::op(a1, a2), a3));
}

static LispObject Nmodular_times(LispObject env, LispObject a1,
                                 LispObject a2,
                                 LispObject a3, LispObject a4plus)
{   LispObject w = ModularTimes::op(ModularTimes::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = ModularTimes::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nmodular_expt(LispObject env, LispObject a1,
                                LispObject a2)
{   return onevalue(ModularExpt::op(a1, a2));
}

static LispObject Nmodular_difference(LispObject env, LispObject a1,
                                      LispObject a2)
{   return onevalue(ModularDifference::op(a1, a2));
}

static LispObject Nmodular_quotient(LispObject env, LispObject a1,
                                    LispObject a2)
{   return onevalue(ModularQuotient::op(a1, a2));
}

static LispObject Nmodular_reciprocal(LispObject env, LispObject a1)
{   return onevalue(ModularReciprocal::op(a1));
}

static LispObject Nmodular_minus(LispObject env, LispObject a1)
{   return onevalue(ModularMinus::op(a1));
}

static LispObject Nset_modulus(LispObject env, LispObject a1)
{   return onevalue(SetModulus::op(a1));
}

static LispObject Nmodular_number(LispObject env, LispObject a1)
{   return onevalue(ModularNumber::op(a1));
}

// The following functions, with name like IPLUS, ITIMES etc are relatives
// of the generic versions but they only support fixnum inputs. On a 32-bit
// machine that is values that fit in 28 bits, while on a 64-bit machine
// 60 bits are supported. Overflow is not checked for and although the
// consequence is probably that values wrap around within the range of fixnums
// that will not be guaranteed.

static LispObject Niplus(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Niplus(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Plus::op(a1, a2));
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Plus::op(Plus::op(a1, a2), a3));
}

static LispObject Niplus(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Plus::op(Plus::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Plus::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nitimes(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nitimes(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Times::op(a1, a2));
}

static LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Times::op(Times::op(a1, a2), a3));
}

static LispObject Nitimes(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Times::op(Times::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Times::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Niexpt(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Expt::op(a1, a2));
}

static LispObject Nigcdn(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nigcdn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Gcdn::op(a1, a2));
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Gcdn::op(Gcdn::op(a1, a2), a3));
}

static LispObject Nigcdn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Gcdn::op(Gcdn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Gcdn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilcmn(LispObject env)
{   return onevalue(fixnum_of_int(1));
}

static LispObject Nilcmn(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2)
{   return onevalue(Lcmn::op(a1, a2));
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onevalue(Lcmn::op(Lcmn::op(a1, a2), a3));
}

static LispObject Nilcmn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   LispObject w = Lcmn::op(Lcmn::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Lcmn::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nidifference(LispObject env, LispObject a1,
                               LispObject a2)
{   return onevalue(Difference::op(a1, a2));
}

static LispObject Niquotient(LispObject env, LispObject a1,
                             LispObject a2)
{   return onevalue(Quotient::op(a1, a2));
}

static LispObject Niremainder(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(Remainder::op(a1, a2));
}

static LispObject Nidivide(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Divide::op(a1, a2));
}

static LispObject Niadd1(LispObject env, LispObject a1)
{   return onevalue(Plus::op(a1, fixnum_of_int(1)));
}

static LispObject Nisub1(LispObject env, LispObject a1)
{   return onevalue(Difference::op(a1, fixnum_of_int(1)));
}

static LispObject Nionep(LispObject env, LispObject a1)
{   return onevalue(Onep::op(a1));
}

static LispObject Nievenp(LispObject env, LispObject a1)
{   return onevalue(Evenp::op(a1));
}

static LispObject Nioddp(LispObject env, LispObject a1)
{   return onevalue(Oddp::op(a1));
}

static LispObject Nizerop(LispObject env, LispObject a1)
{   return onevalue(Zerop::op(a1));
}

static LispObject Niminusp(LispObject env, LispObject a1)
{   return onevalue(Minusp::op(a1));
}

static LispObject Niminus(LispObject env, LispObject a1)
{   return onevalue(Minus::op(a1));
}

static LispObject Niabs(LispObject env, LispObject a1)
{   return onevalue(Abs::op(a1));
}

static LispObject Nireciprocal(LispObject env, LispObject a1)
{   return onevalue(Reciprocal::op(a1));
}

static LispObject Nisquare(LispObject env, LispObject a1)
{   return onevalue(Square::op(a1));
}

static LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2)
{   return onebool(Greaterp::op(a1, a2));
}

static LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2,
                             LispObject a3)
{   return onebool(Greaterp::op(a1, a2) && Greaterp::op(a2, a3));
}

static LispObject Nigreaterp(LispObject env, LispObject a1,
                             LispObject a2,
                             LispObject a3, LispObject a4plus)
{   if (!Greaterp::op(a1, a2)) return onevalue(nil);
    if (!Greaterp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Greaterp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Geq::op(a1, a2));
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Geq::op(a1, a2) && Geq::op(a2, a3));
}

static LispObject Nigeq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Geq::op(a1, a2)) return onevalue(nil);
    if (!Geq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Geq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2)
{   return onebool(Lessp::op(a1, a2));
}

static LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onebool(Lessp::op(a1, a2) && Lessp::op(a2, a3));
}

static LispObject Nilessp(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   if (!Lessp::op(a1, a2)) return onevalue(nil);
    if (!Lessp::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Lessp::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Leq::op(a1, a2));
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3)
{   return onebool(Leq::op(a1, a2) && Leq::op(a2, a3));
}

static LispObject Nileq(LispObject env, LispObject a1, LispObject a2,
                        LispObject a3, LispObject a4plus)
{   if (!Leq::op(a1, a2)) return onevalue(nil);
    if (!Leq::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Leq::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2)
{   return onebool(Eqn::op(a1, a2));
}

static LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onebool(Eqn::op(a1, a2) && Eqn::op(a2, a3));
}

static LispObject Nieqn_a(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   if (!Eqn::op(a1, a2)) return onevalue(nil);
    if (!Eqn::op(a2, a3)) return onevalue(nil);
    a2 = a3;
    while (is_cons(a4plus))
    {   if (Eqn::op(a2, a3 = car(a4plus))) return onevalue(nil);
        a2 = a3;
        a4plus = cdr(a4plus);
    }
    return onevalue(lisp_true);
}

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2)
{   return onebool(Neqn::op(a1, a2));
}

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3)
{   return onebool(Neqn::op(a1, a2) && Neqn::op(a2, a3) &&
                   Neqn::op(a1, a3));
}

// NEQN is what Common Lisp calls "/=" and when given many arguments it
// checks if all aee distinct. Well (neqn a NaN) will be false so if ANY
// of the arguments is a NaN then NEQN will return false.

static LispObject Nineqn(LispObject env, LispObject a1, LispObject a2,
                         LispObject a3, LispObject a4plus)
{   if (!Neqn::op(a1, a2)) return onevalue(nil);
    if (!Neqn::op(a2, a3)) return onevalue(nil);
    if (!Neqn::op(a1, a3)) return onevalue(nil);
    for (LispObject w=a4plus; is_cons(w); w=cdr(w))
    {   LispObject a = car(w);
        if (!Neqn::op(a1, a)) return onevalue(nil);
        if (!Neqn::op(a2, a)) return onevalue(nil);
        if (!Neqn::op(a3, a)) return onevalue(nil);
    }
    a2 = a3;
    for (; is_cons(a4plus); a4plus=cdr(a4plus))
    {   LispObject a = car(a4plus);
        for (LispObject  w = cdr(a4plus); is_cons(w); w = cdr(w))
        {   if (!Neqn::op(a, car(w))) return onevalue(nil);
        }
    }
    return onevalue(lisp_true);
}

static LispObject Nilogand(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nilogand(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logand::op(a1, a2));
}

static LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logand::op(Logand::op(a1, a2), a3));
}

static LispObject Nilogand(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logand::op(Logand::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logand::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nilogor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2)
{   return onevalue(Logor::op(a1, a2));
}

static LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3)
{   return onevalue(Logor::op(Logor::op(a1, a2), a3));
}

static LispObject Nilogor(LispObject env, LispObject a1,
                          LispObject a2,
                          LispObject a3, LispObject a4plus)
{   LispObject w = Logor::op(Logor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogxor(LispObject env)
{   return onevalue(fixnum_of_int(0));
}

static LispObject Nilogxor(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logxor::op(a1, a2));
}

static LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logxor::op(Logxor::op(a1, a2), a3));
}

static LispObject Nilogxor(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logxor::op(Logxor::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logxor::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilogeqv(LispObject env)
{   return onevalue(fixnum_of_int(-1));
}

static LispObject Nilogeqv(LispObject env, LispObject a1)
{   return onevalue(a1);
}

static LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2)
{   return onevalue(Logeqv::op(a1, a2));
}

static LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3)
{   return onevalue(Logeqv::op(Logeqv::op(a1, a2), a3));
}

static LispObject Nilogeqv(LispObject env, LispObject a1,
                           LispObject a2,
                           LispObject a3, LispObject a4plus)
{   LispObject w = Logeqv::op(Logeqv::op(a1, a2), a3);
    while (is_cons(a4plus))
    {   w = Logeqv::op(w, car(a4plus));
        a4plus = cdr(a4plus);
    }
    return onevalue(w);
}

static LispObject Nilognot(LispObject env, LispObject a1)
{   return onevalue(Lognot::op(a1));
}

static LispObject Nileftshift(LispObject env, LispObject a1,
                              LispObject a2)
{   return onevalue(LeftShift::op(a1, a2));
}

static LispObject Nirightshift(LispObject env, LispObject a1,
                               LispObject a2)
{   return onevalue(RightShift::op(a1, a2));
}

static LispObject Nmodf(LispObject env, LispObject a1)
{   float fi, ff;
    double di, df;
    float128_t li, lf;
    switch (a1 & XTAG_BITS)
{       default:
            return cons(a1, make_boxfloat(0.0));
        case XTAG_SFLOAT:   // float28 or perhaps float32
            ff = std::modf(value_of_immediate_float(a1), &fi);
            if (SIXTY_FOUR_BIT && ((a1 & XTAG_FLOAT32) != 0))
                return cons(pack_single_float(fi), pack_single_float(ff));
            else return cons(pack_short_float(fi), pack_short_float(ff));
        case TAG_BOXFLOAT: case TAG_BOXFLOAT+TAG_XBIT:
            switch (flthdr(a1))
        {       default:
                    return aerror("badly formatted float data");
                case SINGLE_FLOAT_HEADER:
                    ff = std::modf(single_float_val(a1), &fi);
                    return cons(pack_single_float(fi), pack_single_float(ff));
                case DOUBLE_FLOAT_HEADER:
                    df = std::modf(double_float_val(a1), &di);
                    return cons(make_boxfloat(di), make_boxfloat(df));
                case LONG_FLOAT_HEADER:
                    lf = arithlib_lowlevel::modf(long_float_val(a1), li);
                    return cons(make_boxfloat128(li), make_boxfloat128(lf));
            }
    }
}

setup_type const arith_setup[] =
{   DEF_1("modf",         Nmodf),
    {"plus",              Nplus, Nplus, Nplus, Nplus, Nplus},
    {"+",                 Nplus, Nplus, Nplus, Nplus, Nplus},
    DEF_1("add1",         Nadd1),
    DEF_1("1+",           Nadd1),
    DEF_2("difference",   Ndifference),
    {"-",                 G0Wother, Nminus, Ndifference, G3Wother, G4Wother},
    {"times",             Ntimes, Ntimes, Ntimes, Ntimes, Ntimes},
    {"*",                 Ntimes, Ntimes, Ntimes, Ntimes, Ntimes},
    DEF_2("quotient",     Nquotient),
    DEF_2("//",           Nquotient),
    DEF_2("/",            NCLQuotient),
    DEF_2("remainder",    Nremainder),
    DEF_2("divide",       Ndivide),
    {"gcdn",              Ngcdn, Ngcdn, Ngcdn, Ngcdn, Ngcdn},
    {"lcmn",              Nlcmn, Nlcmn, Nlcmn, Nlcmn, Nlcmn},
    DEF_1("minus",        Nminus),
    DEF_1("minusp",       Nminusp),
    DEF_1("abs",          Nabs),
    DEF_1("reciprocal",   Nreciprocal),
    DEF_1("square",       Nsquare),
    DEF_1("sqrt",         Nsqrt),
    DEF_1("isqrt",        Nisqrt),
    DEF_1("sub1",         Nsub1),
    DEF_1("1-",           Nsub1),
    DEF_1("zerop",        Nzerop),
    DEF_1("onep",         Nonep),
    DEF_1("oddp",         Noddp),
    DEF_1("evenp",        Nevenp),
    {"float",             G0Wother, Nfloat, Nfloat, G3Wother, G4Wother},
    DEF_1("float128",     Nfloat128),
    DEF_1("fix",          Nfix),
    {"truncate",          G0Wother, Ntruncate, Ntruncate, G3Wother, G4Wother},
    {"floor",             G0Wother, Nfloor, Nfloor, G3Wother, G4Wother},
    {"ceiling",           G0Wother, Nceiling, Nceiling, G3Wother, G4Wother},
    {"ftruncate",         G0Wother, Nftruncate, Nftruncate, G3Wother, G4Wother},
    {"ffloor",            G0Wother, Nffloor, Nffloor, G3Wother, G4Wother},
    {"fceiling",          G0Wother, Nfceiling, Nfceiling, G3Wother, G4Wother},
    DEF_1("frexp",        Nfrexp),
    DEF_2("ldexp",        Nldexp),
    DEF_2("expt",         Nexpt),
// Neqn is a name that gives trouble. In one part of the code here it is
// "N" followed by "eqn", and denotes the function that will perform equality
// tests on numbers. In another it is "Neqn", otherwise "neqn" but capitalized
// and it is the name of a class that implements "neqn". So I tag "_a" on
// the end of one of these to resolve the clash.
    {"eqn",               G0Wother, G1Wother, Neqn_a, Neqn_a, Neqn_a},
    {"=",                 G0Wother, G1Wother, NCLEqn, NCLEqn, NCLEqn},
    {"neqn",              G0Wother, G1Wother, Nneqn, Nneqn, Nneqn},
    {"greaterp",          G0Wother, G1Wother, Ngreaterp, Ngreaterp, Ngreaterp},
    {">",                 G0Wother, G1Wother, Ngreaterp, Ngreaterp, Ngreaterp},
    {"geq",               G0Wother, G1Wother, Ngeq, Ngeq, Ngeq},
    {">=",                G0Wother, G1Wother, Ngeq, Ngeq, Ngeq},
    {"lessp",             G0Wother, G1Wother, Nlessp, Nlessp, Nlessp},
    {"<",                 G0Wother, G1Wother, Nlessp, Nlessp, Nlessp},
    {"leq",               G0Wother, G1Wother, Nleq, Nleq, Nleq},
    {"<=",                G0Wother, G1Wother, Nleq, Nleq, Nleq},
    {"logand",            Nlogand, Nlogand, Nlogand, Nlogand, Nlogand},
    {"logor",             Nlogor, Nlogor, Nlogor, Nlogor, Nlogor},
    {"logior",            Nlogor, Nlogor, Nlogor, Nlogor, Nlogor},
    {"logxor",            Nlogxor, Nlogxor, Nlogxor, Nlogxor, Nlogxor},
    {"logeqv",            Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv, Nlogeqv},
    DEF_1("lognot",       Nlognot),
    DEF_1("logcount",     Nlogcount),
    DEF_2("lshift",       Nleftshift),
    DEF_2("ash",          Nleftshift),
    DEF_2("rshift",       Nrightshift),
    {"modular-plus",      Nmodular_plus, Nmodular_plus, Nmodular_plus, Nmodular_plus, Nmodular_plus},
    DEF_2("modular-difference", Nmodular_difference),
    {"modular-times",     Nmodular_times, Nmodular_times, Nmodular_times, Nmodular_times, Nmodular_times},
    DEF_2("modular-quotient",   Nmodular_quotient),
    DEF_2("modular-expt", Nmodular_expt),
    DEF_1("set-modulus",  Nset_modulus),
    DEF_1("set-small-modulus",  Nset_modulus),
    DEF_1("modular-number",     Nmodular_number),
    DEF_1("modular-minus",      Nmodular_minus),
    DEF_1("modular-reciprocal", Nmodular_reciprocal),
    {"iplus",             Niplus, Niplus, Niplus, Niplus, Niplus},
    DEF_1("iadd1",        Niadd1),
    DEF_2("idifference",  Nidifference),
    {"itimes",            Nitimes, Nitimes, Nitimes, Nitimes, Nitimes},
    DEF_2("iquotient",    Niquotient),
    DEF_2("iremainder",   Niremainder),
    DEF_2("idivide",      Nidivide),
    {"igcdn",             Nigcdn, Nigcdn, Nigcdn, Nigcdn, Nigcdn},
    {"ilcmn",             Nilcmn, Nilcmn, Nilcmn, Nilcmn, Nilcmn},
    DEF_1("iminus",       Niminus),
    DEF_1("iminusp",      Niminusp),
    DEF_1("iabs",         Niabs),
    DEF_1("ireciprocal",  Nireciprocal),
    DEF_1("isquare",      Nisquare),
    DEF_1("isub1",        Nisub1),
    DEF_1("izerop",       Nizerop),
    DEF_1("ionep",        Nionep),
    DEF_1("ioddp",        Nioddp),
    DEF_1("ievenp",       Nievenp),
    DEF_2("iexpt",        Niexpt),
    {"ieqn",              G0Wother, G1Wother, Nieqn_a, Nieqn_a, Nieqn_a},
    {"ineqn",             G0Wother, G1Wother, Nineqn, Nineqn, Nineqn},
    {"igreaterp",         G0Wother, G1Wother, Nigreaterp, Nigreaterp, Nigreaterp},
    {"igeq",              G0Wother, G1Wother, Nigeq, Nigeq, Nigeq},
    {"ilessp",            G0Wother, G1Wother, Nilessp, Nilessp, Nilessp},
    {"ileq",              G0Wother, G1Wother, Nileq, Nileq, Nileq},
    {"ilogand",           Nilogand, Nilogand, Nilogand, Nilogand, Nilogand},
    {"ilogor",            Nilogor, Nilogor, Nilogor, Nilogor, Nilogor},
    {"ilogxor",           Nilogxor, Nilogxor, Nilogxor, Nilogxor, Nilogxor},
    {"ilogeqv",           Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv, Nilogeqv},
    DEF_1("ilognot",      Nilognot),
    DEF_1("ilogcount",    Nlogcount),
    DEF_2("ilshift",      Nileftshift),
    DEF_2("irshift",      Nirightshift),
    {nullptr,             nullptr, nullptr, nullptr, nullptr, nullptr}
};

#endif // ARITHLIB

// end of arith-setup.cpp
