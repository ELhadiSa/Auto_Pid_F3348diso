/*
 * PI.c
 *
 *  Created on: 11 avr. 2020
 *      Author: pc
 */



#include "main.h"

#define ADC_RATIO 1241
#define OUTPUTMAX 180
#define OUTPUTMIN 30


float I_out_target = ADC_RATIO*0.322; // Amp
extern float I_out;
float Kp=0,Ki=0.000;
float integral_sum = 0;


float Compute_Pi_Output()

{
	float output;
	float error=0;


	//error
	 error =  I_out -  I_out_target;

	//integral
	 integral_sum=integral_sum+error;

	 //pi output
	 output = Kp*error + Ki*integral_sum;


	 //comparator

	 if ( output > OUTPUTMAX){
		 integral_sum=0;
		 output=OUTPUTMAX;
	 }


	 if ( output < OUTPUTMIN){
		 integral_sum=0;

		 output=OUTPUTMIN;

		 }


return output;
}


//		  ERROR_T ERROR_Value = E_OK;
//		  int32_t delta_error;
//		  int32_t error;
//
//		  /* Compute PI for Buck DCDC5_Mode */
//
//		  /* compute the the difference between the target and the actual value of the output */
//		  if (TargetType == CONSTANT_VOLTAGE){
//			  error =   (int32_t ) vbat - (int32_t) vtarget  ;
//		  }
//		  else {
//			  error =   (int32_t ) ibat - (int32_t) itarget ;
//		  }
//
//		  //I
//		  _int32_sum_errors_buck_rev =_int32_sum_errors_buck_rev +  error;
//
//		  //D
//		  delta_error = (error - _int32_last_errors_buck_rev);
//
//		  //PID
//		  *thenewduty = (KP_BUCK_REV * error) + (KI_BUCK_REV * _int32_sum_errors_buck_rev) + (KD_BUCK_REV * delta_error);
//
//		  //D
//		  _int32_last_errors_buck_rev = error;
//
//		  if (*thenewduty  >= MAX_DUTY_BUCK_REV)
//		    {
//			  *thenewduty = MAX_DUTY_BUCK_REV;
//			  _int32_sum_errors_buck_rev = 0;
//		      CTMax_buckrev++;
//		    }
//		    else
//		    {
//		      if (CTMax_buckrev != 0)
//		      {
//		        CTMax_buckrev--;
//		      }
//		    }
//		    if (*thenewduty <= MIN_DUTY_BUCK_REV)
//		    {
//		    	*thenewduty = MIN_DUTY_BUCK_REV;
//		    	_int32_sum_errors_buck_rev = 0;
//		      CTMin_buckrev++;
//		    }
//		    else
//		    {
//		      if (CTMin_buckrev != 0)
//		      {
//		        CTMin_buckrev--;
//		      }
//		    }
//
//		  return  ERROR_Value;
