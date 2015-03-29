#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
	if (argc < 2) {
		fprintf(stderr, "usage: rmpre <string> <prefix>\n");
		return 1;
	}
	size_t lenstr = strlen(argv[1]);
	size_t lenprefix = strlen(argv[2]);
	if (lenprefix <= lenstr) {
		char* candidate = malloc(lenprefix + 1);
		strlcpy(candidate, argv[1], lenprefix + 1);
		// printf("%s\n", candidate);
		if (strcasecmp(candidate, argv[2]) != 0) {
			lenprefix = 0;
		}
	}
	printf("%s\n", argv[1] + lenprefix);
	return 0;
}
