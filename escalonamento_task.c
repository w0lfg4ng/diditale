 /*DIDITALE XD*/
 /*TURMINHA DO DIDI XD*/
#include <reg52.h>
#include "DEAD_bmp.c"
#include "SHURIKEN_bmp.c"
#include "ESCUDOHORIZONTAL_bmp.c"
#include "ESCUDOVERTICAL_bmp.c"
#include "apagaHorizontal_bmp.c"
#include "apagaVertical_bmp.c"
#include "CENARIO_bmp.c"
#include "DIDI_bmp.c"
#include "C:\Users\IFMaker\Downloads\diditale-main\sll.h"

extern int shieldUp, shieldDown, shieldLeft, shieldRight;
bit rodando = 1;
int x2 = 0;
int y2 = 0;
int x1 = 0;
int y1 = 0;
char estado1,estado2,estado3;
int stop = 0;
PLAN p0,p1,p2,p3,p4;

int shieldUp, shieldDown, shieldLeft, shieldRight;
extern char estado;
extern int stop;
 

void main(void){
   p0.backgroudplan = BACKPLN1;
    
   p0.shapeplan = BACKPLN2;
   p0.tcolor = RGB(0, 0, 0);
   p0.ptr = &p1;
 
   p1.shapeplan = BACKPLN3;
   p1.tcolor = RGB(0, 0, 0);
   p1.ptr = &p2;

   p2.shapeplan = BACKPLN4;
   p2.tcolor = RGB(0, 0, 0);
   p2.ptr = &p3;

   p3.shapeplan = BACKPLN5;
   p3.tcolor = RGB(0, 0, 0);
   p3.ptr = &p4;

   p4.shapeplan = BACKPLN6;
   p4.tcolor = RGB(0, 0, 0);
   p4.ptr = null;

   GRPLNSEL = BACKPLN1;
   printbmp(0,0,CENARIO);

   TMOD = 0x01;
   TH0=(256-78);
   IE = 0x82;
   TR0 = 1;
   estado = 0;
   shieldUp = 1;
   shieldDown = 0;
   shieldLeft = 0;
   shieldRight = 0;
   while(1);
}

int finish(){
	stop = 1;
	return stop;
}



void task0(void){
  
  GRPLNSEL = BACKPLN2;
  //PaintPlan(RGB(0,0,0));
     if(stop == 0){
	 printbmp(110,54,DIDI);
       if(vkeydown(VK_RIGHT)){
	     printbmp(110,54,DIDI);
         printbmp(140,44,ESCUDOVERTICAL); //direita
         printbmp(100,44,apagaHorizontal); //apaga cima
         printbmp(100,84,apagaHorizontal); //apaga baixo
         printbmp(100,44,apagaVertical); //apaga esquerda

		 shieldRight = 1;
	     shieldUp = 0;
	     shieldDown = 0;
	     shieldLeft = 0;
         delay(10);
       }

       if(vkeydown(VK_LEFT)){
	     printbmp(110,54,DIDI);
         printbmp(100,44,ESCUDOVERTICAL);
         printbmp(140,44,apagaVertical); 
         printbmp(100,44,apagaHorizontal);
         printbmp(100,84,apagaHorizontal);

	     shieldUp = 0;
	     shieldDown = 0;
	     shieldLeft = 1;
	     shieldRight = 0; 
         delay(10);
        }

       if(vkeydown(VK_UP)){
	     printbmp(110,54,DIDI);
         printbmp(100,44,ESCUDOHORIZONTAL);
         printbmp(140,44,apagaVertical);
         printbmp(100,84,apagaHorizontal);   
         printbmp(100,44,apagaVertical);

	     shieldUp = 1;
	     shieldDown = 0;
	     shieldLeft = 0;
	     shieldRight = 0;
         delay(10);    
        }

       if(vkeydown(VK_DOWN)){
	     printbmp(110,54,DIDI);
         printbmp(100,84,ESCUDOHORIZONTAL);
         printbmp(140,44,apagaVertical);
         printbmp(100,44,apagaVertical);
         printbmp(100,44,apagaHorizontal);

	     shieldUp = 0;
	     shieldDown = 1;
	     shieldLeft = 0;
	     shieldRight = 0;
         delay(10); 
        }	 
       }
     }

 void task1(void){
 GRPLNSEL = BACKPLN3;
 PaintPlan(RGB(0,0,0));

 if(stop == 0){
    printbmp(x1,y1, SHURIKEN);

    switch(estado1){
			
	  case 3:
	    x1--;
	    y1--;
	    if(x1<=0 || shieldRight == 1 && x1 == 146 && 44-31 <= y1 && y1 <= 84){
	      estado1 = 2;
	    }

		else if (shieldRight == 0 && x1 == 132 && 44-31 <= y1 && y1 <= 84){
		  finish();
		}  // direita OK
		
	    if(y1 <=0 || shieldDown == 1 && y1 == 90 && x1 >= 90-31 && x1 <= 150){
	      if(estado1 == 2){
		      estado1 = 0;
		  }
		    else{
		      estado1 = 1;
		    }
	    }
         if(shieldDown == 0 && y1 == 90 && x1 >= 100-31 && x1 <= 140){
	       finish();
		 } // baixo OK
	    break;
			
	    case 2:
	      x1++;
	      y1--;
		  if(x1>=(240-21) || shieldLeft == 1 && x1 == 100-31 && 44-31 <= y1 && y1 <= 84){
		    estado1 = 3;
		  }
		  else if (shieldLeft == 0 && x1 == 100-21 && 44-21 <= y1 && y1 <= 84){
		    finish();
		  }
		  if(y1 <=0 || shieldDown == 1 && y1 == 88 && x1 >= 100-31 && x1 <= 140){
		    if(estado1 ==3){
			  estado1 = 1;
		    }  
		    else{
		      estado1 = 0;
		     }
		  }
		  else if(shieldDown == 0 && y1 == 82 && x1 >= 100-21 && x1 <= 140){
	        finish();
	    }  //baixo OK
	    break;
					
	    case 0:
		    x1++;
		    y1++;
			if(x1>=(240-21) || shieldLeft == 1 && x1 == 100-31 && 44-31 <= y1 && y1 <= 84){
			  estado1 = 1;
			}
		  else if (shieldLeft == 0 && x1 == 100-21 && 44-31 <= y1 && y1 <= 84){
		    finish();
		  }
			if(y1 > (128-21)|| shieldUp == 1 && y1 == 44-32 && 100-31 <= x1 && x1 <= 140){
			  if(estado1 == 1){
				  estado1 = 3;
			  }
			  else{
			    estado1 = 2;
			  }
			}
             else if (shieldUp == 0 && y1 == 50-22 && 100-31 <= x1 && x1 <= 140){
		      finish();
		    } //cima OK
			break;
			
		  case 1:
		    x1--;
		    y1++;
			if(x1 <= 0 || shieldRight == 1 && x1 <= 140 && 44-31 <= y1 && y1 <= 84){
			  estado1 = 0;
			}
		    else if (shieldRight == 0 && x1 == 130 && 54 <= y1 && y1 <= 74){
		      finish();
		    } 	// direita OK

			if(y1 >= 128-21 ||shieldUp == 1 && y1 == 44-32 && 100-31 <= x1 && x1 <= 140){
			  if(estado1 == 0){
				  estado1 = 2;
				}
			  else{
			    estado1 = 3;
			  }
			}
			else if (shieldUp == 0 && y1 == 50 && 110-31 <= x1 && x1 <= 125){
		      finish();
		    }  //Cima OK
			
    }
  }
  JoinPlans(&p0);
}

