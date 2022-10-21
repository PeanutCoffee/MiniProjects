/*          HEADER FILES          */
#include <iostream>
#include <conio.h>
#include <string.h>
#include <dos.h>
#include <ctype.h>
#include <stdio.h>
#include <process.h>
#include <iomanip.h>
#include <math.h>

/*	      STRUCTURE DEFINITIONS	       */

struct address /* STRUCTURE FOR ADDRESS */
{
	char hno[30];
	char area[30];
	char city[30];
	char stat[30];
};

struct agn /* STRUCTURE FOR AGENT DETAILS */
{
	int code;
	char nam[80];
	int age;
	address addagn;
	int polsld;		// no. of policies sold
	float sal;		// salary
	char categ[50]; // category
} agnt[15];

struct cust /* STRUCTURE FOR CUSTOMER DETAILS */
{
	char nam[80];
	int age;
	address addcust;
	char polbt[20]; // name of policy bought
	float sal;		// salary
	int code;
	float polamt;
	int polterm;
	char mod_pay;
	float sa_pt_pa; // SA per thousand per annum
	float prem;		// premium
} custm[15];

struct fback /* STRUCTURE FOR FEEDBACK FORM */
{
	int age;
	char gndr;	   // gender
	char occp[20]; // occupation
	float inc;	   // income
	char a[12];	   // ratings
} fbk;

struct poldet /* STRUCTURE FOR POLICY T&C */
{
	char nam[20];
	int minagemat;
	int maxagemat;
	int maxmatage;
	int minpolt;
	int maxpolt;
	float minsumass;
	char maxsumass[10];
	char modeall[25];
	float acci_ben;
	float CI;
	int femliv;
	char agepro[40];
	char nonmed_gen[5];
	char nonmed_spe[5];
	char termrideroptn[4];
	char crtcalilnesridr[4];
	float sa_pt_patrm1_ag1; // SA per thousand per annum
	float sa_pt_patrm1_ag2;
	float sa_pt_patrm2_ag1;
	float sa_pt_patrm2_ag2;
};

/*	  STORING POLICY DETAILS	*/

poldet endow = {"ENDOWMENT POLICY", 12, 65, 75, 5, 55, 50000.00, "No Limit", "All", 1.00,
				7.26, 2, "Birth Certificate / Board Certificate", "Yes", "Yes",
				"Yes", "Yes", 72.00, 73.35, 35.80, 40.00};

poldet monbak = {"MONEY BACK POLICY", 13, 50, 70, 20, 55, 50000.00, "No Limit", "All",
				 2.00, 6.57, 2, "Birth Certificate / Board Certificate", "Yes", "Yes",
				 "Yes", "Yes", 65.35, 53.45, 71.85, 61.55};

poldet jeevkish = {"JEEVAN KISHORE", 0, 12, 45, 15, 35, 50000.00, "40 Lacs", "All", 1.50,
				   6.52, 2, "Birth Certificate / Board Certificate", "N.A.", "N.A.",
				   "No", "No", 49.15, 29.25, 49.15, 29.25};

poldet jeevannd = {"JEEVAN ANAND", 18, 65, 75, 5, 57, 100000.00, "No Limit",
				   "All Except Single", 1.5, 6.45, 2, "Birth Certificate / Board Certificate",
				   "Yes", "Yes", "No", "Yes", 50.95, 39.05, 155.75, 86.25};

poldet jeevsurbh = {"JEEVAN SURABHI", 14, 50, 70, 15, 25, 50000.00, "No Limit", "All",
					1.00, 6.11, 2, "Birth Certificate / Board Certificate", "Yes",
					"Yes", "No", "No", 108.80, 91.30, 123.00, 112.80};

/*           FUNCTION PROTOTYPING	   */

/* FUNCTION FOR DISPLAYING MAIN MENU */

void welcome(); // display welcome page
void mainmen(); // display main menu

/* CUSTOMER FUNCTIONS */

void cusmen();							// display customer menu
void newpol();							// display new policies
void tnccus(poldet pol);				// display details of policies
void newcus(poldet pol);				// new customer data input
float premcalc(cust custm, poldet pol); // premium calculation
void oldcus();							// display old customer's previous policy details
void feed();							// display feedback form
char feedval();							// input & test the ratings of feedback form

/* AGENT FUNCTIONS */

void agnmen(); // display agent menu
void newagn(); // new agent data input
void oldagn(); // old agent details
void tncagn(); // display terms & conditions for agents

