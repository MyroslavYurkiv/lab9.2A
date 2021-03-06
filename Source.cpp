#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 
using namespace std;
enum Specialnist { KOMPUTERNI_NAUKY, INFORMATYKA, MATEMATYKA_TA_EKONOMIKA, PHISYKA_TA_INFORMATYKA, KIBERBEZPEKA };
string specialnistStr[] = { "��", "�����������", "���&����", "���&���", "�����������" };
struct Student
{
    string prizv;
    unsigned kurs;
    Specialnist specialnist;
    unsigned physics;
    unsigned math;
    unsigned informatics;
};
void Create(Student* p, const int N)
{
    int specialnist;

    for (int i = 0; i < N; i++)
    {
        cout << "������� � " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();
        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " ����: "; cin >> p[i].kurs;
        cout << " ������������� (0 - ����'������ �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - �����������):";
        cin >> specialnist;
        cout << " ������ � ������: "; cin >> p[i].physics;
        cout << "������ � ����������: "; cin >> p[i].math;
        cout << "������ � �����������: "; cin >> p[i].informatics;
        p[i].specialnist = Specialnist(specialnist);
    }
}
void Print(Student* p, const int N)
{
    cout << "=========================================================================="
        << endl;
    cout << "| � | ������� | ���� | ������������� | Գ���� | ���������� | ����������� |"
        << endl;
    cout << "--------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << p[i].prizv
            << "| " << setw(2) << right << p[i].kurs << " "
            << "| " << setw(15) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " "
            << "| " << setw(11) << right << p[i].informatics << " " << "|";
        cout << endl;
    }
    cout << "=========================================================================="
        << endl;
    cout << endl;
}

void Sort(Student* p, const int N)
{
    Student tmp;
    for (int i0 = 0; i0 < N - 1; i0++) 
        for (int i1 = 0; i1 < N - i0 - 1; i1++)
            if ((p[i1].physics > p[i1 + 1].physics)
                ||
                (p[i1].physics == p[i1 + 1].physics &&
                    p[i1].specialnist > p[i1 + 1].specialnist &&
                    p[i1].prizv > p[i1 + 1].prizv))
            {
                tmp = p[i1];
                p[i1] = p[i1 + 1];
                p[i1 + 1] = tmp;
            }
}
int BinSearch(Student* p, const int N, const string prizv, Specialnist specialnist)
{ 
    int L = 0, R = N - 1, m;
    do {
        m = (L + R) / 2;
        if (p[m].specialnist == p[m].specialnist && p[m].prizv == prizv)
            return m;
        if ((p[m].prizv < prizv)
            ||
            (p[m].prizv == prizv &&
                p[m].specialnist < p[m].specialnist))
        {
            L = m + 1;
        }
        else
        {
            R = m - 1;
        }
    } while (L <= R);
    return -1;
}
int* IndexSort(Student* p, const int N)
{
    int* I = new int[N]; 
    for (int i = 0; i < N; i++)
        I[i] = i; 
    int i, j, value; 
    for (i = 1; i < N; i++)
    {
        value = I[i];
        for (j = i - 1;
            j >= 0 && ((p[I[j]].physics > p[value].physics) ||
                (p[I[j]].physics == p[value].physics &&
                    p[I[j]].specialnist > p[value].specialnist) ||
                (p[I[j]].specialnist == p[value].specialnist &&
                    p[I[j]].prizv > p[value].prizv));
            j--)
        {
            I[j + 1] = I[j];
        }
        I[j + 1] = value;
    }
    return I;
}
void PrintIndexSorted(Student* p, int* I, const int N)
{ 
    cout << "=========================================================================="
        << endl;
    cout << "| � | ������� | ���� | ������������� | Գ���� | ���������� | ����������� |"
        << endl;
    cout << "--------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(1) << right << i + 1 << " ";
        cout << "| " << setw(10) << left << p[i].prizv
            << "| " << setw(2) << right << p[i].kurs << " "
            << "| " << setw(15) << left << specialnistStr[p[i].specialnist]
            << "| " << setw(6) << right << p[i].physics << " "
            << "| " << setw(10) << left << p[i].math << " "
            << "| " << setw(11) << right << p[i].informatics << " " << "|";
        cout << endl;
    }
    cout << "=========================================================================="
        << endl;
    cout << endl;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int N = 0;
    int* I = new int[N];
    string prizv;
    unsigned kurs;
    int ispecialnist;
    Specialnist specialnist;
    int found;
    cout << "������ N: "; cin >> N;
    Student* p = new Student[N];
    int menuItem;
    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - �������� ����� � ���������" << endl;
        cout << " [2] - ���� ����� �� �����" << endl;
        cout << " [3] - ������� ������������� �����" << endl << endl;
        cout << " [4] - ������� ����� ���������� �� ������� �� ��������" << endl;
        cout << " [5] - �������� ������������� �� ���� �����"
            << endl << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
        cout << endl << endl << endl;
        switch (menuItem)
        {
        case 1:
            Create(p, N);
            break;
        case 2:
            Print(p, N);
            break;
        case 3:
            Sort(p, N);
            break;
        case 4:
            cout << "������ ����� ������:" << endl;
            cout << " ������������� (0 - ����'������ �����, 1 - �����������, 2 - ���������� �� ��������, 3 - ������ �� �����������, 4 - �����������): ";
            cin >> ispecialnist;
            specialnist = (Specialnist)ispecialnist;
            cin.get(); 
            cin.sync(); 

            cout << " �������: "; getline(cin, prizv);
            cout << endl;
            if ((found = BinSearch(p, N, prizv, specialnist)) != -1)
                cout << "�������� �������� � ������� " << found + 1 << endl;
            else
                cout << "�������� �������� �� ��������" << endl;
            break;
        case 5:
            PrintIndexSorted(p, IndexSort(p, N), N);
            break;

        case 0:
            break;
        default:
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);
    return 0;
}
