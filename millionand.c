#include <stdio.h>
#include <string.h>
#define MAX 1000000000
/*
 * Take every number from one to one million and turn it into a bit string. 
 * Print every 100,000th number.
 */

int bit_and(int*, int, int*, int, int*);
int convert_int_to_bit_array(int, int*);
void print_int_array(int*, int);
void rstr(int*, int);
void nswap(int*, int, int);
void testOne(__int64_t);
void print_stuff(int, int, int*, int, int*, int, int*, int);

void testAny(int a, int b, int print) {
	int arr[192], brr[192], res[192];
	int alen, blen, reslen;
	alen = convert_int_to_bit_array(a, arr);
	blen = convert_int_to_bit_array(b, brr);
	reslen = bit_and(arr, alen, brr, blen, res);
	if(print)
		print_stuff(a, b, arr, alen, brr, blen, res, reslen);
}

void testOne(__int64_t d) {
	int i = 114, j = 116, l1, l2, rl;
	int a[1024], b[1024], r[1024];
	l1 = convert_int_to_bit_array(i, a);	
	l2 = convert_int_to_bit_array(j, b);
	rl = bit_and(a, l1, b, l2, r);
	print_stuff(i, j, a, l1, b, l2, r, rl);
}

void print_stuff(int i, int j, int a[], int al, int b[], int bl, int r[], int rl){
	printf("i = %d: ", i);
	print_int_array(a, al);
	printf("j = %d: ", j);
	print_int_array(b, bl);
	print_int_array(r, rl);
}

int main() {
	int first = 10, second = 23, i, r;
	int num = 10000000;
	//for (i = 0; i < num; i ++) 
	for (i = 0; (i % (num / 10) == 0) && i < num; i++){
		testAny(first + i, second + i, i % (num / 10) == 1);
	}
	printf("-------------\n");
	for (i = 0; i < num; i ++) {
		r = (first + i) & (second + i);
		if (i % (num / 10) == 0)
			printf("%d, %d, %d\n", (first + i), (second + i), r);
	}
	return 0;
}

int main1(){
	int len57, i, leni, tmp, bit[1024], bit57[1024], arraytmp[1024], hun[10730], resl, j;
	i = 57, j = 58;
	//print the value for 57 on screen for reference
	printf("%d is ", i);
	tmp = convert_int_to_bit_array(i, arraytmp);
	print_int_array(arraytmp, tmp);
	//convert i + 57 to bits and print
	printf("%d is ", j);
	len57 = convert_int_to_bit_array(j, bit57);
	print_int_array(bit57, len57);
	//convert i into bits and print
	leni = convert_int_to_bit_array(i, bit);
	printf("i is ");
	print_int_array(bit, leni);
	resl = bit_and(bit, leni, bit57, len57, hun);
	printf("%d and %d = ", i, i + 57);
	print_int_array(hun, resl);
	for(i = 0; i != MAX; i++){
		leni = convert_int_to_bit_array(i, bit);
		//print_int_array(bit, leni);
		if(i % 1000000 == 0){
			resl = bit_and(bit, leni, bit57, len57, hun);
			printf("%d is %d is \t", i, resl);
			print_int_array(hun, resl);
		}
	}
	return 0;
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

int convert_int_to_bit_array(int n, int s[]){
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

void print_int_array(int s[], int len){
	int i;
	for(i = 0; i != len; i++)
		printf("%d", s[i]);
	printf("\n");
}

void rstr(int s[], int total){
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
