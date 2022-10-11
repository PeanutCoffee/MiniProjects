#include <bits/stdc++.h>
#define getch() \
    ;           \
    return;
#define clrscr() \
    ;            \
    system("cls");
using namespace std;
class store
{

    float price;
    int qty;
    char nm[26], brand[26];

public:
    void menu();
    void add();
    void dis();
    void ser();
    void edit();
    void modify();
    void dele();
    void billing();
} s;
void store::menu()
{
    int ch;
    while (1)
    {
        clrscr();
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n\t\t\t* GUPTA MASALA STORE *";
        cout << "\n-------------------------------------------------------------------------------";
        cout << "** MAIN MENU **";
        cout << "\n-------------------------------------------------------------------------------";
        cout << "\n\t\t\t\t1. Add new product";
        cout << "\n\t\t\t\t2. Display product list ";
        cout << "\n\t\t\t\t3. Search product";
        cout << "\n\t\t\t\t4. Edit product list";
        cout << "\n\t\t\t\t5. Billing";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n--------------------------------------------------------------------------------";
        cout << "\n\n\t\t\tEnter Your Choice:-";
        cin >> ch;
        switch (ch)
        {
        case 1:
            add();
            break;
        case 2:
            dis();
            break;
        case 3:
            ser();
            break;
        case 4:
            edit();
            break;
        case 5:
            billing();
            break;
        case 6:
            exit(0);
            break;
        default:
        {
            cout << "\n\n\t\t\tWrong choice!!!";
            cout << "\n\t\t\tPress any key to continue!!";
            getch();
        }
        }
    }
}
void store::add()
{
    clrscr();
    fstream fout("mstore.dat", ios::app | ios::binary);
    cout << "\n\t\t\t Enter Product Detalis";
    cout << "\nEnter name\t";
    gets(nm);
    cout << "\nEnter brand\t";
    gets(brand);
    cout << "\nEnter weight(in kg)\t";
    cin >> qty;
    cout << "\nEnter price\t";
    cin >> price;
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout << "\n\n\n\t\t\tNew product Added Successfully";
    cout << "\n\t\t    Press any key to continue..!!";
    getch();
}
void store::ser()
{
    clrscr();
    ifstream fin("mstore.dat", ios::in | ios::binary);
    char pnm[50];
    int count = 0;
    cout << "\n\t\t\tEnter Product Name: ";
    gets(pnm);
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&s, sizeof(s));
        if (strcmp(nm, pnm) == 0)
        {
            clrscr();
            cout << "\n\t\t\t Product Details";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\t\t\t Name: " << nm;
            cout << "\n\t\t\t Brand: " << brand;
            cout << "\n\t\t\t Price: " << price;
            cout << "\n\t\t\t Weight(in kg): " << qty;
            count = 1;
            break;
        }
    }
    if (count == 0)
        cout << "\n Sorry Product Not Found Or Not Available!!";
    cout << "\n\n\t\t Press any key to continue!!";
    fin.close();
    getch();
}
void store::dis()
{
    clrscr();
    int t, i;
    fstream fin("mstore.dat", ios::in | ios::binary);
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&s, sizeof(s));
        if (fin.eof())
            break;
        cout << "\nProduct Details";
        cout << "\nName: " << nm;
        cout << "\nBrand: " << brand;
        cout << "\nPrice: " << price;
        cout << "\nWeight(in kg): " << qty << "\n";
        i++;
    }
    fin.close();
    cout << "\n\n\n\t\t\tPress any key to continue..!!";
    getch();
}
void store::edit()
{
    clrscr();
    int choice;
    cout << "\n\t\t\t\t EDIT MENU";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t 1.Modify Product Record";
    cout << "\n\t\t\t 2.Delete Product Record";
    cout << "\n--------------------------------------------------------------------------------";
    cout << "\n\t\t\t Enter your choice: ";
    cin >> choice;
    clrscr();
    switch (choice)
    {
    case 1:
        s.modify();
        break;
    case 2:
        s.dele();
        break;
    default:
        cout << "\n\t\t\t Wrong Choice!!";
    }
    cout << "\n\t\t\t Press any key to continue!!!";
    getch();
}
void store::modify()
{
    clrscr();
    char pnm[50];
    cout << "Enter Product Name:-";
    gets(pnm);
    long pos, count = 0;
    fstream file("mstore.bin", ios::in | ios::out | ios::binary);
    while (!file.eof())
    {
        pos = file.tellg();
        file.read((char *)&s, sizeof(s));
        if (strcmp(nm, pnm) == 0)
        {
            cout << "\n\t\t\tModification Mode";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\t\t\t Enter New Details";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\t\t\tName: ";
            gets(nm);
            cout << "\n\t\t\tBrand: ";
            gets(brand);
            cout << "\n\t\t\tPrice: ";
            cin >> price;
            cout << "\n\t\t\tWeight: ";
            cin >> qty;
            file.seekg(pos);
            file.write((char *)&s, sizeof(s));
            cout << "\n\t\tRecord is modified!!";
            count = 1;
            break;
        }
    }
    if (count == 0)
        cout << "\n\t\tSorry Product Is Not Found!!";
    file.close();
}
void store::dele()
{
    clrscr();
    char pnm[50];
    int count = 0;
    char ch;
    cout << "Enter Product Name to delete:-";
    gets(pnm);
    fstream fin("mstore.dat", ios::in | ios::binary);
    fstream fout("temp.dat", ios::app | ios::binary);
    while (!fin.eof())
    {
        fin.read((char *)&s, sizeof(s));
        if (strcmp(nm, pnm) == 0)
        {
            cout << "\n\t\t\tDeletion Mode";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\t\t\t Product Details";
            cout << "\n--------------------------------------------------------------------------------";
            cout << "\n\t\t\t Name: " << nm;
            cout << "\n\t\t\t Brand: " << brand;
            cout << "\n\t\t\t Price: " << price;
            cout << "\n\t\t\t Weight(in kg): " << qty;
            cout << "\n\n\t\tDo you want to delete this record(y/n): ";
            cin >> ch;
            count = 1;
            if (ch == 'n')
                fout.write((char *)&s, sizeof(s));
        }
        else
            fout.write((char *)&s, sizeof(s));
    }
    fin.close();
    fout.close();
    if (count == 0)
        cout << "\n\t\tSorry Product Name Is Not found or Available!!";
    else
    {
        remove("mstore.dat");
        rename("temp.dat", "mstore.dat");
    }
}

