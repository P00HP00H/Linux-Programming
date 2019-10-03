#include<stdio.h>

int write_to_file(void)
{
        FILE * fp = fopen("pooh", "w");     // fopen함수는 성공 시 포인터를 반환하고, 실패 시 NULL 반환 -> 첫 번째 인자는 절대경로, 상대경로 둘 다 가능
        if(fp == NULL){     // 실패한 경우
                perror("fopen error\n");    // perror함수로 에러 메시지 출력
                return -1;
        }

        fputs("hello world!!\n", fp);   // 첫 번째 인자를 두 번째 인자에 넣음(write함)
        fclose(fp);

        return 0;
}

int read_from_file(void)
{
        char buf[10];
        FILE * fp = fopen("pooh", "r");     // fopen함수는 성공 시 포인터를 반환하고, 실패 시 NULL 반환 -> 첫 번째 인자는 절대경로, 상대경로 둘 다 가능
        if(fp == NULL){
                perror("fopen error\n");    // perror함수로 에러 메시지 출력
                return -1;
        }

        fgets(buf, sizeof(buf), fp);    /* fp에서 문자열을 받아서 (sizeof(buf)-1)개의 문자를 입력받을 때까지나, 개행문자("\n")나 파일 끝(End-of-File)에 도달할 때까지
        입력 받아서 C형식의 문자열로 저장하며 개행문자("\n")는 fgets로 하여금 입력을 끝나게 하지만 이 문자 역시 buf에 저장 */
        fclose(fp);

        printf("읽어들인 문자열 : %s\n", buf);

        return 0;
}

int main(int argc, char **argv)
{
        write_to_file();
        read_from_file();
        return 0;
}
