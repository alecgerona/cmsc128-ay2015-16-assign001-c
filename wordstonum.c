#include <stdio.h>
#include <string.h>
#include "numtowords.h"

void main(){
	char word[100];
	printf("Enter the number in words: ");
	gets(word);
	//printf(word);
	printf("%d\n",wordstonum(word));
}