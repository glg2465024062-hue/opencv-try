import cv2
import numpy as np
#1. 读取图片
image = cv2.imread("/home/glg/Pictures/Screenshots/fs.png")  
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)  # 灰度图
#2. 二值化
_, thresh = cv2.threshold(gray, 250, 255, cv2.THRESH_BINARY_INV)  
#反相二值化，让目标为白色
#3. 膨胀操作
kernel = np.ones((5, 5), np.uint8)  
dilated = cv2.dilate(thresh, kernel, iterations=2)  # iterations是膨胀次数
#4. 查找轮廓并描边
contours, _ = cv2.findContours(dilated, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
for cnt in contours:#描边
    cv2.drawContours(image, [cnt], -1, (0, 255, 0), 4)  
#显示结果
cv2.imshow("Result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()