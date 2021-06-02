#include <iostream>
#include <string.h>
#define M 1000
using namespace std ;
template< typename T >
class Set
{
public:
	int count ;
	int maxSize ;
	T* data ;
	Set(){
		count=0;
		maxSize=M;
		data=new T[M];
		for(int i=0;i<M;i++){
			data[i]=0;
		}
	}
	Set( int a ){
		count=0;
		maxSize=a;
		data=new T[a];
		for(int i=0;i<a;i++){
			data[i]=0;
		}
	}
	~Set(){
		delete[] data;
	}
	Set( const Set& s){
		count=s.count;
		maxSize=s.maxSize;
		data=new T[maxSize];
		for(int i=0;i<count;i++){
			data[i]=s.data[i];
		}
	}
	Set operator+( const Set& s ){
		T* temp=new T[maxSize];
		int realcount=0;
		for(int i=0;i<count;i++){
			temp[realcount]=data[i];
			realcount++;
		}
		for(int j=0;j<s.count;j++){
			bool exist=false;
			for(int i=0;i<count;i++){
				if(s.data[j]==data[i]){
					exist=true;
					break;
				}
			}
			if(!exist){
				temp[realcount]=s.data[j];
				realcount++;
			}
		}
		Set re(maxSize);
		delete []re.data;
		re.data=temp;
		re.count=realcount;
		return re;
	}
	Set operator-( const Set& s ){
		Set re(maxSize);
		re.count=0;
		for(int i=0;i<count;i++){
			bool exist=false;
			for(int j=0;j<s.count;j++){
				if(data[i]==s.data[j]){
					exist=true;
					break;
				}
			}
			if(!exist){
				re.data[re.count]=data[i];
				re.count++;
			}
		}
		
		return re;
	}
	void operator=( const Set& s ){
		count=s.count;
		delete[] data;
		maxSize=s.maxSize;
		data=new T[maxSize];
		for(int i=0;i<count;i++){
			data[i]=s.data[i];
		}
	}
	bool insert( T newItem ){
		if(count==maxSize){
			return false;
		}
		else{
			bool exist=false;
			for(int i=0;i<count;i++){
				if(newItem==data[i]){
					exist=true;
					break;
				}
			}
			if(!exist){
				data[count]=newItem;
				count++;

			}
			return !exist;
		}
	}
	bool erase( T targetItem ){
		int rb=0;
		bool exist=false;
		for(int i=0;i<count;i++){
			if(targetItem==data[i]){
				rb=i;
				exist=true;
				break;
			}
		}
		if(exist){
			for(int i=rb+1;i<count;i++){
				data[i-1]=data[i];
			}
			count--;
		}
		return exist;
	}
	void print() const{
		for(int i=0;i<count;i++){
			cout<<data[i]<<" ";
		}
		cout<<endl;
	}
	T* getData() const{
		return data;
	}
	int getCount() const{
		return count;
	}
	int getMaxSize() const{
		return maxSize;
	}
	
} ;
//test operator + and operator - and intersection
void test1()
{
	Set<int> s1( 10 ), s2( 10 ), s_plus, s_minus, s_intersection ;
	
	s1.insert( 1 ) ;
	s1.insert( 2 ) ;
	s1.insert( 2 ) ;
	s1.insert( 4 ) ;
	cout << "Items in s1 are : " ;
	s1.print() ;
	
	s2.insert( 3 ) ;
	s2.insert( 3 ) ;
	s2.insert( 1 ) ;
	s2.insert( 2 ) ;
	cout << "Items in s2 are: " ;
	s2.print() ;
	
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test2()
{
	Set<double> s1( 100 ), s2( 100 ), s_plus, s_minus, s_intersection ;
	
	
	for ( int i = 0; i < s1.getMaxSize(); i++ )
	{
		s1.insert( i % 17 ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < s2.getMaxSize(); i++ )
	{
		s2.insert( i % 15 ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
	s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

void test3()
{
	Set<char> s1( 1000 ), s2( 1000 ), s_plus, s_minus, s_intersection ;
	const char str1[] = "adsfasdfasdfasdfdshfhasdfashjglcnvyerwqjtoiruetwertbnsdfosiftgwertiu324u54owert" ;
	const char str2[] = "adsfhahdfuqwernfqwjerfqwhtfihvagiutewrfbnsduasdfqwerqwgb ahb.,p[phvbfgiopsudfgsdafjfas" ;
	
	for ( int i = 0; i < strlen( str1 ); i++ )
	{
		s1.insert( str1[i] ) ;
	}
	cout << "Items in s1 are : " ;
	s1.print() ;
	for ( int i = 0; i < strlen( str2 ); i++ )
	{
		s2.insert( str2[i] ) ;
	}
	cout << "Items in s2 are: " ;
	s2.print() ;
	
		s_plus = s1 + s2 ;
	cout << "Items in s_plus are: " ;
	s_plus.print() ;
	
	s_minus = s1 - s2 ;
	cout << "Items in s_minus are: " ;
	s_minus.print() ;
	
	s_intersection = s1 - ( s1 - s2 ) ;
	cout << "Items in s_intersection are: " ;
	s_intersection.print() ;
}

int main()
{
	test1() ;
	test2() ;
	test3() ;
	return 0 ;
}