#include <iostream>
#include <string.h>
using namespace std;
int getUSN(char * str) {
	int len = strlen(str);	
	int re = 0;
	for(int i=0; i<len; i++)
		for(int j=i+1; j<len; j++)
			if(str[i] > str[j])
				re++;
	return re;
}

int main() {
	int count, len;
	cin >> len >> count;
	char ** seq = new char*[count];
	int * usn = new int[count];
	for(int i=0; i<count; i++) {
		seq[i] = new char[len+1];
		cin >> seq[i];
		usn[i] = getUSN(seq[i]);
	}
	for(int i=0; i<count; i++)
		for(int j=0; j< count-i-1; j++)
			if(usn[j] > usn[j+1]) {
				char * temp = seq[j];
				seq[j] = seq[j+1];
				seq[j+1] = temp;
				int tmp = usn[j];
				usn[j] = usn[j+1];
				usn[j+1] = tmp;
			}
	for(int i=0; i<count; i++)
		cout << seq[i] << endl;

}
