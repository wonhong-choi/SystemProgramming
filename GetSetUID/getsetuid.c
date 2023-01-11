#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	uid_t uid, euid;
	uid=getuid();
	euid=geteuid();
	printf("[init] UID=%d, EUID=%d\n", (int)uid, (int)euid);

	seteuid(getuid());
	int cur_euid=(int)geteuid();
	printf("[set] UID=%d, EUID=%d\n", (int)uid, cur_euid);

	seteuid(euid);
	printf("[set] UID=%d, EUID=%d\n", (int)uid, (int)geteuid());

	return 0;
}
