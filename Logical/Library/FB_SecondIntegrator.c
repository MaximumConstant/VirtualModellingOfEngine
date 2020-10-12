
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
void FB_SecondIntegrator(struct FB_SecondIntegrator* inst)
{
	/*TODO: Add your code here*/
	//Building integrator structure
	inst->out = inst->out + inst->in;
}
