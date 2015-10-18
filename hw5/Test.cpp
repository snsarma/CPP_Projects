#include <iostream>
#include <fstream>
using namespace std;
int main() {
ifstream input;
input.open("scores.txt");
// Testing file existence
if (input.fail()) {
cout << "File not exists" << endl;
return 0;

}
char fname[80];
char lname[80];
int score;
// Testing EoF
while(!input.eof()) {
input >> fname >> lname >> score;
cout<<fname<<lname<<score<<endl;
}
input.close();
}