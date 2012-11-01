#include <iostream>
#include <string.h>
#include <malloc.h>

char *reverse(char *string) {

	int strLen = strlen(string);
	char *rev = (char *)malloc(sizeof(char)*strlen(string));
	strncpy(rev, string, strLen);
	char *revHead = rev;
	char *revBack = rev;
	while (*revBack) {
		revBack++;
	}
	revBack--;

	for(int i = 0; i < (int)((float) strLen/2) ; i++) {
		char temp = *revHead;
		*revHead = *revBack;
		*revBack = temp;
		revHead++;
		revBack--;
	}

	return rev;
}

int main(int argc, char *argv[]) {
	if( argc != 2 ) {
		std::cout << "Proper usage reverse STRING" << std::endl;
	}
	char *rev = reverse(argv[1]);

	std::cout << rev << std::endl;

	free(rev);

	return 0;
}