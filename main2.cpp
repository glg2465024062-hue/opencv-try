
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
Mat src = imread("/home/glg/Pictures/Screenshots/fs.png");
    showImage("原图", src);//显示原图
    Mat task= src.clone();
    for (int y = 0; y < task.rows; y++) {
        for (int x = 0; x < task.cols; x++) {
            Vec3b &pixel = task.at<Vec3b>(y, x);
            if (pixel[0] > 240 && pixel[1] > 240 && pixel[2] > 240) {
                pixel = Vec3b(0, 0, 0);
            }
        }
    }
    showImage("black", task);
    return 0;
}