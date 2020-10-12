
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
void FB_regulator(struct FB_regulator* inst)
{
	/*TODO: Add your code here*/
	//Building regulator's structure

	REAL firstPath = 0;		// the one of the scheme's parts
	REAL secondPath = 0;	// the another of the scheme's parts
	if((inst->e*inst->k_p) < (inst->max_abs_value))
	{
		firstPath = inst->e*inst->k_p;
	}
	else
	{
		firstPath = inst->max_abs_value;
	}
	
	inst->integrator.in = inst->e*inst->k_i*inst->dt + inst->iyOld;
	FB_Integrator(&(inst->integrator));
	secondPath = inst->integrator.out;
	// add into function the antiAccumulationPart
	if((firstPath + secondPath) < (inst->max_abs_value))	
		{
			inst->u = (firstPath + secondPath);
		}
	else 
		{
			inst->u = inst->max_abs_value;
		}
	 inst->iyOld = inst->u - (firstPath + secondPath);

		
}
