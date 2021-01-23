#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
struct element{
	char elname[30];
	char elsymbol[10];
	int elAtomicNo;
	float elAtomicW;
	char elConfig[25];
	char elBlock[3];
};
FILE *fpe;
FILE *fpe1;
struct element el;
void explore();
void scientistAuthen();
void incorrectScientist();
void periodictable();
void addelement();
void viewelement();
void searchelement();
void searchBySymb();
void searchByNum();
void editelement();
void editname();
void editsymbol();
void editweig();
void editblock();
void editconf();
void deleteelement();
void mainpage();
void gotoxy(int x, int y)
{
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
}
void colorit(int col)
{                  
	HANDLE hstdout;
	hstdout = GetStdHandle( STD_OUTPUT_HANDLE );
		                                //12=red, 15=white---------------->this.colorit(12);  this.colorit(15);
	SetConsoleTextAttribute( hstdout, col );
}
void main()
{
    mainpage();
    system ("cls");
}
void mainpage() //MAIN PAGE
{ 
    system("cls");
    int pos=1,keypressed=0;
    int i,j;
	for(i=1;i<=15;++i)
	{
		gotoxy(30,i);
		colorit(15);
		for(j=1;j<=65;++j)
		{
		
		 if(j==1 || j==65 || i==1 || i==15)printf ("|");
		 else printf(" ");
	    }
	}
	
	while(keypressed!=13)
	{            //LOOP WILL RUN UNTIL ENTER KEY (HAVING VALUE 13) IS PRESSED
	gotoxy(40,2);colorit(15);printf ("Welcome to Modern Period Table");
	gotoxy(40,3);printf ("====================++++++====");
	gotoxy(35,6);colorit(15);if(pos==1){colorit(10);}printf ("Login as a Scientist And Explore The Modern Periodic Table");
	gotoxy(35,8);colorit(15);if(pos==2){colorit(10);}printf ("View The Modern Periodic Table");
	gotoxy(35,10);colorit(15);if(pos==3){colorit(10);}printf ("E x i t");
	keypressed = getch();
	if(keypressed==80)  //80 is the value for down key
	   {pos++;}
	if(keypressed==72)   //72 is the value of up key
	   {pos--;}            
	if(pos==4)pos=1; 
	if(pos==0)pos=3;
}
   if(pos==1){system("cls");scientistAuthen();}
   if(pos==2){system ("cls");periodictable();}
   if(pos==3){gotoxy(0,25);colorit(15);exit(0);system("cls");}
}
void scientistAuthen()
{
  FILE *fpe;
  fpe = fopen ("scientist.txt", "r");
  char sID[20],sPass[20],s1[20],pass[20];                 
  char ch,characpos=0;  	
  gotoxy(40,2); printf ("***Authentication Required***");	
  gotoxy(35,6);printf ("Enter Scientist ID : ");fflush(stdin);colorit(8);fflush(stdin);gets(sID);
  gotoxy(35,8);colorit(15);printf ("Enter Password : ");colorit(8);
  fflush(stdin);
    while (1)
{                                       //INFINITE LOOP (WILL TERMINATE ACCORDING TO THE CONDITIONS)
	ch=getch();
	if (ch==13)                                  //BY PRESSING THE ENTER KEY LOOP WILL TERMINATE
	break;
	else if (ch==8)
	{                              //BACKSPACE TO REMOVE A CHARACTER
	if(characpos>0)	
	{                             //BACKSPACE THE CHARACTERS UNTIL THE INDEX NUMBER IS GREATER THAN 0 
	characpos--;
	sPass[characpos]='\0';                        //PRINTING NULL CHARACTER AT THAT CHARACTER POSITION WHICH WE WANT TO REMOVE
	printf ("\b \b");
	    }                            //TO BRING THE CURSOR BACKWARD
    }   
    else 
	{
	sPass[characpos] = ch;
	characpos++;
	printf ("*");
	}                               //MASKING THE PASSWORD
}
   sPass[characpos] = '\0';   //TERMINATING THE STRING
   fscanf (fpe,"%s", &s1);
   fscanf (fpe,"%s", &pass);

   if (strcmp(sID,s1)==0 && strcmp(sPass,pass)==0)
   {
    system("cls");
    explore();
    }
    else incorrectScientist();
    fclose(fpe);
}
void incorrectScientist()
{
	int pos=1,keyp=0;
	gotoxy(37,12);colorit(15);{colorit(12);}printf ("Username or Password is Incorrect");
	while(keyp!=13)
	{
	gotoxy(47,15);colorit(15);if(pos==1){colorit(13);}printf ("Try Again");
	gotoxy(44,16);colorit(15);if(pos==2){colorit(13);}printf ("GO BACK TO MAIN PAGE");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--; 
	if(pos==3)pos=1;
	if(pos==0)pos=2;
	}
	if(pos==1)
	{
	system("cls");
	colorit(15);scientistAuthen();
	}
	if(pos==2)
	{
		system("cls");
		colorit(15);mainpage();
	}
}
void periodictable()
{
	int pos=1,keyp=0;
	char str[14][19][10] = {
		{"______","      ","      ","    ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","______"},
		{"| H  |","______","      ","    ","      ","      ","      ","      ","      ","      ","      ","      ","      ","______","______","______","______","______","| HE |"},
		{"| Li |","| Be |","      ","    ","      ","      ","      ","      ","      ","      ","      ","      ","      ","| B  |","| C  |","| N  |","| O  |","| F  |","| Ne |"},
		{"| Na |","| Mg |","______","    ","______","______","______","______","______","______","______","______","______","| Al |","| Si |","| P  |","| S  |","| Cl |","| Ar |"},
		{"| K  |","| Ca |","| Sc |","    ","| Ti |","| V  |","| Cr |","| Mn |","| Fe |","| Co |","| Ni |","| Cu |","| Zn |","| Ga |","| Ge |","| As |","| Se |","| Br |","| Kr |"},
		{"| Rb |","| Sr |","| Y  |","    ","| Zr |","| Nb |","| Mo |","| Tc |","| Ru |","| Rh |","| Pd |","| Ag |","| Cd |","| In |","| Sn |","| Sb |","| Te |","| I  |","| Xe |"},
		{"| Cs |","| Ba |","| La |","    ","| Hf |","| Ta |","| W  |","| Re |","| Os |","| Ir |","| Pt |","| Au |","| Hg |","| Tl |","| Pb |","| Bi |","| Po |","| At |","| Rn |"},
		{"| Fr |","| Ra |","| Ac |","    ","| Rf |","| Db |","| Sg |","| Bh |","| Hs |","| Mt |","| Ds |","| Rg |","| Cn |","| Nh |","| Fl |","| Mc |","| Lv |","| Ts |","| Og |"},
		{"------","------","------","    ","------","------","------","------","------","------","------","------","------","------","------","------","------","------","------"},
		{"      ","      ","      ","    ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      ","      "},
		{"      ","      ","      ","    ","______","______","______","______","______","______","______","______","______","______","______","______","______","______","      "},
		{"      ","      ","      ","    ","| Ce |","| Pr |","| Nd |","| Pm |","| Sm |","| Eu |","| Gd |","| Tb |","| Dy |","| Ho |","| Er |","| Tm |","| Yb |","| Lu |","      "},
		{"      ","      ","      ","    ","| Th |","| Pa |","| U  |","| Np |","| Pu |","| Am |","| Cm |","| Bk |","| Cf |","| Es |","| Fm |","| Md |","| No |","| Lr |","      "},
		{"      ","      ","      ","    ","------","------","------","------","------","------","------","------","------","------","------","------","------","------","      "},
	
	};
	int i,j;
	for(i=0;i<14;i++)
	{
		for(j=0;j<19;j++)
		printf("%s",str[i][j]);
		printf("\n");
	}
	while(keyp!=13)
	{
		gotoxy(45,26);colorit(15);if(pos==1){colorit(12);}printf("Go back To Main Page");
	    gotoxy(45,28);colorit(15);if(pos==2){colorit(12);}printf("      E X I T      ");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==3)pos=1;
	    if(pos==0)pos=2;
	}

		if(pos==1){system("cls");mainpage();}
		if(pos==2){gotoxy(0,25);colorit(15);exit(0);system("cls");}

}
void explore() //explore block..
{
	system("cls");
	int pos=1,keyp=0;
	
	while (keyp!=13)
	{
		if(keyp == 8)
		{
			system("cls");mainpage();
		}
    gotoxy(45,2);colorit(15);printf("Explore Element Portal");
	gotoxy(45,3);printf("----------------------");
	gotoxy(42,8);colorit(15);if(pos==1){colorit(10);}printf("Add Element Details");
	gotoxy(42,10);colorit(15);if(pos==2){colorit(10);}printf("View All Element Details");
	gotoxy(42,12);colorit(15);if(pos==3){colorit(10);}printf("Search Element Details");
	gotoxy(42,14);colorit(15);if(pos==4){colorit(10);}printf("Edit Element Details");
	gotoxy(42,16);colorit(15);if(pos==5){colorit(10);}printf("Delete Element Details");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==6)pos=1;
	if(pos==0)pos=5;
	}
	if(pos==1){system("cls");addelement();}
	if(pos==2){system("cls");viewelement();}
	if(pos==3){system("cls");searchelement();}
	if(pos==4){system("cls");editelement();}
	if(pos==5){system("cls");deleteelement();}
}
void addelement()
{
	int pos=1,keyp=0;
	system("cls");
	fpe=fopen("element details.txt","a");
	gotoxy(45,8);colorit(15);printf("Enter Element Name:");colorit(8);fflush(stdin);gets(el.elname);
	gotoxy(45,10);colorit(15);printf("Enter Element Symbol:");colorit(8);fflush(stdin);gets(el.elsymbol);
	gotoxy(45,12);colorit(15);printf("Enter Element Atomic No.:");colorit(8);fflush(stdin);scanf("%d",&el.elAtomicNo);
	gotoxy(45,14);colorit(15);printf("Enter Element Atomic Weight:");colorit(8);fflush(stdin);scanf("%f",&el.elAtomicW);fflush(stdin);
	gotoxy(45,16);colorit(15);printf("Enter Element Block:");colorit(8);fflush(stdin);gets(el.elBlock);
	gotoxy(45,18);colorit(15);printf("Enter Element Configuration:");colorit(8);fflush(stdin);gets(el.elConfig);
    fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);

    fclose(fpe);
	while(keyp!=13)
	{
		gotoxy(45,26);colorit(15);if(pos==1){colorit(12);}printf("Add One More Element Detail");
	    gotoxy(45,27);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE PAGE");
		gotoxy(45,28);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}

		if(pos==1){system("cls");addelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void viewelement()
{
	int pos=1,keyp=0;
	system("cls");
	fpe=fopen("element details.txt","r");
    colorit(15);while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
	colorit(15);printf("\nName : %s\nSymbol : %s\nAtomic No. : %d\nAtomic Weight : %f\nElement Block : %s\nElement Configuration : %s\n\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
	fclose(fpe);
	while(keyp!=13){
	    gotoxy(45,27);colorit(15);if(pos==1){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,28);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==3)pos=1;
	if(pos==0)pos=2;
		}
		if(pos==1){system("cls");explore();}
		if(pos==2){system("cls");mainpage();}
}
void searchelement()
{
	system("cls");
	int pos=1,keyp=0;
	
	while (keyp!=13)
	{
		if(keyp == 8)
		{
			system("cls");mainpage();
		}
    gotoxy(45,2);colorit(15);printf("Search Element Portal");
	gotoxy(45,3);printf("----------------------");
	gotoxy(42,8);colorit(15);if(pos==1){colorit(10);}printf("Search By Symbol");
	gotoxy(42,10);colorit(15);if(pos==2){colorit(10);}printf("Search By Atomic Number");
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==3)pos=1;
	if(pos==0)pos=2;
	}
	if(pos==1){system("cls");searchBySymb();}
	if(pos==2){system("cls");searchByNum();}
	
}
void searchBySymb()
{
	int pos=1,keyp=0;
	char searchEl[30];int flag=0;
	system("cls");
	gotoxy(45,3);colorit(15);printf("****Search Element By Symbol****");
	gotoxy(10,6);colorit(15);printf("Enter Element Symbol to Search Element Record : ");colorit(8);fflush(stdin);scanf("%s",searchEl);
	fpe=fopen("element details.txt","r");
	gotoxy(45,12);colorit(5);while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if(strcmp(el.elsymbol,searchEl)==0)
		{
			gotoxy(45,10);colorit(14);printf("R E C O R D   F O U N D");
			gotoxy(45,12);colorit(5);printf("\n\t\t\t\t\t\tName : %s\n\n\t\t\t\t\t\tSymbol : %s\n\n\t\t\t\t\t\tAtomic No : %d\n\n\t\t\t\t\t\tAtomic Weight : %f\n\n\t\t\t\t\t\tElement Block : %s\n\n\t\t\t\t\t\tElement Config : %s\n\n\t\t\t\t\t\t",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
			flag=1;
		}
	}
	if(flag==0)
	{gotoxy(45,18);colorit(1);printf("R E C O R D.N O T.F O U N D\a\a\a");}
    fclose(fpe);
    while(keyp!=13)
	{
		gotoxy(45,30);colorit(15);if(pos==1){colorit(12);}printf("SEARCH ANOTHER RECORD");
	    gotoxy(45,31);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,32);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");searchelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void searchByNum()
{
	int pos=1,keyp=0;
	int searchEl;int flag=0;
	system("cls");
	gotoxy(45,3);colorit(15);printf("****Search Element By Atomic Number****");
	gotoxy(10,6);colorit(15);printf("Enter Atomic Number to Search Element Record : ");colorit(8);fflush(stdin);scanf("%d",&searchEl);
	fpe=fopen("element details.txt","r");
	gotoxy(45,12);colorit(5);while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( el.elAtomicNo == searchEl )
		{
			gotoxy(45,10);colorit(14);printf("R E C O R D   F O U N D");
			gotoxy(45,12);colorit(5);printf("\n\t\t\t\t\t\tName : %s\n\n\t\t\t\t\t\tSymbol : %s\n\n\t\t\t\t\t\tAtomic No : %d\n\n\t\t\t\t\t\tAtomic Weight : %f\n\n\t\t\t\t\t\tElement Block : %s\n\n\t\t\t\t\t\tElement Config : %s\n\n\t\t\t\t\t\t",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
			flag=1;
		}
	}
	if(flag==0)
	{gotoxy(45,18);colorit(1);printf("R E C O R D.N O T.F O U N D\a\a\a");}
    fclose(fpe);
    while(keyp!=13)
	{
		gotoxy(45,30);colorit(15);if(pos==1){colorit(12);}printf("SEARCH ANOTHER RECORD");
	    gotoxy(45,31);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,32);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");searchelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void editelement()
{
	system("cls");
	int pos=1,keyp=0;
	while (keyp!=13)
	{
	gotoxy(45,2);colorit(15);printf("****Edit Element Details****");
	gotoxy(45,3);colorit(15);printf("____________________________");	
    gotoxy(15,9);colorit(15);if(pos==1){colorit(10);}printf("Edit Element Name");
	gotoxy(15,10);colorit(15);if(pos==2){colorit(10);}printf("Edit Element Symbol");
	gotoxy(15,11);colorit(15);if(pos==3){colorit(10);}printf("Edit Element Atomic Weight");
	gotoxy(15,12);colorit(15);if(pos==4){colorit(10);}printf("Edit Element Block");
	gotoxy(15,13);colorit(15);if(pos==5){colorit(10);}printf("Edit Element Configuration");
    
	keyp=getch();
	if(keyp==80)pos++;
	if(keyp==72)pos--;
	if(pos==6)pos=1;
	if(pos==0)pos=5;
	}
	if(pos==1){gotoxy(15,16);editname();}
	if(pos==2){gotoxy(15,16);editsymbol();}
	if(pos==3){gotoxy(15,16);editweig();}
	if(pos==4){gotoxy(15,16);editblock();}
	if(pos==5){gotoxy(15,16);editconf();}
}
void editname()
{
	int pos=1,keyp=0;
	int flag=0;
	char ename1[30];int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Atomic Number :");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( eid1 == el.elAtomicNo)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Name To EDIT :");colorit(8);fflush(stdin);scanf("%s",ename1);
	    fprintf(fpe1,"%s %s %d %f %s %s\n",ename1,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void editsymbol()
{
	int pos=1,keyp=0;
	int flag=0;
	char esymbol1[30];int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Atomic Number :");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( eid1 == el.elAtomicNo)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Symbol To EDIT :");colorit(8);fflush(stdin);scanf("%s",esymbol1);
	    fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,esymbol1,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void editweig()
{
	int pos=1,keyp=0;
	int flag=0;
	float eweig1;int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Atomic Number :");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( eid1 == el.elAtomicNo)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Atomic Weight To EDIT :");colorit(8);fflush(stdin);scanf("%f",&eweig1);
	    fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,eweig1,el.elBlock,el.elConfig);
	}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void editblock()
{
	int pos=1,keyp=0;
	int flag=0;
	char eblock1[30];int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Atomic Number :");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( eid1 == el.elAtomicNo)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Elemenet Block To EDIT :");colorit(8);fflush(stdin);scanf("%s",eblock1);
	    fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,eblock1,el.elConfig);
	}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}
