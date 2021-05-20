#include"bitmap.H"
namespace advCppCourse{
    
    bitmap::bitmap(int width, int height):m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3])
    {
    }
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

    }
    bool bitmap::write(string fileName){
        return false;
    }
    bitmap::~bitmap()
    {
    }
    
}