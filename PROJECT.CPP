#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>
#include<dos.h>

ifstream fin;
ofstream fout;
fstream file;
class country
{
	char name[100],cont[100],area[30],pop[30],capt[100],offlan[100];
	char cur[100],desc[500];
	int cono;
	public:
	void enter();
	void show();
	void enter1();
	int coun_no()
	{
		return cono;  //FUNCTION TO RETURN COUNTRY NUMBER;
	}
} V;  //CLASS OBJECT V;

 int num(int a)   //FUNCTION TO CHECK FOR UNIQUE COUNTRY NUMBER
 {
	fstream check;
	check.open("V.COUNTRY",ios::in|ios::binary);
	while(check.read((char*)&V,sizeof(V)))
	{
		if(a==V.coun_no())
		{
		    check.close();
		    return(0);
		}
	}
	check.close();
	return 1;
 }
void country::enter()
	{
		int g,s;
		textcolor(3);
		gotoxy(4,3);
		cprintf(" ENTER COUNTRY NUMBER:");
		cin>>g;
		s=num(g);
		if(s==1)
		{
			cono=g;
			textcolor(2);
			gotoxy(33,3);
			cprintf(" ENTER COUNTRY'S NAME:");
			gets(name);
			textcolor(5);
			gotoxy(4,5);
			cprintf(" ENTER CONTINENT IN WHICH COUNTRY IS:");
			gets(cont);
			textcolor(6);
			gotoxy(4,7);
			cprintf(" ENTER COUNTRY'S AREA(IN Sq.km):");
			gets(area);
			textcolor(23);
			gotoxy(4,9);
			cprintf(" ENTER COUNTRY'S POPULATION:");
			gets(pop);
			textcolor(28);
			gotoxy(4,11);
			cprintf(" ENTER COUNTRY'S CAPITAL:");
			gets(capt);
			textcolor(9);
			gotoxy(4,13);
			cprintf(" ENTER COUNTRY'S OFFICIAL LANGUAGE(S):");
			gets(offlan);
			textcolor(10);
			gotoxy(4,15);
			cprintf(" ENTER COUNTRY'S CURRENCY:");
			gets(cur);
			textcolor(11);
			gotoxy(4,17);
			cprintf(" ENTER ANY DESCRIPTION ABOUT COUNTRY (MAXIMUM 3 LINES)(PRESS / TO OVER):");
			textcolor(4);
			for(int i=0,u=17;i<500;++i)
			{

				desc[i]=getche();
				if(desc[i]=='\b')
				{
					cout<<" \b";
				}
				else if(desc[i]=='\n'||desc[i]=='\r')
				{
					u++;
					gotoxy(12,u);
				}
				else if(desc[i]=='/')
				{
					break;
				}
			}
			desc[i+1]='\0';
		}
		else
		{
			gotoxy(18,5);
			cout<<" COUNTRY NUMBER ALREADY EXISTS ";
			gotoxy(20,7);
			cout<<" DON'T PRESS ENTER ";
			delay(2500);
			gotoxy(20,9);
			cout<<" PLEASE ENTER AGAIN";
			delay(2000);
			void set(int sr,int sc,int er,int ec,int t);
			set(2,1,24,80,0);
			V.enter();
		}
	}
	void country::show()
	{
		textcolor(3);
		gotoxy(4,3);
		cprintf(" COUNTRY NUMBER:");
		cout<<cono;
		textcolor(2);
		gotoxy(33,3);
		cprintf(" COUNTRY'S NAME:");
		puts(name);
		textcolor(5);
		gotoxy(4,5);
		cprintf(" CONTINENT IN WHICH COUNTRY IS:");
		puts(cont);
		textcolor(6);
		gotoxy(4,7);
		cprintf(" COUNTRY'S AREA:");
		puts(area);
		textcolor(23);
		gotoxy(4,9);
		cprintf(" COUNTRY'S POPULATION:");
		puts(pop);
		textcolor(28);
		gotoxy(4,11);
		cprintf(" COUNTRY'S CAPITAL:");
		puts(capt);
		textcolor(9);
		gotoxy(4,13);
		cprintf(" COUNTRY'S OFFICIAL LANGUAGE(S):");
		puts(offlan);
		textcolor(10);
		gotoxy(4,15);
		cprintf(" COUNTRY'S CURRENCY:");
		puts(cur);
		gotoxy(4,17);
		textcolor(11);
		cprintf(" DESCRIPTION ABOUT COUNTRY :");
		textcolor(4);
		for(int i=0,u=17;i<500;++i)
		{
		      cprintf("%c",desc[i]);
		      if(desc[i]=='\n'||desc[i]=='\r')
		     {
			u++;
			gotoxy(12,u);
		     }
		     else if(desc[i]=='/')
		     {
			break;
		     }

		}
	}

