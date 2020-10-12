
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

REAL count = 0;

void _INIT ProgramInit(void)
{
	speed = 0;
	fb_motor.dt = 0.002;
	fb_motor.ke = 2;	
	fb_motor.Tm = 0.04;	
	
	fb_regulator.dt = 0.002;
	fb_regulator.e = speed - fb_motor.w;
	fb_regulator.iyOld = 0;
	fb_regulator.max_abs_value = 5;
	fb_regulator.k_i = 20;
	fb_regulator.k_p = 8;
	
	fb_secondMotor.dt = 0.002;
	fb_secondMotor.ke = 2;
	fb_secondMotor.Tm = 0.04;
	
	
	enable = 1;
}

void _CYCLIC ProgramCyclic(void)
{
	if(enable == 1)
	{
		count += 100;
		if((count >= 10000) && (count <= 30000))
		{
			speed = 3;
		}
		else
		{
			speed = 0;
		}
		
		// motor with regulator
		fb_regulator.e = speed - fb_motor.w;
		FB_regulator(&fb_regulator);
		fb_motor.u = fb_regulator.u;
		FB_Motor(&fb_motor);
		
		// motor without regulator
		fb_secondMotor.u = speed;
		FB_SecondMotor(&fb_secondMotor);
	}
}

void _EXIT ProgramExit(void)
{

}

