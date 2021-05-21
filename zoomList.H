#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include<vector>
#include<utility>
#include "zoom.H"
using namespace std;
namespace advCppCourse{
    class zoomList
    {
        private:
            double m_xCenter{0};
            double m_yCenter{0};
            double m_scale{1.0};

            int m_width{0};
            int m_height{0};
            vector<zoom> zooms;
        public:
            zoomList(int width, int height);
            void add(const zoom& z);
            pair<double, double>doZoom(int x, int y);
    };
}
#endif//zoomList