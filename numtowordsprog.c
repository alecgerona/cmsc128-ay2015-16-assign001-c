#include<stdio.h>
#include "numtowords.h"
void main(){
	char num[8];
	printf("Enter number: ");
	scanf("%s", num);
	numToWords(num);
}