void country::enter1()
	{
		char nm[100],con[100],ar[30],po[30],cap[100],oflan[100];
		char curr[100],des[500];
		gotoxy(10,3);
		cout<<" [ ENTER '@' IN ANY PART TO RETAIN OLD ONE ]";
		textcolor(3);
		gotoxy(4,4);
		cprintf("  COUNTRY NUMBER:");
		cout<<cono;
		textcolor(2);
		gotoxy(33,4);
		cprintf(" ENTER COUNTRY'S NAME:");
		gets(nm);
		textcolor(5);
		gotoxy(4,6);
		cprintf(" ENTER CONTINENT IN WHICH COUNTRY IS:");
		gets(con);
		textcolor(6);
		gotoxy(4,8);
		cprintf(" ENTER COUNTRY'S AREA(IN Sq.km):");
		gets(ar);
		textcolor(23);
		gotoxy(4,10);
		cprintf(" ENTER COUNTRY'S POPULATION:");
		gets(po);
		textcolor(28);
		gotoxy(4,12);
		cprintf(" ENTER COUNTRY'S CAPITAL:");
		gets(cap);
		textcolor(9);
		gotoxy(4,14);
		cprintf(" ENTER COUNTRY'S OFFICIAL LANGUAGE(S):");
		gets(oflan);
		textcolor(10);
		gotoxy(4,16);
		cprintf(" ENTER COUNTRY'S CURRENCY:");
		gets(curr);
		textcolor(11);
		gotoxy(4,18);
		cprintf(" ENTER ANY DESCRIPTION ABOUT COUNTRY (MAXIMUM 3 LINES)(PRESS / TO OVER):");
		textcolor(4);
		for(int i=0,u=18;i<500;++i)
		{
		     des[i]=getche();
		     if(des[i]=='\b')
		     {
			cout<<" \b";
		     }
		     else if(des[i]=='\n'||des[i]=='\r')
		     {
			u++;
			gotoxy(12,u);
		     }
		     else if(des[i]=='/'||des[i]=='@')
		     {
			break;
		     }
		}
		des[i+1]='\0';

		if(strcmp(nm,"@")!=0)
		{
			strcpy(name,nm);
		}
		if(strcmp(con,"@")!=0)
		{
			strcpy(cont,con);
		}
		if(strcmp(ar,"@")!=0)
		{
			strcpy(area,ar);
		}
		if(strcmp(po,"@")!=0)
		{
			strcpy(pop,po);
		}
		if(strcmp(cap,"@")!=0)
		{
			strcpy(capt,cap);
		}
		if(strcmp(oflan,"@")!=0)
		{
			strcpy(offlan,oflan);
		}
		if(strcmp(curr,"@")!=0)
		{
			strcpy(cur,curr);
		}
		if(strcmp(des,"\r@")!=0)
		{
		    strcpy(desc,des);
		}
	}

 struct quiz
 {
	char que[500],opt[4][100];
	char st;
	int ans;
 }Q;  //Q structure variable;

