	#include <fstream>
	#include <iomanip>
	#include<iostream>
	#include<conio.h>
	using namespace std;
	void getScreen();
	fstream record;
	void welcome();
	void readRecord();
	void setData(float data);
	float getTDS(float x,float y);
	string quality(float tds);
	void run();
	int main(){	

	do{	
	getScreen();
	}while(true);
	}	
void getScreen(){
		welcome();
	char choice;
	screen:
	cout<<"\n\n\n\n\n";	
	cout<<"\t\t\t\t\t"<<"1. Check quality of Water.\n";
	cout<<"\t\t\t\t\t"<<"2. Show My Previous Records.\n";
	cout <<"\t\t\t\t\t"<<"3. Abort.\n\n";
	cout<<"\t\t\t\t\t"<<"Select ";
	choice=getch();
	switch(choice){
		case '1':
			run();
			break;
		case '2':
			readRecord();
			break;
		case '3':
			exit(1);
		default:
		system("cls");
		goto screen;	
	}
	cout<<"\t\t\tpress any key to get menu bar ";
	getch();
	system("cls");
	goto screen;	
	}
void welcome(){
	string s[]={"WELCOME TO ","GANGULY\'S PROJECT ","Let\'s check WATER QUALITY "};
	system("color 0");
	for(int k=0;k<3;k++)
	{	
	cout<<"\n\n\n\n\n"<<"\t\t\t\t\t"<<s[k];
	for(long v=0;v!=9e8;v++);
	system("cls");
	}	
}
void run(){
	float amount_Dish_filt;
	float amount_Dish_only;
	enter:
		system("cls");
	cout<<"\n\t\t\tEnter Amount of the Dish and Filtrate: ";
	cin>>amount_Dish_filt;
	fflush(stdin);
	cout<<"\n\t\t\tEnter the Weight of the Dish on its own.: ";
	cin>>amount_Dish_only;
	if(amount_Dish_filt<amount_Dish_only){
	cout<<"\n\t\t\tAmount Dish Filtrate lessthan Amount of Dish.\n\t\t\t wrong value enterd! : ";
		getch();
		system("cls");
		goto enter;
	}
	float tds=getTDS(amount_Dish_filt,amount_Dish_only);
	cout<<"\nTDS value :"<<setw(10)<<tds;
	cout<<"\nQuality   :"<<setw(20)<<quality(tds)<<"\n";
	setData(tds);
	
return;
}
float getTDS(float P,float Q){
float tds = (P-Q)*1000;
//		The TDS of your solution: TDS=[(A-B) * 1000]/mL
return tds;
}
void readRecord(){
	record.open("record.txt",ios::in);
	string line;
	cout<<'\n';
	while ( getline(record,line) )
    {
      cout << line <<'\n';
    }
    record.close();
}
void setData(float tds){
		record.open("record.txt",ios::app);
		record<<"tds value : "<<setw(20)<<tds<<"\t,Quality of Water : "<<quality(tds)<<'\n';
		record.close();
}
string quality(float tds){
	if(tds<=300)			
	return "Excellent";
	else if(tds<=600)
	return "Good";
	else if(tds<=900)
	return "Fair";
	else if(tds<=1200)
	return "Poor";
	else if(tds>1200)
	return "Very Bad";

return "Invalid Case";
}
