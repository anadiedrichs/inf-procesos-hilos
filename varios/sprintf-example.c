//https://www.geeksforgeeks.org/sprintf-in-c/
// Example program to demonstrate sprintf() 
#include<stdio.h> 
int main() 
{ 
	char buffer[50]; 
	int a = 10, b = 20, c; 
	c = a + b; 
	float m ; m = 9.1;

	sprintf(buffer, "Sum of %d and %d is %f", a, b, c+m); 

	// The string "sum of 10 and 20 is 30" is stored 
	// into buffer instead of printing on stdout 
	printf("%s", buffer); 

	return 0; 
} 