void load()
{
   textcolor(3);
   gotoxy(40,10);
   cprintf("LOADING");
   for(int x=20,i=1;x<=100;x++,i++)
   {
	textcolor(2);
	gotoxy(48,10);
	delay(20);
	cprintf("%d%",x);
	textcolor(4);
	gotoxy(i,12
	);
	delay(20);
	cprintf("0");
	textcolor(9);
	gotoxy(81-i,12);
	delay(20);
	cprintf("0");
   }
   textcolor(11+128);
   gotoxy(40,14);
   cprintf("PROJECT LOADING COMPLETED");
   gotoxy(40,18);
   textcolor(7+128);
   cprintf("PRESS ENTER TO CONTINUE");
   textcolor(1+128);
   gotoxy(58,22);
   cprintf("BY VIVEK CREATIONS");
   gotoxy(55,10);
   printf("\b\b\b   ");
}
void load1()
{
   int r,c,t;
   for(r=1;r<=5;r++)
   {    textcolor(4);
	gotoxy(2,1+r);
	for(t=1;t<=r;++t)
	printf("  ");
	delay(140);
	cprintf("0");
	for(t=1;t<=(5-r)*2-1;++t)
	printf("  ");
	delay(140);
	if(r!=5)
	cprintf("0");
   }
   for(r=1;r<=5;r++)
   {
	textcolor(2);
	gotoxy(21,1+r);
	delay(140);
	if(r==1||r==5)
	cprintf("0 0 0 0 0");
	else
	cprintf("    0");
   }
   for(r=1;r<=5;r++)
   {
	textcolor(3);
	gotoxy(31,1+r);
	for(t=1;t<=r;++t)
	printf("  ");
	delay(140);
	cprintf("0");
	for(t=1;t<=(5-r)*2-1;++t)
	printf("  ");
	delay(140);
	if(r!=5)
	cprintf("0");
   }
   for(r=1;r<=5;r++)
   {
	textcolor(5);
	gotoxy(52,1+r);
	if(r==1||r==3||r==5)
	{
		delay(140);
		cprintf("0 0 0 0");
	}
	else
	{
		delay(140);
		cprintf("0" );
	}
   }
   for(r=1;r<=5;r++)
   {
	textcolor(6);
	gotoxy(62,1+r);
	if(r==1)
	{
		delay(140);
		cprintf("0     0");
	}
	if(r==2)
       {
		delay(140);
		cprintf("0  0");
       }
	if(r==3)
	{
		delay(140);
		cprintf("00");
	}
	if(r==4)
	{
		delay(140);
		cprintf( "0  0");
	}
	if(r==5)
	{
		delay(140);
		cprintf("0     0");
	}
   }
}

void box(int sr, int sc,int er,int ec,int fg,int bg,int t)
{
	int r,c;
	textcolor(fg);
	textbackground(bg);
	gotoxy(sc,sr);
	cprintf("É");
	for(c=sc+1;c<ec;c++)
	cprintf("Í");
	cprintf("»");
       for(r=sr+1;r<er;r++)
       {
	gotoxy(ec,r);
	cprintf("º");
	gotoxy(ec,er);
	cprintf("¼");
	gotoxy(sc,r);
	cprintf("º");
	gotoxy(sc,er);
	cprintf("È");
       }
      gotoxy(sc,er-1);
      for(c=sc+1;c<ec;c++)
      {
	gotoxy(c,er);
	cprintf("Í");
      }
      for(r=sr+1;r<er;r++)
      {
	void bgc(int);
	bgc(t);
	gotoxy(sc+2,r);
	for(c=sc+3;c<ec;c++)
	cprintf(" ");
      }
}

void set(int sr,int sc,int er,int ec,int t)
{
	  for(int r=sr+1;r<er;r++)
	  {
	     void bgc(int);
	     bgc(t);
	     gotoxy(sc+2,r);
	     for(int c=sc+3;c<ec;c++)
	     cprintf(" ");
	  }
}

void bgc(int n)
{
	textbackground(n);
}
void fgc(int a)
{
	textcolor(a);
}

void screen()
{
	box(2,1,24,80,9,2,6);
	textcolor(0);
	textbackground(2);
	gotoxy(4,1);
	cprintf("VIVEK'S PROJECT SYSTEM:- [COUNTRIES OF THE WORLD] WELCOMES YOU");
	textcolor(12+8+128);
	gotoxy(45,25);
	cprintf("           VIVEK'S CREATIONS");
	textcolor(4);
}

void addc()
{
	char ch;
	fout.open("V.COUNTRY",ios::app|ios::binary);
	if(!fout)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
	   do
	   {
	      screen();
	      set(2,1,24,80,0);
	      V.enter();
	      gotoxy(4,22);
	      textcolor(15);
	      cprintf("  SAVE IT(Y/N):");
	      ch=getche();
	      if(ch=='y'||ch=='Y')
	      {
		  fout.write((char*)&V,sizeof(V));
		  cout<<"     [SAVED IN FILE COUNTRY]";
	      }
	      gotoxy(40,23);
	      fgc(15);
	      cprintf("  ADD MORE (Y/N):");
	      ch=getche();;
	   }while(ch=='y'||ch=='Y');
	}
	getch();
	fout.close();
}

