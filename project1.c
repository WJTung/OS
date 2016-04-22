#include <stdio.h>
#include <unistd.h>

int main(){
	int execute[];
	int fork[];
	int i, j;
	pid_t pid;
	int total_time;
	
	//一開始main先設自己priority是1
	for(i = 0; i < N; i ++){
		if(i == fork[j]){
			j++;

			pid=fork();   
		    if(pid < 0)   
		        printf("error in fork!");   
		    else if(pid == 0) {  
		        //child process child exec的程式開頭會把自己設成4
		        //跑完一時間單位他會把main設回1
		        exec();
		    }  
		    else{  
				//parent process
		    }  
		}
		然後main把前一秒執行的process priority也設回4
		//下一秒要執行的(execute[i])設成2

		最後把MAIN自己設成3


		main進入下一次for
	}
}