void store::billing()
{
    clrscr();
    int qtys, total, flag = 0;
    char nme[30];
    fstream fin("mstore.dat", ios::in | ios::binary);
    cout << "\n\t\t SALES INVOICE";
    cout << "\n----------------------------------------------------------------------------";
    cout << "\nProduct Name:-";
    gets(nme);
    fin.seekg(ios::beg);
    while (!fin.eof())
    {
        fin.read((char *)&s, sizeof(s));
        if (strcmp(nme, nm) == 0)
        {
        gourav:
            clrscr();
            cout << "\nName\t";
            cout << nm;
            cout << "\nAvailable Amount in kg\t";
            cout << qty;
            cout << "\n-----------------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\t\t SALES INVOICE";
            cout << "\n---------------------------------------------------------------------";
            cout << "\nProduct Name\t\t" << nm;
            cout << "\nBrand\t\t" << brand;
            cout << "\nPrice\t\t" << price;
            cout << "\nWeight\t\t";
            cin >> qtys;
            flag = 1;
            if (qty < qtys)
            {
                cout << "\n\nQuantity Sold must be less then available";
                goto gourav;
            }
            else
            {
                cout << "\nTOTAl\t" << total;
                total = qtys * price;
            }
        }
    }
    if (flag == 0)
        cout << "\nSorry....!! Product Not Found";
    fin.close();
    cout << "\nThank You... Visit Again";
    getch();
}
int main()
{
    clrscr();
    s.menu();
}
