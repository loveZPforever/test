/*��д����ʵ�ֶԱ�����ί������¼�롢����ƽ���֡���ʾ����ѡ�ֳɼ���ɾ����Чѡ�ֳɼ�����ʾѡ����������
���γ����Ҫ��
1���������й�����Ҫ�в˵���ʾ���˵����£�
* 1.�������
* 2.����ƽ����
* 3.��ʾѡ�����÷�
* 4.ɾ����Чѡ�ֳɼ�
* 5.��ʾѡ����������
* 6.�˳�ϵͳ*
2.�����������������ÿһ��ѡ�֣�10��ѡ�֣�7����ί�����ĳɼ���10���ƣ���
3.������ƽ���֡���ȥ����߷ֺ���ͷ֣�����ѡ�����÷֣�ƽ���֣���
3.����ʾѡ�����÷֡������ÿ��ѡ����š����������÷���Ϣ��
4.��ɾ����Чѡ�ֳɼ�����ɾ��ָ����ŵ�ѡ�ֳɼ�����ƽ���ֵ���6�ֻ�����ί����0�ֵ���������
5.����ʾѡ���������򡱣����ɼ����Ӹߵ��׵�˳����ʾ����ʾʱ����ѡ����š�������
6.���˳�ϵͳ���������������С�*/
#include<iostream>
using namespace std;
#include<string>
struct player {//ѡ�ֵĽṹ��
	int oderNumber;//���
	string name;
	int score[7];
	int avgScore=0;//��ʼ��ѡ�ֵ�ƽ����
};
//��ѡ�ִ��
void grade(player* p, int len) {
	for (int i = 0; i < len; i++)
	{
		p[i].oderNumber = i + 1;
	}
	for (int i = 0; i < len; i++)
	{
		cout << "�������" << p[i].oderNumber << "λѡ�ֵ����֣�" << endl;
		cin >> p[i].name;
		for (int j = 0; j < 7; j++)
		{
			cout << "���" << j + 1 << "λ��ί����" << p[i].oderNumber << "λѡ�ִ�֣�" << endl;
			cin >> p[i].score[j];
		}
	}
}
//��ӡ���ѡ�ֺ�ѡ�ֵĵ÷�
void printScore(player* p, int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "��" << p[i].oderNumber << "λѡ�ֵ�����Ϊ��" << p[i].name << endl;//��ӡѡ�ֵ�����
		cout << "��" << p[i].oderNumber << "λѡ�ֻ�õĵ÷�Ϊ��";
		for (int j = 0; j < sizeof(p[i].score)/sizeof(p[i].score[0]); j++)
		{
			cout << p[i].score[j]<<"\t";//��ӡÿλ��ί������
		}
		cout << endl;//����
	}
}
//��ѡ�ֵķ�������
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
//ɾ����0�ֵ�ѡ��
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
				--i;//����ɾ���˽ṹ������Ľڵ㣬����i�����Լ�1������ȫ�������еĽڵ�
				--* len;
				break;
			}
		}
	}
}
//����ѡ�ֵ�ƽ����,�����ýṹ���avgScore��¼ƽ����
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
//ɾ��ƽ���ֵ���6�ֵ�ѡ��
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
				--i;//����ɾ���˽ṹ������Ľڵ㣬����i�����Լ�1������ȫ�������еĽڵ�
				--* len;
				break;
			}
		}
	}
}
//��ѡ�ָ���ƽ���ֽ�������
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
//��ӡѡ����ź�������ƽ����
void printPlayer(player* p, int len) {
	cout << "���\t����\tƽ����" << endl;
	for (int i = 0; i < len; i++)
	{
		cout << p[i].oderNumber << "\t" << p[i].name << "\t" << p[i].avgScore << endl;
	}
}

int main() {
	player playerArray[10];//����ѡ�ֵ�����
	int length = sizeof(playerArray) / sizeof(playerArray[0]);
	grade(playerArray, length);//���
	scoreSort(playerArray, length);//��ѡ�ֵ���������
	deletePlayer1(playerArray, &length);//ɾ��0��ѡ��
	//cout << length << endl;
	//printScore(playerArray, length);//��ӡ����
	avg_Score(playerArray, length);
	deletePlayer2(playerArray, &length);
	sortPlayer(playerArray, length);
	printPlayer(playerArray, length);
	system("pause");
	return 0;
}