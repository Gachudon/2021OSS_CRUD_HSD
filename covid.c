#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "covid.h"

int selectMenu()
{
    int menu;
    printf("\n***covid-19***\n");
    printf("1. ��ȸ\n");
    printf("2. �߰�\n");
    printf("3. ����\n");
    printf("4. ����\n");
    printf("5. ����\n");
    printf("6. �����̸� �˻�\n");
    printf("7. Ȯ���� �� �˻�\n");
    printf("8. ��¥�˻�\n");
    printf("9. ��ġ�� �� �˻�\n");
    printf("=> ���ϴ� �޴���? ");
    scanf("%d", &menu);
}

int addCovid