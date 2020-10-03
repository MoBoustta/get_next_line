#include "get_next_line.h"

int main(){

	char* file_name = "dbg.h";
	int fd = open(file_name, O_RDONLY);
	char *out = NULL;

	while(get_next_line(fd, &out))
		printf("%s\n", out);
	return 0;
}
