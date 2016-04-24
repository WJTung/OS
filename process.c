#define _GNU_SOURCE
#define _USE_GNU
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>

int main(int argc, char* argv[]){
	char* name = argv[1];
	pid_t pid = getpid();
	int exec_time;
	exec_time = strtol(argv[2], NULL, 10);

	cpu_set_t cpu_mask;
	CPU_ZERO(&cpu_mask);
	CPU_SET(1, &cpu_mask);

	if(sched_setaffinity(0, sizeof(cpu_set_t), &cpu_mask) != 0){
		perror("sched_setaffinity error");
		exit(EXIT_FAILURE);
	}

	//system call print name
	//system call print pid
	//struct timespec current;
	//getnstimeofday(&current);
	//system call print time

	int i;

	for(i = 0; i < exec_time; i++){
		volatile unsigned long j;
		for(j = 0; j < 1000000UL; j++); 
	}

	//getnstimeofday(&current);
	//system call print time

	return 0;
}
