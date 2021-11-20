/*
	Name: B.A Thisara Dilshan
	Date: 24/10/21 19:54
	Description: Homework-10 
*/
#include <iostream>
using namespace std;
int main() {
	char text[10000];
	
	//creating a pointer of type file
	FILE *filePtr; 
	
	//this line will open the file and assign it to the pointer.
	filePtr = fopen("test.txt","w") ; 
	
	cout << "What do you want to print? ";
	fgets(text,sizeof(text),stdin) ; //this line will read the data user input via the fgets function
	fprintf(filePtr,"%s",text) ;
	fclose(filePtr); //closes the file.it is important to close the file whenever you open file in the programme.
	return 0;
}
