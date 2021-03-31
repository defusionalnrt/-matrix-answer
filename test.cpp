#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cstring>
#include <cstdlib>
class CSimpleString {
	char *str;
	unsigned int len;
public:
	CSimpleString();
	CSimpleString(char*);
	~CSimpleString();
	const char& operator[](unsigned int pos);
	CSimpleString& operator=(const CSimpleString &other);
	CSimpleString operator+(const CSimpleString &other);
	unsigned int length();
};
CSimpleString::CSimpleString(){
	len=0;
	str=NULL;
}
CSimpleString::CSimpleString(char* s){
	if(s!=NULL){
		len=strlen(s);
		str=new char[len+1];
		strcpy(str,s);
		str[len]='\0';
	}
	else{
		str=NULL;
		len=0;
	}
}
CSimpleString::~CSimpleString()
{
	if(str!=NULL)
	{
		delete[] str;
		str=NULL;
	}
}
const char& CSimpleString::operator[](unsigned int pos){
	return str[pos];
}
CSimpleString& CSimpleString::operator=(const CSimpleString &other){
	if(other.str!=str){
		delete[] str;
		str=NULL;
		str=new char[other.len+1];
		len=other.len;
		for(unsigned int i=0;i<=len;i++){
			str[i]=other.str[i];
		}
		return *this;
	}
	else{
		return *this;
	}
}
CSimpleString CSimpleString::operator+(const CSimpleString &other){
	
	
		char p[1000]={0};
		for(unsigned int i=0;i<len;i++){
			p[i]=str[i];
		}
		for(unsigned int i=len;i<len+other.len;i++){
			p[i]=other.str[i-len];
		}
		p[len+other.len]='\0';
		 CSimpleString a(p);
		return a;
	
}
unsigned int CSimpleString::length(){
	return len;
}
int main() {
	char str[100];
	cin >> str;
	CSimpleString s1(str);
	cin >> str;
	CSimpleString s2(str);
	CSimpleString s3;
	s1 = s1 + s3;
	s2 = s3 + s2;
	s3 = s1 + s2;
	s1 = s1;
	s1 = s3 + s2;
	for(int i = 0; i < s1.length(); ++i) cout << s1[i];
	cout << endl;
	return 0;
}