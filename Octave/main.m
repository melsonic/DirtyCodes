img = imread("img.jpeg")
imshow(img)
img2 = imadjust(img, stretchlim(img), [])
imshow(img2)
