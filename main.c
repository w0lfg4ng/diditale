 /*DIDITALE XD*/
 /*TURMINHA DO DIDI XD*/
 
#include <reg52.h>
#include "diditale_bmp.c"
#include "..\lib\sll.h"

COLOR corShield = {0, 0, 255};
 void main(void){
   unsigned char shieldx,shieldy;
   BYTE x = 100;
   BYTE y = 45;

   paintscr(0, 0, 0);
   while(1){
	 
    for (shieldx = 90; shieldx <=131; shieldx++){
      plotxy(shieldx,30,&corShield);
    }
     printbmp(120,64,diditale);
     if(vkeydown(VK_RIGHT)){

     }
     if(vkeydown(VK_LEFT)){

     }
     if(vkeydown(VK_UP)){

     }
     if(vkeydown(VK_DOWN)){

     }
     delay(1);
   }
 }
