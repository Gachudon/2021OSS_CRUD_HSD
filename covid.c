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
    printf("0. 종료\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addCovid(covid* c)
{
    printf("지역이름은? ");
    scanf("%s", c->name);
    printf("확진자 수는? ");
    scanf("%d", &c->confirm);
    printf("마지막 확진자 날짜는(형식: yyyymmdd)? ");
    scanf("%d", &c->date);
    printf("완치자 수는? ");
    scanf("%d", &c->healer);
    return 1;
}

void readCovid(covid* c)
{
    printf("%s %5d %08d %5d\n", c->name, c->confirm, c->date, c->healer);
}

void listCovid(covid** c, int count)
{
    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i < count; i++)
    {
        if(c[i] == NULL) continue;
        printf("%2d.",i+1);
        readCovid(c[i]);
    }
}

int selectDataNo(covid** c, int count)
{
    int no;
    listCovid(c, count);
    printf("번호는 (0:취소)? ");
    scanf("%d%*c",&no);
    if(no == 0)
    {
        printf("=> 취소됨!\n");
        return -1;
    }
    else
    {
        return no-1;
    }
}

int updateCovid(covid** c, int count)
{
    int no = selectDataNo(c, count);
    if(no == -1) return 0;
    else
    {
        printf("지역이름은? ");
        scanf("%s", c[no]->name);
        printf("확진자 수는? ");
        scanf("%d", &c[no]->confirm);
        printf("마지막 확진자 날짜는(형식: yyyymmdd)? ");
        scanf("%d", &c[no]->date);
        printf("완치자 수는? ");
        scanf("%d", &c[no]->healer);
        printf("=> 수정 성공!\n");
        return 1;
    }
}

int deleteCovid(covid** c, int count)
{
    int no = selectDataNo(c, count);
    if(no == -1) return 0;
    else
    {
        free(c[no]);
        c[no] = NULL;
        return 1;
    }
}