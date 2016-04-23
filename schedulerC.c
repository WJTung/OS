#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int max_name_length = 32;
const int max_numP = 1E1;
const int max_totalT = 1E4;
const int time_quantum = 5E2;
// malloc should be used if array may be too large
int numP_now = 0;
#define FIFO 0
#define RR 1
#define SJF 2
#define PSJF 3
typedef struct process
{
	char *name;
	int readyT;
	int execT;
	int ID;
} Process;
// function for Process sorting
int compare_Process(const void *a, const void *b)
{
	Process *P1 = (Process *)a;
	Process *P2 = (Process *)b;
	if(P1->readyT < P2->readyT)
		return -1;
	if(P1->readyT > P2->readyT)
		return 1;
	// if readyT is equal, compare their ID
	if(P1->ID < P2->ID)
		return -1;
	if(P1->ID > P2->ID)
		return 1;
	return 0;
}
// function for process list
void insertP(Process **waiting_list, int policy, Process *P)
{
	numP_now++; 
	if(policy == FIFO || policy == RR) // just insert new process to the list
		waiting_list[numP_now - 1] = P;
	if(policy == SJF || policy == PSJF) // need to find appropriate place according to execT
	{
		waiting_list[numP_now - 1] = P;
		for(int i = numP_now - 1; i > 0 && waiting_list[i]->execT < waiting_list[i - 1]->execT; i--)
		{
			// new process should be swapped to left
			Process *temp = waiting_list[i];
			waiting_list[i] = waiting_list[i - 1];
			waiting_list[i - 1] = temp;
		}
	}
}
int execP(Process **waiting_list, int policy) // return how long the process should be executed continuously
{
	if(policy == FIFO || policy == SJF) // first process in the waiting_list will be done
	{
		int exec_length = waiting_list[0]->execT;
		waiting_list[0]->execT = 0;
		waiting_list[0] = NULL;
		numP_now--;
		for(int i = 1; i <= numP_now; i++)
		{
			Process *temp = waiting_list[i];
			waiting_list[i] = waiting_list[i - 1];
			waiting_list[i - 1] = temp;
		}
		return exec_length; 
	}
	if(policy == RR)
	{
		int exec_length;
		if(waiting_list[0]->execT > time_quantum)
		{
			exec_length = time_quantum;
			waiting_list[0]->execT -= time_quantum;
		}
		else
		{
			exec_length = waiting_list[0]->execT;
			waiting_list[0]->execT = 0;
			waiting_list[0] = NULL; // this process is done
		}
		for(int i = 1; i < numP_now; i++)
		{
			Process *temp = waiting_list[i];
			waiting_list[i] = waiting_list[i - 1];
			waiting_list[i - 1] = temp;
		}
		if(waiting_list[numP_now - 1] == NULL)
			numP_now--;
		return exec_length;
	}
	if(policy == PSJF) // execute only one time unit
	{
		waiting_list[0]->execT--;
		if(waiting_list[0]->execT == 0)
		{
			waiting_list[0] = NULL;
			numP_now--;
			for(int i = 1; i <= numP_now; i++)
			{
				Process *temp = waiting_list[i];
				waiting_list[i] = waiting_list[i - 1];
				waiting_list[i - 1] = temp;
			}
		}
		return 1;
	}
}
// main scheduling program
int main()
{
	Process P[max_numP];
	int schedule[max_totalT];
	char policy_name[5];
	scanf("%s", policy_name);
	int numP;
	scanf("%d", &numP);
	getchar();
	int totalT = 0;
	for(int i = 0; i < numP; i++)
	{
		char *process_name = malloc(max_name_length * sizeof(char));
		int ready_time;
		int execution_time;
		scanf("%s %d %d", process_name, &ready_time, &execution_time);
		getchar();
		totalT += execution_time;
		P[i].name = process_name;
		P[i].readyT = ready_time;
		P[i].execT = execution_time;
		P[i].ID = i;
	}
	// sort P according to readyT
	qsort(P, numP, sizeof(Process), compare_Process);
	int policy = 0;
	char policy_list[4][5] = {"FIFO", "RR", "SJF", "PSJF"};
	for(int i = 0; i < 4; i++)
		if(strcmp(policy_name, policy_list[i]) == 0)
			policy = i;
	Process *waiting_list[max_numP];
	for(int i = 0; i < max_numP; i++)
		waiting_list[i] = NULL;
	Process *exec_order[max_totalT];
	int index_now = 0;
	int t = 0;
	while(t < totalT)
	{
		while(P[index_now].readyT <= t)
		{
			insertP(waiting_list, policy, (P + index_now));
			index_now++;
		}
		if(waiting_list[0] != NULL)
		{
			Process *exec_process = waiting_list[0];
			int exec_length = execP(waiting_list, policy);
			for(int i = 1; i <= exec_length; i++)
			{
				exec_order[t] = exec_process;
				t++;
			}
		}
		else
		{
			exec_order[t] = NULL; // no waiting process now
			t++;
		}
	}
	// test result
	for(int i = 0; i < totalT; i++)
	{
		if(exec_order[i] != NULL)
			printf("%d time unit : execute %s\n", i + 1, exec_order[i]->name);
		else 
			printf("%d time unit : No process\n", i + 1);
	}
	return 0;
}
		