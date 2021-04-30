#include <stdio.h>
#include <stdlib.h>
#include "covid.h"
#define SIZE 165

int main()
{
    covid* cRegion[SIZE];
    for(int i = 0; i< SIZE; i++) cRegion[i] = 0;
    int index = 0;
    int count = 0, menu;

    while(1)
    {
        menu = selectMenu();
        getchar();  //엔터키 버리기
        if(menu == 0) break;
        if(count == 0 && (menu == 1 || menu == 3 || menu == 4))
        {
            printf("데이터가 없습니다!\n");
            continue;
        }
        else if(menu == 1)
        {
            listCovid(cRegion, index);
        }
        else if(menu == 2){
            cRegion[index] = (covid*)malloc(sizeof(covid));
            count += addCovid(cRegion[index++]);
        }
        else if(menu == 3)
        {
            updateCovid(cRegion, index);
        }
        else if(menu == 4)
        {
            deleteCovid(cRegion,index);
        }
    }
    return 0;
}