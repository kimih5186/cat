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

    //�������

    while (1) {

        printf("==================== �������===================\n");
        printf("������� ���� ����: %d��\n", soupCount);

        if (isFirst) {
            printf("������� ����(0~4):");
            scanf_s("%d", &x);

            while (x < 0 || x > 4) {
                printf(">>");
                scanf_s("%d", &x);
            }
            isFirst = 0;
        }
        else {
            printf("������� ����(0~4):%d\n", x);
        }

        switch (x) {
        case 0: printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf(" �������Ǳ� ����Դϴ�.\n"); break;
        case 2: printf(" �׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf(" ���� �������Դϴ�.\n"); break;
        }
        printf("==================================================\n\n");


        Sleep(3000);
        system("cls");



        // ��ȣ�ۿ�

        printf("���ȣ�ۿ����Ͻðڽ��ϱ�?   0. �ƹ��͵��������� 1. �ܾ��ֱ�\n>>");

        int y;
        scanf_s("%d", &y);

        while (y != 0 && y != 1) {
            printf(">>");
            scanf_s("%d", &y);
        }

        for (int i = 0; i < 1; i++) {
            if (y == 0) {
                printf("�ƹ��͵� �����ʽ��ϴ�.\n");
                printf("4/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
                printf("�ֻ����� �����ϴ�. �Ǹ���...\n");

                int r = rand() % 6 + 1;
                printf("%d��(��) ���Խ��ϴ�!\n", r);

                if (r <= 4) {
                    printf("ģ�е��� �������ϴ�\n");
                    if (x > 0) {
                        x--;
                    }
                }
                else {
                    printf("������ ģ�е��� �������� �ʾҽ��ϴ�\n");

                }
                printf("���� ģ�е�%d\n", x);
            }

        }


        if (y == 1) {
            printf("�˶����� ���� �ܾ��־����ϴ�.\n");
            printf("2/6�� Ȯ���� ģ�е��� �������ϴ�.\n");
            printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
            for (int i = 0; i < 1; i++) {
                int r = rand() % 6 + 1;
                printf("%d��(��) ���Խ��ϴ�!\n", r);

                if (r >= 5) {
                    if (x < 4) {
                        printf("ģ�е��� �������ϴ�.\n");
                        x++;
                    }
                }
                else {
                    printf("ģ�е��� �״���Դϴ�.\n");
                }
            }
            printf("���� ģ�е�%d\n", x);

        }
        Sleep(3000);
        system("cls");



        //�� �׸���
        printf("############\n");
        printf("#H       B#\n");
        printf("#");

        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == z)
                printf("C");
            else if (i == q && z != q)
                printf(".");
            else
                printf(" ");
        }
        printf("#\n############\n\n");

        Sleep(3000);
        system("cls");


        //�̵�,�ൿ

        printf("�˶� �̵�: ����� ģ���Ҽ��� ���� ������ �� Ȯ���� �������ϴ�.\n");
        printf("�ֻ��� ���� %d�̻��̸� ���� ������ �̵��մϴ�.\n", 6 - x);
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");


        int a = rand() % 6 + 1;
        printf("%d��(��) ���Խ��ϴ�!\n", a);


        if (a >= (6 - x) && z < BWL_POS) {
            q = z;
            z++;
            printf("���� ������ �����Դϴ�.\n\n");
        }
        else if (a < (6 - x) && z > HME_POS) {
            q = z;
            z--;
            printf("�� ������ �����Դϴ�.\n\n");
        }
        else {
            q = z;
        }
        if (z == HME_POS) {
            printf("�˶���(��) �ڽ��� ������ ������� �����ϴ�.\n\n");
        }

        if (z == BWL_POS) {
            int index = rand() % 3;
            printf("�˶��� ���� �����߽��ϴ�! ");
            if (index == 0) {
                printf("���ڼ����� ��������ϴ�!\n");
            }
            else if (index == 1) {
                printf("����̼����� ��������ϴ�!\n");
            }
            else {
                printf("����ݸ������� ��������ϴ�!\n");
            }
            soupCount++;
            printf("������� ���� ���� ����: %d��\n\n", soupCount);
        }


        printf("############\n");
        printf("#H        B#\n");
        printf("#");

        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == z)
                printf("C");
            else if (i == q && z != q)
                printf(".");
            else
                printf(" ");
        }
        printf("#\n############\n\n");





        Sleep(3000);
        system("cls");


        int intimacy = 2;
        int mood = 3;
        int cp = 0;
        int soupCount = 0;
        int hasToyMouse = 0, hasLaser = 0, hasScratcher = 0, hasTower = 0;
        int catPos = HME_POS;
        int prevPos = catPos;
        int turn = 0;
        int roll;
        int beforeMood = mood;
        int beforeIntimacy = intimacy;



        printf("==================== ������� ====================\n");
        printf("������� ���� ����: %d��\n", soupCount);
        printf("CP: %d ����Ʈ\n", cp);
        printf("�˶��� ���(0~3): %d\n", mood);
        switch (mood) {
        case 0: printf(" ����� �ſ� ���޴ϴ�.\n"); break;
        case 1: printf(" �ɽ����մϴ�.\n"); break;
        case 2: printf(" �Ļ��� �����ϴ�.\n"); break;
        case 3: printf(" ������ �θ��ϴ�.\n"); break;
        }



        printf("������� ����(0~4):%d\n", x);
        switch (x) {
        case 0: printf(" �翡 ���� ������ �Ⱦ��մϴ�.\n"); break;
        case 1: printf(" �������Ǳ� ����Դϴ�.\n"); break;
        case 2: printf(" �׷����� �� ���� �����Դϴ�.\n"); break;
        case 3: printf(" �Ǹ��� ����� ���� �ް� �ֽ��ϴ�.\n"); break;
        case 4: printf(" ���� �������Դϴ�.\n"); break;
        }
        printf("============================================\n\n");
        Sleep(5000);
        system("cls");

        // �� �׸���
        printf("############\n");
        printf("#H        B#\n");
        printf("#");
        for (int i = 1; i < ROOM_WIDTH - 1; i++) {
            if (i == catPos)
                printf("C");
            else if (i == prevPos && catPos != prevPos)
                printf(".");
            else
                printf(" ");
        }
        printf("#\n############\n\n");

        Sleep(5000);
        system("cls");


        // ��� ������
        printf("6~2: �ֻ��� ���� 4�����̸� �׳� ����� �������ϴ�.");

        int moodDice = rand() % 6 + 1;
        printf("�ֻ����� �����ϴ�. �Ǹ���...\n");
        printf("%d��(��) ���Խ��ϴ�!\n", moodDice);

        if (moodDice <= (6 - x)) {
            if (mood > 0) mood--;
            printf("�ƹ� ���� ���� ����� �������ϴ�. ����̴ϱ�?\n");
            printf("�˶��� ����� �������ϴ�.\n");
        }
        else {
            printf("�˶��� ����� �״���Դϴ�.\n");
        }

        Sleep(5000);
        system("cls");

        //�̵�
        prevPos = catPos;
        if (mood == 0 && catPos != HME_POS) {
            catPos--;
            printf("����� �ſ� ���� �˶��̴� ������ ���մϴ�.\n");
        }
        else if (mood == 1) {
            if (hasScratcher || hasTower) {
                catPos = (hasScratcher ? 2 : 3);
                printf("�˶��� �ɽ��ؼ� ��ũ��ó ������ �̵��մϴ�.\n");
            }
            else {
                printf("�� �Ÿ��� ��� ����� �ſ� �������ϴ�.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("�˶��� ������� �Ļ��� ���� �ֽ��ϴ�.\n");
        }
        else if (mood == 3 && catPos != BWL_POS) {
            catPos++;
            printf("�˶��� ������ �θ��� ������ ���鷯 ���ϴ�.\n");
        }
        Sleep(5000);
        system("cls");


        //�ൿ

        int prevMood = mood;

        if (catPos == HME_POS && prevPos == HME_POS && mood < 3) {
            mood++;
            printf("�˶��� ������ ���� ����� �������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (hasScratcher && catPos == 2 && mood < 3) {
            mood++;
            printf("�˶��� ��ũ��ó�� �ܰ� ����� ���������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (hasTower && catPos == 3) {
            int increase = (mood <= 1) ? 2 : 1;
            mood += increase;
            if (mood > 3) mood = 3;
            printf("�˶��� ĹŸ������ ��� ����� ���� ���������ϴ�: %d -> %d\n", prevMood, mood);
        }
        else if (catPos == BWL_POS) {
            char soups[3][20] = { "���ڼ���", "����̼���", "����ݸ�����" };
            int s = rand() % 3;
            printf("�˶��� %s�� ��������ϴ�!\n", soups[s]);
            soupCount++;
        }
        Sleep(5000);
        system("cls");
        
        
        //��ȣ�ۿ�
        printf("� ��ȣ�ۿ��� �Ͻðڽ��ϱ�?\n");
        printf(" 0. �ƹ��͵� ���� ����\n 1. �ܾ� �ֱ�");
        if (hasToyMouse && hasLaser) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n 3. ������ �����ͷ� ��� �ֱ�\n");
        }
        else if (hasToyMouse) {
            printf(" 2. �峭�� ��� ��� �ֱ�\n");
        }
        else if (hasLaser) {
            printf(" 2. ������ �����ͷ� ��� �ֱ�\n");
        }
        printf(">> ");





        return 0;
    } 