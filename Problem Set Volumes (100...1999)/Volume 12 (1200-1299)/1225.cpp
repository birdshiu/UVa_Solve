#include <iostream>
#include <string.h>

int main(int argc, char** argv) {
	int t;
	scanf("%d", &t);
	while(t--){
		int n,count[10]={0};
		scanf("%d", &n);
		for(int i=1;i<=n;i++){
			int tmp=i;
			while(tmp>0){
				count[tmp%10]++;
				tmp/=10;
			}
		}
		for(int i=0;i<9;i++) printf("%d ", count[i]);
		printf("%d", count[9]);
		printf("\n");
	}
	return 0;
}
