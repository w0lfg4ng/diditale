 /*DIDITALE XD*/
 /*TURMINHA DO DIDI XD*/
#include "flecha_bmp.c"
#include <reg52.h>
#include "diditale_bmp.c"
#include "C:\Users\EduMaker\Downloads\diditale-main\diditale-main\sll.h"

COLOR corShield = {0, 0, 255};
COLOR eraseShield = {0,0,0};
 void main(void){
   unsigned char shieldx,shieldy;
   BYTE x = 100;
   BYTE y = 45;

   paintscr(0, 0, 0);
   while(1){
	 
    for (shieldx = 100; shieldx <=140; shieldx++){
      plotxy(shieldx,44,&corShield);
    }
     printbmp(110,54,diditale);
     if(vkeydown(VK_RIGHT)){
			 for (shieldy = 44; shieldy <=84; shieldy++){
				 plotxy(141,shieldy,&corShield);	
			}
			 plotxy(shieldx,44,&eraseShield);
     }
     if(vkeydown(VK_LEFT)){

     }
     if(vkeydown(VK_UP)){
       for (shieldx = 100; shieldx <=140; shieldx++){
         plotxy(shieldx,44,&corShield);
			 }
     }
     if(vkeydown(VK_DOWN)){

     }
     delay(1);
   }
 }
