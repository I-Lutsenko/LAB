#include "config.h"
#include <stdint.h>

void softdelay(int N){
  volatile inner;
    for (inner = 0; inner < N; inner++);
}

int main()
{
  // LED output
  TRISGbits.TRISG6 = 0;

  // LED off 
  LATGbits.LATG6 = 0;

  int k = 5000;
  int x = 0;
  
  int j6 = 5000;
  int i6 = 0;

  while (1) {
      for (x = 0; x < k; x++){          
          LATGbits.LATG6 = 0;    
          softdelay(j6);
          LATGbits.LATG6 = 1;
          softdelay(i6);
          i6++;
          j6--;
      }

         LATGbits.LATG6 = 1;

     for (x = 0; x < k; x++){          
          LATGbits.LATG6 = 0;    
          softdelay(j6);
          LATGbits.LATG6 = 1;
          softdelay(i6);
          i6--;
          j6++;
          
      }
          LATGbits.LATG6 = 0;   
  }    
   return 0;
}
