#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include<string>
#include<cstdint>
#include<memory>
#include<math.h>
#include<vector>
#include"Mandelbrot.H"
#include"zoom.H"
#include"bitmap.H"
#include"zoomList.H"
#include"RGB.H"
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
    vector <int> m_ranges;
    vector <RGB> m_colors;
    vector<int> m_rangeTotals;
    bool m_gotFirstRange{false};
    //member functions
    void calculateIteration();
    void calculateTotalIterations();
    void calculateRangeTotals();
    void drawFractal();
    void writeBitmap(string name);
public:
    fractalCreator(int width, int height);
    ~fractalCreator();
    void addZoom(const zoom& z);
    void run(string name);
    void addRange(double rangeEnd, const RGB& rgb);
};


    
}
#endif//fractalCtreator