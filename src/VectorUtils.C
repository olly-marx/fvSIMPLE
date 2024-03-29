//AUTHOR:       Oliver Marx - ojm40@cam.ac.uk

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cmath>

#include "VectorUtils.H"

std::array<double,3> cross(const std::array<double,3>& a, const std::array<double,3>& b){
	std::array<double,3> result = {0.0, 0.0, 0.0};
	result[0]=   (a[1]*b[2] - a[2]*b[1]);
	result[1]= - (a[0]*b[2] - a[2]*b[0]);
	result[2]=   (a[0]*b[1] - a[1]*b[0]);
	return result;
}

std::array<double,3> operator+(const std::array<double,3>& a, const std::array<double,3>& b){
	std::array<double,3> result = {0.0, 0.0, 0.0};
	for(int i=0;i<3;i++) result[i] = a[i] + b[i];
	return result;
}

std::array<double,3> operator-(const std::array<double,3>& a, const std::array<double,3>& b){
	std::array<double,3> result = {0.0, 0.0, 0.0};
	for(int i=0;i<3;i++) result[i] = a[i] - b[i];
	return result;
}

std::array<double,3> operator*(const double& a,  const std::array<double,3>& b){
	std::array<double,3> result = {0.0, 0.0, 0.0};
	for(int i=0;i<3;i++) result[i] = a*b[i];
	return result;
}

std::array<double,3> operator*(const std::array<double,3>& b, const double& a){
	std::array<double,3> result = {0.0, 0.0, 0.0};
	for(int i=0;i<3;i++) result[i] = a*b[i];
	return result;
}

bool operator==(const std::array<double,3>& a, const std::array<double,3>& b)
{
	return a[0]==b[0] && a[1]==b[1] && a[2]==b[2];
}

double dot(std::array<double,3> a, std::array<double,3> b){
	double result = 0.0;
	for(int i=0;i<3;i++) result += a[i] * b[i];
	return result;
}

double mod(std::array<double,3> a){
	double result = 0.0;
	for(int i=0;i<3;i++){
		result += a[i] * a[i];
	}
	return std::sqrt(result);
}

std::string printV(std::array<double, 3> V){
	std::string out = "";
	for(int i=0;i<3;i++) out += std::to_string(V[i]) + " ";
	return out;
}
