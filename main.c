#include <reg52.h>
#include "Z:\Rudah_Mariana\lib\sll.h"
#include "didi_bmp.c"
#include "didicolher_bmp.c"

COLOR corx = {255, 0, 0};
COLOR cory = {0,0,255};
COLOR corz = {0,255,0};

void main(void){
  unsigned char x;
  paintscr(255,255,255);
  gotoxy((30-29)/2,7);
  prints("HACKED BY TURMINHA DO DIDI XD");
  printbmp(0,0,didi);
  printbmp(240-70,128-80,didi);
  printbmp((240-80)/2,(128-80)/2,didicolher);
  plotxy(20,120,&corx);
  for (x = 50; x <=190; x++){
    plotxy(x,30,&corx);
  }
  for (x = 30; x <=120; x++){
    plotxy(50,x,&cory);
  }
  for (x = 0; x <=120; x++){
    plotxy(x,(0.85*x),&corz);
  }
  while(1);
}
