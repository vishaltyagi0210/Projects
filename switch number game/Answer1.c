#include<stdio.h>
#include<string.h>
int main(){
    char string[5][30];
    printf("Enter your strings: ");
    for(int i = 0; i<5; i++){
        gets(string[i]);
    }
    int vowel = 0;
    for(int i = 0; i<5; i++){
        for(int j = 0; string[i][j] ; j++){
            if(string[i][j] == 'a'|| string[i][j] == 'e'|| string[i][j] == 'i' || string[i][j] == 'o' || string[i][j] == 'u'){
                vowel++;
            }
        }
        printf("%s string contain %d vowels\n",string[i],vowel);
        vowel = 0;
    }
}