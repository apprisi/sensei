#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "KinectHelper.h"
#include "LandmarkCoreIncludes.h"
#include <FaceAnalyser.h>
#include "FaceDetector.hpp"

typedef long long frameTime;

struct rect {
    double x;
    double y;
    double width;
    double height;
};

struct faceData {
    rect r;
    vector<double> points;
};

class bufferFrame {
public:
    ofPixels pRGB;
    ofFloatPixels pDepth;
    ofFloatPixels pBigDepth;

    bool hasData = false;

    vector<faceData> faces;

    void draw();
    void findFaces(FaceDetector *faceDetector);
};

class figKinect {
public:

    //bool isOpen();
    //bool hasNewFrame();
    //bufferFrame *getNewFrame();

    ~figKinect();
    void setup();
    void update();
    void draw();

private:
    KinectHelper *kinect = NULL;
    bufferFrame *frame = NULL;
    FaceDetector *faceDetector = NULL;
};

class ofApp : public ofBaseApp {
private:
    figKinect *kinect;
    ofTrueTypeFont font;

public:
    void setup();
    void update();
    void draw();
    ~ofApp();

    void updateKinect();
    void detectLandmarks();
    void detectMxnet();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

};
