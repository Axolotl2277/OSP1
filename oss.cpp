#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <string>

using namespace std;

int main( int argc, char** argv)
{
	pid_t c_pid = fork();
	
	if (c_pid == -1){
	printf("Fork You. Fork Fail.");
	return 0;
	}
	else if (c_pid > 0){
	printf("Oss \n");
	}
	else {
	string arg0 = "./user";
	string arg1 = "5";	
	execlp(arg0.c_str(), arg0.c_str(), arg1.c_str(), (char *)0);
	printf("Child \n");
	}
	

	wait (0);
	printf("waited oss has ended");
	return 0;
}
