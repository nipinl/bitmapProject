#include<fstream>
#include"bitmap.H"
#include"bitmapFileHeader.H"
#include"bitmapInfoHeader.H"
using namespace advCppCourse;
namespace advCppCourse{
    
    bitmap::bitmap(int width, int height):m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{})
    {
    }
    void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

    }
    bool bitmap::write(string fileName){
        bitmapFileHeader fileHeader;
        bitmapInfoHeader infoHeader;
        fileHeader.fileSize = sizeof(bitmapInfoHeader)+sizeof(bitmapFileHeader)+m_width*m_height*3;
        fileHeader.dataOffset = sizeof(bitmapInfoHeader)+sizeof(bitmapFileHeader);
        
        infoHeader.width = m_width;
        infoHeader.height = m_height;

        ofstream file;
        file.open(fileName,ios::out|ios::binary);
        if(!file){
            return false;
        }
        file.write((char *)&fileHeader, sizeof(fileHeader));
        file.write((char *)&infoHeader, sizeof(infoHeader));
        file.write((char *)m_pPixels.get(), m_width*m_height*3);

        file.close();
        return true;
        }
    bitmap::~bitmap(){}
    
}