/* MAIN FUNCTION */
void main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout << setprecision(2);

	textbackground(BLACK);
	textcolor(CYAN + BLINK);

	clrscr();
	delay(1500);

	gotoxy(25, 20);
	puts("LOADING");
	delay(2000);

	for (int i = 0; i < 11; i++)
	{
		textcolor(CYAN);
		textbackground(BLACK);
		clrscr();
		gotoxy(25, 20);
		puts("LOADING");

		gotoxy(25, 22);
		for (int j = 0; j < i; j++)
			cout << "ÛÛ";

		for (int x = 10 - (i); x > 0; x--)
			cout << "  ";

		cout << " " << i << "0%";
		if (i % 2 == 0)
			delay(500);
		else
			delay(200);
	}
	gotoxy(33, 25);
	puts("COMPLETE!!");
	delay(500);

	welcome();
}

/* WELCOME SCREEN */
void welcome()
{
	clrscr();

	for (int x = 0; x < 80; x++)
	{
		gotoxy(x, 0);
		cout << "";
		delay(5);
	}

	for (int y = 0; y < 48; y++)
	{
		gotoxy(0, y);
		cout << "\n";
		delay(5);
	}

	for (x = 79; x > 0; x--)
	{
		gotoxy(x, 49);
		cout << "";
		delay(5);
	}

	gotoxy(80, 49);
	cout << "";

	for (y; y > 0; y--)
	{
		gotoxy(80, y);
		cout << "\n";
		delay(5);
	}

	gotoxy(10, 10);
	puts("*********************** W E L C O M E *********************** ");
	gotoxy(18, 16);
	puts("L . I . C .  D A T A B A S E  S O F T W A R E");
	gotoxy(38, 22);
	puts(" D E V E L O P E D  B Y : ");
	gotoxy(38, 26);
	puts(" Saurabh Khatri & Nikhil Jha ");
	gotoxy(38, 28);
	puts(" XI C");
	gotoxy(38, 30);
	puts(" Greenway Modern Sr.Sec. School");
	gotoxy(38, 32);
	puts(" Dilshad Garden");
	gotoxy(38, 34);
	puts(" DELHI-95");
	gotoxy(38, 40);
	puts(" *** PRESS ANY KEY TO CONTINUE ***");

	getch();
	mainmen();
}

/* MAIN MENU */
void mainmen()
{
	char a;
	clrscr();
	cout << "\n";

	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 16; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(25, 5);
	cout << "WELCOME TO LIFE INSURANCE COMPANY";
	gotoxy(25, 6);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	gotoxy(36, 9);
	cout << "L.I.C. MENU";
	gotoxy(36, 12);
	cout << "C=CUSTOMER";
	gotoxy(36, 14);
	cout << "A=AGENT";
	gotoxy(36, 16);
	cout << "X=EXIT";

	cout << "\n\n";
	for (x = 1; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 19; y++)
	{
		delay(5);
		gotoxy(80, y);
		cout << "";
	}

	gotoxy(30, 20);
	cout << "Please enter your choice : ";
x:
	a = getch();
	switch (a)
	{
	case 'c':
	case 'C':
		cusmen();
		break;
	case 'a':
	case 'A':
		agnmen();
		break;
	case 'x':
	case 'X':
		feed();
		break;
	default:
		goto x;
	}
}

/* CUSTOMER MENU */
void cusmen()
{
	char b;
x:
	clrscr();

	cout << "\n";
	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 16; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(36, 5);
	cout << "CUSTOMER MENU";
	gotoxy(36, 6);
	cout << "$$$$$$$$$$$$$";
	gotoxy(36, 9);
	cout << "O=OLD CUSTOMER";
	gotoxy(36, 11);
	cout << "P=POLICIES";
	gotoxy(36, 13);
	cout << "B=BACK";
	gotoxy(36, 15);
	cout << "X=EXIT";

	cout << "\n\n";
	for (x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 18; y++)
	{
		gotoxy(80, y);
		delay(5);
		cout << "";
	}

	gotoxy(30, 19);
	cout << "Please enter your choice : ";
y:
	b = getch();

	switch (b)
	{
	case 'o':
	case 'O':
		oldcus();
		break;
	case 'p':
	case 'P':
		newpol();
		break;
	case 'b':
	case 'B':
		mainmen();
		break;
	case 'x':
	case 'X':
		feed();
		break;
	default:
		goto y;
	}
}

