#include <opencv2/opencv.hpp>
#include "bits/stdc++.h"
using namespace std;
#define f(i,n) for(i=0;i<n;i++)
using namespace cv;
#define pb push_back
#define ll long long
ll THRESH=0;
int main(){
    Mat image = imread("adaptive_guassian.jpg");
    
    if (image.empty()){
        cout << "Could not open or find the image" << '\n';
        return -1;
    }
    
    cvtColor(image, image, CV_BGR2GRAY);
    int width=image.cols,height=image.rows,i,j;
    cout << "Width : " << image.cols << endl;
    cout << "Height: " << image.rows << endl;
    THRESH=320000;
    // int i,j;
    vector <ll> y(height);
    f(i,height){
        ll sum=0;
        f(j,width){
            sum+=image.at<uchar>(i,j);
                // fin.at<uchar>(i,j) = image.at<uchar>(i,j);
                // sum+=image.at
        }

        cout<<sum<<'\n';
        if(sum<=THRESH){
            y.pb(i);
            i+=height/100;
        }

        if(sum>THRESH){
            f(j,width){
                image.at<uchar>(i,j)=100;
            }
        }
    }
    // vector <bool > h(height,0);
    // for(auto it:y){
    //     h[it]=1;
    // }
    
    // f(i,height){
    //     if(!binary_search(y.begin(),y.end(),i)){

    //     }
    // }
    
    if (!imwrite("MyImage.jpg", image)){
        cout << "Failed to save the image" << endl;
        return -1;
    }

    // String windowName = "The Saved Image"; //Name of the window
    // namedWindow(windowName); // Create a window
    // imshow(windowName, fin); // Show our image inside the created window.
    // waitKey(0); // Wait for any keystroke in the window
    // destroyWindow(windowName); //destroy the created window
    return 0;
}