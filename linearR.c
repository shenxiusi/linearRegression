// 求线性回归方程：Y = a + bx
// dada[rows*2]数组：X, Y；rows：数据行数；a, b：返回回归系数
// SquarePoor[4]：返回方差分析指标: 回归平方和，剩余平方和，回归平方差，剩余平方差
// 返回值：0求解成功，-1错误

#include<math.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


int LinearRegression(double *data, int rows, double *a, double *b, double *SquarePoor)
{
    int m;
    double *p, Lxx = 0.0, Lxy = 0.0, xa = 0.0, ya = 0.0;
    if (data == 0 || a == 0 || b == 0 || rows < 1)
        return -1;
    for (p = data, m = 0; m < rows; m ++)
    {
        xa += *p ++;
        ya += *p ++;
    }
    xa /= rows;                                     // X平均值
    ya /= rows;                                     // Y平均值
    for (p = data, m = 0; m < rows; m ++, p += 2)
    {
        Lxx += ((*p - xa) * (*p - xa));             // Lxx = Sum((X - Xa)平方)
        Lxy += ((*p - xa) * (*(p + 1) - ya));       // Lxy = Sum((X - Xa)(Y - Ya))
    }
    *b = Lxy / Lxx;                                 // b = Lxy / Lxx
    *a = ya - *b * xa;                              // a = Ya - b*Xa
    if (SquarePoor == 0)
        return 0;
    // 方差分析
    SquarePoor[0] = SquarePoor[1] = 0.0;
    for (p = data, m = 0; m < rows; m ++, p ++)
    {
        Lxy = *a + *b * *p ++;
        SquarePoor[0] += ((Lxy - ya) * (Lxy - ya)); // U(回归平方和)
        SquarePoor[1] += ((*p - Lxy) * (*p - Lxy)); // Q(剩余平方和)
    }
    SquarePoor[2] = SquarePoor[0];                  // 回归方差
    SquarePoor[3] = SquarePoor[1] / (rows - 2);     // 剩余方差
    return 0;
}

double data1[12][2] = {
//    X      Y
    {187.1, 25.4},
    {179.5, 22.8},
    {157.0, 20.6},
    {197.0, 21.8},
    {239.4, 32.4},
    {217.8, 24.4},
    {227.1, 29.3},
    {233.4, 27.9},
    {242.0, 27.8},
    {251.9, 34.2},
    {230.0, 29.2},
    {271.8, 30.0}
};
double data2[100][2] = {};

void Display(double *dat, double *Answer, double *SquarePoor, int rows, int cols)
{
    double v, *p;
    int i, j;
    printf("回归方程式:    Y = %.5lf", Answer[0]);
    for (i = 1; i < cols; i ++)
        printf(" + %.5lf*X%d\n", Answer[i], i);
    printf(" \n");
    printf("回归显著性检验: \n");
    printf("回归平方和：%12.4lf  回归方差：%12.4lf \n", SquarePoor[0], SquarePoor[2]);
    printf("剩余平方和：%12.4lf  剩余方差：%12.4lf \n", SquarePoor[1], SquarePoor[3]);
    printf("离差平方和：%12.4lf  标准误差：%12.4lf \n", SquarePoor[0] + SquarePoor[1], sqrt(SquarePoor[3]));
    printf("F   检  验：%12.4lf  相关系数：%12.4lf \n", SquarePoor[2] /SquarePoor[3],
           sqrt(SquarePoor[0] / (SquarePoor[0] + SquarePoor[1])));
    printf("剩余分析: \n");
    printf("      观察值      估计值      剩余值    剩余平方 \n");
    for (i = 0, p = dat; i < rows; i ++, p ++)
    {
        v = Answer[0];
        for (j = 1; j < cols; j ++, p ++)
            v += *p * Answer[j];
        printf("%12.2lf%12.2lf%12.2lf%12.2lf \n", *p, v, *p - v, (*p - v) * (*p - v));
    }
    system("pause");
}
char* readline(FILE* f)
{
    char* line = (char*) calloc(1, sizeof(char) );
    char c;
    int len = 0;
    //printf("Now in fuction readline()\n");
   
    while ( (c = fgetc(f) ) != EOF && c != '\n')
    {
        line = (char*) realloc(line, sizeof(char) * (len + 2) );
        //printf("now line is %s\n",line);
        line[len++] = c;
        line[len] = '\0';
    }
    //printf("c == %d  len == %d\n", c, len);

    return line;
}
void calculate(char *line, int no)
{
   // printf("in calu, input no = %d\n", no);
    char *tmp = strsep(&line,"\t");
    int count = 0;
    //printf("in calu, tmp = %s\n", tmp);    
    while(tmp&&count<3)  
    {  
        if(count == 0)
        {
          count++;
          tmp = strsep(&line, "\t");
          //printf("in cal, tmp1 = %s\n",tmp);
        }
        if(count == 1)
        {
          data2[no][0] = strtod(tmp,NULL);
          count++;
          //printf("data2[%d][0] = %.10g\n",no, data2[no][0]);
          tmp = strsep(&line, "\t");
        }
        if(count == 2)
        {
          data2[no][1] = strtod(tmp,NULL);
          count++;
          //printf("data2[%d][1] = %.10g\n",no, data2[no][1]);
        }
    }
}
int getNextId(char *line)
{
    //printf("in getN, line content is %s\n", line);
    int i = 0;
    char tmp[6];
    for(;i<6;i++)
      tmp[i] = line[i];
    int ID;
    ID = atoi(tmp);
    //printf("in getNextId, ID = %d\n", ID);
    return ID;   
}

int main()
{   
    //Parameters init and open the data file "28.txt", including memery set
    double Answer[2], SquarePoor[4];
    FILE *fp = NULL;
    char *fileName = "28.txt";
    fp = fopen(fileName,"r");
    if(NULL == fp)
    {
        printf("file open failed!\n");
        exit(1);
    }
    int isFinished = 0;
    int oldId = 0;
    int newId = 0;
    int no = 0;
    int i = 0;
    for(;i<100;i++)
    {
        data2[i][1] = 0;
        data2[i][2] = 0;
    }
    
    //Read the data file line by line and store each stock's data in to data2[100][2]
    char* line = readline(fp);
    printf("line in main is %s; no = %d\n",line,no);
    newId = getNextId(line);
    oldId = newId;
    calculate(line,no);
    no++;

    while(!feof(fp))
    {
      char* line = readline(fp);
      printf("line in main is %s; no = %d; len is %d\n",line,no,(int)strlen(line));
      if(0 == (int)strlen(line))
        printf("holly shit!\n");
      newId = getNextId(line);
      if(oldId == newId)
      {
        calculate(line,no);
        no++;
      }
      else
      {
        //Below function actually does the linear regression work
        if (LinearRegression((double*)data2, no, &Answer[0], &Answer[1], SquarePoor) == 0)
          Display((double*)data2, Answer, SquarePoor, no, 2);
        for(i = 0;i < 100;i++)
        {
            data2[i][1] = 0;
            data2[i][2] = 0;
        }
        oldId = newId;
        no = 0;
        calculate(line,no);
        no++;
      }
    }
    fclose(fp);
    return 0;
}
