
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include "svpwm.h"
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void tms_Outputs_wrapper(const real_T *wt_i,
			const real_T *ud_i,
			const real_T *us_a_i,
			real_T *betta_o,
			real_T *Ta_o,
			real_T *Tb_o,
			real_T *Tc_o,
			real_T *Us_o)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
//wt[0];
//f_pwm[0];
//ud[0];
//us_a[0];
wt=wt_i[0];
ud=ud_i[0];
us_a=us_a_i[0];

svpwm(wt, ud, us_a);

betta_o[0]=betta;
Ta_o[0]=Ta;
Tb_o[0]=Tb;
Tc_o[0]=Tc;
Us_o[0]=Us;
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


