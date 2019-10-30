#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int count; //用來計算朋友群的 

struct mystr{ //記錄關係的串列 
	int n;
	struct mystr *next;
};

void relation(struct mystr ** pair, int A, char *check){
	struct mystr *tmp; //用來釋放記憶體的指標 
	
	while(pair[A]!=NULL){ //如果 A 還有關係的話 
		if(check[A]==0){ //如果數字 A 沒有重覆 那就可以算進群組人數裡 
			count++;
			check[A]=1;
		}
		tmp=pair[A];
		pair[A]=pair[A]->next; //每發現一個關聯，就把它去除，避免之後又算成另外一群 
		relation(pair, tmp->n, check); //每發現一個關聯，就再用同樣的方式，找出那個關聯的其他關聯 
		free(tmp);//譯放記憶體 
	}
}

void addData(struct mystr ** pair, int A, int B){ //以下是關聯串列的新增資料，資料在加入時會按造大小排序，還會去除重覆的資料 
	int i;
	struct mystr *trave, *tmp, *create;
	if(pair[A]==0){
		create=(struct mystr *)malloc(sizeof(struct mystr));
		pair[A]=create;
		pair[A]->n=B;
		pair[A]->next=NULL;
	}
	else{
		trave=pair[A];
		while(trave!=NULL){
			if(B < trave->n){
				if(trave==pair[A]){
					pair[A]=(struct mystr *)malloc(sizeof(struct mystr));
					pair[A]->n = B;
					pair[A]->next=trave;
					break;
				}
				else{
					create=(struct mystr *)malloc(sizeof(struct mystr));
					create->n = B;
					tmp->next = create;
					create->next = trave;
					break;
				}
			}
			if(B == trave->n){
				break;
			}
			tmp=trave;
			trave=trave->next;
		}
		if(trave==NULL){
			create=(struct mystr *)malloc(sizeof(struct mystr));
			create->n = B;
			tmp->next = create;
			create->next=trave;
		}	
	}
}

int main(){
	int d, i, j;
	int max;
	
	scanf("%d", &d); //幾筆資料 
		
	for(i=0;i<d;i++){
		int N, M; //人數//配對數 
		scanf("%d %d", &N, &M);
		char check[N+1]; //在找朋友關係時，避免遇到重覆的人，等於1表示有遇到過 
		struct mystr* pair[N+1]; //用來找 "關係" 的，如果我要找誰跟 B 有關係 我可以直接找 pair[B] 所連結的串列 
		memset(check, 0, sizeof(check)); //歸零，以便之後做記號 
		memset(pair, 0, sizeof(pair)); // 也是歸零，方便之後判別這筆資料跟其它筆有無關係 
		
		for(j=0;j<M;j++){ //輸入關係 (A, B) 
			int A, B;
			scanf("%d %d", &A, &B);
			addData(&pair[0], A, B); 
			addData(&pair[0], B, A); //關係是雙向的 所以B,A也要加到關係中 
		}
		max=0; //用來記錄最大的一群 
		for(j=1;j<=N;j++){ //從頭檢視 
			count=0; //每檢查某個數跟它衍伸出的關係前 先歸零 
			relation(&pair[0], j, check);
			if(count > max) max=count;
		}
		if(M==0){ //如果所有人都跟其他人沒關係的話，每個群就只有一人 
			printf("%d\n", 1);
		}
		else{
			printf("%d\n", max);
		} 
	}
		return 0;
	}

	
