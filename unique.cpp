#include <iostream>
#include <string.h>

bool unique(char *string) {
	while( *string ) {
		char *checkString = string;
		++checkString;
		while( *checkString ) {
			if( *string == *checkString ) {
				return false;
			}
			checkString++;
		}
		string++;
	}
	return true;
}

int main(int argc, char *argv[]) {
	if( argc != 2 ) {
		std::cout << "Proper usage unique STRING" << std::endl;
	}
	bool result = unique(argv[1]);

	if (result) {
		std::cout << "The string is unique" << std::endl;
	} else {
		std::cout << "The string isn't unique" << std::endl;
	}

	return 0;
}