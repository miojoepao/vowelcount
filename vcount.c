#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){
    char vowels[][5] = {"a","e","i","o","u"};
/*             ^  ^
              || ||
used for specification of number of rows
                ||
                ||
used for specification of number of columns
2 dimensional array
*/
    char *input; //pointer variable
    input = (char *)malloc(sizeof(char)* + 1);
/*   ^      ^       ^          ^      |__________|
name_|       |       |          |       |
typecast_____|       |          |       |
allocating function__|          |       |
character size fetcher___________       |
mathematic function_____________________
|_________________|
        |
 ______________________
|                     |
 Char size always ==1
    1 (char size)
  x 1 (implicit multiplier since there is no explicit multiplier operand)
  ----
    1 (result of char_size * implicit_multiplier)
  + 1 (increasing factor)
  ----
    2 (result of: char_size * implicit_multiplier + 1)
    malloc would look like: malloc(2);*/
    printf(">>> ");
    scanf("%99[^\n]s", input);
    int vcount = 0;
    for(int i=0; i != (int)strlen(input) ;i++){
        for(int i2=0; i2 < 5; i2++){
            if(*vowels[i2] == input[i]){ //without `*` before 'vowels', the code will try to compare
                                         //pointer (vowels) with char variable (input)
                                         //by using '*', vowels pointer is dereferenced and can be used
                                         //as char variable
                vcount++;
                printf("[Num.%i]\nFound: %c\nText pos: %d\nArray pos: %d\n-------------------\n",vcount,input[i],i+1,i);   
            }   
        }
    }   
    printf("Total number of vowels: %i\n", vcount);
    free(input);
    return 0;
}
