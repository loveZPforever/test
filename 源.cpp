/*编写程序，实现对比赛评委分数的录入、计算平均分、显示所有选手成绩、删除无效选手成绩、显示选手排名次序。
　课程设计要求：
1．程序运行过程中要有菜单提示，菜单如下：
* 1.输入分数
* 2.计算平均分
* 3.显示选手最后得分
* 4.删除无效选手成绩
* 5.显示选手排名次序
* 6.退出系统*
2.“输入分数”：输入每一个选手（10个选手）7个评委给出的成绩（10分制）；
3.“计算平均分”：去掉最高分和最低分，计算选手最后得分（平均分）；
3.“显示选手最后得分”：输出每个选手序号、姓名和最后得分信息；
4.“删除无效选手成绩”：删除指定序号的选手成绩（如平均分低于6分或有评委给出0分等条件）；
5.“显示选手排名次序”；将成绩按从高到底的顺序显示，显示时包含选手序号、姓名。
6.“退出系统”：结束程序运行。*/
#include<iostream>
using namespace std;
#include<string>
struct player {//选手的结构体
	int oderNumber;//序号
	string name;
	int score[7];
	int avgScore=0;//初始化选手的平均分
};
//给选手打分
void grade(player* p, int len) {
	for (int i = 0; i < len; i++)
	{
		p[i].oderNumber = i + 1;
	}
	for (int i = 0; i < len; i++)
	{
		cout << "请输入第" << p[i].oderNumber << "位选手的名字：" << endl;
		cin >> p[i].name;
		for (int j = 0; j < 7; j++)
		{
			cout << "请第" << j + 1 << "位评委给第" << p[i].oderNumber << "位选手打分：" << endl;
			cin >> p[i].score[j];
		}
	}
}
//打印输出选手和选手的得分
void printScore(player* p, int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "第" << p[i].oderNumber << "位选手的名字为：" << p[i].name << endl;//打印选手的名字
		cout << "第" << p[i].oderNumber << "位选手获得的得分为：";
		for (int j = 0; j < sizeof(p[i].score)/sizeof(p[i].score[0]); j++)
		{
			cout << p[i].score[j]<<"\t";//打印每位评委的评分
		}
		cout << endl;//换行
	}
}
//将选手的分数排序
void scoreSort(player* p, int len) {
	int temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < sizeof(p[i].score)/sizeof(p[i].score[0]); j++)
		{
			for (int n = 0; n < sizeof(p[i].score) / sizeof(p[i].score[0])- j-1; n++)
			{
				if (p[i].score[n] < p[i].score[n + 1])
				{
					temp = p[i].score[n];
					p[i].score[n] = p[i].score[n + 1];
					p[i].score[n + 1] = temp;
				}
			}
		}
	}
}
//删除有0分的选手
void deletePlayer1(player* p, int* len) {
	for (int i = 0; i < *len; i++)
	{
		for (int j = 0; j < sizeof(p[i].score)/sizeof(p[i].score[0]); j++)
		{
			if (p[i].score[j]==0)
			{
				for (int n = i; n < *len-1; n++)
				{
					p[n] = p[n + 1];
				}
				--i;//由于删除了结构体数组的节点，所以i必须自减1才能完全遍历所有的节点
				--* len;
				break;
			}
		}
	}
}
//计算选手的平均分,并且用结构体的avgScore记录平均分
void avg_Score(player *p,int len) {
	for (int i = 0; i < len; i++)
	{
		int sum = 0;
		for (int j = 1;  j < sizeof(p[i].score) / sizeof(p[i].score[0])-1; j++)
		{
			sum += p[i].score[j];
		}
		p[i].avgScore = sum / (sizeof(p[i].score) / sizeof(p[i].score[0]) - 2);
	}
}
//删除平均分低于6分的选手
void deletePlayer2(player* p, int* len) {
	for (int i = 0; i < *len; i++)
	{
		for (int j = 0; j < sizeof(p[i].score) / sizeof(p[i].score[0]); j++)
		{
			if (p[i].avgScore <6)
			{
				for (int n = i; n < *len - 1; n++)
				{
					p[n] = p[n + 1];
				}
				--i;//由于删除了结构体数组的节点，所以i必须自减1才能完全遍历所有的节点
				--* len;
				break;
			}
		}
	}
}
//将选手根据平均分进行排名
void sortPlayer(player* p, int len) {
	player temp;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len-i-1; j++)
		{
			if (p[j].avgScore<p[j+1].avgScore)
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}
//打印选手序号和姓名和平均分
void printPlayer(player* p, int len) {
	cout << "序号\t姓名\t平均分" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << p[i].oderNumber << "\t" << p[i].name << "\t" << p[i].avgScore << endl;
	}
}

int main() {
	player playerArray[10];//创建选手的数组
	int length = sizeof(playerArray) / sizeof(playerArray[0]);
	grade(playerArray, length);//打分
	scoreSort(playerArray, length);//将选手的评分排序
	deletePlayer1(playerArray, &length);//删除0分选手
	//cout << length << endl;
	//printScore(playerArray, length);//打印测试
	avg_Score(playerArray, length);
	deletePlayer2(playerArray, &length);
	sortPlayer(playerArray, length);
	printPlayer(playerArray, length);
	system("pause");
	return 0;
}