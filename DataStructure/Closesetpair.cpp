#include "main.h"

point2D::point2D(float px, float py)
{
	x = px;
	y = py;
}


float distBetweenPoints(point2D p1, point2D p2)
{	
	// Euclidean distance between two points.
	float p1x = p1.x, p1y = p1.y;
	float p2x = p2.x, p2y = p2.y;
	return (float)sqrt(pow(p1x - p2x, 2) + pow(p1y - p2y, 2));
}


float bruteforce(vector<point2D>& pt, const int start, const int end)
{
	float min = FLT_MAX;
	for (size_t i = start; i <= end; ++i)
	{
		for (size_t j = 1 + i + start; j <= end; ++j)
		{
			float dist = distBetweenPoints(pt[i], pt[j]);
			if (dist < min)
				min = dist;
		}
	}
	return min;
}

float stripClosestPair(vector<point2D> strip, float gamma)
{
	// sort accourding to Y
	sort(strip.begin(), strip.end(), [](const point2D& a, const point2D& b) { return (a.y < b.y); });
	float min_dist = gamma;

	for (int i = 0; i < strip.size(); ++i)
	{
		for (int j = 1 + i; j < strip.size() && (strip[j].y - strip[i].y) < min_dist; ++j)
		{
			float dist = distBetweenPoints(strip[i], strip[j]);
			if (dist < min_dist)
				min_dist =  dist;
		}
	}
	return min_dist;
}



float closesetPair(vector<point2D>& pt, int const start, int const end)
{
	if (end - start <= 3)
		return bruteforce(pt, start, end);

	int mid = start + (end - start) / 2;
	point2D midpoint = pt[mid];

	float d1 = closesetPair(pt, start, mid);
	float d2 = closesetPair(pt, mid + 1, end);
	float gamma = min(d1, d2);

	// find x with distance to mid less than gamma.
	vector<point2D> slicePoints;

	for (int i = start; i <= end; ++i)
	{
		if (pt[i].x < midpoint.x)
			slicePoints.push_back(pt[i]);
	}

	float d3 = stripClosestPair(slicePoints, gamma);
	return min(d3, gamma);
}