/* NEW POLICY */
void newpol()
{
	char inp;
	clrscr();

	cout << "\n";

	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 17; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(30, 5);
	cout << "LIFE INSURANCE POLICIES";
	gotoxy(30, 6);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$";
	gotoxy(31, 9);
	cout << "1. Endowment Policy";
	gotoxy(31, 11);
	cout << "2. Money Back Policy";
	gotoxy(31, 13);
	cout << "3. Jeevan Kishore";
	gotoxy(31, 15);
	cout << "4. Jeevan Anand";
	gotoxy(31, 17);
	cout << "5. Jeevan Surabhi";

	cout << "\n\n";
	for (x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 19; y++)
	{
		delay(5);
		gotoxy(80, y);
		cout << "";
	}

	gotoxy(31, 21);
	cout << "B=Back";
	gotoxy(31, 23);
	cout << "X=Exit";
	gotoxy(31, 25);
	cout << "Please enter your choice : ";
x:
	inp = getch();

	switch (inp)
	{
	case '1':
		tnccus(endow);

	case '2':
		tnccus(monbak);

	case '3':
		tnccus(jeevkish);

	case '4':
		tnccus(jeevannd);

	case '5':
		tnccus(jeevsurbh);

	case 'b':
	case 'B':
		cusmen();

	case 'x':
	case 'X':
		exit(0);

	default:
		goto x;
	}
}

/* POLICY DETAILS */
void tnccus(poldet pol)
{
	char in;
	clrscr();

	cout << "\n";
	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 32; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(25, 5);
	cout << "TERMS & CONDITIONS FOR ";
	puts(pol.nam);
	gotoxy(12, 8);
	cout << "¯ Min./Max. age at entry  : ";
	cout << pol.minagemat << " / " << pol.maxagemat;
	gotoxy(12, 10);
	cout << "¯ Max. maturity age       : " << pol.maxmatage;
	gotoxy(12, 12);
	cout << "¯ Min./Max. policy term   : " << pol.minpolt << " / " << pol.maxpolt;
	gotoxy(12, 14);
	cout << "¯ Min./Max. sum assured   : " << pol.minsumass << " / ";
	puts(pol.maxsumass);
	gotoxy(12, 16);
	cout << "¯ Mode allowed            : ";
	puts(pol.modeall);
	gotoxy(12, 18);
	cout << "¯ Accident Benefit        : " << pol.acci_ben;
	cout << " per thousand S.A. per annum";
	gotoxy(12, 20);
	cout << "¯ Compound Interest       : " << pol.CI;
	gotoxy(12, 22);
	cout << "¯ Female Lives            : " << pol.femliv;
	gotoxy(12, 24);
	cout << "¯ Age Proof               : ";
	puts(pol.agepro);
	gotoxy(12, 26);
	cout << "¯ Non Medical (General)   : ";
	puts(pol.nonmed_gen);
	gotoxy(12, 28);
	cout << "¯ Non Medical (Special)   : ";
	puts(pol.nonmed_spe);
	gotoxy(12, 30);
	cout << "¯ Term rider option	  : ";
	puts(pol.termrideroptn);
	gotoxy(12, 32);
	cout << "¯ Critical illness rider  : ";
	puts(pol.crtcalilnesridr);

	cout << "\n";
	for (x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 34; y++)
	{
		delay(5);
		gotoxy(80, y);
		cout << "";
	}

	gotoxy(12, 36);
	cout << "Does this policy satisfy your needs?(Y/N) : ";
a:
	in = getch();

	switch (in)
	{
	case 'Y':
	case 'y':
		newcus(pol);

	case 'n':
	case 'N':
		newpol();

	default:
		goto a;
	}
}

