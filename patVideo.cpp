#include "patVideo.h"
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <sys/time.h>

using namespace std;

static void get_walltime(double* wcTime) {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}

vector<double> createPatByKey() {
	cout<<"Pat the enter key when you hear any pace in music"<<endl;
	char c;
	vector<double> ans;
	double t0, t1;
	get_walltime(&t0);
	while( 1 ){
		cout<<"press any key to stop >>";
		c = getchar();
		if(c=='\n') {
			get_walltime(&t1);
			ans.push_back( t1-t0 );
		}
		else break;
	}
	return ans;
}

vector<int> patToKeyFrameSerial(vector<double>& clickTime, int fr) {
	vector<int> ans;
	int n = clickTime.size();
	assert(n>1);
	double dt = 1.0/fr, t = 0;
	int i=0;
	double meanT = (clickTime.back()-clickTime[0])/(n-1);
	for(int j=0; j<n; j++) {
		while( t<clickTime[j] ) {
			ans.push_back(i);
			t += dt;
		}
		i++;
	}
	// append a meanTime for last key frame
	t = 0;
	while(t<meanT) {
		ans.push_back(i);
		t += dt;
	}
	return ans;
}

// one simple way to create video
void keyFrameSerialToVideo(std::vector<int>& kf) {
	FILE* fp = fopen("post.sh","w");
	if(!fp) {
		printf("failed to open post.sh\n");
		return ;
	}

	for(int i=0; i<kf.size(); i++) {
		fprintf(fp, "cp %03d.jpg a%03d.jpg\n", kf[i], i);
	}
	fprintf(fp, "\n\nffmpeg -i a\%d.jpg out.mp4\n");
	fclose(fp);
}
