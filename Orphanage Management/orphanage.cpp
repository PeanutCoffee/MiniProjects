#include <bits/stdc++.h>
#include "windows.h"
#define getch() \
    ;           \
    return;
using namespace std;
void back();
void pass();

class cchild
{
    char name[26], gender[8];
    int age;
    int d1, m1, y1;
    int id;

public:
    void cget()
    {
        cout << "\n\t\t\t\tEnter Child Details";
        cout << "\n\nEnter Child ID: ";
        cin >> id;
        cout << "\nEnter Child Name: ";
        gets(name);
        cout << "\nEnter Gender: ";
        gets(gender);
        cout << "\nEnter Age: ";
        cin >> age;
        cout << "\nDate of Birth: ";
        cin >> d1 >> m1 >> y1;
    }
    void cput()
    {
        cout << "\n\t\t\tChild Details";
        cout << "\nChild code: " << id;
        cout << "\nChild Name: " << name;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nDate of Birth: " << d1 << "/" << m1 << "/" << y1;
    }

    void cadd();
    void cdis();
    void cser();
    void cedit();
    void cmod();
    void cdel();
    void cmain();
} o;
void cchild::cmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add Child Details";
        cout << "\n\t\t\t\t2. Display Child Details";
        cout << "\n\t\t\t\t3. Search Child Details";
        cout << "\n\t\t\t\t4. Edit Child Details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            o.cadd();
            break;
        case 2:
            o.cdis();
            break;
        case 3:
            o.cser();
            break;
        case 4:
            o.cedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void cchild::cadd()
{

    char ch;
    do
    {
        fstream fout("child.dat", ios::app | ios::binary);
        o.cget();
        fout.write((char *)&o, sizeof(o));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\nWant to Add More (y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\tPress any key to continue";
    getch();
}
void cchild::cdis()
{

    int i;
    fstream fin("child.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Child Detalis";
    gotoxy(5, 4);
    cout << "Child ID";
    gotoxy(20, 4);
    cout << "Child Name";
    gotoxy(35, 4);
    cout << "Gender";
    gotoxy(45, 4);
    cout << "Age";
    gotoxy(52, 4);
    cout << "DOB";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&o, sizeof(o));
        if (fin.eof())
            break;
        gotoxy(5, i);
        cout << id;
        gotoxy(21, i);
        cout << name;
        gotoxy(36, i);
        cout << gender;
        gotoxy(46, i);
        cout << age;
        gotoxy(53, i);
        cout << d1 << "/" << m1 << "/" << y1;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}
void cchild::cser()
{

    char ch;
    do
    {
        ifstream fin("child.dat", ios::in | ios::binary);
        int cid;
        int count = 0;
        cout << "\n\t\t\tEnter Child ID: ";
        cin >> cid;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&o, sizeof(o));
            if (cid == id)
            {
                o.cput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void cchild::cedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Child Record";
    cout << "\n\t\t\t 2.Delete Child Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        o.cmod();
        break;
    case 2:
        o.cdel();
        break;
    case 3:
        cmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void cchild::cmod()
{

    int cid;
    char ch;
    long pos, count = 0;
    do
    {
        cout << "Enter Child ID:-";
        cin >> cid;
        fstream file("child.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&o, sizeof(o));
            if (cid == id)
            {
                cout << "\nPrevious Details";
                o.cput();
                cout << "\n\t\tMODIFICATION MODE\n";
                o.cget();
                file.seekg(pos);
                file.write((char *)&o, sizeof(o));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void cchild::cdel()
{

    int cid;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cid;
        fstream fin("child.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&o, sizeof(o)))
        {
            if (cid == id)
            {
                cout << "\n\t\t\tDeletion Mode";
                o.cput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> c;
                if (c == 'n')
                    fout.write((char *)&o, sizeof(o));
            }
            else
                fout.write((char *)&o, sizeof(o));
        }
        fin.close();
        fout.close();

        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("child.dat");
            rename("temp.dat", "child.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getch();
}

class acchild
{
    char name[26], gender[26];
    int age;
    int d1, d2, m1, m2, y1, y2;
    int id;
    char par1[26], par2[26];
    long long int phn;

public:
    void acget()
    {
        cout << "\n\t\t\t\tEnter Adopted Child Details";
        cout << "\n\nEnter Child ID: ";
        cin >> id;
        cout << "\nEnter Child Name: ";
        gets(name);
        cout << "\nEnter Gender: ";
        gets(gender);
        cout << "\nEnter Date of Birth: ";
        cin >> d1 >> m1 >> y1;
        cout << "\nEnter Age: ";
        cin >> age;
        cout << "\nDate of Leaving: ";
        cin >> d2 >> m2 >> y2;
        cout << "\nEnter Father Name: ";
        gets(par1);
        cout << "\nEnter Mother Name: ";
        gets(par2);
        cout << "\nEnter Contact No.: ";
        cin >> phn;
    }

    void acput()
    {
        cout << "\n\t\t\tChild Details";
        cout << "\nChild ID: " << id;
        cout << "\nChild Name: " << name;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nDate of Birth: " << d1 << "/" << m2 << "/" << y1;
        cout << "\nFather name: " << par1;
        cout << "\nMother name: " << par2;
        cout << "\nContact no.: " << phn;
        cout << "\nDate of Leaving: " << d2 << "/" << m2 << "/" << y2;
    }
    void acadd();
    void acdis();
    void acser();
    void acedit();
    void acmod();
    void acdel();
    void acmain();
} ac;
void acchild::acmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED ADOPTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add Child Details";
        cout << "\n\t\t\t\t2. Display Child Details";
        cout << "\n\t\t\t\t3. Search Child Details";
        cout << "\n\t\t\t\t4. Edit Child Details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ac.acadd();
            break;
        case 2:
            ac.acdis();
            break;
        case 3:
            ac.acser();
            break;
        case 4:
            ac.acedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void acchild::acadd()
{

    char ch;
    do
    {
        fstream fout("adopt.dat", ios::app | ios::binary);
        ac.acget();
        fout.write((char *)&ac, sizeof(ac));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\n\n Want To Add More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\t    Press any key to continue..!!";
    getch();
}
void acchild::acdis()
{

    int i;
    fstream fin("adopt.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Child Detalis";
    gotoxy(3, 4);
    cout << "Child ID";
    gotoxy(13, 4);
    cout << "Child name";
    gotoxy(25, 4);
    cout << "Leaving date";
    gotoxy(40, 4);
    cout << "Father name";
    gotoxy(52, 4);
    cout << "Mother name";
    gotoxy(66, 4);
    cout << "Contact no.";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&ac, sizeof(ac));
        if (fin.eof())
            break;
        gotoxy(4, i);
        cout << id;
        gotoxy(14, i);
        cout << name;
        gotoxy(26, i);
        cout << d2 << "/" << m2 << "/" << y2;
        gotoxy(41, i);
        cout << par1;
        gotoxy(53, i);
        cout << par2;
        gotoxy(66, i);
        cout << phn;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}
void acchild::acser()
{

    char ch;
    do
    {
        ifstream fin("adopt.dat", ios::in | ios::binary);
        int cid;
        int count = 0;
        cout << "\n\t\t\tEnter Child ID: ";
        cin >> cid;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&ac, sizeof(ac));
            if (cid == id)
            {
                ac.acput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void acchild::acedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Child Record";
    cout << "\n\t\t\t 2.Delete Child Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        ac.acmod();
        break;
    case 2:
        ac.acdel();
        break;
    case 3:
        ac.acmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void acchild::acmod()
{

    char ch;
    int cid;
    do
    {
        cout << "Enter Child ID:-";
        cin >> cid;
        long pos, count = 0;
        fstream file("adopt.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&ac, sizeof(ac));
            if (cid == id)
            {
                cout << "\nPrevious Details";
                ac.acput();
                cout << "\n\t\tMODIFICATION MODE\n";
                ac.acget();
                file.seekg(pos);
                file.write((char *)&ac, sizeof(ac));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void acchild::acdel()
{

    int cid;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cid;
        fstream fin("adopt.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&ac, sizeof(ac)))
        {
            if (cid == id)
            {
                cout << "\n\t\t\tDeletion Mode";
                ac.acput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> ch;
                if (ch == 'n')
                    fout.write((char *)&ac, sizeof(ac));
            }
            else
                fout.write((char *)&ac, sizeof(ac));
        }
        fin.close();
        fout.close();
        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("adopt.dat");
            rename("temp.dat", "adopt.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    getch();
}

class fund
{
    char nm1[26], nm2[30], mode[10];
    float amt;
    long rep, cheque;
    int d1, m1, y1;

public:
    void mod()
    {
        if ((strcmp(mode, "cheque")) == 0)
        {
            strcpy(mode, "cheque");
            cout << "\nEnter cheque no.: ";
            cin >> cheque;
            cout << "\nEnter amount: ";
            cin >> amt;
        }
        if ((strcmp(mode, "cash")) == 0)
        {
            strcpy(mode, "cash");
            cout << "\nEnter amount: ";
            cin >> amt;
        }
    }
    void fget()
    {
        cout << "\nEnter Receipt Number: ";
        cin >> rep;
        cout << "\nEnter Person name: ";
        cin >> nm1;
        cout << "\nEnter Insitution: ";
        cin >> nm2;
        cout << "\nEnter Date of Money Deposit: ";
        cin >> d1 >> m1 >> y1;
        cout << "\nMode of Payment(cheque/cash): ";
        cin >> mode;
        mod();
    }
    void fput()
    {
        cout << "\n Receipt Number: " << rep;
        cout << "\n Person name: " << nm1;
        cout << "\n Company : " << nm2;
        cout << "\n Date of Money Deposit: " << d1 << "/" << m1 << "/" << y1;
        cout << "\n Mode of Payment: " << mode;
        cout << "\n Amount: " << amt;
    }
    void fmain();
    void fadd();
    void fdis();
    void fmod();
    void fdel();
    void fedit();
    void fser();
} f;
void fund::fmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add fund in detalis";
        cout << "\n\t\t\t\t2. Display";
        cout << "\n\t\t\t\t3. Search details";
        cout << "\n\t\t\t\t4. Edit details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            f.fadd();
            break;
        case 2:
            f.fdis();
            break;
        case 3:
            f.fser();
            break;
        case 4:
            f.fedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void fund::fadd()
{

    char ch;
    do
    {
        fstream fout("fund.dat", ios::app | ios::binary);
        f.fget();
        fout.write((char *)&f, sizeof(f));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\n\n Want To Add More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\t    Press any key to continue..!!";
    getch();
}
void fund::fdis()
{

    int i;
    fstream fin("fund.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Fund Details";
    gotoxy(3, 4);
    cout << "Recpit no.";
    gotoxy(18, 4);
    cout << "Person name";
    gotoxy(30, 4);
    cout << "Company";
    gotoxy(49, 4);
    cout << "MOP";
    gotoxy(58, 4);
    cout << "Cheque no.";
    gotoxy(70, 4);
    cout << "Amount";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&f, sizeof(f));
        if (fin.eof())
            break;
        gotoxy(3, i);
        cout << rep;
        gotoxy(18, i);
        cout << nm1;
        gotoxy(30, i);
        cout << nm2;
        gotoxy(49, i);
        cout << mode;
        gotoxy(58, i);
        cout << cheque;
        gotoxy(70, i);
        cout << amt;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}

void fund::fser()
{

    char ch;
    do
    {
        ifstream fin("fund.dat", ios::in | ios::binary);
        int cer;
        int count = 0;
        cout << "\n\t\t\tEnter Recpit no.: ";
        cin >> cer;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&f, sizeof(f));
            if (cer == rep)
            {
                f.fput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void fund::fedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Record";
    cout << "\n\t\t\t 2.Delete Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        f.fmod();
        break;
    case 2:
        f.fdel();
        break;
    case 3:
        f.fmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void fund::fmod()
{

    char ch;
    int cer;
    do
    {
        cout << "Enter Recpit no.:-";
        cin >> cer;
        long pos, count = 0;
        fstream file("fund.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&f, sizeof(f));
            if (cer == rep)
            {
                cout << "\nPrevious Details";
                f.fput();
                cout << "\n\t\tMODIFICATION MODE\n";
                f.fget();
                file.seekg(pos);
                file.write((char *)&f, sizeof(f));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void fund::fdel()
{

    int cer;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cer;
        fstream fin("fund.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&ac, sizeof(ac)))
        {
            if (cer == rep)
            {
                cout << "\n\t\t\tDeletion Mode";
                f.fput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> ch;
                if (ch == 'n')
                    fout.write((char *)&f, sizeof(f));
            }
            else
                fout.write((char *)&f, sizeof(f));
        }
        fin.close();
        fout.close();
        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("fund.dat");
            rename("temp.dat", "fund.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    getch();
}
void back()
{

    int m;
    cout << "\n\n******************************************************************************";
    cout << "\n**                           SUNSHINE  ORPHANGE                             **";
    cout << "\n******************************************************************************";
    cout << "\n\n\t\t1.UNADOPTED CHILD";
    cout << "\n\t\t2.ADOPTED CHILD";
    cout << "\n\t\t3.FUND RELATED";
    cout << "\n\t\t4.EXIT";
    cout << "\n\n\t\t\tEnter Your Choice: ";
    cin >> m;
    switch (m)
    {
    case 1:
        o.cmain();
        break;
    case 2:
        ac.acmain();
        break;
    case 3:
        pass();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "\nInvalid";
    }
    getch();
}
void pass()
{

    char cd[10];
    int pas = 1234, pass, ch;
    cout << "\n\t\t\tTHIS IS PRIVATE INFORMATION";
    cout << "\n\n\t\tENTER THE FOLLOWING INFO TO GO TO FUND RELATED INFORMATION";
    cout << "\n\nEnter Orphange Code:";
    cin >> cd;
    cout << "\nEnter Password: ";
    cin >> pass;
    if ((strcmp(cd, "abc")) == 0)
    {
        if (pass == pas)
            f.fmain();
    }
    else
        cout << "\n\t\t\t Invalid Code or Password\n1.Back To Main Menu\n2.Exit\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        back();
        break;
    case 2:
        exit(0);
        break;
    }
    getch();
}
#include <bits/stdc++.h>
#define getch() \
    ;           \
    return;
#define clrscr() \
    ;            \
    system(“cls”);
void back();
void pass();

class cchild
{
    char name[26], gender[8];
    int age;
    int d1, m1, y1;
    int id;

public:
    void cget()
    {
        cout << "\n\t\t\t\tEnter Child Details";
        cout << "\n\nEnter Child ID: ";
        cin >> id;
        cout << "\nEnter Child Name: ";
        gets(name);
        cout << "\nEnter Gender: ";
        gets(gender);
        cout << "\nEnter Age: ";
        cin >> age;
        cout << "\nDate of Birth: ";
        cin >> d1 >> m1 >> y1;
    }
    void cput()
    {
        cout << "\n\t\t\tChild Details";
        cout << "\nChild code: " << id;
        cout << "\nChild Name: " << name;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nDate of Birth: " << d1 << "/" << m1 << "/" << y1;
    }

    void cadd();
    void cdis();
    void cser();
    void cedit();
    void cmod();
    void cdel();
    void cmain();
} o;
void cchild::cmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add Child Details";
        cout << "\n\t\t\t\t2. Display Child Details";
        cout << "\n\t\t\t\t3. Search Child Details";
        cout << "\n\t\t\t\t4. Edit Child Details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            o.cadd();
            break;
        case 2:
            o.cdis();
            break;
        case 3:
            o.cser();
            break;
        case 4:
            o.cedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void cchild::cadd()
{

    char ch;
    do
    {
        fstream fout("child.dat", ios::app | ios::binary);
        o.cget();
        fout.write((char *)&o, sizeof(o));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\nWant to Add More (y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\tPress any key to continue";
    getch();
}
void cchild::cdis()
{

    int i;
    fstream fin("child.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Child Detalis";
    gotoxy(5, 4);
    cout << "Child ID";
    gotoxy(20, 4);
    cout << "Child Name";
    gotoxy(35, 4);
    cout << "Gender";
    gotoxy(45, 4);
    cout << "Age";
    gotoxy(52, 4);
    cout << "DOB";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&o, sizeof(o));
        if (fin.eof())
            break;
        gotoxy(5, i);
        cout << id;
        gotoxy(21, i);
        cout << name;
        gotoxy(36, i);
        cout << gender;
        gotoxy(46, i);
        cout << age;
        gotoxy(53, i);
        cout << d1 << "/" << m1 << "/" << y1;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}
void cchild::cser()
{

    char ch;
    do
    {
        ifstream fin("child.dat", ios::in | ios::binary);
        int cid;
        int count = 0;
        cout << "\n\t\t\tEnter Child ID: ";
        cin >> cid;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&o, sizeof(o));
            if (cid == id)
            {
                o.cput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void cchild::cedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Child Record";
    cout << "\n\t\t\t 2.Delete Child Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        o.cmod();
        break;
    case 2:
        o.cdel();
        break;
    case 3:
        cmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void cchild::cmod()
{

    int cid;
    char ch;
    long pos, count = 0;
    do
    {
        cout << "Enter Child ID:-";
        cin >> cid;
        fstream file("child.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&o, sizeof(o));
            if (cid == id)
            {
                cout << "\nPrevious Details";
                o.cput();
                cout << "\n\t\tMODIFICATION MODE\n";
                o.cget();
                file.seekg(pos);
                file.write((char *)&o, sizeof(o));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void cchild::cdel()
{

    int cid;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cid;
        fstream fin("child.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&o, sizeof(o)))
        {
            if (cid == id)
            {
                cout << "\n\t\t\tDeletion Mode";
                o.cput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> c;
                if (c == 'n')
                    fout.write((char *)&o, sizeof(o));
            }
            else
                fout.write((char *)&o, sizeof(o));
        }
        fin.close();
        fout.close();

        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("child.dat");
            rename("temp.dat", "child.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    getch();
}

class acchild
{
    char name[26], gender[26];
    int age;
    int d1, d2, m1, m2, y1, y2;
    int id;
    char par1[26], par2[26];
    long long int phn;

public:
    void acget()
    {
        cout << "\n\t\t\t\tEnter Adopted Child Details";
        cout << "\n\nEnter Child ID: ";
        cin >> id;
        cout << "\nEnter Child Name: ";
        gets(name);
        cout << "\nEnter Gender: ";
        gets(gender);
        cout << "\nEnter Date of Birth: ";
        cin >> d1 >> m1 >> y1;
        cout << "\nEnter Age: ";
        cin >> age;
        cout << "\nDate of Leaving: ";
        cin >> d2 >> m2 >> y2;
        cout << "\nEnter Father Name: ";
        gets(par1);
        cout << "\nEnter Mother Name: ";
        gets(par2);
        cout << "\nEnter Contact No.: ";
        cin >> phn;
    }

    void acput()
    {
        cout << "\n\t\t\tChild Details";
        cout << "\nChild ID: " << id;
        cout << "\nChild Name: " << name;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nDate of Birth: " << d1 << "/" << m2 << "/" << y1;
        cout << "\nFather name: " << par1;
        cout << "\nMother name: " << par2;
        cout << "\nContact no.: " << phn;
        cout << "\nDate of Leaving: " << d2 << "/" << m2 << "/" << y2;
    }
    void acadd();
    void acdis();
    void acser();
    void acedit();
    void acmod();
    void acdel();
    void acmain();
} ac;
void acchild::acmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED ADOPTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add Child Details";
        cout << "\n\t\t\t\t2. Display Child Details";
        cout << "\n\t\t\t\t3. Search Child Details";
        cout << "\n\t\t\t\t4. Edit Child Details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ac.acadd();
            break;
        case 2:
            ac.acdis();
            break;
        case 3:
            ac.acser();
            break;
        case 4:
            ac.acedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void acchild::acadd()
{

    char ch;
    do
    {
        fstream fout("adopt.dat", ios::app | ios::binary);
        ac.acget();
        fout.write((char *)&ac, sizeof(ac));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\n\n Want To Add More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\t    Press any key to continue..!!";
    getch();
}
void acchild::acdis()
{

    int i;
    fstream fin("adopt.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Child Detalis";
    gotoxy(3, 4);
    cout << "Child ID";
    gotoxy(13, 4);
    cout << "Child name";
    gotoxy(25, 4);
    cout << "Leaving date";
    gotoxy(40, 4);
    cout << "Father name";
    gotoxy(52, 4);
    cout << "Mother name";
    gotoxy(66, 4);
    cout << "Contact no.";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&ac, sizeof(ac));
        if (fin.eof())
            break;
        gotoxy(4, i);
        cout << id;
        gotoxy(14, i);
        cout << name;
        gotoxy(26, i);
        cout << d2 << "/" << m2 << "/" << y2;
        gotoxy(41, i);
        cout << par1;
        gotoxy(53, i);
        cout << par2;
        gotoxy(66, i);
        cout << phn;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}
void acchild::acser()
{

    char ch;
    do
    {
        ifstream fin("adopt.dat", ios::in | ios::binary);
        int cid;
        int count = 0;
        cout << "\n\t\t\tEnter Child ID: ";
        cin >> cid;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&ac, sizeof(ac));
            if (cid == id)
            {
                ac.acput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void acchild::acedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Child Record";
    cout << "\n\t\t\t 2.Delete Child Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        ac.acmod();
        break;
    case 2:
        ac.acdel();
        break;
    case 3:
        ac.acmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void acchild::acmod()
{

    char ch;
    int cid;
    do
    {
        cout << "Enter Child ID:-";
        cin >> cid;
        long pos, count = 0;
        fstream file("adopt.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&ac, sizeof(ac));
            if (cid == id)
            {
                cout << "\nPrevious Details";
                ac.acput();
                cout << "\n\t\tMODIFICATION MODE\n";
                ac.acget();
                file.seekg(pos);
                file.write((char *)&ac, sizeof(ac));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void acchild::acdel()
{

    int cid;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cid;
        fstream fin("adopt.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&ac, sizeof(ac)))
        {
            if (cid == id)
            {
                cout << "\n\t\t\tDeletion Mode";
                ac.acput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> ch;
                if (ch == 'n')
                    fout.write((char *)&ac, sizeof(ac));
            }
            else
                fout.write((char *)&ac, sizeof(ac));
        }
        fin.close();
        fout.close();
        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("adopt.dat");
            rename("temp.dat", "adopt.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    getch();
}

class fund
{
    char nm1[26], nm2[30], mode[10];
    float amt;
    long rep, cheque;
    int d1, m1, y1;

public:
    void mod()
    {
        if ((strcmp(mode, "cheque")) == 0)
        {
            strcpy(mode, "cheque");
            cout << "\nEnter cheque no.: ";
            cin >> cheque;
            cout << "\nEnter amount: ";
            cin >> amt;
        }
        if ((strcmp(mode, "cash")) == 0)
        {
            strcpy(mode, "cash");
            cout << "\nEnter amount: ";
            cin >> amt;
        }
    }
    void fget()
    {
        cout << "\nEnter Receipt Number: ";
        cin >> rep;
        cout << "\nEnter Person name: ";
        cin >> nm1;
        cout << "\nEnter Insitution: ";
        cin >> nm2;
        cout << "\nEnter Date of Money Deposit: ";
        cin >> d1 >> m1 >> y1;
        cout << "\nMode of Payment(cheque/cash): ";
        cin >> mode;
        mod();
    }
    void fput()
    {
        cout << "\n Receipt Number: " << rep;
        cout << "\n Person name: " << nm1;
        cout << "\n Company : " << nm2;
        cout << "\n Date of Money Deposit: " << d1 << "/" << m1 << "/" << y1;
        cout << "\n Mode of Payment: " << mode;
        cout << "\n Amount: " << amt;
    }
    void fmain();
    void fadd();
    void fdis();
    void fmod();
    void fdel();
    void fedit();
    void fser();
} f;
void fund::fmain()
{
    int ch;
    while (1)
    {

        cout << "\n\t\t\t* YOU HAVE SElECTED CHILD MENU *";
        cout << "\n\t\t\t** MAIN MENU **";
        cout << "\n\t\t\t\t1. Add fund in detalis";
        cout << "\n\t\t\t\t2. Display";
        cout << "\n\t\t\t\t3. Search details";
        cout << "\n\t\t\t\t4. Edit details";
        cout << "\n\t\t\t\t5. Return to Main Menu";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter Your Choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            f.fadd();
            break;
        case 2:
            f.fdis();
            break;
        case 3:
            f.fser();
            break;
        case 4:
            f.fedit();
            break;
        case 5:
            back();
            break;
        case 6:
            exit(0);
        default:
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
    }
}
void fund::fadd()
{

    char ch;
    do
    {
        fstream fout("fund.dat", ios::app | ios::binary);
        f.fget();
        fout.write((char *)&f, sizeof(f));
        fout.close();
        cout << "\n\n\n\t\t\tNew Details Added Successfully";
        cout << "\n\n Want To Add More(y/n)?\t\t";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\t\t    Press any key to continue..!!";
    getch();
}
void fund::fdis()
{

    int i;
    fstream fin("fund.dat", ios::in | ios::binary);
    gotoxy(35, 1);
    cout << "Fund Details";
    gotoxy(3, 4);
    cout << "Recpit no.";
    gotoxy(18, 4);
    cout << "Person name";
    gotoxy(30, 4);
    cout << "Company";
    gotoxy(49, 4);
    cout << "MOP";
    gotoxy(58, 4);
    cout << "Cheque no.";
    gotoxy(70, 4);
    cout << "Amount";
    i = 6;
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&f, sizeof(f));
        if (fin.eof())
            break;
        gotoxy(3, i);
        cout << rep;
        gotoxy(18, i);
        cout << nm1;
        gotoxy(30, i);
        cout << nm2;
        gotoxy(49, i);
        cout << mode;
        gotoxy(58, i);
        cout << cheque;
        gotoxy(70, i);
        cout << amt;
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}

void fund::fser()
{

    char ch;
    do
    {
        ifstream fin("fund.dat", ios::in | ios::binary);
        int cer;
        int count = 0;
        cout << "\n\t\t\tEnter Recpit no.: ";
        cin >> cer;
        fin.seekg(ios::beg);
        while (!fin.eof())
        {
            fin.read((char *)&f, sizeof(f));
            if (cer == rep)
            {
                f.fput();
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n Sorry Child Details Not Found Or Not Available!!";
        cout << "\n\n Want To Search More(y/n)?\t\t";
        cin >> ch;
        fin.close();
    } while (ch == 'y' || ch == 'Y');
    cout << "\n\n\t\t Press any key to continue!!";
    getch();
}
void fund::fedit()
{

    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Record";
    cout << "\n\t\t\t 2.Delete Record";
    cout << "\n\t\t\t 3.back";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        f.fmod();
        break;
    case 2:
        f.fdel();
        break;
    case 3:
        f.fmain();
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void fund::fmod()
{

    char ch;
    int cer;
    do
    {
        cout << "Enter Recpit no.:-";
        cin >> cer;
        long pos, count = 0;
        fstream file("fund.dat", ios::in | ios::out | ios::binary);
        while (!file.eof())
        {
            pos = file.tellg();
            file.read((char *)&f, sizeof(f));
            if (cer == rep)
            {
                cout << "\nPrevious Details";
                f.fput();
                cout << "\n\t\tMODIFICATION MODE\n";
                f.fget();
                file.seekg(pos);
                file.write((char *)&f, sizeof(f));
                cout << "\n\t\tRecord is modified!!";
                count = 1;
                break;
            }
        }
        if (count == 0)
            cout << "\n\t\tSorry Details  Not Found!!";
        cout << "\n\n Want To Modify More(y/n)?\t\t";
        cin >> ch;
        file.close();
    } while (ch == 'y' || ch == 'Y');
    getch();
}
void fund::fdel()
{

    int cer;
    int count = 0;
    char ch, c;
    do
    {
        cout << "Enter child code to delete:-";
        cin >> cer;
        fstream fin("fund.dat", ios::in | ios::binary);
        fstream fout("temp.dat", ios::app | ios::binary);
        while (fin.read((char *)&ac, sizeof(ac)))
        {
            if (cer == rep)
            {
                cout << "\n\t\t\tDeletion Mode";
                f.fput();
                count = 1;
                cout << "\n\n\t\tDo you want to delete this record(y/n): ";
                cin >> ch;
                if (ch == 'n')
                    fout.write((char *)&f, sizeof(f));
            }
            else
                fout.write((char *)&f, sizeof(f));
        }
        fin.close();
        fout.close();
        if (count == 0)
            cout << "\n\t\tSorry Child Details Not found or Available!!";
        else
        {
            remove("fund.dat");
            rename("temp.dat", "fund.dat");
        }
        cout << "\n\n Want To Delete More(y/n)?\t\t";
        cin >> c;
    } while (c == 'y' || c == 'Y');
    getch();
}
void back()
{

    int m;
    cout << "\n\n******************************************************************************";
    cout << "\n**                           SUNSHINE  ORPHANGE                             **";
    cout << "\n******************************************************************************";
    cout << "\n\n\t\t1.UNADOPTED CHILD";
    cout << "\n\t\t2.ADOPTED CHILD";
    cout << "\n\t\t3.FUND RELATED";
    cout << "\n\t\t4.EXIT";
    cout << "\n\n\t\t\tEnter Your Choice: ";
    cin >> m;
    switch (m)
    {
    case 1:
        o.cmain();
        break;
    case 2:
        ac.acmain();
        break;
    case 3:
        pass();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout << "\nInvalid";
    }
    getch();
}
void pass()
{

    char cd[10];
    int pas = 1234, pass, ch;
    cout << "\n\t\t\tTHIS IS PRIVATE INFORMATION";
    cout << "\n\n\t\tENTER THE FOLLOWING INFO TO GO TO FUND RELATED INFORMATION";
    cout << "\n\nEnter Orphange Code:";
    cin >> cd;
    cout << "\nEnter Password: ";
    cin >> pass;
    if ((strcmp(cd, "abc")) == 0)
    {
        if (pass == pas)
            f.fmain();
    }
    else
        cout << "\n\t\t\t Invalid Code or Password\n1.Back To Main Menu\n2.Exit\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
        back();
        break;
    case 2:
        exit(0);
        break;
    }
    getch();
}
void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if (!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x, y};
    SetConsoleCursorPosition(h, c);
}
int main()
{

    back();
    getch();
}
