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
#include "lcd.h"
#include "saat.h"
#include "kesmeler.h"
#include "string.h"



int i;
char sure[];



void zamaninit(char x[]){
    for (i = 0; i < strlen(x); i++) {
            sure[i] = x[i];
        }

        sure[i] = '\0';

    LCD_yaz(&x[0], 1, 9);
    LCD_yaz(&x[1], 1, 10);
    LCD_yaz(":",1,11);
    LCD_yaz(&x[3], 1, 12);
    LCD_yaz(&x[4], 1, 13);
    LCD_yaz(":",1,14);
    LCD_yaz(&x[6], 1, 15);
    LCD_yaz(&x[7], 1, 16);
    SysCtlDelay(10000000/15);
    LCD_temizle();
}

void zaman(){

for (i=0;i<=9;i++){

        if (sure[7]>'9'){

            if (sure[6]>='5'){

               goto cik3;
            }

            sure[6]++;
            sure[7]='0';

cik3:

        }


 LCD_yaz(&sure[7], 1, 16);
 LCD_yaz(&sure[6], 1, 15);
 LCD_yaz(":", 1, 14);
 LCD_yaz(&sure[4], 1, 13);
 LCD_yaz(&sure[3], 1, 12);
 LCD_yaz(":", 1, 11);
 LCD_yaz(&sure[1], 1, 10);
 LCD_yaz(&sure[0], 1, 9);
 GPIOPinWrite(GPIO_PORTB_BASE,4,4);
 SysCtlDelay(1000000/2);
 GPIOPinWrite(GPIO_PORTB_BASE,4,0);
 sure[7]++;

 SysCtlDelay(10000000/64);
 LCD_temizle();

}
}





void dakika(){

    sure[6]='0';
    sure[7]='0';

    sure[4]++;

    if (sure[4]>'9'){

        if (sure[3]>='5'){

                sure[3]='0';
                sure[4]='0';

            goto cik2;
            }


        sure[3]++;
        sure[4]='0';


    }
cik2:
}



void saat(){

    sure[3]='0';
    sure[4]='0';
    sure[6]='0';
    sure[7]='0';

    sure[1]++;
      if (sure[1]>'9'){

          if (sure[0]>'2' && sure[1]>'3'){

                  sure[0]='0';
                  sure[1]='0';
                  goto cik1;

                      }


          sure[0]++;
          sure[1]='0';
      }
      cik1:
}



