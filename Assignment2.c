/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */
/* 
 * float_abs - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_abs(unsigned uf) {
   int SignCheck = ~(0x1 << 31); //Mask 0x80000000 to set the sign bit to 0
   int CheckExp = (uf << 1); //Shift the number 1 bit left to lose the sign bit
   int CheckMan = (uf << 9); //Shift the number 9 bits left to lose the sign bit and the exp
   int Check = ~0x0; //Mask to check if the number is inf or NaN
   CheckExp = (CheckExp >> 24); //Shift the exp 24 bits right to lose the mantissa part
   if(Check == CheckExp && CheckMan != 0) //Check if the exponent is all 1s and if the mantissa is not 0
   {
      return uf; //Return the original number if NaN
   }
   else //If the number is not NaN
   { 
      return uf&SignCheck; //Change the sign bit to positive if not NaN
   }
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
   int SignCheck = (0x1 << 31); //Mask 0x80000000 to extract the sign bit of the number
   int CheckExp = (uf << 1); //Shift the number 1 bit left to lose the sign bit
   int CheckMan = (uf << 9); //Shift the number 9 bits left to lose the sign bit and the exp
   int Check = ~0x0; //Mask to check if the number is inf or NaN
   CheckExp = (CheckExp >> 24); //Shift the exp 24 bits right to lose the mantissa part
   if(Check == CheckExp && CheckMan != 0) //Check if the exponent is all 1s and if the mantissa is not 0
   {
      return uf; //Return the original number if NaN
   }
   else
   {
      return uf + SignCheck; //Flip the sign bit if not NaN
   }
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int float_f2i(unsigned uf) {
   int CheckMan = ~((0x01 << 31) >> 8); //Mask to extract the mantissa part
   int Man = uf&CheckMan; //Extract the mantissa part by taking & with the mask
   int CheckExp = (uf >> 23); //Shift the number 23 places right to lose the mantissa
   int Exp = CheckExp&0xFF; //Take & with 0xFF (Eight 1 bits) to extract the exp part
   int E = Exp - 127; //Find E using the formula E = Exp - Bias
   int SignCheck = (uf >> 31); //Shift the number 31 places right to lose mantissa
   int Sign = SignCheck&0x01; //Take & with 0x01 to extract the sign bit
   int Answer = Man; //Answer will only include mantissa since we are converting to int and we will set the sign bit later
   if(Exp == 0xFF) //This condition shows  that the number is NaN or inf
   {
      return (0x01 << 31); //Return 0x80000000
   }
   else if(Exp == 0x00) //This conditions shows that the exponent is 0 which means that the integer will be 0
   {
      return 0;
   }
   else if(Exp == 0x7F) //If the exponent is 0 the integer will be +1 or -1
   {
      if(Sign == 0x00) //If the sign is positive then integer will be +1
      {
         return 1;
      }
      else //If the sign is negative then ingteger will be -1
      {
         return -1;
      }
   }
   else if(E > 31) //If E is greater than 31 the value will be out of range since since integer can only go till (2^31 - 1)
   {
      return (0x01 << 31); //Return 0x80000000
   }
   else if(E < 0) //If E is 0 then integer will be 0
   {
      return 0;
   }
   else //The number is not NaN or inf or out of range
   {
      if(Sign == 0x00) //If the sign of the original number is postivie return the answer
      {
         return Answer;
      }
      else //If the sign of the original number is negative then set the sign of integer to negative and return
      {
         return -Answer;
      }
   }
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
   int Man = x; //Store the integer number in mantissa
   int Sign = 0; 
   int Bias = 127; //Bias is (2^8 - 1)
   int E = 0;
   int Exp = 0;
   unsigned Answer = 0;
   int Mask = ~(0x01 << 31); //Mask to lose the sign bit of the integer number
   if(x != 0) //If the integer number is not 0
   {
      Sign = (x&(0x01 << 31)); //Extract the sign bit of the number
      if(Sign == (0x01 << 31)) //If the sign bit is 1 (negative)
      {
         if(x == (0x01 << 31)) //If x is 0x80000000
         {
            return 0xcf000000; //Return its floating point value
         }
         x = -x; //Flip the sign of the number (make is postive)
      }
      while(!((0x01 << 31)&x) != 0) //Shift the number to the right until we hit the first 1 bit (increment E each time)
      {
         x = x << 1;
         E = E + 1;
      }
      E = 31 - E; //Subtract E from 31 to get the real value of E
      Exp = Bias + E; //Find exp using the formula Exp = Bias + E
      Exp = (Exp << 23); //Shift exp to its position in the floating point (which is after the sign bit)
      Man = ((x&Mask) >> 8); //Lose the sign bit and bring the mantissa in it's position in floating point number by shifting right by 8
      if(((x&0x7F) > 0 || Man&0x01)&&(x&0x80)) //Check if we need to round the number using the rounding rules
	   {   
         Man = Man + 1; //Add 1 to the mantissa part round the number
      }
      Answer = Sign + Exp + Man; //Bring together all the components of the floating point number
   }
   else //If the integer number is 0 the floating point will also be 0
   {
      return 0;  
   }
   return Answer;
}
/* 
 * float_half - Return bit-level equivalent of expression 0.5*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_half(unsigned uf) {
   unsigned Answer, ExpMan;
   unsigned Sign = (uf&0x80000000); //Extract the sign bit of the number
   unsigned Exp = ((uf >> 23)&0xFF); //Extract the exponent by first shifting to the right by 23 to bring the exponent to the far right and then take & with 0xFF
   unsigned Man = (uf&0x7FFFFF); //Extract the mantissa part of the number
   if(Exp == 0xFF) //If the exponent is 0xFF (All 1s) then it means that the number is NaN or inf
   {
      return uf; //Return the number as it is if NaN or inf
   }
   else if (Exp == 0) //If the exponent is 0
   {
      Man = Man >> 1; //Check if we need to round the number
      if(Man&0x1 && uf&0x1) //If we need to round the number add 1 to the mantissa part
      {
         Man = Man + 1;
      }
      return Man|Sign; //Return the mantissa part after adding the sign bit to it(no need to add exponent because it is 0)
   }
   else if(Exp == 1) //If the exponent is 1
   {
      Exp = Exp - 1; //Since we are dividing we need to subtract 1 from the exponent
      Exp = (Exp << 23); //Shift exponent to its position in the floating point that is after the sign bit
      Man= (Man >> 1); //Check if we need to round the number
      Man = (0x1 << 22)|Man; //We need to add 1 as the MSB in mantissa sice our exponent was 1
      if(Man&0x1 && uf&0x1) //If we need to round the number add 1 to the mantissa part
      {
         Man = Man+1;
      }
      return Man|Sign; //Return the mantissa part after adding the sign bit to it(no need to add exponent because it is 0)
   }
   else if(uf == 0 || uf == 0x80000000) //If the floating point number is +0 or -0
   {
      return uf; //Return the number as it is
   }
   else //If we can divide without any anomalies
   {
      Exp = Exp - 1; //Since we are dividing we need to subtract 1 from the exponent
      Exp = (Exp << 23); //Shift exponent to its position in the floating point that is after the sign bit
      ExpMan = Exp|Man; //Add the exponent and the mantissa part together
      Answer = ExpMan|Sign; //Add all the components of the floating point numbe together
      return Answer;
   }
}
