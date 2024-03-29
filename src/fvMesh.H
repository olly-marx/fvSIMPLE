//AUTHOR:       Oliver Marx - ojm40@cam.ac.uk

#ifndef MESH_HEADER
#define MESH_HEADER

#include <iostream>
#include <array>
#include <string>
#include <vector>

#include <armadillo>

#include "BoundaryPatch.H"
#include "Face.H"
#include "Cell.H"

class fvMesh{
        public:
		//Constructors
                fvMesh();

		//Mesh construction
		void addPoint(std::array<double,3>);
		void addFace(Face);
		void addCell(Cell);
		void addBoundaryPatch(BoundaryPatch);

		//Mesh fetching
		const Face& getFace(int);
		const std::array<double,3>&        getPoint(int);
		std::vector<std::array<double,3>>& allPoints();
		std::vector<Face>&                 allFaces();
		std::vector<Cell>&                 allCells();
		std::vector<BoundaryPatch>&        allBPs();

		//Mesh utilities
		void                               copyX(arma::mat&) const;
		int                                getNInternalFaces() const;
		void                               setNInternalFaces(int);
		int                                getNCells() const;
		void                               setNCells(int);

		//Random mesh detail methods
		std::array<int, 4>                 getMeshDetails();
		double                             cellVolume(int) const;
		std::array<double,3>               faceAreaVector(int) const;
		std::array<double,3>               cellCentroid(int) const;
		std::array<double,3>               faceCentroid(int) const;
		std::vector<std::array<int,2>>     boundaryFaceOwner(BoundaryPatch);
		std::vector<int>                   cellNeighbors(int) const;
		std::array<int,2>                  faceOwnerNeighbor(int) const;

		std::string displayMeshDetails();
		std::string displayVolumesAndAreas();
		std::string displayCentroids();
		std::string displayBoundaryFaces();
		std::string displayCellNeighbors();
		std::string displayFaceOwnerNeighbor();

		//Mesh finalizing methods
		void                               calculateFaceCellDistanceRatios();
		void                               calculateFaceDeltaCoeffs();

        private:
                std::vector<std::array<double,3>> m_points;
                std::vector<Face> m_faces;
		std::vector<Cell> m_cells;
		std::vector<BoundaryPatch> m_boundaryPatches;
		int m_internalFaces;
		int m_nCells;
};

#endif

