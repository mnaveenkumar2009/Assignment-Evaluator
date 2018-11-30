// g++ testing.cpp -llept -ltesseract
#include <bits/stdc++.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
using namespace std;
int main()
{
    char *outText;

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    // Initialize tesseract-ocr with English, without specifying tessdata path
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
    char s[50];
    cin>>s;
    // Open input image with leptonica library
    
    Pix *image = pixRead(s);
    api->SetImage(image);
    // Get OCR result
    outText = api->GetUTF8Text();
    printf("OCR output:\n%s", outText);

    // Destroy used object and release memory
    api->End();
    delete [] outText;
    pixDestroy(&image);

    return 0;
}
