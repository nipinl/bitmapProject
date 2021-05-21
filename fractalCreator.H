#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include<string>
#include<cstdint>
#include<memory>
#include<math.h>
#include"Mandelbrot.H"
#include"zoom.H"
#include"bitmap.H"
#include"zoomList.H"
using namespace std;
namespace advCppCourse{
class fractalCreator
{
private:
    int m_width;
    int m_height;
    unique_ptr<int[]>m_histogram;
    unique_ptr<int[]>m_iterPerPixel;
    bitmap m_bitmap;
    zoomList m_zoomList;
    int m_histSum;


public:
    fractalCreator(int width, int height);
    ~fractalCreator();
    void calculateIteration();
    void calculateTotalIterations();
    void drawFractal();
    void addZoom(const zoom& z);
    void writeBitmap(string name);
};


    
}
#endif//fractalCtreator