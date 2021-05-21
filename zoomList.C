#include"zoomList.H"
namespace advCppCourse{

    zoomList::zoomList(int width, int height):m_width(width),m_height(height){

    }
    void zoomList::add(const zoom& z){
        zooms.push_back(z);
    }
    std::pair<double, double> zoomList::doZoom(int x, int y){
        return std::pair<double,double>(0,0);
    }

}
