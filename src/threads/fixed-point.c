#include "fixed-point.h"

void ROUND_FP(fpt& X)
{
	if(X>=0)
	{
		X=FP_REV(X+SHIFT_MASK);
	}
	else
	{
		X=FP_REV(X-SHIFT_MASK);
	}
}
