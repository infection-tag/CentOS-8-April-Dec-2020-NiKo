#include <stdio.h>
int isDigit(char);
int main(){
	char cs[] = {'3', 't', '~', 'A'};
	int i;
	for (i = 0; i < 4; i++)
		printf("'%c':%d\n", cs[i], isDigit(cs[i]));
}

int isDigit(char c){
	return c <= '9' && c >= '0';
}
