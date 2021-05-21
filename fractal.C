//name : fractal.C
#include<iostream>
#include<cstdint>
#include<memory>
#include<math.h>
#include"bitmap.H"
#include"Mandelbrot.H"


using namespace std;
using namespace advCppCourse;

int main(){
    const int W = 1200;
    const int H = 900;
    bitmap bitmap1(W,H);
    bitmap1.setPixel(W/2, H/2, 255,255,255);

    double min{1e5}, max{-1e5};
    unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITER+1]{0});//with initialisation to 0
    unique_ptr<int[]>iterPerPixel(new int[W*H]{0});//with initialisation to 0
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            //bitmap1.setPixel(i,j,120,200,100);//fav green color
            double xFractal = (x - W/2-W/4)*(2.0/H);
            double yFractal = (y - H/2)*(2.0/H);


            int iter = Mandelbrot::getIterations(xFractal,yFractal);
            iterPerPixel[y*W+x] = iter;//storing the iterations
            if(iter!=Mandelbrot::MAX_ITER) histogram[iter]++;//to avoid the last entry showing no. of pixels going to inf 
        }
    }
    //totalling histogram
    int histSum=0;
    for (int i=0;i<Mandelbrot::MAX_ITER;i++){histSum+=histogram[i];}
    cout<<"histogram total is : "<<histSum<<endl;
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            int iter = iterPerPixel[y*W+x];
            if(iter!=Mandelbrot::MAX_ITER){
                double hue = 0.0;
                for (int i = 0; i <= iter; i++)
                {
                    hue += ((double)histogram[i] )/histSum; 
                }
                green = pow(255,hue);
                //cout<<"green = "<<green<<"Hue = "<<hue<<endl;
            } 

            bitmap1.setPixel(x,y,red,green,blue);
        }
    }
    
    bitmap1.write("test.bmp");
    cout<<"finished"<<endl; 
}