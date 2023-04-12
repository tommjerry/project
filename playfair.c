#include<stdio.h>
#include<string.h>

#define M 30

char keyM[5][5],loc[2],pt[M],key[M];
void keyMT();
int search(char);
void encrypt();

void main(){
	int i,j;
	scanf("%s",pt);
	scanf("%s",key);
	for(i=0;pt[i]!='\0';i+=2){
		if(pt[i]==pt[i+1]){
			for(j=strlen(pt);j>i;j--){
				pt[j]=pt[j-1];
			}
			pt[i+1]='x';
		}
	}
	if(strlen(pt)%2!=0){
		pt[strlen(pt)]='z';
	}
	keyMT(key);
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			printf("%c",keyM[i][j]);
		}
		printf("\n");
	}
	encrypt();
	printf("%s\n",pt);
}

void keyMT(){
	int i,j,t=0;
	char ch='a';
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(key[t]!='\0'){
				if(!search(key[t])){
					if(key[t]=='j'){
						key[t]='i';
					}
					keyM[i][j]=key[t];
				}
				else j--;
				t++;
			}
			else{
				if(!search(ch)&ch!='j'){
					keyM[i][j]=ch;
				}
				else j--;
				ch++;
			}
		}
	}
}

int search(char ch){
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(keyM[i][j]==ch){
				loc[0]=i;
				loc[1]=j;
				return 1;
			}
		}
	}
	return 0;
}

void encrypt(){
	int i;
	int x[2],y[2];
	for(i=0;pt[i]!='\0';i+=2){
		if(search(pt[i])){
			x[0]=loc[0];
			x[1]=loc[1];
		}
		if(search(pt[i+1])){
			y[0]=loc[0];
			y[1]=loc[1];
		}

		if(x[1]==y[1]){
			pt[i]=keyM[(x[0]+1)%5][x[1]];
			pt[i+1]=keyM[(y[0]+1)%5][y[1]];
		}
		else if(x[0]==y[0]){
			pt[i]=keyM[x[0]][(x[1]+1)%5];
			pt[i+1]=keyM[y[0]][(y[1]+1)%5];
		}
		else{
			pt[i]=keyM[x[0]][y[1]];
			pt[i+1]=keyM[y[0]][x[1]];
		}
	}

}

