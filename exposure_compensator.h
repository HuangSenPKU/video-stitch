#ifndef __VIDEO_STITCH_MY_EXPOSURE_COMPENSATOR_H__
#define __VIDEO_STITCH_MY_EXPOSURE_COMPENSATOR_H__

#include "stdafx.h"

#include "opencv2/opencv_modules.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/stitching/detail/util.hpp"
#include "opencv2/stitching/detail/exposure_compensate.hpp"

using namespace std;
using namespace cv;
using namespace cv::detail;


/*
 * ʹ�õ���BlocksGainCompensator
 */
class MyExposureCompensator
{
public:
	MyExposureCompensator(int bl_width = 32, int bl_height = 32)
		: bl_width_(bl_width), bl_height_(bl_height) {}

	void createWeightMaps(const vector<Point> &corners, const vector<UMat> &images,
		const vector<UMat> &masks, vector<Mat_<float>> &ec_maps);

	void createWeightMaps(const vector<Point> &corners, const vector<UMat> &images,
		const vector<pair<UMat,uchar>> &masks, vector<Mat_<float>> &ec_maps);

	void feed(const vector<Point> &corners, const vector<UMat> &images, vector<UMat> &masks);

	void gainMapResize(vector<Size> sizes_, vector<Mat_<float>> &ec_maps);

	void apply(int index, Mat &image);

private:
	int bl_width_, bl_height_;
	vector<Mat_<float> > ec_maps_;
};



#endif