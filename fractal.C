//name : fractal.C
#include<iostream>
#include"bitmap.H"


using namespace std;
using namespace advCppCourse;
int main(){
    bitmap bitmap1(800,600);
    bitmap1.write("test.bmp");
    cout<<"finished"<<endl;
}