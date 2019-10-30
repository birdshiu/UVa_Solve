#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int count; //�Ψӭp��B�͸s�� 

struct mystr{ //�O�����Y����C 
	int n;
	struct mystr *next;
};

void relation(struct mystr ** pair, int A, char *check){
	struct mystr *tmp; //�Ψ�����O���骺���� 
	
	while(pair[A]!=NULL){ //�p�G A �٦����Y���� 
		if(check[A]==0){ //�p�G�Ʀr A �S������ ���N�i�H��i�s�դH�Ƹ� 
			count++;
			check[A]=1;
		}
		tmp=pair[A];
		pair[A]=pair[A]->next; //�C�o�{�@�����p�A�N�⥦�h���A�קK����S�⦨�t�~�@�s 
		relation(pair, tmp->n, check); //�C�o�{�@�����p�A�N�A�ΦP�˪��覡�A��X�������p����L���p 
		free(tmp);//Ķ��O���� 
	}
}

void addData(struct mystr ** pair, int A, int B){ //�H�U�O���p��C���s�W��ơA��Ʀb�[�J�ɷ|���y�j�p�ƧǡA�ٷ|�h�����Ъ���� 
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
	
	scanf("%d", &d); //�X����� 
		
	for(i=0;i<d;i++){
		int N, M; //�H��//�t��� 
		scanf("%d %d", &N, &M);
		char check[N+1]; //�b��B�����Y�ɡA�קK�J�쭫�Ъ��H�A����1��ܦ��J��L 
		struct mystr* pair[N+1]; //�Ψӧ� "���Y" ���A�p�G�ڭn��ָ� B �����Y �ڥi�H������ pair[B] �ҳs������C 
		memset(check, 0, sizeof(check)); //�k�s�A�H�K���ᰵ�O�� 
		memset(pair, 0, sizeof(pair)); // �]�O�k�s�A��K����P�O�o����Ƹ�䥦�����L���Y 
		
		for(j=0;j<M;j++){ //��J���Y (A, B) 
			int A, B;
			scanf("%d %d", &A, &B);
			addData(&pair[0], A, B); 
			addData(&pair[0], B, A); //���Y�O���V�� �ҥHB,A�]�n�[�����Y�� 
		}
		max=0; //�ΨӰO���̤j���@�s 
		for(j=1;j<=N;j++){ //�q�Y�˵� 
			count=0; //�C�ˬd�Y�ӼƸ򥦭l���X�����Y�e ���k�s 
			relation(&pair[0], j, check);
			if(count > max) max=count;
		}
		if(M==0){ //�p�G�Ҧ��H�����L�H�S���Y���ܡA�C�Ӹs�N�u���@�H 
			printf("%d\n", 1);
		}
		else{
			printf("%d\n", max);
		} 
	}
		return 0;
	}

	
