#pragma once
#include "pch.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<double, double> point;

struct line {
	int a;
	int b;
	int c;
};
struct circle {
	int x;
	int y;
	int r;
};

class Image {
public:
	Image();
	void addLine(int x1, int y1, int x2, int y2);
	void addCircle(int x, int y, int r);
	int getNum();

private:
	int pointNum;
	set <point> points;
	vector <line> lines;
	vector <circle> circles;
	void getLineAndLinePoint();
	void getLineAndCirclePoint();
	void getCircleAndCirclePoint();
};