#include <string>
#include <iostream>
using namespace std;

int main()
{
	string s(5, '\0');
	s.append("a");
	cout << " s.size() " << s.size() << endl
		<< "s.first" << s[0] << endl
		<< "s.first.number " << (int)s[0] << endl
		<< "s " << s << endl; 
	return 0;
}