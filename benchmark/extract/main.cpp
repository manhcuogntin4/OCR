#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <tesseract/baseapi.h>
using namespace cv;

int main(int argc, char* argv[])
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }

    // Open input image with leptonica library
    //Pix *image = pixRead(argv[1]);
    std::string input_path = argv[1];
    cv::Mat src_img = cv::imread(input_path, 0);
 	int bytesPerPixel = src_img.elemSize();
        int bytesPerLine = src_img.step;
        api->SetImage(src_img.data,
                      src_img.cols,
                      src_img.rows,
                      bytesPerPixel,
                      bytesPerLine);
    //api->SetImage(src_img);
    // Get OCR result
   /*api->SetRectangle(30, 86, 200, 1000);
    outText = api->GetUTF8Text();

    printf("OCR output:\n%s", outText);*/
    Rect r(0,200,src_img.cols, 100);    
    //api->SetRectangle(0, 200, src_img.cols, 200);
    api->SetRectangle(r.x, r.y, r.width, r.height);
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    //pixDestroy(&image);

    return 0;
}
