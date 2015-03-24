#ifndef _FIXED_POINT_H
#define _FIXED_POINT_H

typedef int fpt;

#define SHIFT_AMOUNT 16 // 2^16 = 65536

//convert integer into fixed point
#define FP_CONV(X)  ((fpt)(X << SHIFT_AMOUNT))
//convert fixed point into integer by rounding down
#define INT_CONV(X)  ((fpt)(X >> SHIFT_AMOUNT))
//add two fixed points
#define ADD_FP(X,Y) (X+Y)
//add a fixed point and integer
#define ADD_FP_INT(X,Y) (X + FP_CONV(Y))
//subtract two fixed points
#define SUB_FP(X,Y) (X - Y)
//subtract an integer from a fixed point
#define SUB_FP_INT(X,Y) (X - FP_CONV(Y))
//multiply two fixed points
#define MUL_FP(X,Y) ((fpt)(((int64_t) X) * INT_CONV(Y)))
//divide two fixed points
#define DIV_FP(X,Y) ((fpt)(FP_CONV((int64_t) X) / Y))
//multiply a fixed point and integer
#define MULT_FP_INT(X,Y) (X*Y)
//divide a fixed point by an integer
#define DIV_FP_INT(X,Y) (X/Y)
//round fixed_pt to nearest integer
#define ROUND_FP(X) (X>=0 ? ((X + (1 << 15)) >> SHIFT_AMOUNT) : ((X - (1 << 15)) >> SHIFT_AMOUNT))


#endif
