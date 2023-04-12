#include<stdio.h>
#include<string.h>

void main(){
	int i,j=0,s,rail;
	char text[60];
	gets(text);
	printf("Enter rails:");
	scanf("%d",&rail);
	//printf("%d\n",rail);
	s=strlen(text);
	//printf("%d",s);
	char key[rail][s];
	int count=0;
	for(i=0;i<rail;i++){
		for(j=0;j<s;j++){
			key[i][j]='0';
		}
	}
	j=0;
	while(j<s){
		if(count%2==0){
			for(i=0;i<rail;i++){
				key[i][j]=text[j];
				j++;
			}
		}
		else{
			for(i=rail-2;i>0;i--){
				key[i][j]=text[j];
				j++;
			}
		}
		count++;
	}
	for(i=0;i<rail;i++){
		for(j=0;j<s;j++){	 
			if(key[i][j]!='0') printf("%c",key[i][j]);	
		}
	}

}	
