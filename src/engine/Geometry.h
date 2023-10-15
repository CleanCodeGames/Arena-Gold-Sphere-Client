// ▼
#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include "OverHeader.h"

class Geometry
{
private:

	Geometry() = delete;
	~Geometry() = default;

public:

	static cv2f Normalized(cv2f& p, cfloat& dist, cfloat& angle);
	static cfloat Distance(cv2f& p1, cv2f& p2);
	static cfloat Angle(cv2f& p1, cv2f& p2);
	static cv2f BezierGetPoint(cv2f& p1, cv2f& p2, cv2f& p3, cv2f& p4, float step);
};

#endif