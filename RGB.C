#include<iostream>
#include"RGB.H"
using namespace std;
namespace advCppCourse{
        
    RGB::RGB(double r, double g, double b):r(r), g(g), b(b) {}
    RGB operator-(const RGB& left, const RGB& right){
        return RGB(left.r - right.r,left.g - right.g,left.b - right.b);
    }
}
