// pic.c
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("taking pic\n");
	system("python Camera.py");
	printf("took pic\n");
}
