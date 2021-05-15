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
    printf(" %8s %9d %14d %9d\n", c->name, c->confirm, c->date, c->healer);
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
    int isdel = 0;
    if(no == -1) return 0;
    else
    {
        printf("정말 삭제하시겠습니까(1: 실행)? ");
        scanf("%d", &isdel);
        if(isdel == 1)
        {
            free(c[no]);
            c[no] = NULL;
            printf("=> 삭제됨!\n");
            return 1;
        }
    }
    return 0;
}

void searchCovidByName(covid **c, int count){
    int scnt = 0;
    char search[20];

    printf("검색할 지역명은?");
    scanf("%s", search);

    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i <count; i++){
        if(c[i] == NULL)continue;
        if(strstr(c[i]->name, search)){
            printf("%2d", i+1);
            readCovid(c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchCovidByConfirm(covid **c, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 확진자 수는? (오차범위 500명)");
    scanf("%d", &search);

    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i <count; i++){
        if(c[i] == NULL)continue;
        if((c[i]->confirm<=(search+500))&&(c[i]->confirm>=(search-500))){
            printf("%2d", i+1);
            readCovid(c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchCovidByDate(covid **c, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 마지막 확진자 발생날짜는? (오차범위 1달)");
    scanf("%d", &search);

    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i <count; i++){
        if(c[i] == NULL)continue;
        if((c[i]->date<=(search+100))&&(c[i]->date>=(search-100))){
            printf("%2d", i+1);
            readCovid(c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

void searchCovidByHealer(covid **c, int count){
    int scnt = 0;
    int search = 0;

    printf("검색할 완치자 수는? (오차범위 500명)");
    scanf("%d", &search);

    printf("\nNo. 지역이름 확진자 수 마지막확진날짜 완치자 수\n");
    printf("============================================\n");
    for(int i = 0; i <count; i++){
        if(c[i] == NULL)continue;
        if((c[i]->healer<=(search+500))&&(c[i]->healer>=(search-500))){
            printf("%2d", i+1);
            readCovid(c[i]);
            scnt++;
        }
    }
    if(scnt == 0) printf("=> 검색된 데이터 없음!");
    printf("\n");
}

int loadData(covid **c){
    int count = 0,  i = 0;
    FILE *fp;
    fp = fopen("covid.txt", "rt");
    if(fp==NULL){
      printf("=>파일 없음\n");
      return 0;
    }
    else{
      for(; i<165; i++){
          fscanf(fp, "%s", c[i]->name);
          if(feof(fp))break;
          fscanf(fp, "%d", &c[i]->confirm);
          fscanf(fp, "%d", &c[i]->date);
          fscanf(fp, "%d", &c[i]->healer);
      }
    printf("=> 로딩 성공!\n");
    return i;
    }
    fclose(fp);
}

void saveData(covid **c, int count){
    FILE *fp;
    fp = fopen("covid.txt", "wt");

    for (int i = 0; i<count; i++){
        if(c[i] == NULL)continue;
        fprintf(fp, "%s %d %d %d\n", c[i]->name, c[i]->confirm, c[i]->date, c[i]->healer);
    }
    fclose(fp);
    printf("=> 저장됨!\n");
}
