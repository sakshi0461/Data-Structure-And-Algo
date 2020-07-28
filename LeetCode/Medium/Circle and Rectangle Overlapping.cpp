class Solution {
public:
    bool checkOverlap(int radius, int xcen, int ycen, int x1, int y1, int x2, int y2) {
        
        if((xcen>=x1 && xcen<=x2) && (ycen>=y1 && ycen<=y2)) return true;
        
        double x,y;
        
        if(xcen<=x1)
          x=x1-xcen;
        else if(xcen>=x2)
          x=xcen-x2;
        
        if(ycen<=y1)
          y=y1-ycen;
        else if(ycen>=y2)
          y=ycen-y2;
        
        return (x*x)+(y*y)<=(double)(radius*radius);
    }
};