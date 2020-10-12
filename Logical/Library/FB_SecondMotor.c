
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_SecondMotor(struct FB_SecondMotor* inst)
{
	/*TODO: Add your code here*/
	inst->integrator.in = ((1/(inst->ke))*(inst->u)-(inst->w))*((inst->dt)/(inst->Tm));
	FB_Integrator(&(inst->integrator));
	inst->w = inst->integrator.out;
	//for phi output
	inst->integrator.in = (inst->w)*(inst->dt);
	FB_Integrator(&(inst->integrator));
	inst->phi = inst->integrator.out;
}
