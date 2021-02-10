#include <stdio.h>

//this is the pointer implementation of strlen, which takes in a character pointer and returns an unsigned int. 
//(c)NiKo, Inc., 1963. All rights reserved.

unsigned strlen_ptr(const char*);


int main(){
	char* s = "hello\0";
	
	printf("given string: %s\nsize of string: %d\n", s, strlen_ptr(s));
}


unsigned int strlen_ptr(const char *s){
	char *a;
	
	for(a = s; *a != '\0'; a++);
	
	return a - s;
}
