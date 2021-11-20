#include<iostream>
using namespace std;
int main() {
	char c;
	char strng[10000];
	int count;
	FILE *fptr;
	cout << "How many lines do you need to print? " ;
	cin >> count ;
	fptr = fopen("third.txt","w");
	cout << "Enter the things you want to print below:"<< endl;
	for(int i=0 ; i<count+1 ;i++){
		fgets(strng,sizeof(strng),stdin) ;
		fprintf(fptr,"%s",strng);
	}
	fclose(fptr);
	cout << "----------------------------------------------------------\n" ;
	cout << "\nAll data were input to the file third.txt successfully!\nThe content in the file is: " ;
	fptr = fopen("third.txt","r");
	cout << "\n" ;
	while((c=getc(fptr))!=EOF) {
		printf("%c", c);
	}
	return 0;
}
