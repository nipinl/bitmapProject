#ifndef MANDELBROT_H_
#define MANDELBROT_H_
namespace advCppCourse{
    class Mandelbrot
    {
    public:
        Mandelbrot();
        ~Mandelbrot();
        static int getIterations(double x, double y);
    };
       
}
#endif//Mandelbrot header