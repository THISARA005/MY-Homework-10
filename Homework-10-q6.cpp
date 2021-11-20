#include<iostream>
using namespace std;
int main() {
	char c;
	//array for getting the file name
	char fileName[100]; 
	
	int charNo = 0 ,wordNo =0;
	FILE *fptr;
	cout << "What is the file name you want to open ? " ;
	cin >> fileName ;
	fptr = fopen(fileName,"r") ;
	if(fptr == NULL){
		cout << "No such file!" ;
		return 0 ;
	} 
	while((c=fgetc(fptr))!=EOF) {
		//this will check for newline characrter(\n)
		if(c == '\n' || c == ' ' ){ 
			wordNo++ ;
		}else{
			charNo ++ ;
		}
	}
	fclose(fptr) ;
	cout << "\nThere are " <<charNo <<" character(s) and "<< wordNo+1 <<" word(s) in the file"<<fileName << endl ;
}

