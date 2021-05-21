#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_
#include<string>
#include"zoom.H"
using namespace std;
namespace advCppCourse{
class fractalCreator
{
public:
    fractalCreator(int width, int height);
    ~fractalCreator();
    void calculateIteration();
    void drawFractal();
    void addZoom(const zoom& z);
    void writeBitmap(string& name);
};


    
}
#endif//fractalCtreator