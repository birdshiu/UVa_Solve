#include <iostream>
#include <string.h>
char input[100000];
int main(int argc, char** argv) {
	int t;
	char atom[4]={'C','H','O','N'};
	float molar[4]={12.01, 1.008, 16.00, 14.01};
	
	scanf("%d", &t);
	while(t--){
		float temp, sum=0;
		int number=0, index=0, isalpha=1;
		scanf("%s", input);
		while(index<strlen(input)){
			if(isalpha){
				for(int i=0;i<4;i++) if(input[index]==atom[i]) temp=molar[i];
				if(!(strlen(input)-1-index)){
					sum+=temp;
					index++;
				}
				else if('9'>=input[index+1] && '0'<=input[index+1]){
					index++;
					isalpha=0;	
					number=0;
				}
				else{
					sum+=temp;
					index++;
					number=0;
				}
			}
			else{
				if(number) number=number*10+input[index]-'0';
				else number+=input[index]-'0';
				if(!(strlen(input)-1-index)){
					sum+=temp*number;
					index++;
				}
				else if('9'>=input[index+1] && '0'<=input[index+1]) index++;
				else{
					isalpha=1;
					sum+=temp*number;
					index++;
				}
			}
		}
		printf("%.3f\n", sum);
	}
	return 0;
}
