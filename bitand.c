#include <stdio.h>

int bit_and(int*, int, int*, int, int*);
void print_int_array(int*, int);
void test_print_int_array();
int convert_int_to_bit_array(int, int*);
void reverse_int_string(int*, int);
void int_swap(int*, int, int);

int main(){
	int a[1024], al = convert_int_to_bit_array(45, a);
	int b[1024], bl = convert_int_to_bit_array(2, b);
	int c[1024], cl = convert_int_to_bit_array(23, c);
	int res[1024];
	printf("45 is %d ", al);
	print_int_array(a, al);
	printf("2 is %d ", bl);
	print_int_array(b, bl);
	printf("23 is %d ", cl);
	print_int_array(c, cl);
	//j = bit_and(a, al, b, bl, res);
	//printf("j: %d\n", j);
	//print_int_array(res, j);
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

void print_int_array(int s[], int len){
	int i;
	for(i = 0; i != len; i++)
		printf("%d", s[i]);
	printf("\n");
}

/**
 * Take an integer n in base 10 and convert it into an array, populate the array a, 
 * and return the length of the resulting bit string.
 */
int convert_int_to_bit_array(int n, int s[]){
	int mod, i, bin = 0;
	//for(i = 0; i != len; i++)
		//total = 10 * total + s[i];
	for(i = 0; n > 1; i++, n = (n - mod) / 2){
		mod = n % 2;
		s[i] = mod;
	}
	i++;
	s[i] = n;
	reverse_int_string(s, i);
	return 6;
}

void test_print_int_array(){
	int s[100], i;
	s[0] = 0;
	s[1] = 1;
	//for(i = 0; i < 100; s[i] = i, i++);
	print_int_array(s, 2);
	//print_int_array(s, 1);
	//print_int_array(s, 7);
}

void reverse_int_string(int s[], int len){
	for(int i = 0; i <= len; i++)
		int_swap(s, i, len - (i + 1));
}

/* Swap places in an int function */
void int_swap(int s[], int i, int j){
	int tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}
