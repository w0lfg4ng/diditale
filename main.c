 /*DIDITALE XD*/
 /*TURMINHA DO DIDI XD*/
 
#include <reg52.h>
#include "diditale_bmp.c"
#include "..\lib\sll.h"

 void main(void){
   BYTE x = 100;
   BYTE y = 45;

   paintscr(0, 0, 0);
   while(1){
	 
     
     printbmp(x,y,diditale);
	 if(vkeydown(VK_RIGHT)){
	     x++;
		 if (x >= 240-21){
		   x = 240-21;
		 }
	 }
	 if(vkeydown(VK_LEFT)){
	     x--;
		 if(x <= 1){
		   x = 1;
	   }
	 }
	 if(vkeydown(VK_UP)){
	     y--;
		 if(y <= 1){
		   y = 1;
	   }

	   
	 }
	 if(vkeydown(VK_DOWN)){
	   y++;
	   
	   if(y >=128-21){
	     y = 128-21;
	   }	
	 }
	 delay(1);
   }
 }