#include <sys/sysinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
	struct sysinfo buf;

	printf("Clock Tick : %ld\n", sysconf(_SC_CLK_TCK));
	printf("Max Open File : %ld\n", sysconf(_SC_OPEN_MAX));
	printf("Max Login Name Length : %ld\n", sysconf(_SC_LOGIN_NAME_MAX));
	

	return 0;
}
