#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define VERSION "版本号：共享版\n发布时间：2018.5.24\n"

void randn(void);//产生随机答案 
void game(void);//游戏过程 
void menu(void);//菜单 
int Ans[4];//存放答案的数组 

int main(void) {
	printf("4A0B--猜数字小游戏\n");
	menu();
	printf("\n再见！欢迎下次再玩！");
	return 0;
}

void menu(void) {//菜单 
	printf("\n请输入选项前数字以开始，以回车键结束输入！\n");
	printf("1.开始游戏            2.游戏规则(建议阅读)\n");
	printf("3.作者信息            4.版本说明\n");
	int n = 0;
	printf("\n我选择: ");
	scanf("%d", &n);
	switch (n){
		case 1:
			game();
			break;
		case 2:
			printf("\n游戏规则:\n");
			printf("1.系统会随机产生4个不同的数（数从0-9中选择）。\n2.根据系统提示，您有10次机会推理出这四个数是什么。\n3.当您输入4个数后，系统会以*A*B的格式提示您。\n4.*代表个数，A代表数字和位置均正确，B代表数字正确但位置不正确。\n示例：假设随机数为2803，您猜测0123，系统会提示您1A2B。\n\n");
			printf("请继续输入选项前数字以开始！");
			menu();
			break;
		case 3:
			printf("\n作者信息:\n");
			printf("共享版\n\n");
			printf("请继续输入选项前数字以开始！");
			menu();
			break;
		case 4:
			printf("\n版本说明:\n");
			printf("%s\n\n", VERSION);
			printf("请继续输入选项前数字以开始！");
			menu();
			break;
		default:
			game();
			break;
	}
}

void randn(void) {//产生随机函数 
	int i;
	srand(time(NULL));//伪随机种子 
	while(1){
		for (i = 0; i <4; i++)
			Ans[i] = rand() % 10;
		if(Ans[0]!=Ans[1] && Ans[0]!= Ans[2] && Ans[0]!=Ans[3] && Ans[1]!=Ans[2] && Ans[1]!=Ans[3] && Ans[2]!=Ans[3])
			break;
	}
}

void game(void) {
	int i, j; 
	int N[4];//存放回答 
	int r;//用于检测用户输入是否合法 
	int A, B;//每次的结果 
	int q;//回答次数 
	randn();
	system("cls");//清屏 
	printf("游戏现在开始！\n");
	printf("请在输入4位不同的数字后，以回车键结束输入！\n\n");
	while (getchar() != '\n')
		continue;
	for (q = 1; q <= 10; q++){
		A = 0;
		B = 0;
		r = 1;
		printf("第%2d次机会\t\t>> ", q);
		for (i = 0; i < 4; i++){
			N[i] = -1;
			scanf("%1d", &N[i]);
		}
		while (getchar() != '\n')
			r = 0;
		for (i = 0; i < 4; i++)
			for (j = i + 1; j < 4; j++){
				if (N[i] < 0 || N[i] > 9 || N[i] == N[j])
					r = 0;
			}
		if (r == 0){
			printf("请输入4位不同的数字！\t  [错误]\n");
			q--;
		}
		else
			for (i = 0; i < 4; i++){
				if (N[i] == Ans[i])
					A++;
				for (j = 0; j < 4; j++){
					if (N[i] == Ans[j] && i != j)
						B++;
				}
			}
		if (r != 0)
			printf("\t\t\t  [%dA%dB]\n",A,B);
		printf("--------------------------------\n");
		if (A == 4){
			printf("恭喜您猜对了！您共用了%d次机会！\n", q);
			break;
		}
		if (q >= 10){
			printf("很遗憾！您的机会用完了！\n");
			printf("正确答案是%d%d%d%d!\n",Ans[0], Ans[1], Ans[2], Ans[3]);
			break;
		}
	}
	char c;
	printf("\n是否重新开始游戏？是：1；否：0；返回上级菜单：q\n");
	printf("我选择:");
	c=getchar();
	switch(c)
	{
		case '1':
			game();
			break;
		case '0':
			break;
		case 'q':
			menu();
			break;
		default:
			game();
			break;
	}
}
