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
    printf("8. 날짜검색\n");
    printf("9. 완치자 수 검색\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
}

int addCovid