#pragma once

#include <string>
#include <fstream>

class LoadUtil
{
public:
	static const std::string LoadShader(const std::string& fileName);

private:
};

const std::string LoadUtil::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open(fileName.c_str());

	std::string output;
	std::string line;

	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
		return "";

	return output;
}