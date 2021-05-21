//name : fractal.C
#include<iostream>
#include<iostream>
#include"bitmap.H"
#include"Mandelbrot.H"
#include"zoomList.H"
#include"fractalCreator.H"


using namespace std;
using namespace advCppCourse;

int main(){
    int height=600;
    fractalCreator fractalCreator(800,600);
    fractalCreator.addZoom(zoom(295,height-202,0.1) );
    fractalCreator.addZoom(zoom(312,height-304,0.1) );
    fractalCreator.calculateIteration();
    fractalCreator.calculateTotalIterations();
    fractalCreator.drawFractal();    
    fractalCreator.writeBitmap("test1.bmp");
    cout<<"finished"<<endl; 
}