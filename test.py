try:
	import Image
	import urllib, cStringIO
except ImportError:
	from PIL import Image
import pytesseract	

file = cStringIO.StringIO(urllib.urlopen("https://www.realpython.com/images/blog_images/ocr/ocr.jpg").read())
print(pytesseract.image_to_string(Image.open(file), lang='fra'))
