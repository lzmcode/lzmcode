#include "ReadMnistData.h"

int main()
{
	ReadMnistData rmd;

	/*��ȡѵ���ļ��������ͼƬ��ʽ*/
	string filename_train_images = "\\mnist\\train-images-idx3-ubyte";		//train images �ļ�·��
	string filename_train_labels = "\\mnist\\train-labels-idx1-ubyte";			//train labels �ļ�·��
	string save_train_image_path = "\\mnist\\train_images\\";						//train images ����·��
	//string filename_train_images = "C:\\Users\\lyf\\Desktop\\train-images-idx3-ubyte";		//train images �ļ�·��
	//string filename_train_labels = "C:\\Users\\lyf\\Desktop\\train-labels-idx1-ubyte";			//train labels �ļ�·��
	//string save_train_image_path = "C:\\Users\\lyf\\Desktop\\train_images\\";						//train images ����·��
	vector<cv::Mat> vec_train_images;			//�����ȡ��train images
	vector<int> vec_train_labels;					//�����ȡ��train labels

	rmd.Read_Mnist_Images(filename_train_images, vec_train_images);			//��ȡtrain images
	cout << "-----------------------------" << endl;
	rmd.Read_Mnist_Labels(filename_train_labels, vec_train_labels);				//��ȡtrain labels
	cout << "-----------------------------" << endl;
	rmd.Save_Mnist_Images(save_train_image_path, vec_train_images, vec_train_labels);		//����train_images

	//==================================================================================
	/*��ȡ�����ļ��������ͼƬ��ʽ*/
//	string filename_test_images = "C:\\Users\\lyf\\Desktop\\mnist\\t10k-images-idx3-ubyte";		//test images �ļ�·��
////	string filename_test_images = "C:\\Users\\lyf\\Desktop\\t10k-images-idx3-ubyte";		//test images �ļ�·��
//	string filename_test_labels = "C:\\Users\\lyf\\Desktop\\mnist\\t10k-labels-idx1-ubyte";			//test labels �ļ�·��
////	string filename_test_labels = "C:\\Users\\lyf\\Desktop\\t10k-labels-idx1-ubyte";			//test labels �ļ�·��
//	string save_test_image_path = "C:\\Users\\lyf\\Desktop\\mnist\\test_images\\";						//test images ����·��
////	string save_test_image_path = "C:\\Users\\lyf\\Desktop\\test_images\\";						//test images ����·��
//	vector<cv::Mat> vec_test_images;			//�����ȡ��test images
//	vector<int> vec_test_labels;					//�����ȡ��test labels
//	
//	rmd.Read_Mnist_Images(filename_test_images, vec_test_images);			//��ȡtest images
//	cout << "-----------------------------" << endl;
//	rmd.Read_Mnist_Labels(filename_test_labels, vec_test_labels);				//��ȡtest labels
//	cout << "-----------------------------" << endl;
//	rmd.Save_Mnist_Images(save_test_image_path, vec_test_images, vec_test_labels);		//����test_images

	return 0;
}

