#include <iostream>
#include <cstring>
using namespace std;
class String{
	private:
		char *str;
		int len;
	public:
		String() {
			len = 0;
			str = nullptr;
		}
		String(const char *p) {
			len = strlen(p);
			str = new char [len+1];
			strcpy(str,p);

		}
		~String() {
			len = 0;
			delete[]str;
		}
		int lengh() {
			return len;
		}
};
int main(){
	String s1("adfgh");
	String s2(s1);
	cout << s1.lengh() << "  " <<  s2.lengh() ;
	return 0;
}
