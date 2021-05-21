//name : fractal.C
#include<iostream>
#include<cstdint>
#include<memory>
#include"bitmap.H"
#include"Mandelbrot.H"


using namespace std;
using namespace advCppCourse;

int main(){
    const int W = 800;
    const int H = 600;
    bitmap bitmap1(W,H);
    bitmap1.setPixel(W/2, H/2, 255,255,255);

    double min{1e5}, max{-1e5};
    unique_ptr<int[]>histogram(new int[Mandelbrot::MAX_ITER+1]{0});//with initialisation to 0
    for(int x=0;x<W;x++){
        for(int y=0;y<H;y++){
            //bitmap1.setPixel(i,j,120,200,100);//fav green color
            double xFractal = (x - W/2-W/4)*(2.0/H);
            double yFractal = (y - H/2)*(2.0/H);

            int iter = Mandelbrot::getIterations(xFractal,yFractal);
            histogram[iter]++;
            
            uint8_t color = (uint8_t)(256*(double) iter/Mandelbrot::MAX_ITER);
            color = color*color*color;//max will be 255 since uint_8 has a max 255

            bitmap1.setPixel(x,y,0,color,0);
            if (color<min) min=color;
            if (color>max) max=color;
            /* if (color<min) min=color;
            if (yFractal>max) max=yFractal; */
        }
    }
    cout<<endl;
    int count =0;
    for (int i=0; i<=Mandelbrot::MAX_ITER;i++){
        count += histogram[i];
        cout<<histogram[i]<<" ;      "<<flush;
    }
    cout<<" sum "<<endl;
    cout<<count<<"  "<<W*H<<endl;
    cout<<min<<","<<max<<endl;
    bitmap1.write("test.bmp");
    cout<<"finished"<<endl; 
}