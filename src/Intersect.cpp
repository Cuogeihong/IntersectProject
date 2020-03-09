// Intersect.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#pragma warning(disable: 4996)

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

Image::Image() {
	pointNum = 0;
}

void Image::addLine(int x1, int y1, int x2, int y2) {
	line cur;
	cur.a = y1 - y2;
	cur.b = x2 - x1;
	cur.c = x1 * y2 - x2 * y1;
	lines.push_back(cur);
}

void Image::addCircle(int x, int y, int r) {
	circle cur;
	cur.x = x;
	cur.y = y;
	cur.r = r;
	circles.push_back(cur);
}

int Image::getNum() {
	cout << "start" << endl;
	this->getLineAndLinePoint();
	cout << "stage1 complete\n" << endl;
	this->getLineAndCirclePoint();
	cout << "stage2 complete\n" << endl;
	this->getCircleAndCirclePoint();
	cout << "stage3 complete\n" << endl;
	pointNum = points.size();
	return pointNum;
}

void Image::getLineAndLinePoint() {
	int linesLength = lines.size();
	for (int i = 0; i < linesLength; i++) {
		for (int j = i + 1; j < linesLength; j++) {
			line lineA, lineB;
			lineA = lines[i];
			lineB = lines[j];

			

			int judgeNum = lineA.a * lineB.b - lineA.b * lineB.a;
			if (judgeNum == 0) {
				continue;
			}
			double x, y;
			x = (lineB.c * lineA.b - lineA.c * lineB.b) / judgeNum;
			y = (lineB.a * lineA.c - lineA.a * lineB.c) / judgeNum;
			//cout << x << " " << y << endl;
			point cur(x, y);
			points.insert(cur);
		}
		if (i % 100 == 0) {
			cout << "stage complete 100 per" << endl;
		}
		
	}
}

void Image::getLineAndCirclePoint() {
	int linesLength = lines.size();
	int circlesLength = circles.size();
	for (int i = 0; i < linesLength; i++) {
		for (int j = 0; j < circlesLength; j++) {
			line curLine;
			circle curCircle;
			curLine = lines[i];
			curCircle = circles[j];
			if (curLine.b == 0) {
				double distanceLC = curLine.c / curLine.a + curCircle.x;
				if (fabs(fabs(distanceLC) - abs(curCircle.r)) < 1e-8) {
					point cur(-1 * curLine.c / curLine.a, curCircle.y);
					points.insert(cur);
				}
				else if (fabs(distanceLC) - abs(curCircle.r) < 0) {
					double sqrtTmp = sqrt(curCircle.r * curCircle.r - distanceLC * distanceLC);
					point cur1(-1 * curLine.c / curLine.a, curCircle.y + sqrtTmp);
					point cur2(-1 * curLine.c / curLine.a, curCircle.y + sqrtTmp);
					points.insert(cur1);
					points.insert(cur2);
				}
			}
			else {
				double k = -1 * curLine.a / curLine.b, b = -1 * curLine.c / curLine.b;
				double equationA, equationB, equationC;
				equationA = k * k + 1;
				equationB = 2 * (k * b - k * curCircle.y - curCircle.x);
				equationC = curCircle.x * curCircle.x - curCircle.r * curCircle.r + (b - curCircle.y) * (b - curCircle.y);
				double judge = equationB * equationB - 4 * equationA * equationC;
				if (fabs(judge) < 1e-8) {
					double answerX = -1 * equationB / 2 / equationA;
					point cur(answerX, answerX * k + b);
					points.insert(cur);
				}
				else if (judge > 0) {
					double answerX1 = (-1 * equationB + sqrt(judge)) / 2 / equationA;
					point cur1(answerX1, answerX1 * k + b);
					points.insert(cur1);
					double answerX2 = (-1 * equationB - sqrt(judge)) / 2 / equationA;
					point cur2(answerX2, answerX2 * k + b);
					points.insert(cur2);
				}
			}
		}
		if (i % 100 == 0) {
			cout << "stage complete 100 per" << endl;
		}
	}
}

