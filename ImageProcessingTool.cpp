// Codsoft Internship Task 5
// Image Processing Tool
#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

//Image Filters
void applyGrayscale(Mat& img) {
    cvtColor(img, img, COLOR_BGR2GRAY);
}

void applyBlur(Mat& img) {
    GaussianBlur(img, img, Size(5, 5), 0);
}

void applySharpen(Mat& img) {
    Mat kernel = (Mat_<float>(3, 3) <<
                  0, -1, 0,
                  -1, 5, -1,
                  0, -1, 0);
    filter2D(img, img, img.depth(), kernel);
}

//Color Adjustment
void adjustBrightnessContrast(Mat& img, double alpha, int beta) {
    img.convertTo(img, -1, alpha, beta);
}

//Crop and Resize
void cropImage(Mat& img, Rect roi) {
    img = img(roi);
}

void resizeImage(Mat& img, int newWidth, int newHeight) {
    resize(img, img, Size(newWidth, newHeight));
}

//Image Saving
void saveImage(const Mat& img, const string& path) {
    imwrite(path, img);
}

//User Interface
void showMenu() {
    cout << "Choose an option: \n";
    cout << "1. Apply Grayscale\n";
    cout << "2. Apply Blur\n";
    cout << "3. Apply Sharpen\n";
    cout << "4. Adjust Brightness/Contrast\n";
    cout << "5. Crop\n";
    cout << "6. Resize\n";
    cout << "7. Save Image\n";
    cout << "0. Exit\n";
}

int main() {
    // Load image
    Mat img = imread("path_to_image.jpg");
    if (img.empty()) {
        cout << "Could not open or find the image!" << endl;
        return -1;
    }

    int option;
    do {
        showMenu();
        cin >> option;

        switch (option) {
            case 1:
                applyGrayscale(img);
                break;
            case 2:
                applyBlur(img);
                break;
            case 3:
                applySharpen(img);
                break;
            case 4:
                double alpha;
                int beta;
                cout << "Enter contrast (1.0-3.0): ";
                cin >> alpha;
                cout << "Enter brightness (0-100): ";
                cin >> beta;
                adjustBrightnessContrast(img, alpha, beta);
                break;
            case 5: {
                int x, y, width, height;
                cout << "Enter x, y, width, height for cropping: ";
                cin >> x >> y >> width >> height;
                cropImage(img, Rect(x, y, width, height));
                break;
            }
            case 6:
                int newWidth, newHeight;
                cout << "Enter new width and height: ";
                cin >> newWidth >> newHeight;
                resizeImage(img, newWidth, newHeight);
                break;
            case 7:
                saveImage(img, "output_image.jpg");
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
        }

        namedWindow("Processed Image", WINDOW_AUTOSIZE);
        imshow("Processed Image", img);
        waitKey(0);

    } while (option != 0);

    return 0;
}