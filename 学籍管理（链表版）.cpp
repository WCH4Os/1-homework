#include<iostream>
using namespace std;
#include<string>
#include<cstring>
#include<iomanip>
#define MAX 1000

char yon[5];

struct studentInfo
{
	string Id;
	string Class;
	string name;
	double score1;
	double score2;
	double score3;
	double ttscore;
	studentInfo* next;
};

void showMenu()
{
	cout << "1.input\n";
	cout << "2.delete\n";
	cout << "3.select\n";
	cout << "4.order\n";
	cout << "5.output\n";
	cout << "6.quit\n";
	cout << "please input your option" << endl;
}

void input(studentInfo*& head)
{
	string Id, Class, name;
	double score1, score2, score3, ttscore;
	cout << "Id "; cin >> Id;
	cout << "class "; cin >> Class;
	cout << "name "; cin >> name;
	cout << "score1 "; cin >> score1;
	cout << "score2 "; cin >> score2;
	cout << "score3 "; cin >> score3;

	ttscore = score1 + score2 + score3;

	if (head == NULL)
	{
		head = new studentInfo{ Id,Class,name,score1,score2,score3,ttscore,NULL };
	}
	else
	{
		studentInfo* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new studentInfo{ Id,Class,name,score1,score2,score3,ttscore,NULL };
	}
	cout << "continue?" << endl;
	cin >> yon;
	if (yon[0] == 'y')
	{
		input(head);
	}
	else if (yon[0]=='n')
	{
		return;
	}
}

void Delete(studentInfo*& head)
{
	cout << fixed;
	cout.precision(1);

	string Info;
	cin >> Info;
	struct studentInfo* p1, * p2;
	if (head == NULL)
	{
		return;
	}
	p1 = head;
	p2 = head;
	while ((Info != p1->Id && Info != p1->name) && p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (Info == p1->name || Info == p1->Id)
	{
		if (p1 == head)
		{
			head = p1->next;
		}
		else
		{
			p2->next = p1->next;
		}
		delete p1;
		struct studentInfo* p;
		p = head;
		do
		{
			cout << p->Id << "," << p->Class << "," << p->name << "," << p->score1 << "," << p->score2 << "," << p->score3 << "," << p->ttscore << endl;
			p = p->next;
		} while (p != NULL);
		cout << "continue?" << endl;
		cin >> yon;
		if (yon[0] == 'y')
		{
			input(head);
		}
		else if (yon[0] == 'n')
		{
			return;
		}
	}
	else
	{
		struct studentInfo* p;
		p = head;
		do
		{
			cout << p->Id << "," << p->Class << "," << p->name << "," << p->score1 << "," << p->score2 << "," << p->score3 << "," << p->ttscore << endl;
			p = p->next;
		} while (p != NULL);
	}
}

void Select(studentInfo*& head)
{
	cout << fixed;
	cout.precision(1);

	string Info;
	cin >> Info;
	studentInfo* current = head;
	while (current != NULL)
	{
		if (current->Id == Info || current->Class == Info)
		{
			cout << current->Id << "," << current->Class << "," << current->name << "," << current->score1 << "," << current->score2 << "," << current->score3 << "," << current->ttscore << endl;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}
	cout << "continue?" << endl;
	cin >> yon;
	if (yon[0] == 'y')
	{
		Select(head);
	}
	else if (yon[0] == 'n')
	{
		return;
	}
	return;
}

void Order(studentInfo*& head)
{
	cout << fixed;
	cout.precision(1);

	if (head == NULL)
	{
		return;
	}
	else if (head == NULL)
	{
		cout << head->Id << "," << head->Class << "," << head->name << "," << head->score1 << "," << head->score2 << "," << head->score3 << "," << head->ttscore << endl;
	}
	bool swapped1;
	do
	{
		swapped1 = false;
		studentInfo* current = head;
		while (current->next != NULL)
		{
			if (current->Class > current->next->Class)
			{
				swap(current->Class, current->next->Class);
				swap(current->Id, current->next->Id);
				swap(current->name, current->next->name);
				swap(current->score1, current->next->score1);
				swap(current->score2, current->next->score2);
				swap(current->score3, current->next->score3);
				swap(current->ttscore, current->next->ttscore);
				swapped1 = true;
			}
			current = current->next;
		}
	} while (swapped1);
	
	studentInfo* current = head;

	while (current->next != NULL)
	{
		if (current->Class == current->next->Class)
		{
			if (current->ttscore < current->next->ttscore)
			{
				swap(current->Class, current->next->Class);				
				swap(current->Id, current->next->Id);
				swap(current->name, current->next->name);
				swap(current->score1, current->next->score1);
				swap(current->score2, current->next->score2);
				swap(current->score3, current->next->score3);				
				swap(current->ttscore, current->next->ttscore);
			}
		} 
		current = current->next;
	}
	struct studentInfo* p;
	p = head;
	do
	{
		cout << p->Id << "," << p->Class << "," << p->name << "," << p->score1 << "," << p->score2 << "," << p->score3 << "," << p->ttscore << endl;
		p = p->next;
	} while (p != NULL);
	return;
}

void Output(studentInfo*& head)
{
	cout << fixed;
	cout.precision(1);

	if (head == NULL)
	{
		return;
	}
	struct studentInfo* p = head;
	p = head;
	do
	{
		cout << p->Id << "," << p->Class << "," << p->name << "," << p->score1 << "," << p->score2 << "," << p->score3 << "," << p->ttscore << endl;
		p = p->next;
	} while (p != NULL);
	return;
}

int main()
{
	studentInfo* head = NULL;

	while (true)
	{
		showMenu();
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(head);
			break;
		case 2:
			Delete(head);
			break;
		case 3:
			Select(head);
			break;
		case 4:
			Order(head);
			break;
		case 5:
			Output(head);
			break;
		case 6:
			return 0;
		}
	}
	return 0;
}