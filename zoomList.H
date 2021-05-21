#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
namespace advCppCourse{
struct zoomList
{
    int x{0};
    int y{0};
    double scale{0.0};
    zoom(int x, int y, double scale):x(x),y(y),scale(scale){}
};

}
#endif//zoomList