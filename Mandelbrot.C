#include<complex>
#include"Mandelbrot.H"
using namespace std;
namespace advCppCourse{
    
    Mandelbrot::Mandelbrot(){}
    Mandelbrot::~Mandelbrot(){}
    int Mandelbrot::getIterations(double x, double y){

        complex<double> z =0;
        complex<double> c(x,y);
        int iter = 0;
        while(iter<MAX_ITER){
            z = z*z +c;
            if(abs(z)>2){//if z exeed 2, it will go to infinity with iterations
                break;
            }
            iter++;
        }



        return iter;

    }
    
}