void editconf()
{
	int pos=1,keyp=0;
	int flag=0;
	char econf1[30];int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(15,16);colorit(15);printf("Enter Atomic Number :");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( eid1 == el.elAtomicNo)
		{
			flag=1;
	    gotoxy(15,18);colorit(15);printf("Enter Elemenet Configuration To EDIT :");colorit(8);fflush(stdin);scanf("%s",econf1);
	    fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,econf1);
	}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,19);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,24);colorit(15);if(pos==1){colorit(12);}printf("EDIT ANOTHER RECORD");
	    gotoxy(45,25);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,26);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");editelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}


void deleteelement()
{
	system("cls");
	int pos=1,keyp=0;
	int flag=0;
	int eid1;
	fpe=fopen("element details.txt","r");
	fpe1=fopen("temp.txt","a");
	gotoxy(45,2);colorit(15);printf("****DELETE ELEMENT REDCORD****");
	gotoxy(45,3);colorit(15);printf("______________________________");
	gotoxy(15,6);colorit(15);printf("Enter Element Atomic Number Whose Record You Want To Delete:");colorit(8);fflush(stdin);scanf("%d",&eid1);
	while(fscanf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
	{
		if( el.elAtomicNo == eid1 )
		{
			flag=1;
			gotoxy(30,8);colorit(13);printf("R E C O R D..S U C C E S S F U L L Y.. D E L E T E D");
		}
	else
	{
	fprintf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
	}
}
if(flag==0){gotoxy(45,12);colorit(15);printf("Record Of Element with Atomic Number : %d is not found",eid1);}
fclose(fpe);
fclose(fpe1);
fpe=fopen("element details.txt","w");
fclose(fpe);
fpe=fopen("element details.txt","a");
fpe1=fopen("temp.txt","r");
	while(fscanf(fpe1,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,&el.elAtomicNo,&el.elAtomicW,el.elBlock,el.elConfig)!=EOF)
{
		fprintf(fpe,"%s %s %d %f %s %s\n",el.elname,el.elsymbol,el.elAtomicNo,el.elAtomicW,el.elBlock,el.elConfig);
}
fclose(fpe);
fclose(fpe1);
fpe=fopen("temp.txt","w");
fclose(fpe);
while(keyp!=13)
	{
		gotoxy(45,15);colorit(15);if(pos==1){colorit(12);}printf("DELETE ANOTHER RECORD");
	    gotoxy(45,16);colorit(15);if(pos==2){colorit(12);}printf("GO BACK TO EXPLORE BLOCK");
		gotoxy(45,17);colorit(15);if(pos==3){colorit(12);}printf("GO BACK TO MAIN PAGE BLOCK");
		keyp=getch();
	    if(keyp==80)pos++;
	    if(keyp==72)pos--;
	    if(pos==4)pos=1;
	    if(pos==0)pos=3;
	}
		if(pos==1){system("cls");deleteelement();}
		if(pos==2){system("cls");explore();}
		if(pos==3){system("cls");mainpage();}
}

