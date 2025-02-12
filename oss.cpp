#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

#include <string>

using namespace std;

int main( int argc, char** argv)
{
	int opt;
	int n_Value = 0;
	int s_Value = 0;
	int t_Value = 0;

	while ((opt = getopt(argc, argv, "n:s:t:h")) != -1)
	{
	switch (opt)
		{
			case 'n':
				n_Value = atoi(optarg);
				break;
			case 's':
				s_Value =  atoi(optarg);
				break;
			case 't':
				t_Value = atoi(optarg);
				break;
			case 'h':
				printf("Help Text \n");
				return 0;
		}
	}
	printf("Value check \n");

	if (n_Value <= 0){
	printf("N Value not accepted. Ending process.");
	return -1;
	}
	if (s_Value <= 0){
	printf("S Value not accepted. Ending process.");
	return -1;
	}
	if (t_Value <= 0){
	printf("T Value not accepted. Ending process.");
	return -1;
	}







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