void seeall()
{
	int n;
	fin.open("V.COUNTRY",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
	   screen();
	   fin.seekg(0,ios::beg);
	   while(fin.read((char*)&V,sizeof(V)))
	   {
		getch();
		set(2,1,24,80,0);
		V.show();
	   }
	}
	fin.seekg(0,ios::end);
	n=fin.tellg();
	if(n==0)
	{
	   screen();
	   box(10,10,14,74,1,4,2);
	   gotoxy(12,12);
	   cout<<" SORRY THERE ARE NO RECORDS IN A FILE, ADD RECORDS.";
	}
	getch();
	fin.close();
}

void seesp()
{
	int no,m=0,n,k=0;
	fin.open("V.COUNTRY",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
		fin.seekg(0,ios::end);
		n=fin.tellg();
		if(n==0)
		{
			screen();
			box(10,10,14,74,1,4,2);
			gotoxy(12,12);
			cout<<" SORRY THERE ARE NO RECORDS IN A FILE, ADD RECORDS.";
			k=1;
		}
		else
		{
			screen();
			box(10,10,16,74,1,4,2);
			gotoxy(12,12);
			cout<<" ENTER COUNTRY'S SERIAL NUMBER TO SEE ITS RECORD:";
			cin>>no;
			fin.seekg(0,ios::beg);
			while(fin.read((char*)&V,sizeof(V)))
			{
				if(no==V.coun_no())
				{       m=1;
					screen();
					set(2,1,24,80,0);
					V.show();
					getch();
					break;
				}
			}
		}
	}
	if(m==0&&k==0)
	{
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO RECORD IN FILE HAVING COUNTRY NUMBER	"<<no;
	}
	getch();
	fin.close();
}

void editc()
{
	int nom,m=0,rec=0,found=0,n,k=0;
	char ch;
	file.open("V.COUNTRY",ios::in|ios::out|ios::binary);
	if(!file)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
		file.seekp(0,ios::end);
		n=file.tellp();
		if(n==0)
		{
			k=1;
			screen();
			box(10,10,14,74,1,4,2);
			gotoxy(12,12);
			cout<<" SORRY THERE ARE NO RECORDS IN A FILE, ADD RECORDS.";
		}
		else
		{
			screen();
			box(10,10,16,74,1,4,2);
			gotoxy(12,12);
			cout<<" ENTER SERIAL NUMBER OF COUNTRY TO BE MODIFIED:";
			cin>>nom;
			file.seekg(0,ios::beg);
			while(file.read((char*)&V,sizeof(V)))
			{
				if(nom==V.coun_no())
				{
					found=1;
				}
				if(found==1)
				{
					m=1;
					screen();
					set(2,1,24,80,0);
					V.show();
					gotoxy(4,22);
					cout<<"   WANT TO MODIFY IT (Y/N):";
					cin>>ch;
					if(ch=='y'||ch=='Y')
					{
						screen();
						set(2,1,24,80,0);
						V.enter1();
						file.seekp((rec)*sizeof(V),ios::beg);
						file.write((char*)&V,sizeof(V));
						gotoxy(12,23);
						cout<<" RECORD MODIFIED";

					}
					getch();
					break;
				}
				rec++;

			}
	    }
	}
	if(m==0&&k==0)
	{
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO RECORD IN FILE HAVING COUNTRY NUMBER	"<<nom;
	}
	getch();
	file.close();
}
void delc()
{
	int found=0,sno,n,k=0;
	char ch;
	ofstream fil;
	fil.open("temp",ios::app|ios::binary);
	fin.open("V.COUNTRY",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
			fin.seekg(0,ios::end);
			n=fin.tellg();
			if(n==0)
			{
				k=1;
				screen();
				box(10,10,14,74,1,4,2);
				gotoxy(12,12);
				cout<<" SORRY THERE ARE NO RECORDS IN A FILE, ADD RECORDS.";
			}
			else
			{
				screen();
				box(10,10,16,74,1,4,2);
				gotoxy(12,12);
				cout<<" ENTER SERIAL NUMBER OF COUNTRY TO BE DELETED:";
				cin>>sno;
				fin.seekg(0,ios::beg);
				while(fin.read((char*)&V,sizeof(V)))
				{
					if(sno==V.coun_no())
					{
						found=1;
						screen();
						set(2,1,24,80,0);
						V.show();
						gotoxy(4,22);
						cout<<"   WANT TO DELETE IT (Y/N):";
						cin>>ch;
						if(ch=='n'||ch=='N')
						{
							fil.write((char*)&V,sizeof(V));
						}
						else
						{
							gotoxy(50,22);
							cout<<" RECORD DELETED";
						}
					}
					else
					{
						fil.write((char*)&V,sizeof(V));
					}
				}
			}
	}
	if(found==0&&k==0)
	{
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO RECORD IN FILE HAVING COUNTRY NUMBER	"<<sno;
	}
	fin.close();
	fil.close();
	remove("V.COUNTRY");
	rename("temp","V.COUNTRY");
	getch();
}
void enterq()
{
     gotoxy(4,4);
     fgc(7);
     cprintf(" ENTER QUESTION :-(ENTER ? TO END QUESTION)");
     gotoxy(20,5);
     fgc(2);
     for(int i=0,u=5;i<500;++i)
     {
	  Q.que[i]=getche();
	  if(Q.que[i]=='\b')
	  {
		cout<<" \b";
	  }
	  else if(Q.que[i]=='\n'||Q.que[i]=='\r')
	  {
		u++;
		gotoxy(20,u);
	  }
	  else if(Q.que[i]=='?')
	  {
		break;
	  }
     }
      for(i=0,u+=2;i<4;++i,u+=2)
      {
		gotoxy(20,u);
		cout<<" OPTION "<<i+1<<" :-";
		gets(Q.opt[i]);
      }
      gotoxy(20,u+1);
      cout<<"ENTER ANSWER NUMBER:-";
      cin>>Q.ans;
      Q.st='N';
}

