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