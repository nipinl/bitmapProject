#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_
#include<vector>
#include<utility>
#include "zoom.H"
namespace advCppCourse{
    class zoomList
    {
        private:
            int m_width{0};
            int m_height{0};
            std::vector<zoom> zooms;
        public:
            zoomList(int width, int height);
            void add(const zoom& z);
            std::pair<double, double>doZoom(int x, int y);
    };
}
#endif//zoomList