#define _GNU_SOURCE
#define _USE_GNU
#include <stdio.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sched.h>
const long long n = 1E9;
const int buffer_size = 1E2;

int main(int argc, char* argv[]){
    
    long long start_time = syscall(328);
    long long start_time_s = start_time / n;
    long long start_time_ns = start_time % n; 
    
    char* name = argv[1];
    pid_t pid = getpid();
    int exec_time;
    exec_time = strtol(argv[2], NULL, 10);

    int i;
    for(i = 0; i < exec_time; i++){
        volatile unsigned long j;
        for(j = 0; j < 1000000UL; j++); 
    }
    
    long long end_time = syscall(328);
    long long end_time_s = end_time / n;
    long long end_time_ns = end_time % n;

    char buffer[buffer_size];
    sprintf(buffer, "[project1] %d %lld.%lld %lld.%lld", pid, start_time_s, start_time_ns, end_time_s, end_time_ns);
    syscall(327, buffer);
    return 0;
}
