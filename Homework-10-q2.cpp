#include <iostream>
using namespace std;
int main() {
	char c;
	FILE *fptr;
	fptr =fopen("existing.bin","r");
	if(fptr == NULL){
		cout << "No such file!" ;
		return 0 ;
	}while((c=getc(fptr))!=EOF){
	//get c will get a single character from the file.this while part will read chars until it reaches end of line
		printf("%c", c);
	}
	return 0;
}
