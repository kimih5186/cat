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

    //��Ʈ��
    printf("****�߿��̿� ����****\n\n");
    printf("@@@���⿡ ascii art �׸��� @@@\n\n");
    printf("�߿����� �̸��� �����ּ���: �˶�\n");
    printf("�߿����� �̸��� �˶��Դϴ�.\n");

    printf("        /��_/��\n");
    printf(" /��   / o  o ��  \n");
    printf("//���� ��~(*)~/ \n");
    printf("   ��/    ^ /\n");
    printf("     |  ��|| ||\n");
    printf("     ��  '|| ||\n");
    printf("       ��)()-())\n");

    Sleep(5000);
    system("cls");