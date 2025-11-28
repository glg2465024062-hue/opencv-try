import cv2
import numpy as np

image = cv2.imread("/home/glg/Pictures/Screenshots/fs.png", cv2.IMREAD_GRAYSCALE)

gray = cv2.cvtColor(image, cv2.COLOR_BAYER_BGGR2GRAY)

lower_white = 200
upper_white = 255
dark = cv2.inRange(gray, lower_white, upper_white)

image[dark != 0] = 0

cv2.imshow("window",image)
cv2.waitKey(0)
cv2.destroyWindows("image")