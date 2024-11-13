 /*DIDITALE XD*/
 /*TURMINHA DO DIDI XD*/

#include <reg52.h>
#include "diditale_bmp.c"
#include "..\lib\sll.h"

COLOR corShield = {0, 0, 255};
COLOR eraseShield = {0,0,0};
 void task0(void){
   unsigned char shieldx,shieldy,erasex,erasey;
   BYTE x = 100;
   BYTE y = 45;

   paintscr(0, 0, 0);
   for (shieldx = 100; shieldx <=140; shieldx++){
      plotxy(shieldx,44,&corShield);
    }
     printbmp(110,54,diditale);

   while(1){
	
     if(vkeydown(VK_RIGHT)){
       for (shieldy = 44; shieldy <=84; shieldy++){
         plotxy(141,shieldy,&corShield); //direita	
       }
       for (erasex = 100; erasex <=140; erasex++){
      plotxy(erasex,44,&eraseShield);          //apaga cima
       }
      for (erasex = 100; erasex <=140; erasex++){
         plotxy(erasex,84,&eraseShield);  //apaga baixo
       }
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(100,erasey,&eraseShield);  //apaga esquerda
       }
       delay(30);
     }

     if(vkeydown(VK_LEFT)){
       for (shieldy = 44; shieldy <=84; shieldy++){
         plotxy(100,shieldy,&corShield);  //esquerda
       }
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(141,erasey,&eraseShield);  //apaga direita
       }
       for (erasex = 100; erasex <=140; erasex++){
      plotxy(erasex,44,&eraseShield);    // apaga cima     
       }
       for (erasex = 100; erasex <=140; erasex++){
         plotxy(erasex,84,&eraseShield);  //apaga baixo
       } 
       delay(30);
     }
     if(vkeydown(VK_UP)){
       for (shieldx = 100; shieldx <=140; shieldx++){
         plotxy(shieldx,44,&corShield);  //cima
       }
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(141,erasey,&eraseShield);     //apaga direita
       }
       for (erasex = 100; erasex <=140; erasex++){
         plotxy(erasex,84,&eraseShield);  //apaga baixo
       }   
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(100,erasey,&eraseShield);  //apaga esquerda
       }
       delay(30);    
       }
     if(vkeydown(VK_DOWN)){
       for (shieldx = 100; shieldx <=140; shieldx++){
         plotxy(shieldx,84,&corShield);  //baixo
         }
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(141,erasey,&eraseShield); // apaga direita
       }
       for (erasex = 100; erasex <=140; erasex++){
         plotxy(erasex,44,&eraseShield);    // apaga cima     
       }
       for (erasey = 44; erasey <=84; erasey++){
         plotxy(100,erasey,&eraseShield);  //apaga esquerda
       }
       delay(30); 
   }
   delay(1);
     }

 }