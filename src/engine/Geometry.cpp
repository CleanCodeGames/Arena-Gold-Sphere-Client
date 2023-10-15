// ▼
#include "Geometry.h"

cv2f Geometry::Normalized(cv2f& p, cfloat& dist, cfloat& angle)
{
	cfloat& A = { angle * RAD };
	return p + cv2f(cosf(A), sinf(A)) * dist;
}

cfloat Geometry::Distance(cv2f& p1, cv2f& p2)
{
	cv2f diff = p2 - p1;
    return hypotf(diff.x, diff.y);
}

cfloat Geometry::Angle(cv2f& p1, cv2f& p2)
{
	return atan2f(p2.y - p1.y, p2.x - p1.x) * DEG;
}

cv2f Geometry::BezierGetPoint(cv2f& p1, cv2f& p2, cv2f& p3, cv2f& p4, float step)
{
	step = clamp(step, 0.f, 1.f);
	cfloat& dist = 1.f - step;
	cv2f& result = 
	{ 
		dist * dist * dist * p1 + 
		3.f * dist * dist * step * p2 + 
		3.f * dist * step * step * p3 + 
		step * step * step * p4 
	};

	return result;
}
