#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

struct stat stat1, stat2;
struct tm *time1, *time2;

void filestat1();
void filestat2();
void filetime1();
void filetime2();
void sizecmp();
void blockcmp();
void datecmp();
void timecmp();

int main(){
    filestat1();
    filestat2();
    filetime1();
    filetime2();
    sizecmp();
    blockcmp();
    datecmp();
    timecmp();
}

//파일 1의 정보를 가져오는 함수 작성
void filestat1(){
    char buf[256];
    int bufsize = sizeof(buf);
    getcwd(buf, bufsize);
    strcat(buf, "/text1");
    stat(buf,&stat1);
}

//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    char buf[256];
    int bufsize = sizeof(buf);
    getcwd(buf, bufsize);
    strcat(buf, "/text2");
    stat(buf,&stat2);
}

//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){ 
    time1 = localtime(&stat1.st_mtime);
}

//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){
    time2 = localtime(&stat2.st_mtime);
}

//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp(){
    printf("date compare\n");

    // 두 파일의 mon을 비교
    if (time1->tm_mon < time2->tm_mon) {
        printf("text1 is early");
    }
    else if (time1->tm_mon > time2->tm_mon) {
        printf("text2 is early");
    }
    // 두 파일의 mon이 같으므로 mday를 비교
    else if (time1->tm_mday < time2->tm_mday) {
        printf("text1 is early");
    }
    else if (time1->tm_mday > time2->tm_mday) { 
        printf("text2 is early");
    }
    // mon과 mday가 같음
    else {
        printf("same time");
    }
    printf("\n\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp(){
    // 두 파일의 hour를 비교
    if (time1->tm_hour < time2->tm_hour) {
        printf("text1 is early\n");
    }
    else if (time1->tm_hour > time2->tm_hour) {
        printf("text2 is early\n");
    }
    // 두 파일의 hour가 같으므로 min을 비교
    else if (time1->tm_min < time2->tm_min) {
        printf("text1 is early\n");
    }
    else if (time1->tm_min > time2->tm_min) { 
        printf("text2 is early\n");
    }
    // hour와 min이 같음
    else {
        printf("same time\n");
    }
}