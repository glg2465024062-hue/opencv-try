import cv2

image = cv2.imread("/home/glg/Pictures/Screenshots/fs.png",cv2.IMREAD_GRAYSCALE)

gray = cv2.cvtColor(image, cv2.COLOR_BAYER_BG2BGR)
cv2.imshow("gray", gray)

cv2.waitKey(0)
cv2.destroyWindows("gray")