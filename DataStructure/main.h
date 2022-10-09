#pragma once

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// counting iversion function
int count_mid_inv(int array[], const int begin, const int mid, const int end);
int count_inv(int array[], const int begin, const int end);


// sort function
void merge(int array[], int const begin, int const mid, int const end);
void mergeSort(int array[], const int begin, const int end);

// closestpair
class point2D
{
public:
	float x;
	float y;
	point2D(float px, float py);
};
float distBetweenPoints(point2D p1, point2D p2);
float bruteforce(vector<point2D>& pt, const int start, const int end);
float stripClosestPair(vector<point2D> strip, float gamma);
float closesetPair(vector<point2D>& pt, int const start, int const end);

// Karatsuba Multiplication
vector<int> kara_Multi(vector<int> x, vector<int> y);
void abcd(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d, vector<int> x, vector<int> y);
vector<int> sum_vec(vector<int> x, vector<int> y);
vector<int> sub_vec(vector<int> x, vector<int> y);
vector<int> multi_vec(vector<int> x, vector<int> y);
vector<int> pow_10(vector<int>& x, int n);
#endif