void adq()
{
	char ch;
	fout.open("CTRY.QUIZ",ios::app|ios::binary);
	if(!fout)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
	  do
	  {
	    screen();
	    set(2,1,24,80,0);
	    enterq();
	    gotoxy(20,21);
	    textcolor(6);
	    cprintf("  SAVE IT(Y/N):");
	    ch=getche();
	    if(ch=='y'||ch=='Y')
	    {
		fout.write((char*)&Q,sizeof(Q));
		cout<<"     [SAVED IN FILE ]";
	    }
	    gotoxy(20,23);
	    fgc(2);
	    cprintf("WANT TO ADD MORE(Y/N):");
	    ch=getche();
	  }while(ch=='y'||ch=='Y');
	}
	getch();
	fout.close();
}
void showqs()
{
     gotoxy(20,5);
     fgc(2);
     for(int i=0,u=5;i<500;++i)
     {
	   cprintf("%c",Q.que[i]);
	   if(Q.que[i]=='\n'||Q.que[i]=='\r')
	  {
		u++;
		gotoxy(20,u);
	  }
	  else if(Q.que[i]=='?')
	  {
		break;
	  }
     }
      fgc(4);
      for(i=0,u+=2;i<4;++i,u+=2)
      {
		gotoxy(20,u);
		cout<<" OPTION "<<i+1<<" :-";
		puts(Q.opt[i]);
      }
      gotoxy(20,u+1);
      cout<<"ANSWER NUMBER:-"<<Q.ans;
      gotoxy(20,u+3);
      cout<<"QUESTION STATUS:-"<<Q.st;
}

void showallq()
{
	int n;
	fin.open("CTRY.QUIZ",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
	   screen();
	   fin.seekg(0,ios::beg);
	   while(fin.read((char*)&Q,sizeof(Q)))
	   {
		getch();
		set(2,1,24,80,0);
		showqs();
	   }
	}
	fin.seekg(0,ios::end);
	n=fin.tellg();
	if(n==0)
	{
	    screen();
	   box(10,10,14,74,1,4,2);
	   gotoxy(12,12);
	   cout<<" SORRY THERE ARE NO QUESTIONS IN A FILE, ADD QUESTIONS.";
	}
	getch();
	fin.close();
}

