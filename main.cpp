#include <iostream>
#include <opencv2/opencv.hpp>
#include <fstream>
using namespace std;
using namespace cv;

int main(int argc, char** argv){
    if(argc != 3){
        cout << "Missing argument!\nFormat: ./convert input.jpg output.txt" << endl;
        return 0;
    }
    Mat image;
    image = imread(argv[1]);
    
    if( image.empty() ) return -1;

    for(int i=0; i<image.cols; i++){
        for(int j=0; j<image.rows; j++){
            int temp = image.at<Vec3b>(i,j)[0] + image.at<Vec3b>(i,j)[1] + image.at<Vec3b>(i,j)[2];
            temp /= 3;
            image.at<Vec3b>(i,j)[0] = temp;
            image.at<Vec3b>(i,j)[1] = temp;
            image.at<Vec3b>(i,j)[2] = temp;
        }
    }

    char ch[] = {' ', ':', '~', '*', ':', 'i', '+', 'I', '$', '#', };

    ofstream file;
    file.open(argv[2]);

    for(int i=0; i<image.rows; i++){
        for(int j=0; j<image.cols; j++){
            file << ch [ 9-(image.at<Vec3b>(i,j)[0] / 26) ];
        }
        file << '\n';
    }

    file.close();    

}
