#include <stdio.h>
#include <stdlib.h>
#include <time.h>   
#include <windows.h> 

#define ROOM_WIDTH 12
#define HME_POS 1
#define BWL_POS (ROOM_WIDTH - 2)

int main(void) {
    srand(time(NULL));
    int x;
    int z = 1;
    int q = z;
    int soupCount = 0;
    int isFirst = 1;

    //인트로
    printf("****야옹이와 수프****\n\n");
    printf("@@@여기에 ascii art 그리기 @@@\n\n");
    printf("야옹이의 이름을 지어주세요: 쫀떡\n");
    printf("야옹이의 이름은 쫀떡입니다.\n");

    printf("        /＼_/＼\n");
    printf(" /＼   / o  o ＼  \n");
    printf("//＼＼ ＼~(*)~/ \n");
    printf("   ＼/    ^ /\n");
    printf("     |  ＼|| ||\n");
    printf("     ＼  '|| ||\n");
    printf("       ＼)()-())\n");

    Sleep(5000);
    system("cls");