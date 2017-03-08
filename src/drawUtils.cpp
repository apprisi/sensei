#include "drawUtils.h"

void drawBoundBox(ofRectangle r, ofColor color) {
  ofPath p;
  p.setFillColor(color);
  p.rectangle(r);
  ofRectangle outer(r);
  outer.scaleFromCenter(1.1);
  p.rectangle(outer);
  p.draw();
}



void drawStringCentered(ofTrueTypeFont font, string s, int xc, int yc, ofColor boxColor, ofColor textColor){
  //do some voodoo
  int sw = (font.stringWidth(s));
  int sh = (font.stringHeight(s));

  int sw1 = sw * 1.05;
  int sh1 = sh * 1.8;

  int x1 = xc - (sw1/2);
  int y1 = yc - (sh1/2);

  ofSetColor(boxColor);
  ofFill();
  ofDrawRectangle(x1,y1,sw1,sh1);

  int sw2 = sw;
  int sh2 = sh;

  int x2 = xc - (sw2/2);
  int y2 = yc - ((sh2*1.3)/2);

  ofSetColor(textColor);
  font.drawString(s, x2, y2 + (sh2));}


void drawStringTopLeft(ofTrueTypeFont font, string s, int xl, int yl, ofColor boxColor, ofColor textColor){
  //do some voodoo
  int sw = (font.stringWidth(s));
  int sh = (font.stringHeight(s));

  int sw1 = sw * 1.05;
  int sh1 = sh * 1.8;

  int x1 = xl;
  int y1 = yl;

  ofSetColor(boxColor);
  ofFill();
  ofDrawRectangle(x1,y1,sw1,sh1);

  int sw2 = sw;
  int sh2 = sh;

  int xc = x1 + (sw1/2);
  int yc = y1 + (sh1/2);

  int x2 = xc - (sw2/2);
  int y2 = yc - ((sh2*1.3)/2);

  ofSetColor(textColor);
  font.drawString(s, x2, y2 + (sh2));}

void drawStringTopRight(ofTrueTypeFont font, string s, int xr, int yr, ofColor boxColor, ofColor textColor){

  //do some voodoo
  int sw = (font.stringWidth(s));
  int sh = (font.stringHeight(s));

  int sw1 = sw * 1.05;
  int sh1 = sh * 1.8;

  xr -= sw1;

  int x1 = xr;
  int y1 = yr;

  ofSetColor(boxColor);
  ofFill();
  ofDrawRectangle(x1,y1,sw1,sh1);

  int sw2 = sw;
  int sh2 = sh;

  int xc = x1 + (sw1/2);
  int yc = y1 + (sh1/2);

  int x2 = xc - (sw2/2);
  int y2 = yc - ((sh2*1.3)/2);

  ofSetColor(textColor);
  font.drawString(s, x2, y2 + (sh2));}

void drawStringBottomLeft(ofTrueTypeFont font, string s, int xl, int yl, ofColor boxColor, ofColor textColor){

  //do some voodoo
  int sw = (font.stringWidth(s));
  int sh = (font.stringHeight(s));

  int sw1 = sw * 1.05;
  int sh1 = sh * 1.8;

  yl -= sh1;

  int x1 = xl;
  int y1 = yl;

  ofSetColor(boxColor);
  ofFill();
  ofDrawRectangle(x1,y1,sw1,sh1);

  int sw2 = sw;
  int sh2 = sh;

  int xc = x1 + (sw1/2);
  int yc = y1 + (sh1/2);

  int x2 = xc - (sw2/2);
  int y2 = yc - ((sh2*1.3)/2);

  ofSetColor(textColor);
  font.drawString(s, x2, y2 + (sh2));}

void drawStringBottomRight(ofTrueTypeFont font, string s, int xr, int yr, ofColor boxColor, ofColor textColor){

  //do some voodoo
  int sw = (font.stringWidth(s));
  int sh = (font.stringHeight(s));

  int sw1 = sw * 1.05;
  int sh1 = sh * 1.8;

  xr -= sw1;
  yr -= sh1;

  int x1 = xr;
  int y1 = yr;

  ofSetColor(boxColor);
  ofFill();
  ofDrawRectangle(x1,y1,sw1,sh1);

  int sw2 = sw;
  int sh2 = sh;

  int xc = x1 + (sw1/2);
  int yc = y1 + (sh1/2);

  int x2 = xc - (sw2/2);
  int y2 = yc - ((sh2*1.3)/2);

  ofSetColor(textColor);
  font.drawString(s, x2, y2 + (sh2));}


void scaleDepthPixelsForDrawing(ofFloatPixels *depthPixels) {
  // Scale from meters to 0-1 (float)
  float *pixelData = depthPixels->getData();
  for (int i = 0; i < depthPixels->size(); i++) {
      pixelData[i] = ofMap(pixelData[i], MIN_MILLIMETERS, MAX_MILLIMETERS, 1, 0, true);
  }
}