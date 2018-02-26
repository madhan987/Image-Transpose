
//image transpose
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

int main()
{
	Mat image = imread("C:\\Users\\HP\\Pictures\\Download\\pattern.jpg");

	//Displaying an image
	imshow("1", image);

	Mat grey_image(image.rows, image.cols, CV_8UC1);

	Mat transpose_image(image.cols, image.rows, CV_8UC1);

	Mat transpose_imag(image.cols, image.rows, CV_8UC3);

	//converting RGB to grey scale
	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			grey_image.at<uchar>(i , j) = (image.at<Vec3b>(i, j)[0] + image.at<Vec3b>(i, j)[1] + image.at<Vec3b>(i, j)[2]) / 3;
		}
	}

	for (int i = 0; i < image.rows; i++)
	{
		for (int j = 0; j < image.cols;j++)
		{
			transpose_image.at<uchar>(j, i) = grey_image.at<uchar>(i, j);
			transpose_imag.at<Vec3b>(j, i) = image.at<Vec3b>(i, j);
		}
	}

	imshow("2", transpose_image);
	imshow("3", transpose_imag);
	waitKey(0);
	return 1;

}