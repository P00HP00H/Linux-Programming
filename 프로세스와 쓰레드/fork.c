#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int num = 10;   // 전역 변수 num = 10

void get_pid(void){
        printf("this is my PID : %d\n", getpid());
}

int main(int argc, char **argv)
{
	int num2 = 20;  // 지역 변수 num2 = 20
	printf("origin process pid : %d\n", getpid());  // 부모 프로세스에서만 실행됨
	
	pid_t pid = fork();     // fork() -> 실패 시 반환 값 : -1, 성공 시 반환 값 : 자식 프로세스 PID,  자식 프로세스는 fork()의 반환값이 0
    	sleep(1);       // 자식 프로세스는 부모 프로세스를 그대로 불러오는 것이므로 위의 코드들은 부모 프로세스에서 이미 실행된 것들이므로 다시 실행 X -> 대신 상태 그대로 가져옴
       
	if(pid == 0){
		/* child process */
        	printf("child process pid : %d\n", getpid());
        	num += 2, num2 += 2;    // 부모 프로세스의 전역 변수, 지역 변수 그대로 불러옴
        	printf("child num, num2 : %d, %d\n", num, num2);        // 따라서, num=10+2=12, num2=20+2=22
    	}
    	else if(pid > 0){
		/* parent process */
        	printf("parent process pid : %d, child pid : %d\n", getpid(), pid);
        	num -= 2, num2 -= 2;
        	printf("parent num, num2 : %d, %d\n", num, num2);
    	}
    	else if(pid == -1) {	// -1 이면 fork() 생성 실패
		printf("can't fork, error\n");
        	exit(0);
    	}
	
	get_pid();
    	printf("------------------------------------------\n\n");
	
	return 0;
}