/* NEW POLICY FORM */
void newcus(poldet pol)
{
	int j;
	clrscr();

	for (int i = 0; i < 15; i++)
	{
		if (strcmp(custm[i].nam, "\0") == 0)
			break;
	}

	gotoxy(28, 3);
	cout << "POLICY FORM FOR ";
	puts(pol.nam);
	gotoxy(25, 6);
	cout << "Please enter the following details : ";
	gotoxy(25, 8);
	cout << "¯ NAME : ";
	gotoxy(25, 10);
	cout << "¯ AGE : ";
	gotoxy(25, 12);
	cout << "¯ ADDRESS : ";
	gotoxy(29, 14);
	cout << "* HOUSE NO. : ";
	gotoxy(29, 16);
	cout << "* AREA : ";
	gotoxy(29, 18);
	cout << "* CITY : ";
	gotoxy(29, 20);
	cout << "* STATE : ";
	gotoxy(25, 22);
	if (strcmp(pol.nam, "JEEVAN KISHORE"))
		cout << "¯ SALARY : ";
	gotoxy(25, 24);
	cout << "¯ POLICY AMOUNT : ";
	gotoxy(25, 26);
	cout << "¯ MODE OF PAYMENT : ";
	gotoxy(29, 28);
	cout << "( Q=QUARTERLY, H=HALF YEARLY, Y=YEARLY)";
	gotoxy(25, 30);
	cout << "¯ POLICY TERM : ";

a:
	gotoxy(34, 8);
	gets(custm[i].nam);
	if (strcmp(custm[i].nam, "\0") == 0)
		goto a;

b:
	gotoxy(33, 10);
	for (j = 0; j < 20; j++)
		cout << " ";
	gotoxy(33, 10);
	cin >> custm[i].age;
	if (custm[i].age < pol.minagemat || custm[i].age > pol.maxagemat)
	{
		gotoxy(20, 40);
		cout << "Age must be between " << pol.minagemat << " to " << pol.maxagemat << " years";
		goto b;
	}
	else
	{
		gotoxy(20, 40);
		for (j = 0; j < 34; j++)
			cout << " ";
	}

c:
	gotoxy(43, 14);
	gets(custm[i].addcust.hno);
	if (strcmp(custm[i].addcust.hno, "\0") == 0)
		goto c;

d:
	gotoxy(38, 16);
	gets(custm[i].addcust.area);
	if (strcmp(custm[i].addcust.area, "\0") == 0)
		goto d;

e:
	gotoxy(38, 18);
	gets(custm[i].addcust.city);
	if (strcmp(custm[i].addcust.city, "\0") == 0)
		goto e;

f:
	gotoxy(39, 20);
	gets(custm[i].addcust.stat);
	if (strcmp(custm[i].nam, "\0") == 0)
		goto f;

	gotoxy(36, 22);
	if (strcmp(pol.nam, "JEEVAN KISHORE")) // check if the policy name
		cin >> custm[i].sal;			   // is JEEVAN KISHORE

g:
	gotoxy(43, 24);
	for (j = 0; j < 20; j++)
		cout << " ";
	gotoxy(43, 24);
	cin >> custm[i].polamt;
	if (custm[i].polamt < pol.minsumass)
	{
		gotoxy(20, 40);
		cout << "Policy amount must be more than Rs. " << pol.minsumass;
		goto g;
	}
	else
	{
		gotoxy(20, 40);
		for (j = 0; j < 50; j++)
			cout << " ";
	}
	gotoxy(45, 26);
h:
	custm[i].mod_pay = getch();
	switch (custm[i].mod_pay)
	{
	case 'q':
	case 'Q':
	case 'h':
	case 'H':
	case 'y':
	case 'Y':
		custm[i].mod_pay = toupper(custm[i].mod_pay);
		cout << custm[i].mod_pay;
		getch();
		break;
	default:
		goto h;
	}

k:
	custm[i].polterm = 0;
	gotoxy(41, 30);
	for (j = 0; j < 15; j++)
		cout << " ";
	gotoxy(41, 30);
	cin >> custm[i].polterm;
	if ((custm[i].polterm < pol.minpolt) || (custm[i].polterm > pol.maxpolt))
	{
		gotoxy(20, 40);
		cout << "Policy term must be between " << pol.minpolt;
		cout << " to " << pol.maxpolt << " years";
		goto k;
	}
	else
	{
		gotoxy(20, 40);
		for (j = 0; j < 34; j++)
			cout << " ";
	}

	strcpy(custm[i].polbt, pol.nam); // copy the policy name to customer's details

	custm[i].code = fabs((100 * i) + 89 - (custm[i].age)); // create unique code

	custm[i].prem = premcalc(custm[i], pol); // calculate premium

	clrscr();
	gotoxy(30, 3);
	cout << "Your details are : ";
	gotoxy(25, 6);
	cout << "¯ NAME : ";
	puts(custm[i].nam);
	gotoxy(25, 8);
	cout << "¯ AGE : " << custm[i].age;
	gotoxy(25, 10);
	cout << "¯ ADDRESS : ";
	gotoxy(29, 12);
	cout << "* HOUSE NO. : ";
	puts(custm[i].addcust.hno);
	gotoxy(29, 14);
	cout << "* AREA : ";
	puts(custm[i].addcust.area);
	gotoxy(29, 16);
	cout << "* CITY : ";
	puts(custm[i].addcust.city);
	gotoxy(29, 18);
	cout << "* STATE : ";
	puts(custm[i].addcust.stat);
	gotoxy(25, 20);
	cout << "¯ POLICY NAME : ";
	puts(custm[i].polbt);
	gotoxy(25, 22);
	if (strcmp(pol.nam, "JEEVAN KISHORE"))
		cout << "¯ SALARY : Rs. " << custm[i].sal;
	gotoxy(25, 24);
	cout << "¯ POLICY AMOUNT : Rs. " << custm[i].polamt;
	gotoxy(25, 26);
	cout << "¯ POLICY TERM : " << custm[i].polterm << " years";
	gotoxy(25, 28);
	cout << "¯ MODE OF PAYMENT : ";
	switch (custm[i].mod_pay)
	{
	case 'Y':
		cout << "YEARLY";
		break;
	case 'H':
		cout << "HALF YEARLY";
		break;
	case 'Q':
		cout << "QUARTERLY";
	}
	gotoxy(25, 30);
	cout << "¯ PREMIUM : Rs. " << custm[i].prem << " per annum";
	gotoxy(25, 32);
	cout << "¯ CUSTOMER CODE : " << custm[i].code;

	getch();
	cusmen();
}

