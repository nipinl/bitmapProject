#ifndef BITMAP_H_
#define BITMAP_H_

#include<string>
#include <cstdint>
using namespace std;

namespace advCppCourse{
    class bitmap
    {
    private:
        int m_width{0};
        int m_height{0 };
    public:
        bitmap(int width, int height);
        void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
        bool write(string fileName);
        virtual ~bitmap();
    };
       
}

#endif//bitmap header