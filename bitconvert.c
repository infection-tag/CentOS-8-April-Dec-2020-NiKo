#include <stdio.h>

int convert_int_to_bit_array(int, int*);
void print_int_array(int*, int);
int convert_bit_to_int_array(int, int*);
void rstr(int*, int);
void nswap(int*, int, int);

int main()
{
	int a[10], al, b[10], bl;
	al = convert_int_to_bit_array(42, a);
	//printf("2 is %d is ", al);
	print_int_array(a, al);
}

int convert_bit_to_int_array(int n, int s[]){
	int total = 0, i;
	for(i = 0; n > 1; i++)
		
}

int convert_int_to_bit_array(int n, int s[])
{
	int mod, i;
	for(i = 0; n > 1; i++, n = n / 2){
		mod = n % 2;
		s[i] = mod;
	}
	s[i] = n;
	++i;
	rstr(s, i);
	return i;
}

void print_int_array(int s[], int len)
{
	int i;
	for(i = 0; i != len; i++)
		printf("%d", s[i]);
	printf("\n");
}

void rstr(int s[], int total)
{
	int i;
	for(i = 0; i != (total / 2); i++){
		nswap(s, i, total - (i + 1));
	}
}

void nswap(int s[], int i, int j){
	int tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}
