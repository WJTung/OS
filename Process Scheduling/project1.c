#include <stdio.h>
#include <unistd.h>
#include <sched.h>

int main(){
	int execute[];
	int fork[];
	int time_count, fork_count;
	pid_t pid;
	int total_time;
	fork_count = 0;

	//set CPU
	cpu_set_t cpu_mask;
	CPU_ZERO(&cpu_mask);
	CPU_SET(0, &cpu_mask);

	if(sched_setaffinity(0, sizeof(cpu_set_t), &cpu_mask) != 0){
		perror("sched_setaffinity error");
		exit(EXIT_FAILURE);
	}

	//raise the priority
	struct sched_param param;
	param.sched_priority = 50;
	//I'm not sure about how high param.sched_priority should go
	//Just want to make sure it won't get preempted by other processes on its CPU
	if(sched_setscheduler(pid, SCHED_FIFO, & param) != 0) {
		perror("sched_setscheduler error");
		exit(EXIT_FAILURE);  
	}

	for(time_count = 0; time_count < total_time; time_count++){
		//fork the processes that are ready at time_count
		while(time_count == fork[fork_count].ready_t){

			pid = fork();
		    //TODO: connect the pid with the process name
		    if(pid < 0)   
		        printf("error in fork!");   
		    else if(pid == 0) {  
		        char exec_time[10];
				sprintf(exec_time, "%d", fork[fork_count].exec_t);
		        if(execlp("./process", "process", fork[fork_count].name, exec_time, (char *)NULL) < 0){
					perror("execlp error");
					exit(EXIT_FAILURE);
		        }
		    }  
			
			fork_count++;
		}
		//decide who to run on the CPU for child processes
		//change priority if a different process is going to run
		if(time_count == 0){
			pid = findPID(execute[time_count].name);/*findPID to be implemented*/
			param.sched_priority = 2;
			if(sched_setscheduler(pid, SCHED_FIFO, & param) != 0) {
	    		perror("sched_setscheduler error");
				exit(EXIT_FAILURE);
			}
		}
		else if(execute[time_count].name != execute[time_count - 1].name){
			pid_t prev_pid = findPID(execute[time_count - 1].name);
			pid = findPID(execute[time_count].name);/*findPID to be implemented*/

			param.sched_priority = 1;
			if(sched_setscheduler(prev_pid, SCHED_FIFO, & param) != 0) {
	    		perror("sched_setscheduler error");
				exit(EXIT_FAILURE);  
			}

			param.sched_priority = 2;
			if(sched_setscheduler(pid, SCHED_FIFO, & param) != 0) {
	    		perror("sched_setscheduler error");
				exit(EXIT_FAILURE);  
			}
		}

		volatile unsigned long i;
		for(i=0;i<1000000UL;i++); 
	}
}