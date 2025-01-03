#include "stdint.h"
#include "stdbool.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "inc/hw_gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "saat.h"
#include "kesmeler.h"



int timerAsayaci = 0;
int timerBsayaci = 0;


int timerAasim = 800*60;
int timerBasim = 800*3600;

void timerAkesmedakika()
{

    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    timerAsayaci++;

    if (timerAsayaci==timerAasim){
     GPIOPinWrite(GPIO_PORTB_BASE,4,4);
     SysCtlDelay(10000000/4);
     GPIOPinWrite(GPIO_PORTB_BASE,4,0);

     dakika();
     timerAsayaci=0;
    }


}


void timerBkesmesaat()
{

    TimerIntClear(TIMER0_BASE, TIMER_TIMB_TIMEOUT);
    timerBsayaci++;

    if (timerBsayaci==timerBasim){
      saat();
      timerBsayaci=0;
    }


}
