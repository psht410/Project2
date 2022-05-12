#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

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
    char* filename1 = "text1";
    if(stat(filename1, &stat1) != 0){
	    switch(errno){
		    case ENOENT:
			    fprintf(stderr, "file1 not found. \n"); break;
		    case EINVAL:
			    fprintf(stderr, "invalid parameter to stat. \n"); break;
		    default:
			    fprintf(stderr, "unexpected error. \n");
	    }
	}

}
//파일 2의 정보를 가져오는 함수 작성
void filestat2(){
    char* filename2 = "text2";
    if(stat(filename2, &stat2) != 0){
	    switch(errno){
		    case ENOENT:
			    fprintf(stderr, "file1 not found. \n"); break;
		    case EINVAL:
			    fprintf(stderr, "invalid parameter to stat. \n"); break;
		    default:
			    fprintf(stderr, "unexpected error. \n");
	    }
    
    }
}
//파일 1의 시간 정보를 가져오는 함수 작성
void filetime1(){

	time1 = malloc(sizeof(struct tm));

	localtime_r(&stat1.st_mtime, time1);
}
//파일 2의 시간 정보를 가져오는 함수 작성
void filetime2(){

	time2 = malloc(sizeof(struct tm));
	localtime_r(&stat2.st_mtime, time2);

}
//두 개의 파일 크기를 비교하는 함수 작성
void sizecmp(){
    printf("size compare\n");
    int st_size1, st_size2;
    st_size1 = (int)stat1.st_size;
    st_size2 = (int)stat2.st_size;

    if (st_size1 == st_size2) {
        printf("sizes are equal\n");
    }
    else if (size_stat1 > size_stat2) {
        printf("text1 is bigger\n");
    }
    else {
        printf("text2 is bigger\n");
    }
    printf("\n");
}

//두 개의 파일 블락 수를 비교하는 함수 작성
void blockcmp(){
    printf("block compare\n");
    int st_block1, st_block2;
    st_block1 = (int)stat1.st_blocks;
    st_block2 = (int)stat2.st_blocks;

    if (st_block1 == st_block2) {
        printf("sizes are equal\n");
    }
    else if (st_block1 > st_block2) {
        printf("text1 is bigger\n");
    }
    else {
        printf("text2 is bigger\n");
    }
    printf("\n");
}

//두 개의 파일 수정 날짜를 비교하는 함수 작성
void datecmp() {
    int date_month_stat1, date_month_stat2;
    int date_day_stat1, date_day_stat2;

    date_month_stat1 = time1->tm_mon + 1;
    date_month_stat2 = time2->tm_mon + 1;

    date_day_stat1 = time1->tm_mday;
    date_day_stat2 = time2->tm_mday;

    printf("date compare\n");
    if (date_month_stat1 == date_month_stat2) {
        if (date_day_stat1 == date_day_stat2) {
            printf("same date\n");
        }
        else if (date_day_stat1 < date_day_stat2) {
            printf("text1 is early\n");
        }
        else {
            printf("text2 is early\n");
        }
    }
    else if (date_month_stat1 < date_month_stat2) {
        printf("text1 is early\n");
    }
    else {
        printf("text2 is early\n");
    }
    printf("\n");
}

//두 개의 파일 수정 시간을 비교하는 함수 작성
void timecmp() {
    int t1_hour = time1->tm_hour;
    int t2_hour = time2->tm_hour;
    int t1_min = time1->tm_min;
    int t2_min = time2->tm_min;

    printf("time compare\n");
    if (t1_hour > t2_hour) {
        printf("text2 is early\n");
    }
    else if (t1_hour < t2_hour) {
        printf("text1 is early\n");
    }
    else {
        if (t1_min > t2_min) {
            printf("text2 is early\n");
        }
        else if (t1_min < t2_min) {
            printf("text1 is early\n");
        }
        else {
            printf("same time\n");
        }
    }
    printf("\n");
}
