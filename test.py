import cv2

image = cv2.imread("/home/glg/Pictures/Screenshots/fs.png")

cv2.imshow("blue",image[:,:, 0])
cv2.imshow("green",image[:,:, 1])
cv2.imshow("red",image[:,:, 2])



cv2.imshow("window",image)
cv2.waitKey(0)
cv2.destroyAllWindows()
