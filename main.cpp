#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
//函数(显示图片)
void showImage(const string& winName, const Mat& img) {
    namedWindow(winName, WINDOW_NORMAL); 
    imshow(winName, img);
    waitKey(0);//等待按键
    destroyWindow(winName);//关闭当前窗口
}
int main() {
//读取原始图片
    Mat src = imread("/home/glg/Pictures/Screenshots/fs.png");
    showImage("原图", src);//显示原图
    Mat gray;
    cvtColor(src, gray, COLOR_BGR2GRAY);
    showImage("gray", gray);
    return 0;
}