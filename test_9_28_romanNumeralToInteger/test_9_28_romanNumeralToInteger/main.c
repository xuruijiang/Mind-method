//
//  main.c
//  test_9_28_romanNumeralToInteger
//
//  Created by 徐瑞江 on 2022/9/28.
//

#include <stdio.h>
#include <string.h>
/*I             1
V             5
X             10
L             50
C             100
D             500
M             1000*/
#define O 1
#define v 5
#define x 10
#define l 50
#define c 100
#define d 500
#define m 1000

int romanToInt(char * s){
    
    int lenth = (int)strlen(s);
    
    int sum = 0;
    for (int i = 0; i < lenth - 1; ++i) {
        if(*(s+i) == 'M'){
            sum += m;
        } else if(*(s + i) == 'D'){
            sum += d;
        } else if(*(s + i) == 'C'){
            if(*(s + i +1) == 'D' || *(s + i +1) == 'M'){
                
                sum -= c;
            } else{
                sum += c;
            }
            
        } else if(*(s + i) == 'L'){
            sum += l;
        }else if(*(s + i) == 'X'){
            if(*(s + i +1) == 'L' || *(s + i +1) == 'C'){
                
                sum -= x;
            }else{
                sum += x;
                
            }
            
            
            
        }else if(*(s + i) == 'V'){
            sum += v;
        }else if(*(s + i) == 'I'){
            if(*(s + i +1) == 'V' || *(s + i +1) == 'X'){
                
                sum -= O;
            }else{
                sum += O;
            }
            
            
        }
        
        
    
    }
    
    if(*(s + lenth -1) == 'M'){
        sum += m;
    }else if (*(s + lenth -1) == 'D'){
        sum += d;
    }else if (*(s + lenth -1) == 'C'){
        sum += c;
    }else if (*(s + lenth -1) == 'L'){
        sum += l;
    }else if (*(s + lenth -1) == 'X'){
        sum += x;
    }else if (*(s + lenth -1) == 'V'){
        sum += v;
    }else if (*(s    + lenth -1) == 'I'){
        sum += O;
    }
    
    
    
    
    return sum ;
}
int main(){

    char str[7] = "MCMXCIV";

    int a =  romanToInt(str);
    printf("%d\n",a);
    return 0;
}
