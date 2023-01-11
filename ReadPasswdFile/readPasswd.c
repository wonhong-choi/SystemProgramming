#include <unistd.h>
#include <pwd.h>

int main(){
	struct passwd* pw;

	pw=getpwuid(getuid());
	printf("UID = %d\n", (int)pw->pw_uid);
	printf("Login Name = %s\n", pw->pw_name);

	return 0;
}