/* PREMIUM CALCULATION */
float premcalc(cust custm, poldet pol)
{
	float a;

	if (custm.age < (pol.minagemat + pol.maxagemat) / 2)
	{
		if (custm.polterm <= (pol.minpolt + pol.maxpolt) / 2)
			custm.sa_pt_pa = pol.sa_pt_patrm1_ag1;
		if (custm.polterm > (pol.minagemat + pol.maxagemat) / 2)
			custm.sa_pt_pa = pol.sa_pt_patrm2_ag1;
	}

	if (custm.age >= (pol.minagemat + pol.maxagemat) / 2)
	{
		if (custm.polterm <= (pol.minpolt + pol.maxpolt) / 2)
			custm.sa_pt_pa = pol.sa_pt_patrm1_ag2;
		if (custm.polterm > (pol.minpolt + pol.maxpolt) / 2)
			custm.sa_pt_pa = pol.sa_pt_patrm2_ag2;
	}

	if (custm.mod_pay == 'h' || custm.mod_pay == 'H')
		custm.sa_pt_pa *= 0.985;

	else if (custm.mod_pay == 'y' || custm.mod_pay == 'Y')
		custm.sa_pt_pa *= 0.97;

	if (custm.polamt > pol.minsumass && custm.polamt <= (2 * pol.minsumass))
		custm.sa_pt_pa -= 1;

	if (custm.polamt > (2 * pol.minsumass))
		custm.sa_pt_pa -= 2;

	a = (custm.sa_pt_pa) * (custm.polamt) / 1000;

	return a;
}

/* OLD CUSTOMER'S DETAILS */
void oldcus()
{
	int flag = 0;
	clrscr();

	gotoxy(25, 6);
	cout << "PLEASE ENTER CUSTOMER CODE : ";
	int pn;
	cin >> pn;

	for (int i = 0; i < 15; i++)
	{
		if (pn == custm[i].code) // check the customer code
		{
			flag = 1;
			gotoxy(25, 10);
			cout << "¯ NAME : ";
			puts(custm[i].nam);
			gotoxy(25, 12);
			cout << "¯ AGE : " << custm[i].age;
			gotoxy(25, 14);
			cout << "¯ ADDRESS : ";
			gotoxy(29, 16);
			cout << "* HOUSE NO. : ";
			puts(custm[i].addcust.hno);
			gotoxy(29, 18);
			cout << "* AREA : ";
			puts(custm[i].addcust.area);
			gotoxy(29, 20);
			cout << "* CITY : ";
			puts(custm[i].addcust.city);
			gotoxy(29, 22);
			cout << "* STATE : ";
			puts(custm[i].addcust.stat);
			gotoxy(25, 24);
			cout << "¯ POLICY NAME : ";
			puts(custm[i].polbt);
			gotoxy(25, 26);
			cout << "¯ SALARY : Rs. " << custm[i].sal;
			gotoxy(25, 28);
			cout << "¯ POLICY AMOUNT : Rs. " << custm[i].polamt;
			gotoxy(25, 30);
			cout << "¯ POLICY TERM : " << custm[i].polterm << " years";
			gotoxy(25, 32);
			cout << "¯ MODE OF PAYMENT : ";
			switch (custm[i].mod_pay)
			{
			case 'Y':
				cout << "YEARLY";
				break;
			case 'H':
				cout << "HALF YEARLY";
				break;
			case 'Q':
				cout << "QUARTERLY";
			}
			gotoxy(25, 34);
			cout << "¯ PREMIUM : Rs. " << custm[i].prem << " per annum";

			getch();
			cusmen();
		}
	}

	if (flag == 0) // if customer is not found
	{
		gotoxy(25, 8);
		cout << "SORRY, CUSTOMER NOT FOUND";
	}

	getch();
	cusmen();
}

