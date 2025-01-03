#include "stdint.h"
#include "stdbool.h"
#include "ayarlar.h"
#include "kesmeler.h"
#include "lcd.h"
#include "saat.h"


char saatsuan[] = "20:39:00";     // start time

int main(void) {

  ayar();
  LCD_ayar();
  zamaninit(saatsuan);

     while (1) {

         zaman();

     }


}


