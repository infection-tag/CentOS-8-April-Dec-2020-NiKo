#include <stdio.h>
#include <string.h>

#define PRIVATE static

void print_int_array(int*, int);
void reverse_int_array(int*, int);
int convert_int_to_bit_array(int, int*);
void nswap(int*, int, int);
int bit_and(int*, int, int*, int, int*);
int array_to_int(int*, int);
size_t strlen_ptr(const char*);


void print_int_array(int s[], int len){
	int i;
	
	for(i = 0; i != len; i++)
		printf("%d ", s[i]);
	printf("\n");
}


void reverse_int_array(int s[], int total){
	int i;
	
	for(i = 0; i != (total / 2); i++){
		nswap(s, i, total - (i + 1));
	}
}


int convert_int_to_bit_array(int n, int s[]){
	int mod, i;
	
	for(i = 0; n > 1; i++, n = n / 2){
		mod = n % 2;
		s[i] = mod;
	}
	s[i] = n;
	++i;
	reverse_int_array(s, i);
	
	return i;
}


void nswap(int s[], int i, int j){
	int tmp;
	
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}


int bit_and(int a[], int al, int b[], int bl, int res[]){
	
	int i, diff, j;
	
	//print_int_array(a, al);
	//print_int_array(b, bl);
	diff = al - bl;
	if(diff < 0)
		for(i = 0; i != al && i != bl; i++){
			res[i] = (a[i] & b[i - diff]);
			//printf("res[%d] = %d\n", i, res[i]);
	}
	else if(diff > 0)
		for(i = 0; i != al && i != bl; res[i] = (a[i + diff] & b[i]), i++);
		else
		for(i = 0; i != al && i != bl; res[i] = (a[i] & b[i]), i++);
	
	return i;
}


int array_to_int(int s[], int len){
	int i, total = 0;
	
	for(i = 0; i != len; i++)
		total = 10 * total + s[i];
	
	return total;
}


size_t int strlen_ptr(const char *s){
	char *a;
	
	for(a = s; *a != '\0'; a++);
	
	return a - s;
}
