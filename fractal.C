//name : fractal.C
#include<iostream>
#include"bitmap.H"


using namespace std;
using namespace advCppCourse;

int main(){
    const int W = 800;
    const int H = 600;
    bitmap bitmap1(W,H);
    bitmap1.setPixel(W/2, H/2, 255,255,255);
    for(int i=0;i<W;i++){
        for(int j=0;j<H;j++){
            bitmap1.setPixel(i,j,120,200,100);
        }
    }
    bitmap1.write("test.bmp");
    cout<<"finished"<<endl;
}