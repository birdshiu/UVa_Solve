#include <iostream>
#include <string.h>
char code[8][1<<8];

int read_char(){
	while(1){
		int ch=getchar();
		if(ch != '\n' && ch!='\r') return ch;
	}
}

int read_code(){
	memset(code, 0, sizeof(code));
	code[1][0]=read_char();
	for(int i=2;i<8;i++){
		for(int j=0;j<(1<<i)-1;j++){
			char c=getchar();
			if(c=='\r' || c=='\n') return 1;
			if(c==EOF) return 0;
			code[i][j]=c;
		}
	}
	return 1;
}

int read_int(int n){
	int sum=0;
	while(n--){
		int c=read_char();
		sum+=(1<<n)*(c-'0');
	}
	return sum;
}

void get_code(){
	printf("%d %d %c\n", 1, 0, code[1][0]);
	for(int i=2;i<8;i++){
		for(int j=0;j<(1<<i);j++){
			printf("%d %d %c\n", i, j, code[i][j]);
		}
	}
}


int main(int argc, char** argv) {
		while(read_code()){
			while(1){
				int len=read_int(3);
				if(len==0) break;
				while(1){
					int v=read_int(len);
					if(v==(1<<len)-1) break;
					printf("%c", code[len][v]);
				}
			}
			printf("\n");
		}
	return 0;
}
