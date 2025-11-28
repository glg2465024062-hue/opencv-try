import cv2
import numpy as np
def rotate_image(image, angle):
    (h, w) = image.shape[:2]
    center = (w // 2, h // 2)
    M = cv2.getRotationMatrix2D(center, angle, 1.0)
    rotated_image = cv2.warpAffine(image, M, (w, h))
    return rotated_image
image = cv2.imread("/home/glg/Pictures/Screenshots/fs.png")
new = rotate_image(image, 45)
cv2.imshow("new", new)
cv2.waitKey(0)
