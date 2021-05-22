#ifndef RGB_H_
#define RGB_H_

using namespace std;
namespace advCppCourse{
    struct RGB
    {
        double r{};
        double g{};
        double b{};
        RGB(double r, double g, double b);
    };   
    
    RGB operator-(const RGB& left, const RGB& right);     
}
#endif//rgb