void show1q()
{
	int no,m=0,n,k=0,r;
	fin.open("CTRY.QUIZ",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
		fin.seekg(0,ios::end);
		n=fin.tellg();
		r=n/sizeof(Q);
		if(n==0)
		{
			screen();
			box(10,10,14,74,1,4,2);
			gotoxy(12,12);
			cout<<" SORRY THERE ARE NO QUESTIONS IN A FILE, ADD QUESTIONS.";
			k=1;
		}

		else
		{
			screen();
			box(10,10,16,74,1,4,2);
			gotoxy(12,12);
			cout<<" ENTER QUESTION NUMBER TO SEE QUESTION (1 -"<<r<<" ):";
			cin>>no;
			if(no<=r&&no>=1)
			{
				no--;
				m=1;
			}
			if(m==1)
			{
				screen();
				set(2,1,24,80,0);
				fin.seekg(no*sizeof(Q),ios::beg);
				fin.read((char*)&Q,sizeof(Q));
				showqs();
				getch();
			}
		   }
	}

	 if(m==0&&k==0)
	 {
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO QUESTION IN FILE  WITH NUMBER "<<no;
	 }
	getch();
	fin.close();
}

void editq()
{
	int nom,m=0,found=0,n,k=0,r;
	char ch;
	file.open("CTRY.QUIZ",ios::in|ios::out|ios::binary);
	if(!file)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
		file.seekp(0,ios::end);
		n=file.tellp();
		r=n/sizeof(Q);
		if(n==0)
		{
			k=1;
			screen();
			box(10,10,14,74,1,4,2);
			gotoxy(12,12);
			cout<<" SORRY THERE ARE NO QUESTIONS IN A FILE, ADD QUESTIONS.";
		}
		else
		{
			screen();
			box(10,10,16,74,1,4,2);
			gotoxy(12,12);
			cout<<" ENTER QUESTION NUMBER TO BE MODIFIED (1 -"<<r<<" ):";
			cin>>nom;
			if(nom<=r&&nom>=1)
			{
				nom--;
				m=1;
			}
			file.seekg(0,ios::beg);
			if(m==1)
			{
				found=1;
			}
			if(found==1)
			{
				screen();
				set(2,1,24,80,0);
				file.seekg(nom*sizeof(Q),ios::beg);
				file.read((char*)&Q,sizeof(Q));
				showqs();
				gotoxy(20,21);
				cout<<"   WANT TO MODIFY IT (Y/N):";
				cin>>ch;
				if(ch=='y'||ch=='Y')
				{
					screen();
					set(2,1,24,80,0);
					enterq();
					file.seekp((nom)*sizeof(Q),ios::beg);
					file.write((char*)&Q,sizeof(Q));
					gotoxy(20,22);
					cout<<" RECORD MODIFIED";
				}
			}
		}
	}
	if(m==0&&k==0)
	{
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO QUESTION IN FILE HAVING QUESTION NUMBER "<<nom;
	}
	getch();
	file.close();
}

void delq()
{
	int found=0,sno,n,k=0,r,y,z=0;
	char ch;
	ofstream fil;
	fil.open("tempq",ios::app|ios::binary);
	fin.open("CTRY.QUIZ",ios::in|ios::binary);
	if(!fin)
	{
		gotoxy(30,12);
		cout<<" FILE CANNOT OPEN";
		getch();
	}
	else
	{
		fin.seekg(0,ios::end);
		n=fin.tellg();
		r=n/sizeof(Q);
		if(n==0)
		{
			k=1;
			screen();
			box(10,10,14,74,1,4,2);
			gotoxy(12,12);
			cout<<" SORRY THERE ARE NO QUESTIONS IN A FILE, ADD QUESTIONS.";
		}
		else
		{
			screen();
			box(10,10,16,74,1,4,2);
			gotoxy(12,12);
			cout<<" ENTER SERIAL NUMBER OF QUESTION TO BE DELETED (1 -"<<r<<" ):";
			cin>>sno;
			if(sno<=r&&sno>=1)
			{
				sno--;
				found=1;
			}
			if(found==1)
			{
			       screen();
			       set(2,1,24,80,0);
			       fin.seekg(sno*sizeof(Q),ios::beg);
			       fin.read((char*)&Q,sizeof(Q));
			       showqs();
			       gotoxy(20,21);
			       cout<<"   WANT TO DELETE IT (Y/N):";
			       cin>>ch;
			       if(ch=='y'||ch=='Y')
			       {
					z=1;
					for(y=0;y<r;++y)
					{
					   if(y!=sno)
					   {
					     fin.seekg(y*sizeof(Q),ios::beg);
					     fin.read((char*)&Q,sizeof(Q));
					     fil.write((char*)&Q,sizeof(Q));
					   }
					}
				}
			}
		}
	}
	if(found==0&&k==0)
	{
		gotoxy(12,14);
		cout<<" SORRY,THERE IS NO QUESTION IN FILE HAVING QUESTION NUMBER "<<sno;
	}
	if(z==1)
	{
		remove("CTRY.QUIZ");
		rename("tempq","CTRY.QUIZ");
		gotoxy(60,22);
		cout<<" RECORD DELETED";
	}
	fin.close();
	fil.close();
	getch();
}

