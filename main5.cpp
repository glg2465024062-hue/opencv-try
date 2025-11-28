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
    Point2f center(src.cols / 2.0f, src.rows / 2.0f);//旋转中心
    Mat rotate_mat = getRotationMatrix2D(center, 45, 1.0);//获取旋转矩阵
    Mat task;   
    warpAffine(src, task6, rotate_mat, src.size());//旋转45度
    showImage("turn45°", task);
    return 0;
}