#include <iostream>
#include <cstring>
using namespace std;

class Matrix
{
public:
   Matrix();                                           //构造函数
   ~Matrix();                                          //析构函数
   Matrix(const Matrix &);                             //拷贝构造函数
   Matrix(int row, int col, int** elements);           //默认构造函数  
   Matrix operator+(const Matrix &)const;              //重载运算符“+”
   Matrix operator=(const Matrix &);                   //重载运算符“=”
   Matrix transpose()const;                            //矩阵的转置
   void display()const;                                //输出数据函数   
private:
   int row;                                            //矩阵的行
   int col;                                            //矩阵的列
   int** mat;                                          //用于储存矩阵
};
Matrix::Matrix(){
	row=col=0;
	mat=NULL;
}                                           
   Matrix::~Matrix(){
	   for(int i=0;i<row;i++){
		   delete[] mat[i];
	   }
	   delete[] mat;
	   mat=NULL;
   }
   Matrix::Matrix(const Matrix & b){
	   row=b.row;
	   col=b.col;
	   mat=new int*[b.row];
	   for(int i=0;i<b.row;i++){
		   mat[i]=new int[b.col];
	   }
	   for(int i=0;i<b.row;i++){
		   for(int j=0;j<b.col;j++){
			   mat[i][j]=b.mat[i][j];
		   }
	   }
   }                             
   Matrix::Matrix(int row, int col, int** elements){
	   this->col=col;
	   this->row=row;
	   mat=new int*[row];
	   for(int i=0;i<row;i++){
		   mat[i]=new int[col];
	   }
	   for(int i=0;i<row;i++){
		   for(int j=0;j<col;j++){
			   mat[i][j]=elements[i][j];
		   }
	   }
   }
   Matrix Matrix::operator+(const Matrix &b)const{
	   Matrix c(b);
	   for(int i=0;i<b.row;i++){
		   for(int j=0;j<b.col;j++){
			   c.mat[i][j]+=mat[i][j];
		   }
	   }
       Matrix* p=&c;
	   return *p;
   }
   Matrix Matrix::operator=(const Matrix &b){
	   if(mat!=NULL){
		   for(int i=0;i<row;i++){
			   delete[] mat[i];
		   }
		   delete []mat;
	   }
	   row=b.row;
	   col=b.col;
	   mat=new int*[row];
	   for(int i=0;i<row;i++){
		   mat[i]=new int[col];
	   }
	   for(int i=0;i<row;i++){
		   for(int j=0;j<col;j++){
			   mat[i][j]=b.mat[i][j];
		   }
	   }
	   return *this;
   }                   
   Matrix Matrix::transpose()const{
		Matrix c;
		c.row=this->col;
		c.col=this->row;
		c.mat=new int*[c.row];
		for(int i=0;i<c.row;i++){
			c.mat[i]=new int[c.col];
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				c.mat[j][i]=mat[i][j];
			}
		}
        Matrix* p=&c;
		return *p;
   }
   void Matrix::display()const{
	   for(int i=0;i<row;i++){
		   for(int j=0;j<col;j++){
			   cout<<mat[i][j]<<" ";
		   }
		   cout<<endl;
	   }
   }
int main()
{
    int row, col;
    cout << "input the row and the col for Matrix a, b" << endl;
    cin >> row >> col;

    int **mat_a_arr = new int*[row];
    for (int i = 0; i < row; i++) {
        mat_a_arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> mat_a_arr[i][j];
        }
    }
    int **mat_b_arr = new int*[row];
    for (int i = 0; i < row; i++) {
        mat_b_arr[i] = new int[col];
        for (int j = 0; j < col; j++) {
            cin >> mat_b_arr[i][j];
        }
    }

    Matrix a(row, col, mat_a_arr), b(row, col, mat_b_arr), c(a), d;
    cout << endl << "Matrix a:" << endl;
    a.display();
    cout << endl << "Matrix b:" << endl;
    b.display();
    c = a + b;//用重载运算符“+”实现两个矩阵相加 
    cout << endl << "Matrix c = Matrix a + Matrix b :" << endl;
    c.display();
    cout << endl << "Matrix a transpose to Matrix d:" << endl;
    d = a.transpose();
    d.display();
    for (int i = 0; i < row; i++) {
        delete[]mat_a_arr[i];
    }
    delete[]mat_a_arr;
    for (int i = 0; i < row; i++) {
        delete[]mat_b_arr[i];
    }
    delete[]mat_b_arr;
    return 0;
}
/*c.col=b.col;
	   c.row=b.row;
	   c.mat=new int*[b.row];
	   for(int i=0;i<b.row;i++){
		   c.mat[i]=new int[b.col];
	   }
	   for(int i=0;i<c.row;i++){
		   for(int j=0;j<c.col;j++){
			   c.mat[i][j]=b.mat[i][j];
		   }
	   }*/