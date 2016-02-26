#include <stdio.h>
#include <string.h>

void main(){
	char word[100];
	printf("Enter the number in words: ");
	gets(word);
	//printf(word);
	wordstonum(word);
}

void wordstonum(char *word){
	char *token;
	char *args[40];
	int i=0;
	int num=0;
	int count=0;
	int temp=0;
	int total=0;
	int flag = 0;

	token = strtok(word, " ");
	for (i=0; token!=NULL; i++){
		args[i]=token;
		token = strtok(NULL, " ");
		args[i+1]=NULL;
		count++;
	}
	count--;
	total = count;
	while (count>=0){
		
		if (strcmp(args[count], "hundred") == 0){
			flag=0;
			for (temp=count; temp<= total; temp++){
				if (strcmp(args[temp], "thousand") == 0){
					num += 100000 * wordNumLite(args[count-1]);
					count--;
					flag=1;
					break;
				}
			}
			if (flag==0){
				num += 100 * wordNumLite(args[count-1]);
				count--;
			}

		} else if (strcmp(args[count], "thousand") == 0){


			if(count-2 >= 0 && strcmp(args[count-1], "hundred") != 0 && strcmp(args[count-2], "hundred") != 0){ //If there are words before thousand that isn't "hundred"
				temp = wordNumLite(args[count-1]) + wordNumLite(args[count-2]);
				num += 1000 * temp;
				count-=2;

			} else if (count-1 >= 0 && strcmp(args[count-1], "hundred") != 0) { //If there is only one word before thousand that isn't hundred
				num += 1000 * wordNumLite(args[count-1]);
				count--;
			}


			// if (strcmp(args[count-1], "hundred") == 0){
			// 	num += 1000 * 100 * wordNumLite(args[count-2]);
			// 	count-=2;

			// } else {
				
			// 	if (strcmp(args[count-1], "hundred") != 0 && strcmp(args[count-2], "million") != 0){
			// 		temp = wordNumLite(args[count-1]) + wordNumLite(args[count-2]);
			// 		num += 1000 * temp;
			// 		count-=2;
			// 		printf("fuck");

			// 	} else {
			// 		printf("shit");

			// 		num += 1000 * wordNumLite(args[count-1]);
			// 		count--;
			// 	}
				
			// }
		} else if (strcmp(args[count], "million") == 0){
			num += 1000000 * wordNumLite(args[count-1]);
			if (strcmp(args[count-1], "hundred") != 0 || strcmp(args[count-1], "thousand") != 0) count--;
		} else {
			num += wordNumLite(args[count]);
		}
		count--;
	}
	printf("%d\n", num);
}

int wordNumLite(char *conv){
	int num=0;
	if (strcmp(conv, "one") == 0){
		return 1;
	} else if (strcmp(conv, "two") == 0){
		return 2;
	} else if (strcmp(conv, "three") == 0){
		return 3;
	} else if (strcmp(conv, "four") == 0){
		return 4;
	} else if (strcmp(conv, "five") == 0){
		return 5;
	} else if (strcmp(conv, "six") == 0){
		return 6;
	} else if (strcmp(conv, "seven") == 0){
		return 7;
	} else if (strcmp(conv, "eight") == 0){
		return 8;
	} else if (strcmp(conv, "nine") == 0){
		return 9;
	} else if (strcmp(conv, "ten") == 0){
		return 10;
	} else if (strcmp(conv, "eleven") == 0){
		return 11;
	} else if (strcmp(conv, "twelve") == 0){
		return 12;
	} else if (strcmp(conv, "thirteen") == 0){
		return 13;
	} else if (strcmp(conv, "fourteen") == 0){
		return 14;
	} else if (strcmp(conv, "fifteen") == 0){
		return 15;
	} else if (strcmp(conv, "sixteen") == 0){
		return 16;
	} else if (strcmp(conv, "seventeen") == 0){
		return 17;
	} else if (strcmp(conv, "eighteen") == 0){
		return 18;
	} else if (strcmp(conv, "nineteen") == 0){
		return 19;
	} else if (strcmp(conv, "twenty") == 0){
		return 20;
	} else if (strcmp(conv, "thirty") == 0){
		return 30;
	} else if (strcmp(conv, "forty") == 0){
		return 40;
	} else if (strcmp(conv, "fifty") == 0){
		return 50;
	} else if (strcmp(conv, "sixty") == 0){
		return 60;
	} else if (strcmp(conv, "seventy") == 0){
		return 70;
	} else if (strcmp(conv, "eighty") == 0){
		return 80;
	} else if (strcmp(conv, "ninety") == 0){
		return 90;
	} else {
		return 1;
	}
}