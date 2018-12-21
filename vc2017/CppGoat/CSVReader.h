#pragma once
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

namespace cx {
	namespace util {
		/*
		* A class to read data from a csv file.
		*/
		class CSVReader
		{
			std::string fileName;
			std::string delimeter;

		public:
			CSVReader(std::string filename, std::string delm = ",") :
				fileName(filename), delimeter(delm)
			{ }

			// Function to fetch data from a CSV File
			std::vector<std::vector<std::string> > getData();
		};

		/*
		* Parses through csv file line by line and returns the data
		* in vector of vector of strings.
		*/
		std::vector<std::vector<std::string> > CSVReader::getData()
		{
			std::ifstream file(fileName);

			std::vector<std::vector<std::string> > dataList;

			std::string line = "";
			// Iterate through each line and split the content using delimeter
			while (getline(file, line))
			{
				std::vector<std::string> vec;
				dataList.push_back(vec);
			}
			// Close the File
			file.close();

			return dataList;
		}
	}
}