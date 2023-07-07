#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    if (n==0 || n==1)
        return 1;
    else
        return n*factorial(n-1);
}

int countanagrams(char *word) {
    int length=strlen(word);
    int count=factorial(length);

    int lettercount[26]={0};

    for (int i=0; i<length; i++) {
        int index=word[i] - 'A';
        lettercount[index]++;
    }

    for (int i=0; i<26; i++) {
        if (lettercount[i]>1)
            count/=factorial(lettercount[i]);
    }

    return count;
}

int main() {

    printf("Zaichenko Bohdan IPZ-22008b\n");

    char word[15];

    printf("\nEnter word: ");
    scanf("%s", word);

    int result=countanagrams(word);

    printf("\nNumber of anagrams: %d\n", result);

    return 0;
}
