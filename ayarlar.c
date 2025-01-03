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
#include "kesmeler.h"
#include "ayarlar.h"


void ayar() {

    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);

    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 4);
    GPIOPinWrite(GPIO_PORTB_BASE,4,0);

    TimerConfigure(TIMER0_BASE, TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PERIODIC | TIMER_CFG_B_PERIODIC);

    TimerLoadSet(TIMER0_BASE, TIMER_A, 50000);

    TimerLoadSet(TIMER0_BASE, TIMER_B, 50000);

    IntMasterEnable();
    IntEnable(INT_TIMER0A);
    IntEnable(INT_TIMER0B);

    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMB_TIMEOUT);

    TimerIntRegister(TIMER0_BASE, TIMER_A, timerAkesmedakika);
    TimerIntRegister(TIMER0_BASE, TIMER_B, timerBkesmesaat);

    TimerEnable(TIMER0_BASE, TIMER_A);
    TimerEnable(TIMER0_BASE, TIMER_B);


}

