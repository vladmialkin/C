#include <stdio.h>

int main(){
    int c, all_numb = 0;
    int nchars[26];

    for (int i = 0; i < 26; i++)
        nchars[i] = 0;

    while((c = getchar()) != EOF){
        if (c >= 'a' && c <= 'z'){
            ++all_numb;
            ++nchars[c - 'a'];
        }
        else if(c >= 'A' && c <= 'Z'){
            ++all_numb;
            ++nchars[c - 'A'];
        }
    }
    printf("all numbers - %d\n", all_numb);
    printf("chars - numb, %\n");
    for(int i = 0; i < 26; i++){
        float frequency;
        if (nchars[i] == 0)
            frequency = 0.0;
        else 
            frequency = (float)nchars[i] * (float)all_numb;
        
        printf("%c - %d, %f\n",'a' + i,  nchars[i], frequency);
    }
    return 0;
}
