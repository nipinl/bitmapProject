#include<iostream>
#include<assert.h>
#include"fractalCreator.H"
using namespace std;
namespace advCppCourse{
    //public method run
    void fractalCreator::run(string name){
        calculateIteration();
        calculateTotalIterations();
        calculateRangeTotals();
        drawFractal();    
        writeBitmap(name);
    }
    //public method addRange
    void fractalCreator::addRange(double rangeEnd, const RGB& rgb){
        m_ranges.push_back(rangeEnd*Mandelbrot::MAX_ITER);
        m_colors.push_back(rgb);
        if (m_gotFirstRange){
            m_rangeTotals.push_back(0);
        }
        m_gotFirstRange = true;
        
    }
    //public method addZoom
    void fractalCreator::addZoom(const zoom& z){
        m_zoomList.add(z);
    }
    
    //constructor
    fractalCreator::fractalCreator(int width, int height)
    :
    m_width(width),m_height(height),
    m_histogram(new int[Mandelbrot::MAX_ITER+1]{0}),
    m_iterPerPixel(new int[m_width*m_height]{0}),
    m_bitmap(m_width,m_height),
    m_zoomList(m_width,m_height),
    m_histSum(0)
    {
        m_zoomList.add(zoom(m_width/2,m_height/2,4.0/m_width));
    }
    //destructor
    fractalCreator::~fractalCreator(){}
    //member functions definitions
    void fractalCreator::calculateIteration(){
        for(int x=0;x<m_width;x++){
            for(int y=0;y<m_height;y++){
                pair<double,double> coords = m_zoomList.doZoom(x,y);
                int iter = Mandelbrot::getIterations(coords.first,coords.second);
                m_iterPerPixel[y*m_width+x] = iter;//storing the iterations
                if(iter!=Mandelbrot::MAX_ITER) m_histogram[iter]++;
            }
        }
    }
    void fractalCreator::calculateTotalIterations(){
    for (int i=0;i<Mandelbrot::MAX_ITER;i++){m_histSum+=m_histogram[i];}
    }
    void fractalCreator::calculateRangeTotals(){
        
            int rangeIndex = 0;
            for (int i = 0; i < Mandelbrot::MAX_ITER; i++)
            {
                int pixels = m_histogram[i];
                if (i>=m_ranges[rangeIndex+1]){
                    rangeIndex++;
                }
                

                m_rangeTotals[rangeIndex] += pixels; 
            }
        }
    int fractalCreator::getIntRange(int iter) const{
        int range = 0;
        for (int i = 1; i < m_ranges.size(); i++)
        {
            range = i;
            if (m_ranges[i]>iter){
                break;
            }
        }
        range--;
        assert(range>-1);
        assert(range<m_ranges.size());
        return range;
    }

    void fractalCreator::drawFractal()
    {
        RGB startColor(0,0,0);
        RGB endColor(0,0,255);
        RGB colorDiff = startColor - endColor;
    
        for(int x=0;x<m_width;x++){
            for(int y=0;y<m_height;y++){

                int iter = m_iterPerPixel[y*m_width+x];
                int range = getIntRange(iter);
                int rangeTotal = m_rangeTotals[range];
                int rangeStart = m_ranges[range];

                RGB& startColor = m_colors[range];
                RGB& endColor = m_colors[range+1];
                RGB colorDiff = endColor - startColor;

                uint8_t red = 0;
                uint8_t green = 0;
                uint8_t blue = 0;


                if(iter!=Mandelbrot::MAX_ITER){
                    int totalPixels = 0;
                    for (int i = rangeStart; i <= iter; i++)
                    {
                        totalPixels += m_histogram[i]; 
                    }
                    red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
                    green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
                    blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
                } 

                m_bitmap.setPixel(x,y,red,green,blue);
                
            }
        }
    }
    void fractalCreator::writeBitmap(string name){
        m_bitmap.write(name);
    }


}
