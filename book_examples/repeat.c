#include <stdio.h>

int main(int argc, char *argv[])
{
	int count;
	printf("Количество элементов, указанных в командной строке: %d\n", argc-1);
	for(count = 1; count < argc; count++)
		printf("%d: %s\n", count, argv[count]);
	printf("\n");
	return 0;
}