/* AGENT MENU */
void agnmen()
{
	char b;
x:
	clrscr();

	cout << "\n";
	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 17; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(36, 5);
	cout << "AGENT MENU";
	gotoxy(36, 6);
	cout << "$$$$$$$$$$";
	gotoxy(36, 9);
	cout << "O=OLD AGENT";
	gotoxy(36, 11);
	cout << "N=NEW AGENT";
	gotoxy(36, 13);
	cout << "T=TERMS & CONDITIONS";
	gotoxy(36, 15);
	cout << "B=BACK";
	gotoxy(36, 17);
	cout << "X=EXIT";

	cout << "\n\n";
	for (x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 19; y++)
	{
		delay(5);
		gotoxy(80, y);
		cout << "";
	}

	gotoxy(30, 21);
	cout << "Please enter your choice : ";
y:
	b = getch();

	switch (b)
	{
	case 'o':
	case 'O':
		oldagn();
		break;
	case 'n':
	case 'N':
		newagn();
		break;
	case 'T':
	case 't':
		tncagn();
		goto x;
	case 'b':
	case 'B':
		mainmen();
		break;
	case 'X':
	case 'x':
		exit(0);
		break;
	default:
		goto y;
	}
}

/* NEW AGENT FORM */
void newagn()
{
	int o;
	clrscr();

	for (int i = 0; i < 15; i++)
	{
		if (strcmp(agnt[i].nam, "\0") == 0)
			break;
	}

	gotoxy(34, 3);
	cout << "NEW AGENT FORM";
	gotoxy(25, 6);
	cout << "Please enter the following details : ";
	gotoxy(25, 8);
	cout << "¯ NAME : ";
	gotoxy(25, 10);
	cout << "¯ AGE : ";
	gotoxy(25, 12);
	cout << "¯ ADDRESS : ";
	gotoxy(29, 14);
	cout << "* HOUSE NO. : ";
	gotoxy(29, 16);
	cout << "* AREA : ";
	gotoxy(29, 18);
	cout << "* CITY : ";
	gotoxy(29, 20);
	cout << "* STATE : ";
	gotoxy(25, 22);
	cout << "¯ SALARY : ";
	gotoxy(25, 24);
	cout << "¯ POLICIES SOLD : ";

x:
	gotoxy(34, 8);
	gets(agnt[i].nam);
	if (strcmp(agnt[i].nam, "\0") == 0)
		goto x;

y:
	gotoxy(33, 10);
	cin >> agnt[i].age;
	if (agnt[i].age < 18)
	{
		gotoxy(20, 40);
		cout << "Age must be more than 18";
		gotoxy(33, 10);
		for (o = 0; o < 4; o++)
			cout << " ";
		goto y;
	}
	else
	{
		gotoxy(20, 40);
		for (o = 0; o < 35; o++)
			cout << " ";
	}

a:
	gotoxy(43, 14);
	gets(agnt[i].addagn.hno);
	if (strcmp(agnt[i].addagn.hno, "\0") == 0)
		goto a;

b:
	gotoxy(38, 16);
	gets(agnt[i].addagn.area);
	if (strcmp(agnt[i].addagn.area, "\0") == 0)
		goto b;

c:
	gotoxy(38, 18);
	gets(agnt[i].addagn.city);
	if (strcmp(agnt[i].addagn.city, "\0") == 0)
		goto c;

d:
	gotoxy(39, 20);
	gets(agnt[i].addagn.stat);
	if (strcmp(agnt[i].addagn.stat, "\0") == 0)
		goto d;

	gotoxy(36, 22);
	cin >> agnt[i].sal;

	gotoxy(43, 24);
	cin >> agnt[i].polsld;

	if ((agnt[i].polsld) > 0 && (agnt[i].polsld) < 1000) // categorise the agent
		strcpy(agnt[i].categ, "BRANCH MANAGER CLUB MEMBER");

	else if ((agnt[i].polsld) > 999 && (agnt[i].polsld) < 2000)
		strcpy(agnt[i].categ, "DIVISIONAL MANAGER CLUB MEMBER");

	else if ((agnt[i].polsld) > 1999 && (agnt[i].polsld) < 3000)
		strcpy(agnt[i].categ, "ZONAL MANAGER CLUB MEMBER");

	else if ((agnt[i].polsld) > 2999)
		strcpy(agnt[i].categ, "CHAIRMAN CLUB MEMBER");

	agnt[i].code = fabs(100 + (20 * agnt[i].age) - (80 * i)); // create unique code

	clrscr();
	gotoxy(34, 3);
	cout << "Your details are : ";
	gotoxy(25, 6);
	cout << "¯ NAME : ";
	puts(agnt[i].nam);
	gotoxy(25, 8);
	cout << "¯ AGE : " << agnt[i].age;
	gotoxy(25, 10);
	cout << "¯ SALARY : Rs. " << agnt[i].sal;
	gotoxy(25, 12);
	cout << "¯ ADDRESS : ";
	gotoxy(29, 14);
	cout << "* HOUSE NO. : ";
	puts(agnt[i].addagn.hno);
	gotoxy(29, 16);
	cout << "* AREA : ";
	puts(agnt[i].addagn.area);
	gotoxy(29, 18);
	cout << "* CITY : ";
	puts(agnt[i].addagn.city);
	gotoxy(29, 20);
	cout << "* STATE : ";
	puts(agnt[i].addagn.stat);
	gotoxy(25, 22);
	cout << "¯ POLICIES SOLD : " << agnt[i].polsld;
	gotoxy(25, 24);
	cout << "¯ AGENT CATEGORY : ";
	puts(agnt[i].categ);
	gotoxy(25, 26);
	cout << "¯ AGENT CODE : " << agnt[i].code;

	getch();
	agnmen();
}

