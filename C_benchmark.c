#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int times = 100000000;
char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";


void main(){
	char rndword[10];
	int i;
	srand((unsigned)time(NULL));
	struct timeval myTime;
	struct tm *time_st;
	time_t st;
	//gettimeofday(&myTime, NULL);
	st = time(&myTime);
	time_st = localtime(&myTime.tv_sec);
    printf("start : %02d:%02d.%06d\n",
                time_st->tm_min,           // 分
                time_st->tm_sec,           // 秒
                myTime.tv_usec            // マイクロ秒
                );

    while(times != 0){
    	for(i=0;i<10;i++){
    		rndword[i] = chars[rand()%(sizeof(chars)-1)];
    	}
    	//printf(rndword);printf("\n");
    	times--;
    }


	struct tm *time_ed;
	time_t ed;
	//gettimeofday(&myTime, NULL);
	ed = time(&myTime);
	time_ed = localtime(&myTime.tv_sec);
    printf("end : %02d:%02d.%06d\n",
                time_ed->tm_min,           // 分
                time_ed->tm_sec,           // 秒
                myTime.tv_usec            // マイクロ秒
                );

    double from2k;
    from2k = difftime(ed, st);
    printf("%lf\n", from2k);
}