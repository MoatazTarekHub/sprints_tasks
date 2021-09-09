/*
 * RTOS_Program.c
 *
 *  Created on: Jan 10, 2021
 *      Author: Al Badr
 */



#include "std_type.h"
#include "BIT_MATH.h"
#include "RTOS_Config.h"
#include "RTOS_Private.h"
#include "timer_Interface.h"

#define TASK_RESUMED   1
#define TASK_SUSPENDED  0

Task_t SysTask[Task_Number]={{Null}};

void RTOS_CreateTask(u16 Copy_periodicity,void (*ptr)(void), u8 periority, u8 task_del){
	SysTask[periority].periodicity=Copy_periodicity;
	SysTask[periority].TaskFunction=ptr;
	SysTask[periority].state=TASK_RESUMED;
	SysTask[periority].first_delay=task_del;


}
void RTOS_vidSuspendTask(u8 periority){
	SysTask[periority].state=TASK_SUSPENDED;
}
void RTOS_vidResumedTask(u8 periority){
	SysTask[periority].state=TASK_RESUMED;
}
void RTOS_vidKillTask(u8 periority){

	SysTask[periority].TaskFunction=Null;

}
void RTOS_vidSchadular(void){
	static u8 TICK_counter=0;
	TICK_counter++;
	for (u8 i=0;i<Task_Number;i++)
	{
		if (SysTask[i].first_delay==0)
		{
			if (SysTask[i].TaskFunction != Null)
			{
				if (/*(TICK_counter % SysTask[i].periodicity==0 ) &&*/ ( SysTask[i].state== TASK_RESUMED)){
					SysTask[i].TaskFunction();
					SysTask[i].first_delay=SysTask[i].periodicity -1;
				}
				else{
				}
			}

		}
		else{
			SysTask[i].first_delay=SysTask[i].first_delay-1;
		}
	}
}


void RTOS_vidStart(void){
	ISR_FUN(&RTOS_vidSchadular);
	Timer0_voidInit();

}