void refresh()
{
	file.open("CTRY.QUIZ",ios::in|ios::out|ios::binary);
	int m=0;
	file.seekg(0,ios::beg);
	while( file.read((char*)&Q,sizeof(Q)))
	{
		Q.st='N';
		file.seekp(m*sizeof(Q),ios::beg);
		file.write((char*)&Q,sizeof(Q));
		m++;
	}
	file.close();
}
void showplay()
{
     gotoxy(20,5);
     fgc(2);
     for(int i=0,u=5;i<500;++i)
     {
	   cprintf("%c",Q.que[i]);
	   if(Q.que[i]=='\n'||Q.que[i]=='\r')
	   {
		u++;
		gotoxy(20,u);
	   }
	   else if(Q.que[i]=='?')
	   {
		break;
	   }
     }
     fgc(4);
     for(i=0,u+=2;i<4;++i,u+=2)
     {
	  gotoxy(20,u);
	  cprintf(" OPTION %d :-",i+1);
	  puts(Q.opt[i]);
     }
     gotoxy(20,u+1);
}

void playq()
{
	int x,n,m,s=0,anns=0,p=0;
	file.open("CTRY.QUIZ",ios::in|ios::out|ios::binary);
	file.seekg(0,ios::end);
	n=file.tellg()/sizeof(Q);
	screen();
	box(10,10,18,74,1,4,2);
	gotoxy(12,14);
	cout<<" ANY WRONG ANSWER WILL STOP THE QUIZ!!  : ";
	gotoxy(12,12);
	cout<<"  HOW MANY QUESTIONS TO BE ASKED (OUT OF " <<n<<") : ";
	cin>>m;
	if(m>n||m<1)
	{
		gotoxy(25,16);
		cout<<" WRONG ENTRY";
		p=1;
		s=1;
	}
	else
	{
		screen();
		set(2,1,24,80,0);
		int g;
		for(x=0;x<m&&p==0;x++)
		{
			g=random(n);
			file.seekg(g*sizeof(Q),ios::beg);
			file.read((char*)&Q,sizeof(Q));
			if(Q.st=='N')
		    {
			set(2,1,24,80,0);
			s++;
			gotoxy(15,6);
			cout<<"Q."<<s;
			showplay();
			cout<<" ENTER OPTION NO. TO ANSWER(1,2,3,4):";
			cin>>anns;
			gotoxy(20,22);
			if(Q.ans==anns)
			{
				fgc(6);
				cprintf(" CORRECT ANSWER");
				 getch();
			}
			else
			{
				fgc(6);
				cprintf(" SORRY WRONG ANSWER");
				getch();
				p=1;
			}
			Q.st='Y';
			file.seekp(g*sizeof(Q),ios::beg);
			file.write((char*)&Q,sizeof(Q));
			getch();
		}
	}
   }
		int d=0,q;
		q=s;
		for(x=0;x<n&&q<m&&p==0;x++)
		{
		   file.seekg(x*sizeof(Q),ios::beg);
		   file.read((char*)&Q,sizeof(Q));
		   if(Q.st=='N')
		   {
			set(2,1,24,80,0);
			d++;
			q=s+d;
			gotoxy(15,6);
			cout<<"Q."<<q;
			showplay();
			cout<<" ENTER OPTION NO. TO ANSWER(1,2,3,4):";
			cin>>anns;
			gotoxy(20,22);
			if(Q.ans==anns)
			{
				fgc(6);
				cprintf(" CORRECT ANSWER");
				getch();
			}
			else
			{
				fgc(6);
				cprintf(" SORRY WRONG ANSWER");
				p=1;
				getch();
			}
			Q.st='Y';
			file.seekp(x*sizeof(Q),ios::beg);
			file.write((char*)&Q,sizeof(Q));
			getch();
		   }
		}
		if((s==0||q<m)&&p!=1)
		{
			screen();
			box(12,12,16,70,0,1,2);

			gotoxy(20,14);
			cout<<" ALL QUESTIONS ARE ASKED ,PLEASE REFRESH";
		}
	getch();
	file.close();
}

