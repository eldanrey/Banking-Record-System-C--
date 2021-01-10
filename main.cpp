/*
 * Author: KageSama
 ->Add Record
 ->Show Record
 ->Search Record
 ->Update Record
 ->Delete Record
 ->Quit
 
 Record:
 Account Number;
 First Name;
 Last Name;
Account Balance;
 */
#include <iostream>
#include <sstream>
#include <fstream>
#include<windows.h>
#include <iomanip>

std::ifstream inFile;
std::ofstream outFile;
int main();
int exitprog(){
	std::cout<<"\n\n\t\t\tTHANK YOU FOR USING MY PROGRAM\n\n\n";
	system("pause");
	exit(0);
}
void AddRecord(){
	aRecord:
	std::cout<<"\t\t--------------ADD RECORD--------------\n\n";
	std::string fName,lName,accNum,s,DBaccNum;
	float accBal;
	bool present=false;
	inFile.open("data.dat");
	std::cout<<"Please enter your Account Number(-1 to go back): ";
	std::cin>>accNum;
	if(accNum=="-1"){
		system("cls");
		main();
	}
	while(getline(inFile,s)){
		std::stringstream ss(s);
		ss>>DBaccNum;
		if(accNum==DBaccNum){
			present=true;
			break;
		}
	}
	inFile.close();
	if(present){
		system("cls");
		std::cout<<"\n\n\t\t\tThis Account Number is already taken\n\n\n\n";
		system("pause");
		system("cls");
		goto aRecord;
		
	}
	else{
	std::cout<<"Please enter your First Name: ";
	std::cin>>fName;
	std::cout<<"Please enter your Last Name: ";
	std::cin>>lName;
	accBal=1000;
	outFile.open("data.dat",std::ios::app);
	outFile<<accNum<<" "<<fName<<" "<<lName<<" "<<accBal<<'\n';
	outFile.close();	
	}
	system("cls");
	std::cout<<"\n\n\t\t\tACCOUNT ADDED\n\n\n";
	Sleep(1500);
	system("cls");
	main();
	
}
void ShowRecord(){
	sRecord:
	std::cout<<"\t\t--------------SHOW RECORD--------------\n\n";
	system("cls");
	std::string fName="",lName="",accNum,s;
	float accBal=0;
	inFile.open("data.dat");
	while(getline(inFile,s)){
		std::stringstream ss(s);
		ss>>accNum>>fName>>lName>>accBal;
		std::cout<<"Account Number: "<<accNum;
		std::cout<<"\nFirst Name: "<<fName;
		std::cout<<"\nLast Name: "<<lName;
		std::cout<<"\nAccount Balance: "<<std::fixed<<std::setprecision(2)<<accBal<<"\n\n";
	}
	inFile.close();
	std::cout<<"\n\n[1]Go back to menu\n[2]Quit\nYour choice: ";
	char choice;
	std::cin>>choice;
	system("cls");
	switch(choice){
		case '1':{
			main();
			break;
		}
		case '2':{
			exitprog();
			break;
		}
		default:{
			std::cout<<"\n\n\t\t\tWRONG INPUT!!! TRY AGAIN\n\n";
			goto sRecord;
			break;
		}
	}
}
void SearchRecord(){
	shRecord:
	std::cout<<"\t\t--------------SEARCH RECORD--------------\n\n";
	std::string fName="",lName="",accNum;
	float accBal=0;
	std::cout<<"Please Enter the Account Number(-1 to go back): ";
	std::cin>>accNum;
	if(accNum=="-1"){
		system("cls");
		main();
	}
	inFile.open("data.dat");
	std::string DBfName,DBlName,DBaccNum;
	float DBaccBal;
	std::string s;
	while(getline(inFile,s)){
		std::stringstream ss(s);
		ss>>DBaccNum>>DBfName>>DBlName>>DBaccBal;
		if(DBaccNum==accNum){
			accNum=DBaccNum;
			fName=DBfName;
			lName=DBlName;
			accBal=DBaccBal;
			break;
		}
	}
	inFile.close();
	system("cls");
	std::cout<<"Account Number: "<<accNum;
	std::cout<<"\nFirst Name: "<<fName;
	std::cout<<"\nLast Name: "<<lName;
	std::cout<<"\nAccount Balance: "<<std::fixed<<std::setprecision(2)<<accBal;
	std::cout<<"\n\n[1]Go back to menu\n[2]Quit\nYour choice: ";
	char choice;
	std::cin>>choice;
	system("cls");
	switch(choice){
		case '1':{
			main();
			break;
		}
		case '2':{
			exitprog();
			break;
		}
		default:{
			std::cout<<"\n\n\t\t\tWRONG INPUT!!! TRY AGAIN\n\n";
			goto shRecord;
			break;
		}
	}
}
void UpdateRecord(){
	uRecord:
	std::cout<<"\t\t--------------UPDATE RECORD--------------\n\n";
	std::string fName="",lName="",accNum,DBaccNum,DBfName,DBlName,s;
	float accBal=0,DBaccBal;
	bool present=false;
	inFile.open("data.dat");
	
	std::cout<<"Please Enter the account number you want to edit(-1 to go back): ";
	std::cin>>accNum;
	if(accNum=="-1"){
	system("cls");
	main();
	}
	while(getline(inFile,s)){
		std::stringstream ss(s);
		ss>>DBaccNum;
		if(DBaccNum==accNum){
			present=true;
			break;
		}
		else present=false;
	}
	inFile.close();
	
	if(present){
	inFile.open("data.dat");
	outFile.open("temp.dat");
	while(getline(inFile,s)){
		std::stringstream ss(s);
			ss>>DBaccNum>>DBfName>>DBlName>>DBaccBal;
			if(DBaccNum==accNum){
				std::cout<<"Account Number: ";
				std::cin>>accNum;
				std::cout<<"\nFirst Name: ";
				std::cin>>fName;
				std::cout<<"\nLast Name: ";
				std::cin>>lName;
				std::cout<<"Account Balance: ";
				std::cin>>accBal;
				outFile<<accNum<<" "<<fName<<" "<<lName<<" "<<accBal<<'\n';
			}
			else{
				outFile<<DBaccNum<<" "<<DBfName<<" "<<DBlName<<" "<<DBaccBal<<'\n';
			}
	}
	inFile.close();
	outFile.close();
	remove("data.dat");
	rename("temp.dat","data.dat");
	system("cls");
	std::cout<<"\n\n\t\t\tACCOUNT DATA UPDATED\n\n";
	system("pause");
	system("cls");
	main();
	}
	else{
		system("cls");
		std::cout<<"\n\n\t\t\tINVALID ACCOUNT NUMBER TRY AGAIN\n\n\n";
		system("pause");
		system("cls");
		goto uRecord;
	}

}
void DeleteRecord(){
	dRecord:
	std::cout<<"\t\t--------------DELETE RECORD--------------\n\n";
	//get acc number -> make temp file -> store each data without the inputted data -> rename data.dat
	std::string fName="",lName="",accNum,DBaccNum,DBfName,DBlName,s;
	float accBal=0,DBaccBal;
	bool present=false;
	std::cout<<"Please Enter the account number you want to delete(-1 to go back): ";
	std::cin>>accNum;
	if(accNum=="-1"){
		system("cls");
		main();
	}
	inFile.open("data.dat");
	while(getline(inFile,s)){
		std::stringstream ss(s);
		ss>>DBaccNum;
		if(accNum==DBaccNum){
			present=true;
			break;
		}
	}
	inFile.close();
	if(present){
		inFile.open("data.dat");
		outFile.open("temp.dat");
		while(getline(inFile,s)){
			std::stringstream ss(s);
			ss>>DBaccNum>>DBfName>>DBlName>>DBaccBal;
			if(DBaccNum!=accNum){
				outFile<<DBaccNum<<" "<<DBfName<<" "<<DBlName<<" "<<DBaccBal<<"\n";
			}
		}
		inFile.close();
		outFile.close();
		remove("data.dat");
		rename("temp.dat","data.dat");
		system("cls");
		std::cout<<"\n\n\t\t\tACCOUNT DATA SUCCESSFULLY DELETED\n\n";
		Sleep(1500);
		system("cls");
		main();
	}
	else{
		system("cls");
		std::cout<<"\n\n\t\t\tINVALID ACCOUNT NUMBER TRY AGAIN\n\n\n";
		system("pause");
		system("cls");
		goto dRecord;
	}
	
	
	
}

int main(){
	std::cout<<"Please Enter your choice: ";
	std::cout<<"\n[1]Add Record\n[2]Show Records\n[3]Search Records\n[4]Update Records\n[5]Delete Records\n[6]Quit\nYour choice: ";
	char choice;
	std::cin>>choice;
	system("cls");
	switch(choice){
		case '1':{
			AddRecord();
			break;
		}
		case '2':{
			ShowRecord();
			break;
		}
		case '3':{
			SearchRecord();
			break;
		}
		case '4':{
			UpdateRecord();
			break;
		}
		case '5':{
			DeleteRecord();
			break;
		}
		case '6':{
			exit(0);
			break;
		}
	}
}
//DONE
