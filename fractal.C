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

    double min{1e5}, max{-1e5};
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            //bitmap1.setPixel(i,j,120,200,100);//fav green color
            double xFractal = (x - W/2)*(2.0/W);
            double yFractal = (y - H/2)*(2.0/H);
            if (xFractal<min) min=xFractal;
            if (xFractal>max) max=xFractal;
            if (yFractal<min) min=yFractal;
            if (yFractal>max) max=yFractal;
        }
    }
    cout<<min<<","<<max<<endl;
    bitmap1.write("test.bmp");
    cout<<"finished"<<endl;
}