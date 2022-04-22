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
    G.vexs[0] = "图书馆";
    G.vexs[1] = "教学楼";
    G.vexs[2] = "北生活区";
    G.vexs[3] = "南生活区";
    G.vexs[4] = "正门";
    G.vexs[5] = "体育馆";
    G.vexs[6] = "艺术馆";
    G.vexs[7] = "机械馆";
    G.vexs[8] = "逸夫馆";
    G.vexs[9] = "经管楼";
    G.vexs[10] = "行政楼";
    G.vexs[11] = "宇航馆";
    G.vexs[12] = "北区食堂";
    G.vexs[13] = "南区食堂";
    G.vexs[14] = "青阳湖";
    G.vexs[15] = "南门";
    G.vexs[16] = "蓝天剧场";
    G.vexs[17] = "大学生活动中心";
    G.vexs[18] = "航空研究院";
    G.vexs[19] = "技术研究中心";
    G.vexs[20] = "重点实验楼";
    G.vexs[21] = "操场";
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
    cout << "1.图书馆 2.教学楼 3.北生活区 4.南生活区 5.正门" << endl;
    cout << "6.体育馆 7.艺术馆 8.机械馆 9.逸夫馆 10.经管楼" << endl;
    cout << "11.行政楼 12.宇航馆 13.北区食堂 14.南区食堂 15.青阳湖" << endl;
    cout << "16.南门 17.蓝天剧场 18.大学生活动中心 19.技术研究中心 20.技术研究中心" << endl;
    cout << "21.重点实验楼 22.操场" << endl;
    cout << "输入起点的序号" << endl;
    cin >> a;
    if(a> G.vexnum||a<=0)
    {
        cout << "输入起点错误";
        return 0;
    }  
    cout << "输入终点的序号" << endl;
    cin >> b;
    if (b > G.vexnum || b <= 0)
    {
        cout << "输入终点错误" << endl;
        return 0;
    }
    m = a - 1;
    n = b - 1;
    cout << "最短时间：" << shortPath[m][n] << "分" << endl;
    cout << "路径为：" << G.vexs[m];
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
    cout << "|                      艺术馆       体育馆                 北生活区              技术研究中心       重点实验楼  |" << endl;
    cout << "|                                                      操场                                           航空研究院|" << endl;
    cout << "|                机械馆                                          北食堂                                         |" << endl;
    cout << "|逸夫馆                   图书馆                                                                                |" << endl;
    cout << "|                                                青阳湖    大学生活动中心                                       |" << endl;
    cout << "|                                                              蓝天剧场                                         |" << endl;
    cout << "|      经管楼   宇航馆                                                                                          |" << endl;
    cout << "|            行政楼                     教学楼                                                                  |" << endl;
    cout << "|                                                                                                               |" << endl;
    cout << "|                                                                               南生活区                        |" << endl;
    cout << "|                                                                 南食堂                                        |" << endl;
    cout << "|                                                                                                               |" << endl;
    cout << "|正门                                                                  南门                                     |" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
}

void Gui()
{
    system("color f0");
    char a;
    cout << "\t\t\t┌--------------------------------┐" << endl;
    cout << "\t\t\t│                                │" << endl;
    cout << "\t\t\t│   欢迎使用沈航校园导航系统     │" << endl;
    cout << "\t\t\t│                                │" << endl;
    cout << "\t\t\t│--------------------------------│" << endl;
    cout << "\t\t\t│      1. 查看校园全貌           │" << endl;
    cout << "\t\t\t│      2. 计算最短时间           │" << endl;
    cout << "\t\t\t│      3. 退出导航系统           │" << endl;
    cout << "\t\t\t└--------------------------------┘" << endl;
    while (true) {
        cout << "\t\t\t输入要操作的序号(1-3):";
        cin >> a;
        (int)a;
        if (a >'0' && a <= '3')
            switch (a)
            {
            case '1': scence(); break;
            case '2': math(); break;
            case '3': cout << "\t\t\t感谢您的使用！"; exit(0); break;
            }
        else cout << "\t\t\t请输入1-3!!" << endl;
    }
}

int main()
{
    Gui();
}