/* OLD AGENT'S DETAILS */
void oldagn()
{
	int flag = 0;
	clrscr();

	gotoxy(25, 6);
	cout << "PLEASE ENTER THE AGENT CODE : ";
	int pn;
	cin >> pn;

	for (int i = 0; i < 15; i++)
	{
		if (pn == agnt[i].code) // check agent code
		{
			flag = 1;
			gotoxy(25, 9);
			cout << "¯ NAME : ";
			cout << agnt[i].nam;
			gotoxy(25, 11);
			cout << "¯ ADDRESS : ";
			gotoxy(29, 13);
			cout << "* HOUSE NO. : ";
			puts(agnt[i].addagn.hno);
			gotoxy(29, 15);
			cout << "* AREA : ";
			puts(agnt[i].addagn.area);
			gotoxy(29, 17);
			cout << "* CITY : ";
			puts(agnt[i].addagn.city);
			gotoxy(29, 19);
			cout << "* STATE : ";
			puts(agnt[i].addagn.stat);
			gotoxy(25, 21);
			cout << "¯ POLICIES SOLD : ";
			cout << agnt[i].polsld;
			gotoxy(25, 23);
			cout << "¯ AGENT CATEGORY : ";
			puts(agnt[i].categ);
			gotoxy(25, 25);
			cout << "¯ SALARY : Rs. ";
			cout << agnt[i].sal;
			getch();
			agnmen();
		}
	}

	if (flag == 0) // if agent is not found
	{
		gotoxy(25, 8);
		cout << "SORRY, AGENT NOT FOUND";
	}

	getch();

	agnmen();
}

