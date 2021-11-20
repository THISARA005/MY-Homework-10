#include<iostream>
#define textSize 1000 //character size of the text inputs
using namespace std;
int main(){
	FILE * fPtr;
	FILE * fTemp;
	char c;
	char path[100];
	char buffer[textSize];
	char newline[textSize];
	int line, count;
	cout << "Enter path of source file: ";
	cin >> path;
	fPtr = fopen(path,"r") ;
	if(fPtr == NULL){
		cout << "No such file!" ;
		return 0 ;
	}
	cout << "\n=======================================" ;
	cout << "\nThe data inside the file are :\n" ;
	cout << "=======================================\n" ;
	while((c=getc(fPtr))!=EOF) {
		printf("%c", c);
	}
	fclose(fPtr) ;
	cout << endl;
	printf("Enter the line number you want to replace: ");
	cin >> line;
	fflush(stdin); //removes the extra line created with stdin
	cout << "Enter the string you want to replace with : " ;
	fgets(newline, textSize, stdin);
	fPtr = fopen(path, "r");
	fTemp = fopen("replace.tmp", "w");
	count = 0;
	while ((fgets(buffer, textSize, fPtr)) != NULL){
		count++;
		/* If current line is line to replace */
		if (count == line)
		fputs(newline, fTemp);
		else
		fputs(buffer, fTemp);
	}
	fclose(fPtr);
	fclose(fTemp);
	remove(path); //delete the original file
	rename("replace.tmp", path); //replace the original file with the temp file
	cout << "Successfully replaced the line number " << line << endl;
	fPtr = fopen(path,"r") ;
	cout << "\n============================================" ;
	cout << "\nThe data inside the file after replacement :\n" ;
	cout << "============================================\n" ;
	while((c=getc(fPtr))!=EOF) {
		printf("%c", c);
	}
	fclose(fPtr) ;
	return 0;
}

