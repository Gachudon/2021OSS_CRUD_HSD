typedef struct{
    char name[20];  // �����̸�
    int confirm;    // Ȯ���� ��
    int date;       // ������ Ȯ����¥ // format: yyyymmdd
    int healer;     // ��ġ�� ��
} covid;

int addCovid(covid*);       //������ �߰�
void readCovid(covid*);     //������ ��ȸ
int updateCovid(covid*);    //������ ����
int deleteCovid(covid*);    //������ ����