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

    //상태출력

    while (1) {

        printf("==================== 현재상태===================\n");
        printf("현재까지 만든 수프: %d개\n", soupCount);

        if (isFirst) {
            printf("집사와의 관계(0~4):");
            scanf_s("%d", &x);

            while (x < 0 || x > 4) {
                printf(">>");
                scanf_s("%d", &x);
            }
            isFirst = 0;
        }
        else {
            printf("집사와의 관계(0~4):%d\n", x);
        }

        switch (x) {
        case 0: printf(" 곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf(" 간식자판기 취급입니다.\n"); break;
        case 2: printf(" 그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf(" 훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf(" 집사 껌딱지입니다.\n"); break;
        }
        printf("==================================================\n\n");


        Sleep(3000);
        system("cls");



        // 상호작용

        printf("어떤상호작용을하시겠습니까?   0. 아무것도하지않음 1. 긁어주기\n>>");

        int y;
        scanf_s("%d", &y);

        while (y != 0 && y != 1) {
            printf(">>");
            scanf_s("%d", &y);
        }

        for (int i = 0; i < 1; i++) {
            if (y == 0) {
                printf("아무것도 하지않습니다.\n");
                printf("4/6의 확률로 친밀도가 떨어집니다.\n");
                printf("주사위를 굴립니다. 또르륵...\n");

                int r = rand() % 6 + 1;
                printf("%d이(가) 나왔습니다!\n", r);

                if (r <= 4) {
                    printf("친밀도가 떨어집니다\n");
                    if (x > 0) {
                        x--;
                    }
                }
                else {
                    printf("다행히 친밀도가 떨어지지 않았습니다\n");

                }
                printf("현재 친밀도%d\n", x);
            }

        }


        if (y == 1) {
            printf("쫀떡이의 턱을 긁어주었습니다.\n");
            printf("2/6의 확률로 친밀도가 높아집니다.\n");
            printf("주사위를 굴립니다. 또르륵...\n");
            for (int i = 0; i < 1; i++) {
                int r = rand() % 6 + 1;
                printf("%d이(가) 나왔습니다!\n", r);

                if (r >= 5) {
                    if (x < 4) {
                        printf("친밀도가 높아집니다.\n");
                        x++;
                    }
                }
                else {
                    printf("친밀도는 그대로입니다.\n");
                }
            }
            printf("현재 친밀도%d\n", x);

        }
        Sleep(3000);
        system("cls");



        //방 그리기
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


        //이동,행동

        printf("쫀떡 이동: 집사와 친밀할수록 냄비 쪽으로 갈 확률히 높아집니다.\n");
        printf("주사위 눈이 %d이상이면 냄비 쪽으로 이동합니다.\n", 6 - x);
        printf("주사위를 굴립니다. 또르륵...\n");


        int a = rand() % 6 + 1;
        printf("%d이(가) 나왔습니다!\n", a);


        if (a >= (6 - x) && z < BWL_POS) {
            q = z;
            z++;
            printf("냄비 쪽으로 움직입니다.\n\n");
        }
        else if (a < (6 - x) && z > HME_POS) {
            q = z;
            z--;
            printf("집 쪽으로 움직입니다.\n\n");
        }
        else {
            q = z;
        }
        if (z == HME_POS) {
            printf("쫀떡은(는) 자신의 집에서 편안함을 느낍니다.\n\n");
        }

        if (z == BWL_POS) {
            int index = rand() % 3;
            printf("쫀떡이 냄비에 도착했습니다! ");
            if (index == 0) {
                printf("감자수프를 만들었습니다!\n");
            }
            else if (index == 1) {
                printf("양송이수프를 만들었습니다!\n");
            }
            else {
                printf("브로콜리수프를 만들었습니다!\n");
            }
            soupCount++;
            printf("현재까지 만든 수프 개수: %d개\n\n", soupCount);
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



        printf("==================== 현재상태 ====================\n");
        printf("현재까지 만든 수프: %d개\n", soupCount);
        printf("CP: %d 포인트\n", cp);
        printf("쫀떡이 기분(0~3): %d\n", mood);
        switch (mood) {
        case 0: printf(" 기분이 매우 나쁩니다.\n"); break;
        case 1: printf(" 심심해합니다.\n"); break;
        case 2: printf(" 식빵을 굽습니다.\n"); break;
        case 3: printf(" 골골송을 부릅니다.\n"); break;
        }



        printf("집사와의 관계(0~4):%d\n", x);
        switch (x) {
        case 0: printf(" 곁에 오는 것조차 싫어합니다.\n"); break;
        case 1: printf(" 간식자판기 취급입니다.\n"); break;
        case 2: printf(" 그럭저럭 쓸 만한 집사입니다.\n"); break;
        case 3: printf(" 훌륭한 집사로 인정 받고 있습니다.\n"); break;
        case 4: printf(" 집사 껌딱지입니다.\n"); break;
        }
        printf("============================================\n\n");
        Sleep(5000);
        system("cls");

        // 방 그리기
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


        // 기분 나빠짐
        printf("6~2: 주사위 눈이 4이하이면 그냥 기분이 나빠집니다.\n");

        int moodDice = rand() % 6 + 1;
        printf("주사위를 굴립니다. 또르륵...\n");
        printf("%d이(가) 나왔습니다!\n", moodDice);

        if (moodDice <= (6 - x)) {
            if (mood > 0) mood--;
            printf("아무 이유 없이 기분이 나빠집니다. 고양이니까?\n");
            printf("쫀떡의 기분이 나빠집니다.\n");
        }
        else {
            printf("쫀떡의 기분은 그대로입니다.\n");
        }

        Sleep(5000);
        system("cls");

        //이동
        prevPos = catPos;
        if (mood == 0 && catPos != HME_POS) {
            catPos--;
            printf("기분이 매우 나쁜 쫀떡이는 집으로 향합니다.\n");
        }
        else if (mood == 1) {
            if (hasScratcher || hasTower) {
                catPos = (hasScratcher ? 2 : 3);
                printf("쫀떡은 심심해서 스크래처 쪽으로 이동합니다.\n");
            }
            else {
                printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
                if (mood > 0) mood--;
            }
        }
        else if (mood == 2) {
            printf("쫀떡은 기분좋게 식빵을 굽고 있습니다.\n");
        }
        else if (mood == 3 && catPos != BWL_POS) {
            catPos++;
            printf("쫀떡은 골골송을 부르며 수프를 만들러 갑니다.\n");
        }
        Sleep(5000);
        system("cls");


        //행동

        int prevMood = mood;

        if (catPos == HME_POS && prevPos == HME_POS && mood < 3) {
            mood++;
            printf("쫀떡이 집에서 쉬며 기분이 좋아집니다: %d -> %d\n", prevMood, mood);
        }
        else if (hasScratcher && catPos == 2 && mood < 3) {
            mood++;
            printf("쫀떡이 스크래처를 긁고 기분이 좋아졌습니다: %d -> %d\n", prevMood, mood);
        }
        else if (hasTower && catPos == 3) {
            int increase = (mood <= 1) ? 2 : 1;
            mood += increase;
            if (mood > 3) mood = 3;
            printf("쫀떡이 캣타워에서 놀며 기분이 제법 좋아졌습니다: %d -> %d\n", prevMood, mood);
        }
        else if (catPos == BWL_POS) {
            char soups[3][20] = { "감자수프", "양송이수프", "브로콜리수프" };
            int s = rand() % 3;
            printf("쫀떡이 %s를 만들었습니다!\n", soups[s]);
            soupCount++;
        }
        Sleep(5000);
        system("cls");
        
        
        //상호작용
        printf("어떤 상호작용을 하시겠습니까?\n");
        printf(" 0. 아무것도 하지 않음\n 1. 긁어 주기\n");
        if (hasToyMouse && hasLaser) {
            printf(" 2. 장난감 쥐로 놀아 주기\n 3. 레이저 포인터로 놀아 주기\n");
        }
        else if (hasToyMouse) {
            printf(" 2. 장난감 쥐로 놀아 주기\n");
        }
        else if (hasLaser) {
            printf(" 2. 레이저 포인터로 놀아 주기\n");
        }
        printf(">> ");


        //상호작용 처리
        int act;
        scanf_s("%d", &act);
        roll = rand() % 6 + 1;

        switch (act) {
        case 0:
            if (mood > 0) mood--;
            printf("쫀떡의 기분이 나빠졌습니다: %d->%d\n", beforeMood, mood);
            if (roll <= 5 && intimacy > 0) {
                intimacy--;
                printf("집사와의 관계가 나빠집니다.\n");
            }
            break;

        case 1:
            printf("쫀떡의 기분은 그대로입니다: %d\n", mood);
            if (roll >= 5 && intimacy < 4) {
                intimacy++;
                printf("집사와의 관계가 좋아졌습니다.\n");
            }
            break;

        case 2:
            if (hasToyMouse) {
                printf("장난감 쥐로 쫀떡과 놀아 주었습니다.\n");
                if (mood < 3) mood++;
                printf("쫀떡의 기분이 조금 좋아졌습니다: %d->%d\n", beforeMood, mood);
                if (roll >= 4 && intimacy < 4) {
                    intimacy++;
                    printf("집사와의 관계가 좋아졌습니다.\n");
                }
            }
            break;

        case 3:
            if (hasLaser) {
                printf("레이저 포인터로 쫀떡과 신나게 놀아 주었습니다.\n");
                mood += 2;
                if (mood > 3) mood = 3;
                printf("쫀떡의 기분이 꽤 좋아졌습니다: %d->%d\n", beforeMood, mood);
                if (roll >= 2 && intimacy < 4) {
                    intimacy++;
                    printf("집사와의 관계가 좋아졌습니다.\n");
                }
            }
            break;

            Sleep(5000);
            system("cls");





        return 0;
    } 