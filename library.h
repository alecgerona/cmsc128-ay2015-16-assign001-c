void numToWords(char *num){
	int i, size=0, copy=0;
	for (i=0; i<8; i++){ //Get length of number
		if(num[i]==NULL){
			size = i;
			copy = size;
			break;
		}
	}
	for (i=0; i<size; i++){ //Print words
		if(num[i-1]=='1' && copy==4){
			num[i]='0';
		}
		if(num[i-1]=='1' && copy==1){
			num[i]='0';
		}

		printNum(num[i], num[i+1], copy);
		if (num[i]=='0' && copy != 4){
			copy--;
			continue;
		}
		if (num[i]=='0' && copy==4 && num[i-1]!='0'){
			printWord(copy);
			copy--;
			continue;
		}
		if (num[i]=='0' && copy==4 && num[i-2]==NULL){
			copy--;
			continue;
		}
		printWord(copy);
		copy--;
	}
}
void printWord(int place){
	switch (place){
		case 7 :
			printf("million ");
		break;
		case 6 :
			printf("hundred ");
		break;
		case 4 :
			printf("thousand ");
		break;
		case 3 :
			printf("hundred ");
		break;
	}
}

void printNum(char num, char num2, int place){
	if (num == '1' && place != 5 && place != 2){
		printf("one ");
	}
	else if (num == '2' && place != 5 && place != 2){
		printf("two ");
	}
	else if (num == '3' && place != 5 && place != 2){
		printf("three ");
	}
	else if (num == '4' && place != 5 && place != 2){
		printf("four ");
	}
	else if (num == '5' && place != 5 && place != 2){
		printf("five ");
	}
	else if (num == '6' && place != 5 && place != 2){
		printf("six ");
	}
	else if (num == '7' && place != 5 && place != 2){
		printf("seven ");
	}
	else if (num == '8' && place != 5 && place != 2){
		printf("eight ");
	}
	else if (num == '9' && place != 5 && place != 2){
		printf("nine ");
	}
	else if ((num == '1' && num2 == '0' && place == 5) || (num == '1' && num2 == '0' && place == 2)){
		printf("ten ");
	}
	else if ((num == '1' && num2 == '1' && place == 5) || (num == '1' && num2 == '1' && place == 2)){
		printf("eleven ");
	}
	else if ((num == '1' && num2 == '2' && place == 5) || (num == '1' && num2 == '2' && place == 2)){
		printf("twelve ");
	}
	else if ((num == '1' && num2 == '3' && place == 5) || (num == '1' && num2 == '3' && place == 2)){
		printf("thirteen ");
	}
	else if ((num == '1' && num2 == '4' && place == 5) || (num == '1' && num2 == '4' && place == 2)){
		printf("fourteen ");
	}
	else if ((num == '1' && num2 == '5' && place == 5) || (num == '1' && num2 == '5' && place == 2)){
		printf("fifteen ");
	}
	else if ((num == '1' && num2 == '6' && place == 5) || (num == '1' && num2 == '6' && place == 2)){
		printf("sixteen ");
	}
	else if ((num == '1' && num2 == '7' && place == 5) || (num == '1' && num2 == '7' && place == 2)){
		printf("seventeen ");
	}
	else if ((num == '1' && num2 == '8' && place == 5) || (num == '1' && num2 == '8' && place == 2)){
		printf("eighteen ");
	}
	else if ((num == '1' && num2 == '9' && place == 5) || (num == '1' && num2 == '9' && place == 2)){
		printf("nineteen ");
	}
	else if ((num == '2' && place == 5) || (num == '2' && place == 2)){
		printf("twenty ");
	}
	else if ((num == '3' && place == 5) || (num == '3' && place == 2)){
		printf("thirty ");
	}
	else if ((num == '4' && place == 5) || (num == '4' && place == 2)){
		printf("forty ");
	}
	else if ((num == '5' && place == 5) || (num == '5' && place == 2)){
		printf("fifty ");
	}
	else if ((num == '6' && place == 5) || (num == '6' && place == 2)){
		printf("sixty ");
	}
	else if ((num == '7' && place == 5) || (num == '7' && place == 2)){
		printf("seventy ");
	}
	else if ((num == '8' && place == 5) || (num == '8' && place == 2)){
		printf("eighty ");
	}
	else if ((num == '9' && place == 5) || (num == '9' && place == 2)){
		printf("ninety ");
	}
}

int wordstonum(char *word){
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

		} else if (strcmp(args[count], "million") == 0){
			num += 1000000 * wordNumLite(args[count-1]);
			if (strcmp(args[count-1], "hundred") != 0 || strcmp(args[count-1], "thousand") != 0) count--;
		} else {
			num += wordNumLite(args[count]);
		}
		count--;
	}
	return num;
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
