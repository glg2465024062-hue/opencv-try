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
//灰度图
    Mat task = src.clone();
    Mat task_gray;
    cvtColor(src, task_gray, COLOR_BGR2GRAY);
    Mat binary;
    threshold(task_gray, binary, 200, 255, THRESH_BINARY_INV);//二值化
//膨胀轮廓描边
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));//膨胀核
    Mat dilate_mat;
    dilate(binary, dilate_mat, kernel);
    vector<vector<Point>> contours;
    findContours(dilate_ma, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
    for (size_t i = 0; i < contours.size(); i++) {
        Scalar color = (i % 2 == 0) ? Scalar(0, 0, 255) : Scalar(0, 255, 0);
        drawContours(task, contours, i, color, 2);//描边
    }
    showImage("arround", task);
    return 0;
}