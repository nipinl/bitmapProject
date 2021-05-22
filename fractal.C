//name : fractal.C
#include<iostream>
#include<iostream>
#include"bitmap.H"
#include"Mandelbrot.H"
#include"zoom.H"
#include"zoomList.H"
#include"fractalCreator.H"
#include"RGB.H"

using namespace std;
using namespace advCppCourse;

int main(){
    fractalCreator fractalCreator(800,600);
    fractalCreator.addZoom(zoom(295,202,0.1) );
    fractalCreator.addZoom(zoom(312,304,0.1) );
        
    fractalCreator.run("test2.bmp");

    cout<<"finished"<<endl; 
}