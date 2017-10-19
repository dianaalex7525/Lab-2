#include<iostream>
using namespace std;
struct list
{
	int field; // ���� ������
	struct list *ptr; // ��������� �� ��������� �������
};
struct list * init(int a) // �- �������� ������� ����
{
	struct list *lst = new list;
	// ��������� ������ ��� ������ ������
	lst->field = a;
	lst->ptr = lst; // ��������� �� ��� �������� ����
	return(lst);
}

void listprint(list *lst)
{
	struct list *p;
	p = lst;
	do {
		std::cout << (p->field); // ����� �������� ���� p
		p = p->ptr; // ������� � ���������� ����
	} while (p != lst); // ������� ��������� ������
}
struct list* addelem(list *lst, int number)
{
	struct list *temp, *p;
	temp = new struct list;
	p = lst->ptr; // ���������� ��������� �� ��������� �������
	lst->ptr = temp; // ���������� ���� ��������� �� �����������
	temp->field = number; // ���������� ���� ������ ������������ ����
	temp->ptr = p; // ��������� ���� ��������� �� ��������� �������
	return temp;
}
void DeleteListElem(list *&First)
{
	int DelElem;
	int k = 0;
	list* cur2 = First;
	cout << "������� ����� ���������� ��������\n";
	cin >> DelElem;
	list* iter = First;
	cur2 = cur2->ptr;
	if (DelElem != 1)
	{
		for (int i = 1; i < DelElem; i++)
		{
			iter = iter->ptr;
		}
		iter->ptr = iter->ptr->ptr;
	}
	else
	{
		delete iter;
		First = cur2;
	}
}
/*struct list * deletelem(list *lst, int n)
{
	struct list *temp;
	temp = lst;
	while (temp->ptr != lst) // ������������� ������ ������� � �����
	{ // ���� �� ������ ����, �������������� lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // ������������ ���������
	free(lst); // ����������� ������ ���������� ����
	return(temp);
}*/
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "������� 5 ����� �����"<<endl;
	int g; //�������� �������� �������� ������
	int i = 1;
	int c = 0;
	int n = 0;
	//list*lst = NULL;
	cin >> g;
	list* head = init(g);
	list* st = head;
	while (i != 5)
	{
		cin >> g;
		st = addelem(st, g);
		i++;
	}
	while (1)
	{
		    cout << " " << endl;
		    cout << "1 - ����� ������ �� �����"<<endl;
			cout << "2 - ���������� �������� � ������"<<endl;
			cout << "3 - �������� �������� �� ������"<<endl;
			cout << "4 - ����� ������ ������� ��������"<<endl;
			cout << "0 - �����"<<endl;
			cin >> c;
			switch (c)
			{
			case 1: { listprint(head); break; }
			case 2: {cin >> g;
				st = addelem(st, g);
				listprint(head); break;
			}
			case 3: {cout << "�������� ������� ��� ��������";
				DeleteListElem(st); break; }
			//case 4:
			//case 0:
			}
	}
	system("pause");
	return 0;
}