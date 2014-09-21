/*************************************************************************
    > File Name: main.cpp
    > Subject: Max point on a line --- LeetCode 
    > Author: ayumi_Long
    > Mail: ayumilong41@gmail.com 
    > Created Time: Wed 22 Jan 2014 08:33:38 PM EST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point{
	int x;
    int y;
	Point(): x(0), y(0){}
	Point(int m, int n): x(m), y(n){}
};

bool operator<(const Point& p1, const Point& p2){
	return p1.x < p2.x;
}

class Solution {
public:
	void sortPoints(std::vector<Point>& points){//Insertion sort
		int size = points.size();
		for(int i = 1; i < size; ++i){
			for(int  j = 0; j < i; ++j){
				if(points[i].x < points[j].x){
					Point temp = points[i];
					for(int k = i; k > j; --k){
						points[k] = points[k - 1];
					}
					points[j] = temp;
					break;
				}
			}	
		}
	}

	int maxPoints(const std::vector<Point>& points){    
		std::vector<Point> tempPoints(points.begin(), points.end());
		sort(tempPoints.begin(), tempPoints.end());
		for(size_t i = 0; i < tempPoints.size(); ++i){
			std::cout << tempPoints[i].x << " " << tempPoints[i].y <<std::endl;
		}
		//sortPoints(tempPoints); //Sort the points by X value in ascending sequence
		if(tempPoints.size() == 0){ //If there is only one point, just return 1
			return 0;
		}else if(tempPoints.size() == 1){ //If there is no point at all
			return 1;
		}else if(tempPoints.size() == 2){
			return 2;
		}
		size_t maxLineLen = 2; 
		for(size_t i = 0; i < tempPoints.size(); ++i){
			if(maxLineLen >= tempPoints.size() - i){ //Already find the max line, there are no more number of points left than the maxLineLen
				return maxLineLen;
			}
			double x1 = tempPoints[i].x;
			double y1 = tempPoints[i].y;
			for(size_t j = i + 1; j < tempPoints.size(); ++j){
				size_t tempLineLen = 1; //The current point tempPoints[i] is the first point
				double x2 = tempPoints[j].x;
				double y2 = tempPoints[j].y;	
				while(x1 == x2 && y1 == y2){ //Skip all the same points
					++tempLineLen;
					++j;
					if(j == tempPoints.size()){ //All the rest points are the same
						if(maxLineLen < tempLineLen){
							return tempLineLen;
						}else{
							return maxLineLen;
						}
					}
					x2 = tempPoints[j].x;
					y2 = tempPoints[j].y;
				}
				double lineK = (y2 - y1)/(x2 - x1); //Get the slope rate of the current line
				if(x1 == x2){//If x1 equals to x2, this means linkK is inf or -inf
					lineK = fabs(lineK);
				}
				++tempLineLen; //The next different point is the second point
				for(size_t k = j + 1; k < tempPoints.size(); ++k){ //Now we have a certain line and want to find more points in this line
					double x3 = tempPoints[k].x;
					double y3 = tempPoints[k].y;
					double tempK = (y3 - y1)/(x3 - x1);
					if(x1 == x3){
						tempK = fabs(tempK);
					}
					if(lineK == tempK){ //If the slope rate is the same, then this point is in the current line
						++tempLineLen;
					}
				}
				if(maxLineLen < tempLineLen){ //Update maxLineLen
					maxLineLen = tempLineLen;
				}
			}
		}
		return maxLineLen;
    }
};

int main(){
	std::string s = "(-240,-657),(-27,-188),(-616,-247),(-264,-311),(-352,-393),(-270,-748),(3,4),(-308,-87),(150,526),(0,-13),(-7,-40),(-3,-10),(-531,-892),(-88,-147),(4,-3),(-873,-555),(-582,-360),(-539,-207),(-118,-206),(970,680),(-231,-47),(352,263),(510,143),(295,480),(-590,-990),(-236,-402),(308,233),(-60,-111),(462,313),(-270,-748),(-352,-393),(-35,-148),(-7,-40),(440,345),(388,290),(270,890),(10,-7),(60,253),(-531,-892),(388,290),(-388,-230),(340,85),(0,-13),(770,473),(0,73),(873,615),(-42,-175),(-6,-8),(49,176),(308,222),(170,27),(-485,-295),(170,27),(510,143),(-18,-156),(-63,-316),(-28,-121),(396,304),(472,774),(-14,-67),(-5,7),(-485,-295),(118,186),(-154,-7),(-7,-40),(-97,-35),(4,-9),(-18,-156),(0,-31),(-9,-124),(-300,-839),(-308,-352),(-425,-176),(-194,-100),(873,615),(413,676),(-90,-202),(220,140),(77,113),(-236,-402),(-9,-124),(63,230),(-255,-118),(472,774),(-56,-229),(90,228),(3,-8),(81,196),(970,680),(485,355),(-354,-598),(-385,-127),(-2,7),(531,872),(-680,-263),(-21,-94),(-118,-206),(616,393),(291,225),(-240,-657),(-5,-4),(1,-2),(485,355),(231,193),(-88,-147),(-291,-165),(-176,-229),(154,153),(-970,-620),(-77,33),(-60,-111),(30,162),(-18,-156),(425,114),(-177,-304),(-21,-94),(-10,9),(-352,-393),(154,153),(-220,-270),(44,-24),(-291,-165),(0,-31),(240,799),(-5,-9),(-70,-283),(-176,-229),(3,8),(-679,-425),(-385,-127),(396,304),(-308,-352),(-595,-234),(42,149),(-220,-270),(385,273),(-308,-87),(-54,-284),(680,201),(-154,-7),(-440,-475),(-531,-892),(-42,-175),(770,473),(118,186),(-385,-127),(154,153),(56,203),(-616,-247)";
	std::string newStr;
	for(size_t i = 0; i < s.size(); ++i){
		if(s[i] != '(' && s[i] != ')' && s[i] != ','){
			newStr += s[i];
		}else if(s[i] == ','){
			newStr += ' ';
		}
	}
	//std::cout<<newStr<<std::endl;

	std::vector<Point> points;
	Point p;
	while(std::cin >> p.x >> p.y){ //Read all points to a vector
		points.push_back(p);
	}


	Solution ss;
	std::cout << ss.maxPoints(points) << std::endl;
	return 0;
}
