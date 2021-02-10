#include <stdio.h>

void nstrcat(char *, char *);

int main(){
	char s[100] = "hello";
	//s[0] = '\0';
	//nstrcat(s , "hello");
	printf("%s\n", s);
}

void nstrcat(char a[], char b[]){
	int i, j;
	for(i = 0; a[i] != '\0'; i++);
	for(j = 0; b[j] != '\0'; j++)
		a[i + j] = b[j];
	a[i + j] = '\0';
}