void Image::getCircleAndCirclePoint() {
	int circleLength = circles.size();
	for (int i = 0; i < circleLength; i++) {
		for (int j = i + 1; j < circleLength; j++) {
			circle circleA, circleB;
			circleA = circles[i];
			circleB = circles[j];

			if (circleA.r == circleB.r && circleA.x == circleB.x && circleA.y == circleB.y) {
				continue;
			}

			int tmpA, tmpB, tmpC;
			tmpA = 2 * (circleB.x - circleA.x);
			tmpB = 2 * (circleB.y - circleA.y);
			tmpC = circleA.x * circleA.x + circleA.y * circleA.y - circleB.x * circleB.x - circleB.y * circleB.y + circleB.r * circleB.r - circleA.r * circleA.r;
			if (tmpB == 0) {
				if (tmpA != 0) {
					double answerX = -1 * tmpC / tmpA;
					double judge = circleA.r * circleA.r - (answerX - circleA.x) * (answerX - circleA.x);
					if (fabs(judge) < 1e-8) {
						point cur(answerX, circleA.y);
						points.insert(cur);
					}
					else if (judge > 0) {
						point cur1(answerX, circleA.y + sqrt(judge));
						points.insert(cur1);
						point cur2(answerX, circleA.y - sqrt(judge));
						points.insert(cur2);
					}
				}
			}
			else {
				double k = tmpA / tmpB;
				double t = tmpC / tmpB + circleA.y;
				double equationA, equationB, equationC;
				equationA = k * k + 1;
				equationB = 2 * (k * t - circleA.x);
				equationC = circleA.x * circleA.x + t * t - circleA.r * circleA.r;
				double judge = equationB * equationB - 4 * equationA * equationC;
				if (fabs(judge) < 1e-8) {
					double answerX = -1 * equationB / 2 / equationA;
					double answerY = -1 * tmpA / tmpB * answerX - tmpC / tmpB;
					point cur(answerX, answerY);
					points.insert(cur);
				}
				else if (judge > 0) {
					double answerX1 = (-1 * equationB + sqrt(judge)) / 2 / equationA;
					double answerY = -1 * tmpA / tmpB * answerX1 - tmpC / tmpB;
					point cur1(answerX1, answerY);
					points.insert(cur1);
					double answerX2 = (-1 * equationB - sqrt(judge)) / 2 / equationA;
					answerY = -1 * tmpA / tmpB * answerX2 - tmpC / tmpB;
					point cur2(answerX2, answerY);
					points.insert(cur2);
				}
			}
		}
		if (i % 100 == 0) {
			cout << "stage complete 100 per" << endl;
		}
	}
}

int main(int argc, char * argv[])
{
	FILE *fpIn, *fpOut;
	for (int i = 0; i < argc; i++) {
		if (argv[i][0] == '-' && argv[i][1] == 'i' &&argv[i][2] == '\0') {
			freopen_s(&fpIn, argv[i + 1], "r", stdin);
			//cout << argv[i + 1] << endl;
		}
		else if (argv[i][0] == '-' && argv[i][1] == 'o' &&argv[i][2] == '\0') {
			freopen_s(&fpOut, argv[i + 1], "w", stdout);
			//cout << argv[i + 1] << endl;
		}
	}
	
	Image img;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char judgeLorC;
		int num_1, num_2, num_3, num_4;
		cin >> judgeLorC;
		if (judgeLorC == 'L') {
			cin >> num_1 >> num_2 >> num_3 >> num_4;
			img.addLine(num_1, num_2, num_3, num_4);
		}
		else if (judgeLorC == 'C') {
			cin >> num_1 >> num_2 >> num_3;
			img.addCircle(num_1, num_2, num_3);
		}
	}
	printf("%d\n", img.getNum());
}
