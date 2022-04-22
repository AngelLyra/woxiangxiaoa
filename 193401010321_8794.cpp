#include<iostream>
#include<stdlib.h> 
#include<stdlib.h>
using namespace std;
#define MaxInt 32767 
#define MaxNum 100  
typedef int status;
typedef string VerTexType; 
typedef int ArcType; 
typedef struct
{
    VerTexType vexs[MaxNum];  
    ArcType arcs[MaxNum][MaxNum];  
    int vexnum, arcnum;
    char name[MaxNum];
}AMGraph;

status CreateMap(AMGraph& G)
{
    G.vexnum = 22;
    G.arcnum = 42;
    G.vexs[0] = "ͼ���";
    G.vexs[1] = "��ѧ¥";
    G.vexs[2] = "��������";
    G.vexs[3] = "��������";
    G.vexs[4] = "����";
    G.vexs[5] = "������";
    G.vexs[6] = "������";
    G.vexs[7] = "��е��";
    G.vexs[8] = "�ݷ��";
    G.vexs[9] = "����¥";
    G.vexs[10] = "����¥";
    G.vexs[11] = "���";
    G.vexs[12] = "����ʳ��";
    G.vexs[13] = "����ʳ��";
    G.vexs[14] = "������";
    G.vexs[15] = "����";
    G.vexs[16] = "����糡";
    G.vexs[17] = "��ѧ�������";
    G.vexs[18] = "�����о�Ժ";
    G.vexs[19] = "�����о�����";
    G.vexs[20] = "�ص�ʵ��¥";
    G.vexs[21] = "�ٳ�";
    for (int i = 0; i < MaxNum; i++)
    {
        for (int j = 0; j < MaxNum; j++)
        {
            G.arcs[i][j] = MaxInt;
        }
    }
    G.arcs[5][6] = G.arcs[6][5] = 2;
    G.arcs[2][5] = G.arcs[5][2] = 5;
    G.arcs[2][19] = G.arcs[19][2] = 5;
    G.arcs[19][20] = G.arcs[20][19] = 3;
    G.arcs[14][17] = G.arcs[17][14] = 2;
    G.arcs[9][11] = G.arcs[11][9] = 1;
    G.arcs[10][1] = G.arcs[1][10] = 7;
    G.arcs[6][7] = G.arcs[7][6] = 2;
    G.arcs[7][0] = G.arcs[0][7] = 3;
    G.arcs[5][0] = G.arcs[0][5] = 4;
    G.arcs[5][21] = G.arcs[21][5] = 5;
    G.arcs[2][21] = G.arcs[21][2] = 1;
    G.arcs[2][12] = G.arcs[12][2] = 2;
    G.arcs[20][18] = G.arcs[18][20] = 1;
    G.arcs[7][8] = G.arcs[8][7] = 4;
    G.arcs[7][11] = G.arcs[11][7] = 5;
    G.arcs[0][6] = G.arcs[6][0] = 3;
    G.arcs[0][14] = G.arcs[14][0] = 8;
    G.arcs[0][11] = G.arcs[11][0] = 5;
    G.arcs[0][1] = G.arcs[1][0] = 7;
    G.arcs[21][12] = G.arcs[12][21] = 2;
    G.arcs[21][14] = G.arcs[14][21] = 3;
    G.arcs[12][19] = G.arcs[19][12] = 5;
    G.arcs[12][17] = G.arcs[17][12] = 2;
    G.arcs[12][14] = G.arcs[14][12] = 3;
    G.arcs[8][9] = G.arcs[9][8] = 3;
    G.arcs[14][1] = G.arcs[1][14] = 4;
    G.arcs[16][1] = G.arcs[1][16] = 5;
    G.arcs[16][13] = G.arcs[13][16] = 6;
    G.arcs[16][3] = G.arcs[3][16] = 6;
    G.arcs[9][10] = G.arcs[10][9] = 1;
    G.arcs[10][11] = G.arcs[11][10] = 1;
    G.arcs[1][11] = G.arcs[11][1] = 8;
    G.arcs[1][10] = G.arcs[10][1] = 8;
    G.arcs[1][13] = G.arcs[13][1] = 8;
    G.arcs[1][3] = G.arcs[3][1] = 10;
    G.arcs[1][14] = G.arcs[14][1] = 3;
    G.arcs[13][3] = G.arcs[3][13] = 2;
    G.arcs[13][15] = G.arcs[15][13] = 2;
    G.arcs[3][15] = G.arcs[15][3] = 3; 
    G.arcs[4][10] = G.arcs[10][4] = 6;
    return 1;
}
int shortPath[MaxNum][MaxNum];
int Path[MaxNum][MaxNum];
void ShortestPath_Floyd(AMGraph G)
{
    int i, j, k;
    for (i = 0; i < G.vexnum; i++)
    {
        for (j = 0; j < G.vexnum; j++)
        {
            shortPath[i][j] = G.arcs[i][j];
            if (shortPath[i][j] < MaxInt && i != j)
                Path[i][j] = j;
            else Path[i][j] = -1;
        }
    }
    for (k = 0; k < G.vexnum; k++) 
    {
        for (i = 0; i < G.vexnum; i++) 
        {
            for (j = 0; j < G.vexnum; j++)
            {
                if (shortPath[i][k] + shortPath[k][j] < shortPath[i][j])
                {
                    shortPath[i][j] = shortPath[i][k] + shortPath[k][j];
                    Path[i][j] = Path[i][k];
                }
            }
        }
    }
}
int math()
{
    int a, b, i, j, k, m, n;
    AMGraph G;
    CreateMap(G);
    ShortestPath_Floyd(G);
    cout << "1.ͼ��� 2.��ѧ¥ 3.�������� 4.�������� 5.����" << endl;
    cout << "6.������ 7.������ 8.��е�� 9.�ݷ�� 10.����¥" << endl;
    cout << "11.����¥ 12.��� 13.����ʳ�� 14.����ʳ�� 15.������" << endl;
    cout << "16.���� 17.����糡 18.��ѧ������� 19.�����о����� 20.�����о�����" << endl;
    cout << "21.�ص�ʵ��¥ 22.�ٳ�" << endl;
    cout << "�����������" << endl;
    cin >> a;
    if(a> G.vexnum||a<=0)
    {
        cout << "����������";
        return 0;
    }  
    cout << "�����յ�����" << endl;
    cin >> b;
    if (b > G.vexnum || b <= 0)
    {
        cout << "�����յ����" << endl;
        return 0;
    }
    m = a - 1;
    n = b - 1;
    cout << "���ʱ�䣺" << shortPath[m][n] << "��" << endl;
    cout << "·��Ϊ��" << G.vexs[m];
    k = Path[m][n];
    while (k != n)
    {
        cout << " -> " << G.vexs[k];
        k = Path[k][n];
    }
    cout << " -> " << G.vexs[n] << endl;
    return 1;
}
void scence()
{
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|                      ������       ������                 ��������              �����о�����       �ص�ʵ��¥  |" << endl;
    cout << "|                                                      �ٳ�                                           �����о�Ժ|" << endl;
    cout << "|                ��е��                                          ��ʳ��                                         |" << endl;
    cout << "|�ݷ��                   ͼ���                                                                                |" << endl;
    cout << "|                                                ������    ��ѧ�������                                       |" << endl;
    cout << "|                                                              ����糡                                         |" << endl;
    cout << "|      ����¥   ���                                                                                          |" << endl;
    cout << "|            ����¥                     ��ѧ¥                                                                  |" << endl;
    cout << "|                                                                                                               |" << endl;
    cout << "|                                                                               ��������                        |" << endl;
    cout << "|                                                                 ��ʳ��                                        |" << endl;
    cout << "|                                                                                                               |" << endl;
    cout << "|����                                                                  ����                                     |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void Gui()
{
    system("color f0");
    char a;
    cout << "\t\t\t��--------------------------------��" << endl;
    cout << "\t\t\t��                                ��" << endl;
    cout << "\t\t\t��   ��ӭʹ����У԰����ϵͳ     ��" << endl;
    cout << "\t\t\t��                                ��" << endl;
    cout << "\t\t\t��--------------------------------��" << endl;
    cout << "\t\t\t��      1. �鿴У԰ȫò           ��" << endl;
    cout << "\t\t\t��      2. �������ʱ��           ��" << endl;
    cout << "\t\t\t��      3. �˳�����ϵͳ           ��" << endl;
    cout << "\t\t\t��--------------------------------��" << endl;
    while (true) {
        cout << "\t\t\t����Ҫ���������(1-3):";
        cin >> a;
        (int)a;
        if (a >'0' && a <= '3')
            switch (a)
            {
            case '1': scence(); break;
            case '2': math(); break;
            case '3': cout << "\t\t\t��л����ʹ�ã�"; exit(0); break;
            }
        else cout << "\t\t\t������1-3!!" << endl;
    }
}

int main()
{
    Gui();
}