//AUTHOR:       Oliver Marx - ojm40@cam.ac.uk
#include <iostream>
#include <array>
#include <vector>
#include <string>

#include "Face.H"
#include "VectorUtils.H"


// Face constructor, takes a vector of points to define a face of n Points
Face::Face(const std::vector<std::array<double,3>> &points, std::vector<int> indices, int faceId){
	m_faceId = faceId;
	m_owner = -1;
	m_neighbor = -1;
        m_vertices = indices;
	m_isBoundary = true;
	m_boundaryPatchId = -1;

        //Implement face centroid calculation
        calcFaceCentroid(points);
	//std::cout << m_faceCentroid[0] << " " << m_faceCentroid[1] << " " << m_faceCentroid[2] << std::endl;

        //Implement tesselation calc
        calcFaceAreaVector(points);
	//std::cout << m_faceId << " " << m_faceAreaVector[0] << " " << m_faceAreaVector[1] << " " << m_faceAreaVector[2] << std::endl;
}

// Return face ID
int Face::getFaceId(){
	return m_faceId;
}

// Return vector of points forming face
std::vector<int> Face::getFaceVertexIndices(){
        return m_vertices;
}

// Return face centroid coordinates
std::array<double,3> Face::getFaceCentroid() const{
	return m_faceCentroid;
}

// Return face centroid coordinates
std::array<double,3> Face::getFaceAreaVector() const{
	return m_faceAreaVector;
}

// Return owner cell integer index
int Face::getOwner() const{
	return m_owner;
}

// Return neighbor cell integer index
int Face::getNeighbor() const{
	return m_neighbor;
}

// set owner cell integer index
void Face::setOwner(int o){
	m_owner = o;
}

// set owner cell integer index
void Face::setNeighbor(int n){
	m_neighbor = n;
}

void Face::makeInternalFace(){
	m_isBoundary = false;
}

// Algorithm to take points defining face and calculate position of face
// centroid in 3D
// Defined as the vector average of the points defining a faces
void Face::calcFaceCentroid(const std::vector<std::array<double,3>> &points)
{
        // Init empty result array
        std::array<double,3> result = {0.0, 0.0, 0.0};
        // Loop over points of face
        for(unsigned int i=0;i<m_vertices.size();i++){

                // Add current point to result
		result = result + points[m_vertices[i]];
        }

        // divide by number of points in face to take average
        result = (1.0/4.0) * result;

        m_faceCentroid = result;
}

// Algorithm to tesselate face points and calculate face area
void Face::calcFaceAreaVector(const std::vector<std::array<double, 3>> &points)
{
        //Init empty result array
        std::array<double,3> result = {0.0, 0.0, 0.0};

        // Loop over all vertices in face
        for(unsigned int i=0;i<m_vertices.size();i++){
                // Init empty point arrays
                std::array<double,3> p, p2;

                // While the current point is not the final point, use i and i+1
                if(i<m_vertices.size()-1){
                        p = points[m_vertices[i]];
                        p2 = points[m_vertices[i+1]];
                }
                // When i is the final point, use point 0 and i
                else{
                        p = points[m_vertices[i]];
                        p2 = points[m_vertices[0]];
                }

                // Vector differences to set up cross product
                std::array<double,3> vector1, vector2;
		vector1 = p - p2;
		vector2 = m_faceCentroid - p2;

                // take the cross product * 0.5 to get area of each triangle
		result = result - cross(vector1, vector2);
        }
        m_faceAreaVector = 0.5 * result;
}

double Face::getfx() const
{
	return m_fx;
}

void Face::setfx(double fx)
{
	m_fx = fx;
}

double Face::getDelta() const
{
	return m_delta;
}

void Face::setDelta(double delta)
{
	m_delta = delta;
}

bool Face::isBoundary() const
{
	return m_isBoundary;
}
