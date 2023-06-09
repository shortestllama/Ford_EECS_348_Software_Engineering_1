#include <stdio.h>
#include <iostream>
#include <fstream>
#include "matrix.h"

void matrix::createMatrix()
{
	std::ifstream inFile;
	inFile.open("input.txt");
	inFile>>rows;
	inFile>>cols;
	grid = new double*[rows];
	grid_temp = new double*[rows];
	for(int i = 0; i<rows; i++){
		grid[i] = new double[cols];
		grid_temp[i] = new double[cols];
	}
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			inFile>>grid[i][j];
		}
	}
	return;
}

void matrix::printMatrix(){
        for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
                        std::cout<<grid[i][j]<<"\t";
                }
                std::cout<<"\n";
        }
}

void matrix::addMatrix(){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			grid_temp[i][j] = grid[i][j]+grid[i][j];
		}
	}
        for(int i = 0; i<rows; i++){
                for(int j = 0; j<cols; j++){
			std::cout<<grid_temp[i][j]<<"\t";
                }
		std::cout<<"\n";
        }
}

double matrix::getMax(){
	//TO DO
	double max_element = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] > max_element) {
				max_element = grid[i][j];
			}
		}
	}

	return max_element;
}

bool matrix::findElement(int no){
	//TO DO
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (grid[i][j] == no) {
				std::cout << "Element found at " << i << ", " << j << "\n";
				return true;
			}
		}
	}

	std::cout<<"\nElement not found\n";
	return false;
}

void matrix::changeElement(int r, int c, int no){
	//TO DO
	
	grid[r][c] = no;
	return;
}
void matrix::multiplyMatrix(){
	//TO DO
	//Hint: May want to store the new result in grid_temp and print that matrix
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			for (int k = 0; k < cols; k++) {
				grid_temp[i][j] += grid[i][k] * grid[k][j];
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << grid_temp[i][j] << " ";
		}

		std::cout << "\n";
	}
	
	return;
}

void matrix::transposeMatrix(){
	//TO DO
	//Hint: May want to store the new results in grid_temp and print that matrix
	
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			grid_temp[j][i] = grid[i][j];
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << grid_temp[i][j] << " ";
		}

		std::cout << "\n";
	}

	return;
}
matrix::~matrix(){
        for(int i = 0; i<rows; i++){
                delete[] grid[i];
                delete[] grid_temp[i];
        }
        delete[] grid;
        delete[] grid_temp;
}
