#include "patVideo.h"
#include <iostream>

using namespace std;

int main() {
	vector<double> clickTime = createPatByKey();
	vector<int> kf = patToKeyFrameSerial(clickTime, 60);
	keyFrameSerialToVideo(kf);
	return 0;
}