void playc()
{
       int op,r,c;
       do
       {
	     screen();
	     box(3,20,23,55,4,11,7);
	     gotoxy(34,3);
	     cout<<"PLAY MENU";
	     gotoxy(29,5);
	     fgc(3);
	     cprintf("1.ADD QUESTIONS ");
	     gotoxy(29,7);
	     cprintf("2.SHOW ALL QUESTIONS ");
	     gotoxy(29,9);
	     cprintf("3.SHOW SPECIFIC QUESTION ");
	     gotoxy(29,11);
	     cprintf("4.EDIT QUESTION");
	     gotoxy(29,13);
	     cprintf("5.DELETE QUESTION ");
	     gotoxy(29,15);
	     cprintf("6.REFRESH QUESTIONS ");
	     gotoxy(29,17);
	     cprintf("7.PLAY QUIZ ");
	     gotoxy(29,19);
	     cprintf("8.EXIT ");
	     gotoxy(29,21);
	     fgc(17);
	     cprintf("ENTER CHOICE:- ");
	     cscanf("%d",&op);
	     switch(op)
	     {
		case 1:
			screen();
			adq();
			break;

		case 2:
			screen();
			showallq();
			break;

		case 3:
			screen();
			show1q();
			getch();
			break;

		case 4:
			screen();
			editq();
			getch();
			break;

		case 5:
			screen();
			delq();
			getch();
			break;

		case 6:
			screen();
			refresh();
			getch();
			break;

		case 7:
			screen();
			playq();
			getch();
			break;
	     }
       }while(op!=8);
}

void menu()
{
       int op,r,c;
       do
       {       	screen();
		box(8,22,20,61,0,0,0);
		box(7,20,19,60,11,4,4);
		gotoxy(35,7);
		fgc(1);
		cout<<"MAIN MENU";
		for(r=8;r<19;r++)
		{
			bgc(4);
			gotoxy(21,r);
			for(c=20;c<59;c++)
			cprintf(" ");
		}
		fgc(15);
		gotoxy(23,9);
		cprintf("1.ADD INFRO OF NEW COUNTRY");
		gotoxy(23,10);
		cprintf("2.SEE ALL COUNTRY'S INFRO");
		gotoxy(23,11);
		cprintf("3.SEE SPECIFIC COUNTRY'S RECORD");
		gotoxy(23,12);
		cprintf("4.EDIT RECORD OF ANY COUNTRY");
		gotoxy(23,13);
		cprintf("5.DELETE RECORD OF ANY COUNTRY");
		gotoxy(23,14);
		cprintf("6.PLAY COUNTRY QUIZ");
		gotoxy(23,15);
		cprintf("7.EXIT");
		gotoxy(23,17);
		fgc(0);
		cprintf("ENTER CHOICE [ ]\b\b");
		cscanf("%d",&op);
		switch(op)
		{
			case 1:
				screen();
				addc();
				break;
			case 2:
				screen();
				seeall();
				getch();
				break;
			case 3:
				screen();
				seesp();
				getch();
				break;
			case 4:
				screen();
				editc();
				getch();
				break;
			case 5:
				screen();
				delc();
				getch();
				break;
			case 6:
				screen();
				playc();
				getch();
				break;
		}
      }while(op!=7);
}

void main()
{
	 randomize();
	  textbackground(0);
	  clrscr();
	  load1();
	for(int a=1;a<=80;a++)
	{
		gotoxy(a,12);
		textcolor(15);
		cprintf("0");
	}
	load();
	getch();
	set(-1,-1,27,82,2);
	menu();
	screen();
	box(7,10,17,70,4,1,3);
	gotoxy(17,12);
	for(int i=1;i<=50;++i)
	{
		bgc(0);
		gotoxy(16+i,12);
		delay(50);
		cprintf("  ");
	}
	char ar[]="THANKS FOR VISITING VIVEK'S COMPUTER PROJECT.";
	int l=strlen(ar);
	gotoxy(17,12);
	for(i=0;i<l;++i)
	{
		fgc(4);
		delay(110);
		cprintf("%c",ar[i]);
	}
	delay(2500);
	getch();
}