void task2(void){

  GRPLNSEL = BACKPLN4;
  PaintPlan(RGB(0,0,0));

   if(stop == 0){
    printbmp(x2,y2, SHURIKEN);
    switch(estado2){
			
	  case 3:
	    x2--;
	    y2--;
	    if(x2<=0 || shieldRight == 1 && x2 == 142 && 44-31 <= y2 && y2 <= 84){
	      estado2 = 2;
	    }

		else if (shieldRight == 0 && x2 == 132 && 44-31 <= y2 && y2 <= 84){
		  finish();
		}  // direita OK
		
	    if(y2 <=0 || shieldDown == 1 && y2 == 85 && x2 >= 90-31 && x2 <= 150){
	      if(estado2 == 2){
		      estado2 = 0;
		  }
		    else{
		      estado2 = 1;
		    }
	    }
         if(shieldDown == 0 && y2 == 82 && x2 >= 100-31 && x2 <= 140){
	       finish();
		 } // baixo OK
	    break;
			
	    case 2:
	      x2++;
	      y2--;
		  if(x2>=(240-21) || shieldLeft == 1 && x2 == 100-31 && 44-31 <= y2 && y2 <= 84){
		    estado2 = 3;
		  }
		  else if (shieldLeft == 0 && x2 == 100-21 && 44-21 <= y2 && y2 <= 84){
		    finish();
		  }
		  if(y2 <=0 || shieldDown == 1 && y2 == 85 && x2 >= 100-31 && x2 <= 140){
		    if(estado2 ==3){
			  estado2 = 1;
		    }  
		    else{
		      estado2 = 0;
		     }
		  }
		  else if(shieldDown == 0 && y2 == 82 && x2 >= 100-21 && x2 <= 140){
	        finish();
	    }  //baixo OK
	    break;
					
	    case 0:
		    x2++;
		    y2++;
			if(x2>=(240-21) || shieldLeft == 1 && x2 == 100-31 && 44-31 <= y2 && y2 <= 84){
			  estado2 = 1;
			}
		  else if (shieldLeft == 0 && x2 == 100-21 && 44-31 <= y2 && y2 <= 84){
		    finish();
		  }
			if(y2 > (128-21)|| shieldUp == 1 && y2 == 44-32 && 100-31 <= x2 && x2 <= 140){
			  if(estado2 == 1){
				  estado2 = 3;
			  }
			  else{
			    estado2 = 2;
			  }
			}
             else if (shieldUp == 0 && y2 == 50-22 && 100-31 <= x2 && x2 <= 140){
		      finish();
		    } //cima OK
			break;
			
		  case 1:
		    x2--;
		    y2++;
			if(x2 <= 0 || shieldRight == 1 && x1 <= 140 && 44-31 <= y1 && y1 <= 84){
			  estado2 = 0;
			}
		    else if (shieldRight == 0 && x2 == 130 && 44-31 <= y2 && y2 <= 84){
		      finish();
		    } 	// direita OK

			if(y2 >= 128-21 || shieldUp == 1 && y2 == 44-32 && 100-31 <= x2 && x2 <= 140){
			  if(estado2 == 0){
				  estado2 = 2;
				}
			  else{
			    estado2 = 3;
			  }
			}
			else if (shieldUp == 0 && y2 == 50-22 && 100-31 <= x2 && x2 <= 140){
		      finish();
		    }  //Cima OK
			
    }
  }
}

void gameover(void){
  if(stop == 1){
    GRPLNSEL = BACKPLN2;
	PaintPlan(RGB(0,0,0));
	printbmp(0,0,DEAD);
  }
}
