#include<iostream>
#include"zoomList.H"
using namespace std;
namespace advCppCourse{

    zoomList::zoomList(int width, int height):m_width(width),m_height(height){}
    void zoomList::add(const zoom& z){
        zooms.push_back(z);
        m_xCenter += (z.x - m_width/2)*m_scale;
        m_yCenter += -(z.y - m_height/2)*m_scale;
        m_scale *= z.scale;
        cout<<m_xCenter<<",  "<<m_yCenter<<",  "<<m_scale<<endl;
    }
    pair<double, double> zoomList::doZoom(int x, int y){
        double xFractal = (x - m_width/2)*m_scale + m_xCenter;
        double yFractal = (y - m_height/2)*m_scale + m_yCenter;
        return pair<double,double>(xFractal,yFractal);
    }

}
