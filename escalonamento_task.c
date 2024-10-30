/*SOLOPLAY */
#include <reg52.h>
#include "diditale_bmp.c"
#include "..\lib\sll.h"

int x1,x2,x3,y1,y2,y3;
char estado1,estado2,estado3;

void task1(void){
	
    printbmp(x1,y1, rostobom);
    switch(estado1){
			
	  case 3:
	    x1--;
	    y1--;
	    if(x1<=0){
	      estado1 = 2;
	    }
	    if(y1 <=0){
	      if(estado1 == 2){
		      estado1 = 0;
		  } 
		    else{
		      estado1 = 1;
		    }
	    }
	    break;
			
	    case 2:
	      x1++;
	      y1--;
		  if(x1>=(240-21)){
		    estado1 = 3;
		  }
			if(y1 <=0){
			  if(estado1 ==3){
				  estado1 = 1;
				}
			  else{
			    estado1 = 0;
			  }
	    }
	    break;
					
	    case 0:
		    x1++;
		    y1++;
			if(x1>=(240-21)){
			  estado1 = 1;
			}
			if(y1 > (128-21)){
			  if(estado1 == 1){
				  estado1 = 3;
				}
			
			  else{
			    estado1 = 2;
			  }
			}
			break;
			
		  case 1:
		    x1--;
		    y1++;
			if(x1 <= 0){
			  estado1 = 0;
			}
			if(y1 >= 128-21){
			  if(estado1 == 0){
				  estado1 = 2;
				}
			  else{
			    estado1 = 3;
			  }
			}
			
    }
}

void task2 (void){
	
	printbmp(x2,y2, rostomau);
    switch(estado2){
			
	  case 3:
	    x2--;
	    y2--;
	    if(x2<=0){
	      estado2 = 2;
	    }
	    if(y2 <=0){
	      if(estado2 == 2){
		      estado2 = 0;
		  } 
		    else{
		      estado2 = 1;
		    }
	    }
	    break;
			
	    case 2:
	      x2++;
	      y2--;
		  if(x2>=(240-21)){
		    estado2 = 3;
		  }
			if(y2 <=0){
			  if(estado2 ==3){
				  estado2 = 1;
				}
			  else{
			    estado2 = 0;
			  }
	    }
	    break;
					
	    case 0:
		    x2++;
		    y2++;
			if(x2>=(240-21)){
			  estado2 = 1;
			}
			if(y2 > (128-21)){
			  if(estado2 == 1){
				  estado2 = 3;
				}
			
			  else{
			    estado2 = 2;
			  }
			}
			break;
			
		  case 1:
		    x2--;
		    y2++;
			if(x2 <= 0){
			  estado2 = 0;
			}
			if(y2 >= 128-21){
			  if(estado2 == 0){
				  estado2 = 2;
				}
			  else{
			    estado2 = 3;
			  }
			}
			
    }
}

void task3(void){ 
	
	printbmp(x3,y3, rostoneutro);
    switch(estado3){
			
	  case 3:
	    x3--;
	    y3--;
	    if(x3<=0){
	      estado3 = 2;
	    }
	    if(y3 <=0){
	      if(estado3 == 2){
		      estado3 = 0;
		  } 
		    else{
		      estado3 = 1;
		    }
	    }
	    break;
			
	    case 2:
	      x3++;
	      y3--;
		  if(x3>=(240-21)){
		    estado3 = 3;
		  }
			if(y3 <=0){
			  if(estado3 ==3){
				  estado3 = 1;
				}
			  else{
			    estado3 = 0;
			  }
	    }
	    break;
					
	    case 0:
		    x3++;
		    y3++;
			if(x3>=(240-21)){
			  estado3 = 1;
			}
			if(y3 > (128-21)){
			  if(estado3 == 1){
				  estado3 = 3;
				}
			
			  else{
			    estado3 = 2;
			  }
			}
			break;
			
		  case 1:
		    x3--;
		    y3++;
			if(x3 <= 0){
			  estado3 = 0;
			}
			if(y3 >= 128-21){
			  if(estado3 == 0){
				  estado3 = 2;
				}
			  else{
			    estado3 = 3;
			  }
			}
			
    }
}