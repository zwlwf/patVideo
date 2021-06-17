#include <vector>

// more work will be done to make createPat more friendly.
// play a music and click enter
std::vector<double> createPatByKey();

// clickTime is created by createPatByxxx function, fr is frame rate of output video
std::vector<int> patToKeyFrameSerial(std::vector<double>& clickTime, int fr=60);

// convert the serial of keyframe to video, merge video and audio can be done in jianyi or ffmpeg
void keyFrameSerialToVideo(std::vector<int>&);

