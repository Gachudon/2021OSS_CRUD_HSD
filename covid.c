#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "covid.h"

int selectMenu()
{
    int menu;
    printf("\n***covid-19***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 저장\n");
    printf("6. 지역이름 검색\n");
    printf("7. 확진자 수 검색\n");
    printf("8. 날짜 검색\n");
    printf("9. 완치자 수 검색\n");
    printf("0. 종료");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addCovid(covid* covid)
{
    covid = malloc(sizeof(covid));
    printf("지역이름은? ");
    scanf("%s", covid->name);
    printf("확진자 수는? ");
    scanf("%d", &covid->confirm);
    printf("마지막 확진자 날짜는(형식: yyyymmdd)? ");
    scanf("%d", &covid->date);
    printf("완치자 수는? ");
    scanf("%d", &covid->healer);
    return 1;
}

void readCovid(covid* covid)
{
    printf("%s %5d %08d %5d\n", covid->name, covid->confirm, covid->date, covid->healer);
}

void listCovid(covid** covid, int count)
{
    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i < count; i++)
    {
        if(covid[i] == NULL) continue;
        printf("%2d.",i+1);
        readCovid(covid[i]);
    }
}