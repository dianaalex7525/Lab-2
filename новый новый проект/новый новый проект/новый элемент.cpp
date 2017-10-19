#include<iostream>
using namespace std;
struct list
{
	int field; // поле данных
	struct list *ptr; // указатель на следующий элемент
};
struct list * init(int a) // а- значение первого узла
{
	struct list *lst = new list;
	// выделение памяти под корень списка
	lst->field = a;
	lst->ptr = lst; // указатель на сам корневой узел
	return(lst);
}

void listprint(list *lst)
{
	struct list *p;
	p = lst;
	do {
		std::cout << (p->field); // вывод значения узла p
		p = p->ptr; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
}
struct list* addelem(list *lst, int number)
{
	struct list *temp, *p;
	temp = new struct list;
	p = lst->ptr; // сохранение указателя на следующий элемент
	lst->ptr = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->ptr = p; // созданный узел указывает на следующий элемент
	return temp;
}
void DeleteListElem(list *&First)
{
	int DelElem;
	int k = 0;
	list* cur2 = First;
	cout << "Введите номер удаляемого элемента\n";
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
	while (temp->ptr != lst) // просматриваем список начиная с корня
	{ // пока не найдем узел, предшествующий lst
		temp = temp->ptr;
	}
	temp->ptr = lst->ptr; // переставляем указатель
	free(lst); // освобождаем память удаляемого узла
	return(temp);
}*/
int main()
{
	setlocale(LC_ALL, "rus");
	cout << "введите 5 целых чисел"<<endl;
	int g; //хранение значения элемента списка
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
		    cout << "1 - вывод списка на экран"<<endl;
			cout << "2 - добавление элемента в список"<<endl;
			cout << "3 - удаление элемента из списка"<<endl;
			cout << "4 - вывод списка средних значений"<<endl;
			cout << "0 - выход"<<endl;
			cin >> c;
			switch (c)
			{
			case 1: { listprint(head); break; }
			case 2: {cin >> g;
				st = addelem(st, g);
				listprint(head); break;
			}
			case 3: {cout << "выбирите элемент для удаления";
				DeleteListElem(st); break; }
			//case 4:
			//case 0:
			}
	}
	system("pause");
	return 0;
}