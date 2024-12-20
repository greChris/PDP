    /* USER: user5.37pdp 
    LANG: C 
    TASK: finding*/  
    #include "findinglib.h"  //xriazete findinglib.h arxio 
    #include <stdio.h>  
      
    int main() {  
      int N, D, x1, x2, q ,A,B;  
      int subtask_num = getSubtask();  
      
      while (true) {  
      
        D = getD();  
        q = query(1);  
        x1 = q;  
          
        if(D != -1)  
        {  
            A = (x1 - D) / 2 + 1;  
            B = A + D;  
            printf("%c %c",A,B);  
            if (!answer(A, B)) break;  
            else  
            {  
                continue;  
            }  
        }  
      
        q = query(x1 / 2 + 1);  
        x2 = q;  
          
        A = (x1 - x2) / 2 + 1;  
        B = A + x2;  
        printf("%c %c",A,B);  
        if (!answer(A, B)) break;  
      }  
      
      return 0;  
    }  