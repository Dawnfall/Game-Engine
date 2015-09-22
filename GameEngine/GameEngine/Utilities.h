#pragma once

#include <iostream>
#include <glm/glm.hpp>
#include <string>
#include <vector>

namespace Utilities
{
	static void printMatrix(const glm::mat4& M)
	{
		std::cerr << M[0][0] << "|" << M[0][1] << "|" << M[0][2] << "|" << M[0][3] << std::endl;
		std::cerr << M[1][0] << "|" << M[1][1] << "|" << M[1][2] << "|" << M[1][3] << std::endl;
		std::cerr << M[2][0] << "|" << M[2][1] << "|" << M[2][2] << "|" << M[2][3] << std::endl;
		std::cerr << M[3][0] << "|" << M[3][1] << "|" << M[3][2] << "|" << M[3][3] << std::endl;
	}

	static std::vector<std::string> split(const std::string& line, unsigned lineLength, const char delimiter, unsigned firstIndex = 0) // just one delimiter possible for now
	{
		std::vector<std::string> output;

		unsigned startIndex = firstIndex; //we find first non empty character
		while (startIndex < lineLength)
		{
			while (startIndex < lineLength)
			{
				if (line[startIndex] != delimiter)
					break;
				startIndex++;
			}

			std::string token{ "" };//append chars to string until we find next delimiter
			while (startIndex < lineLength)
			{
				if (line[startIndex] == delimiter)
				{
					startIndex++;
					break;
				}
				token += line[startIndex];
				startIndex++;
			}
			output.push_back(token); //adding token in vector
		}
		return output;
	}

	static glm::vec3 parseToVec3(const std::vector<std::string>& tokens, unsigned startIndex) //for parsing strings in vector to integers(in vec3 or vec2) 
	{
		try
		{
			return glm::vec3{ std::stof(tokens[startIndex]), std::stof(tokens[startIndex + 1]), std::stof(tokens[startIndex + 2]) };
		}
		catch (int e)
		{
			std::cerr << "Error: Cannot parse to float at index : " << startIndex << std::endl;
		}
	}
	static glm::vec2 parseToVec2(const std::vector<std::string>& tokens, unsigned startIndex)
	{
		try
		{
			return glm::vec2{ std::stof(tokens[startIndex]), std::stof(tokens[startIndex + 1]) };
		}
		catch (int e)
		{
			std::cerr << "Error: Cannot parse to Int." << std::endl;
		}
	}
}