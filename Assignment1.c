/* 
 * CS:APP Data Lab 
 * 
 * <Samee Arif 23100088>
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
      ...5
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
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
  /* Alteranative way to take and operater is by using double negation with an or operator (DeMorgan's Law)*/
  int And = ~(~x | ~y); 
  return And;
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
  /* The bits are shifted to the right and n is shifted to the left by 3 bits to convert the bits to bytes (Multiples the number of bytes (n) by 8), 
  and modulus is taken with 0xFF which is (1111 1111) to remove any unecessary leading bits and replace them with 0 */
  int ByteAnswer = x >> (n << 3);
  ByteAnswer = ByteAnswer&0xFF;
  return ByteAnswer;
}
/* 
 * anyEvenBit - return 1 if any even-numbered bit in word set to 1
 *   Examples anyEvenBit(0xA) = 0, anyEvenBit(0xE) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyEvenBit(int x) {
  /* Ox55 is a bit pattern of "0101" which places 1s at the even positions. We right shift by 2^n (with increasing n each time) bytes to get 4 bits 
  and take a modulus with 0x55 to get the values at odd numbered positions. Then we add all the bits we get to get a bit pattern with all the significant bits at odd positons*/
  int isEvenBit = (x&0x55) + ((x >> 8)&0x55) + ((x >> 16)&0x55) + ((x >> 24)&0x55);
  return !(!isEvenBit);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /* OxAA is a bit pattern of "1010" which places 1s at the odd positions. We right shift by 2^n (with increasing n each time) bytes to get 4 bits 
  and take a modulus with 0xAA to get the values at odd numbered positions. Then we take bitwise AND of all the bits we get to get a bit pattern with 
  all the significant bits at odd positons. Then we take XOR of the value we get with 0xAA which is equivalent to value == 0xAA.*/
  int IsOddBit = (x&0xAA) & ((x >> 8)&0xAA) & ((x >> 16)&0xAA) & ((x >> 24)&0xAA);
  int AreOddBits = IsOddBit^0xAA;
  return !AreOddBits;
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
  /* When we shift to the right, 1s are added as leading since the shift is arithematic in our machine.To remove the 1s after shifting the the bits to the right, 
  we will use a masking value and take & with it. To get the masking value we left shift 0x01 by 31 and then right shift by n (this will give us n + 1 number of 
  1 bits on MSB side so we do a left shift by 1 to get n number of 1 bits on MSB side. Then we take the compliment of the value.*/
  int ShiftRightA = (x >> n);
  int ShiftLeft = ~(((0x01 << 31) >> n) << 1);
  int ShiftRightL = (ShiftRightA&ShiftLeft);
  return ShiftRightL;
}
/* 
 * rotateRight - Rotate x to the right by n
 *   Can assume that 0 <= n <= 31
 *   Examples: rotateRight(0x87654321,4) = 0x18765432
 *   Legal ops: ~ & ^ | + << >> !
 *   Max ops: 25
 *   Rating: 3 
 */
int rotateRight(int x, int n) {
  /*(32 - n) is equivalent to (33 + ~n). We have to discard the n number of bits on the LSB side and shift those to the MSB side. We right shift the bit pattern
  to discard the n bits and to store the bits (discarded ones) we right shift TMax by (n - 1) and take & with the n times left shifted bitpattern. To get the result we can
  take | between the two values we found*/
	int Shift = ~(0x1 << 31) >> (n + ~0x01 + 0x01);
	int CheckOne = (x >> n)&Shift; 
	int CheckTwo = (x << (33 + ~n));
	int Answer = CheckOne | CheckTwo;
  return Answer;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* 1 followed by a string of 0s is the smallest two's complement number so we just shift 0x01 by 31 bits*/
  int TMin = 0x01 << 31;
  return TMin;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
  /* Since the positioning needs to be "32-n", the notation we will use is 33+~n since "-" operator is not allowed. We will shift the required bits to the left 
  and make it the leading bit to check if number is positive or negative, and then shift them back to right by the same position. Then we will use XOR between the value 
  we get and the original bit pattern (this is equivalent to value == x), this will give 0 if the values are equal or 1 if they are not equal so we will take NOT of the answer*/
  int Shiftleft = x << (33 + ~n);
  int RightShift = Shiftleft >> (33 + ~n);
  int Answer = !(x^RightShift);
  return Answer;
}
/* 
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2 
 */
int leastBitPos(int x) {
  /*(~x + 1) puts all the 0s to the right of our desired position and when we take an & with our original number, it will remove all the bits we don't require,
  and keep our desired bit*/
  int Answer = (~x + 1)&x;
  return Answer;
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
  /* Dividing by 2^n gives us a right shift by n (since each right shift divides by 2), but we need to check if the number is a negative or positive number. 
  Shifting the desired bit to the end and taking an & with a string of zeros with 1 as LSB tells us whether it is a negative or positive number. 
  If it is a negative we have to compute keeping that in mind*/
  int Check = (x >> 31)&0x01;
  int Answer = (Check << n)+((Check << 31) >> 31);
  Answer = ((x + Answer) >> n);
  return Answer;
}
/* 
 * isNonNegative - return 1 if x >= 0, return 0 otherwise 
 *   Example: isNonNegative(-1) = 0.  isNonNegative(0) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 3
 */
int isNonNegative(int x) {
  /*We right shift the number by 31 bits and then we take & with 0x01 which will give us the 0x00 in case of negative number and 0x01 in case of positive number.
  We will take NOT of the value to get the answer in 0 and 1.*/
  int Answer = (x >> 31)&0x01;
  return !Answer;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*To check if x is equal to y we take XOR. To check if x is smaller than y we have to check two cases, 1) When x and y both are positive or negative (same signs)
  and 2) When x is negative and y is positive (different signs).*/
  int Add = y + (~x + 1);
	int CheckSign = (x^y)&x;
	int Isless=((~(x^y) & ~Add) | CheckSign) & (1<<31);
  int Answer = (!!Isless)|(!Add);
  return Answer; 
}
/*
 * satMul2 - multiplies by 2, saturating to Tmin or Tmax if overflow
 *   Examples: satMul2(0x30000000) = 0x60000000
 *             satMul2(0x40000000) = 0x7FFFFFFF (saturate to TMax)
 *             satMul2(0x60000000) = 0x80000000 (saturate to TMin)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int satMul2(int x) {
  /*We extract the sign bit and then use it to saturate to TMin or TMax depending on x << 1. We would get 0 in case if it is a positive number since we & it with 
  TMin. We would get 1 in case if it is a negative number since we & it with TMax*/
  int TMin = 1 << 31;
	int SignBit = x >> 31;
	int DifferentBits = x ^ (x << 1);
	int CheckOne = DifferentBits >> 31;
	int CheckTwo = CheckOne & (SignBit ^ ~TMin);
  int Answer = CheckTwo | (~CheckOne & (x << 1));
	return Answer;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  /* We have to check if the given number is negtive or positive and we also have to check if the number is zero or not. Numbers <= 0 donot qualify as power of 2.
  To check the power of the number we will add a string of 32 bit 1s into it and we will take & between the result and the original bit pattern.*/
  int isNegative = !!((x >> 31) + 0x01);
  int isZero = !!x;
  int isPower = !((x + ~0x00)&x);
  int Answer = isNegative & isZero & isPower;
  return Answer;
}
