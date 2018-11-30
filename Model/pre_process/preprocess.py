
#binarise 
import cv2 
import numpy as np
from matplotlib import pyplot as plt
img = cv2.imread(raw_input("enter image\n"),0)
cv2.imwrite('grayscale.jpg',img)

cv2.imwrite('../../assignment/images/MyImage.jpg',img)
img = cv2.adaptiveThreshold(img,255,cv2.ADAPTIVE_THRESH_GAUSSIAN_C,\
            cv2.THRESH_BINARY,11,2)


def compute_skew(image):
    image = cv2.bitwise_not(image)
    height, width = image.shape

    edges = cv2.Canny(image, 150, 200, 3, 5)
    lines = cv2.HoughLinesP(edges, 1, 3.14159/180.00, 100, minLineLength=width / 2.0, maxLineGap=20)
    angle = 0.0
    nlines = lines.size
    for x1, y1, x2, y2 in lines[0]:
        angle += np.arctan2(y2 - y1, x2 - x1)
    return angle / nlines


def deskew(image, angle):
    image = cv2.bitwise_not(image)
    non_zero_pixels = cv2.findNonZero(image)
    center, wh, theta = cv2.minAreaRect(non_zero_pixels)

    root_mat = cv2.getRotationMatrix2D(center, angle, 1)
    rows, cols = image.shape
    rotated = cv2.warpAffine(image, root_mat, (cols, rows), flags=cv2.INTER_CUBIC)

    return cv2.getRectSubPix(rotated, (cols, rows), center)


# img = cv2.medianBlur(img,5)
cv2.imwrite('adaptive_guassian.jpg',img)
# cv2.imwrite('../../assignment/images/MyImage.jpg',img)
# import os
# os.system("")
# sub_image = img[y:y+h,:]

# converted_img = cv2.cvtColor(img, cv2.COLOR_GRAY2BGR)
# dst = cv2.fastNlMeansDenoisingColored(converted_img,None,10,10,7,21)
# plt.imshow(img)
# h_initial=0
# h_current=1

plt.show()