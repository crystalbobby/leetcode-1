/*
clang -O1 -g -fsanitize=address -fno-omit-frame-pointer ./c/test.c
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include<limits.h>

struct
{
	unsigned int x1 : 3;
	unsigned int x2 : 33;
	// unsigned int x3 : 3;
} Age;

int main()
{
	Age.x1 = 2;
	printf("Age size is %d\n", sizeof(Age));
	return 0;
}