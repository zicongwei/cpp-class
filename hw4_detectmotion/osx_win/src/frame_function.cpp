#include "frame_function.h"

#define loop(i, n) for(int i = 0; i < n; i++)


void frame_function(Context &context, Scalar colour, Mat &mat, BackgroundSubtractorMOG2 &background, Point *prevMC){
    //find foreground
    Mat src;
    //BackgroundSubtractorMOG2 bg;
    background.operator()(mat,src);
    erode(src,src,Mat());
    dilate(src,src,Mat());
    
    //findContours of the foreground img
    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( src, contours,hierarchy,CV_RETR_CCOMP, CV_CHAIN_APPROX_SIMPLE );

    /*
    cout <<hierarchy.size() <<endl;
    int idx = 0;
    for( ; idx >= 0; idx = hierarchy[idx][0] )
    {
        drawContours( mat, contours, idx, colour, CV_FILLED, 8, hierarchy );
    } */
    
    // Draw Foreground
    int size = contours.size();
    loop(i,size){
        if (contourArea(contours[i])> 50){ // set a threshold value
            drawContours( mat, contours, i, colour, CV_FILLED);
        }
    }
    
    // Moments
    vector<Moments> mo(size);
    loop(i,size){
        mo[i] = moments( contours[i], false );
    }
    
    // Mass Centers
    vector<Point2f> mc(size);
    loop(i,size){
        mc[i] = Point2f( mo[i].m10/mo[i].m00 , mo[i].m01/mo[i].m00 ); //Point?
    }
    float total_X = 0.0;
    float total_Y = 0.0;
    loop(i,size){
        total_X +=mc[i].x;
        total_Y +=mc[i].y;
    }
    
    Point massCenter(total_X/size, total_Y/size);
    
    // draw line
    double curMC_x = massCenter.x;
    double curMC_y = massCenter.y;
    
    if (curMC_x>(-640) && curMC_y>(-640)){ //prevent -2147483648
        double prevMC_x = prevMC->x;
        double prevMC_y = prevMC->y;
    
        Point *edgeP = new Point(mat.cols, mat.rows);
        double k = (curMC_y-prevMC_y)/(curMC_x-prevMC_x);
        edgeP->x = mat.cols;
        edgeP->y = (-k)*(curMC_x-mat.cols)+curMC_y;
        if (curMC_x == prevMC_x){
            edgeP->x = prevMC_x;
            edgeP->y = mat.rows;
        }
        cout << "massCenter " << massCenter << endl;

        line(mat, massCenter, *edgeP, Scalar(255,255,255), 1);
        *prevMC = massCenter;
        delete edgeP;
    }
}
