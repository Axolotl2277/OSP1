//This is Project 1 for CMP_SCI-4760 Spring 2025 for Logan Bessinger
//Will take arg -n (for Number) -s (for Simaltainis) and -t (for Interations)
//and create n processes,but no more that s number at a time, and those files will run t times.
//created processes are named user.cpp and take 1 argument other than file name and is an int
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
	int total_Count = 0;
	int running_Count =0;
	
	
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
				printf("Called with (./oss -n x -s y -t z) where x, y, and z are ints. \n");
				return 0;
		}
	}
	printf("Value check \n");
	//value/input checking
	if (n_Value <= 0){
	printf("N Value not accepted. Ending process. \n");
	return -1;
	}
	if (s_Value <= 0){
	printf("S Value not accepted. Ending process. \n");
	return -1;
	}
	if (t_Value <= 0){
	printf("T Value not accepted. Ending process. \n");
	return -1;
	}

	
	while (n_Value > total_Count)
	{
		pid_t c_pid = fork();
	
		if (c_pid == -1)
		{
		printf("Fork You. Fork Fail. \n");
		return 0;
		}
		if (c_pid > 0){
		running_Count++;
		total_Count++;
			if(running_Count >= s_Value)
			{
			wait(0);
			running_Count--;
			}
		}
		if (c_pid == 0) 
		{
		string arg0 = "./user";
		string arg1 = std::to_string(t_Value);	
		execlp(arg0.c_str(), arg0.c_str(), arg1.c_str(), (char *)0);
		printf("If printed, an error has occured.");
		return -2;
		}
	}
	printf("Oss has ended \n");
	return 0;
}
