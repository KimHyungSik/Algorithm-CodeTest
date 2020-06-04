int A_arr[] = { 1,2,3,4,5,6,7,8,9,10 };
int B_arr[] = { 10,9,8,7,6,5,4,3,2,1 };
void temp(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}