/* T&C FOR AGENTS */
void tncagn()
{
	clrscr();

	cout << "\n";
	for (int x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (int y = 1; y < 34; y++)
	{
		delay(5);
		gotoxy(0, y);
		cout << "\n";
	}

	gotoxy(25, 5);
	cout << "TERMS & CONDITIONS FOR AGENT";
	gotoxy(25, 6);
	cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
	gotoxy(15, 10);
	cout << "¯ MINIMUM ELIGIBILITY FOR LIFE INSURANCE AGENCY";
	gotoxy(19, 12);
	cout << "* QUALIFICATION : 12th class passed";
	gotoxy(19, 14);
	cout << "* AGE : 18 years completed";
	gotoxy(19, 16);
	cout << "* Applicant should have passed the online exam";
	gotoxy(21, 18);
	cout << "conducted by NSE-IT";
	gotoxy(15, 22);
	cout << "¯ AGENT'S LICENSE is issued for 3 years in the";
	gotoxy(17, 24);
	cout << "beginning and renewed thereafter for another 3 years";
	gotoxy(17, 26);
	cout << "after the completion of 25 hours of Agent's training.";
	gotoxy(15, 30);
	cout << "¯ BUSINESS CONDITION FOR THE AGENCY ENFORCED";
	gotoxy(19, 32);
	cout << "* 12 lives with 1 lac sum assured";
	gotoxy(19, 34);
	cout << "* First Premium Income(FPI) : Rs. 1 lac";

	cout << "\n\n";
	for (x = 0; x < 80; x++)
	{
		delay(5);
		cout << "";
	}

	for (y = 2; y < 36; y++)
	{
		delay(5);
		gotoxy(80, y);
		cout << "";
	}

	getch();
}

/* DISPLAY FEEDBACK FORM */
void feed()
{
	char str[9] = "THANK YOU";
	clrscr();

	gotoxy(34, 3);
	cout << "FEEDBACK FORM";
	gotoxy(34, 4);
	cout << "*************";
	gotoxy(6, 6);
	cout << "Please enter the following details : ";
	gotoxy(6, 8);
	cout << "AGE : ";
	gotoxy(6, 10);
	cout << "GENDER (m/f) : ";
	gotoxy(6, 12);
	cout << "OCCUPATION : ";
	gotoxy(6, 14);
	cout << "MONTHLY INCOME : ";
	gotoxy(32, 16);
	cout << "QUESTIONAIRE FORM";
	gotoxy(32, 17);
	cout << "*****************";
	gotoxy(6, 19);
	cout << "How would you rate LIC's performance on the following service features";
	gotoxy(6, 21);
	cout << "using (1-7) where \"1\" indicates LOW rating & \"7\" indicates HIGH rating";
	gotoxy(6, 23);
	cout << "1. LIC performs the service right the first time : ";
	gotoxy(6, 25);
	cout << "2. Agents in LIC give you prompt service : ";
	gotoxy(6, 27);
	cout << "3. Agents in LIC are always willing to help you : ";
	gotoxy(6, 29);
	cout << "4. You feel safe in your transactions with LIC : ";
	gotoxy(6, 31);
	cout << "5. Agents of LIC understand your specific needs : ";
	gotoxy(6, 33);
	cout << "6. LIC agents have the knowledge to answer your questions : ";
	gotoxy(6, 35);
	cout << "7. LIC has modern-looking equipments : ";
	gotoxy(6, 37);
	cout << "8. LIC has convenient business hours : ";
	gotoxy(6, 39);
	cout << "9. Location of LIC office is conducive : ";
	gotoxy(6, 41);
	cout << "10. Range of life insurance plans : ";
	gotoxy(6, 43);
	cout << "11. Premium rates of insurance plans : ";
	gotoxy(6, 45);
	cout << "12. Trouble free policy servicing : ";

	gotoxy(12, 8);
	cin >> fbk.age;

	gotoxy(21, 10);
b:
	fbk.gndr = getch();
	switch (fbk.gndr)
	{
	case 'm':
	case 'M':

	case 'f':
	case 'F':
		cout << fbk.gndr;
		break;

	default:
		goto b;
	}
	getch();

c:
	gotoxy(19, 12);
	gets(fbk.occp);
	if (strcmp(fbk.occp, "\0") == 0)
		goto c;

	gotoxy(23, 14);
	cin >> fbk.inc;

	gotoxy(57, 23);
	fbk.a[0] = feedval();

	gotoxy(49, 25);
	fbk.a[1] = feedval();

	gotoxy(56, 27);
	fbk.a[2] = feedval();

	gotoxy(55, 29);
	fbk.a[3] = feedval();

	gotoxy(56, 31);
	fbk.a[4] = feedval();

	gotoxy(66, 33);
	fbk.a[5] = feedval();

	gotoxy(45, 35);
	fbk.a[6] = feedval();

	gotoxy(45, 37);
	fbk.a[7] = feedval();

	gotoxy(47, 39);
	fbk.a[8] = feedval();

	gotoxy(42, 41);
	fbk.a[9] = feedval();

	gotoxy(45, 43);
	fbk.a[10] = feedval();

	gotoxy(42, 45);
	fbk.a[11] = feedval();

	gotoxy(36, 47);
	for (int x = 0; x < 9; x++)
	{
		cout << str[x];
		delay(100);
	}

	getch();
	exit(0);
}

/* INPUT THE RATINGS & CHECK THEM */
char feedval()
{
	char x;
d:
	x = getch();

	if (x > '0' && x < '8')
		cout << x;

	else
		goto d;

	getch();

	return x;
}
