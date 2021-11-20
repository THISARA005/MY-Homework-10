#include<iostream>
#define textSize 1000 //character size of the text inputs
using namespace std;
int main(){
	FILE * fPtr;
	FILE * fTemp;
	char c;
	char srcPath[100],mergePath[100];
	char buffer[textSize];
	fTemp = fopen("replace.tmp", "w");
	for (int i = 0 ; i < 2 ; i++){
		cout << "Enter path of source file "<< i+1 << " : " ;
		cin >> srcPath;
		fPtr = fopen(srcPath,"r") ;
		if(fPtr == NULL){
			cout << "No such file!" ;
			return 0 ;
		}
		while ((fgets(buffer, textSize, fPtr)) != NULL){
	 //reads the source file and copy the data to a temp file.
		fputs(buffer, fTemp);
		}
	}
	
	cout << "Input the new file name where to merge the above two files : " ;
	cin >> mergePath;
	fclose(fPtr);
	fclose(fTemp);
	rename("replace.tmp", mergePath); //replace the original file with the temp file
	cout << "Successfully copied the source files to the new file " << mergePath << endl;
	fPtr = fopen(mergePath,"r") ;
	cout << "\n=======================================" ;
	cout << "\nThe data inside the merge file is :\n" ;
	cout << "=======================================\n" ;
	while((c=getc(fPtr))!=EOF) {
		printf("%c", c);
	}
	fclose(fPtr) ;
	return 0;
}

