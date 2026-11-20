// BombOS_Reader_main.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

std::string header;
std::string version;
std::string title;
std::string tmp;

int textureAmount;
int lvlWidth;
int lvlHeight;

char** floorMap;
char** mapMap;
char** collisionsMap;
char** objectsMap;

std::map<char, std::string> texturesMap;

int main()
{
	std::ifstream inputFile("level_1.bos");

	if (!inputFile.is_open()) return 1;


	// VERSION
	// Check header
	getline(inputFile, header, ';');
	if (header != "BOS")
	{
		inputFile.close();
		return 2;
	}

	// Store and print title
	getline(inputFile, version, ';');
	std::cout << "Version: " << version << std::endl;

	// Skip ; and get the next word
	getline(inputFile, tmp);


	// TITLE
	// Check header
	getline(inputFile, header, ';');
	if (header != "TITLE")
	{
		std::cout << "Title format error";
		inputFile.close();
		return 3;
	}

	// Store and print title
	getline(inputFile, title, ';');
	std::cout << "Title: " << title << std::endl;

	// Skip ; and get the next word
	getline(inputFile, tmp);


	// TEXTURES
	// Check header
	getline(inputFile, header, ';');
	if (header != "TEXTURES")
	{
		std::cout << "Texture format error";
		inputFile.close();
		return 4;
	}

	// Store and print textures amount
	getline(inputFile, tmp, ';');
	textureAmount = std::stoi(tmp);
	std::cout << "Texture amount: " << textureAmount << std:: endl;

	getline(inputFile, tmp);

	// From file into map
	for (int i = 0; i < textureAmount; i++)
	{
		// Read texture char
		getline(inputFile, tmp, ';');
		char tmpChar = tmp[0];

		// Read texture name an inserts char and name into the map
		getline(inputFile, tmp, ';');
		texturesMap.insert({ tmpChar, tmp });

		// Go to next line
		getline(inputFile, tmp);
	}

	for (auto texturesMapIt : texturesMap)
	{
		std::cout << texturesMapIt.first << " => " << texturesMapIt.second << std::endl;
	}


	// SIZE
	// Check header
	getline(inputFile, header, ';');
	if (header != "SIZE")
	{
		std::cout << "Size format error";
		inputFile.close();
		return 5;
	}

	// Store lvl width
	getline(inputFile, tmp, ';');
	lvlWidth = std::stoi(tmp);

	// Store lvl height
	getline(inputFile, tmp, ';');
	lvlHeight = std::stoi(tmp);

	std::cout << "Width = " << lvlWidth << std::endl;
	std::cout << "Height = " << lvlHeight << std::endl;

	getline(inputFile, tmp);


	// FLOOR
	// Check header
	getline(inputFile, header, ';');
	if (header != "FLOOR")
	{
		std::cout << "Floor format error";
		inputFile.close();
		return 6;
	}
	getline(inputFile, tmp);

	
	// Create pointer matrix
	floorMap = new char* [lvlHeight];

	for (int i = 0; i < lvlHeight; i++)
	{
		floorMap[i] = new char[lvlWidth];
	}

	// Insert chars in the matrix
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			getline(inputFile, tmp, ';');
			floorMap[i][j] = tmp[0];
		}
		getline(inputFile, tmp);
	}

	// Print matrix chars
	std::cout << "FLOOR" << std::endl;
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			std::cout << floorMap[i][j];
		}

		std::cout << std::endl;
	}


	// MAP
	// Check header
	getline(inputFile, header, ';');
	if (header != "MAP")
	{
		std::cout << "Map format error";
		inputFile.close();
		return 7;
	}
	getline(inputFile, tmp);

	// Create pointer matrix
	mapMap = new char* [lvlHeight];

	for (int i = 0; i < lvlHeight; i++)
	{
		mapMap[i] = new char[lvlWidth];
	}

	// Insert chars in the matrix
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			getline(inputFile, tmp, ';');
			mapMap[i][j] = tmp[0];
		}
		getline(inputFile, tmp);
	}

	// Print matrix chars
	std::cout << "MAP" << std::endl;
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			std::cout << mapMap[i][j];
		}

		std::cout << std::endl;
	}


	// COLLISIONS
	// Check header
	getline(inputFile, header, ';');
	if (header != "COLLISIONS")
	{
		std::cout << "Collisions format error";
		inputFile.close();
		return 8;
	}
	getline(inputFile, tmp);


	// Create pointer matrix
	collisionsMap = new char* [lvlHeight];

	for (int i = 0; i < lvlHeight; i++)
	{
		collisionsMap[i] = new char[lvlWidth];
	}

	// Insert chars in the matrix
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			getline(inputFile, tmp, ';');
			collisionsMap[i][j] = tmp[0];
		}
		getline(inputFile, tmp);
	}

	// Print matrix chars
	std::cout << "COLLISIONS" << std::endl;
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			std::cout << collisionsMap[i][j];
		}

		std::cout << std::endl;
	}


	// OBJECTS
	// Check header
	getline(inputFile, header, ';');
	if (header != "OBJECTS")
	{
		std::cout << "Objects format error";
		inputFile.close();
		return 9;
	}
	getline(inputFile, tmp);


	// Create pointer matrix


	objectsMap = new char* [lvlHeight];

	for (int i = 0; i < lvlHeight; i++)
	{
		objectsMap[i] = new char[lvlWidth];
	}

	// Insert chars in the matrix
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			getline(inputFile, tmp, ';');
			objectsMap[i][j] = tmp[0];
		}
		getline(inputFile, tmp);
	}

	// Print matrix chars
	std::cout << "OBJECTS" << std::endl;
	for (int i = 0; i < lvlHeight; i++)
	{
		for (int j = 0; j < lvlWidth; j++)
		{
			std::cout << objectsMap[i][j];
		}

		std::cout << std::endl;
	}

	// Floor reading with vectors
	//std::vector<std::vector<char>> column;

	//for (int i = 0; i < lvlHeight; i++)
	//{
	//	std::vector<char> row;

	//	for (int j = 0; j < lvlWidth; j++)
	//	{
	//		getline(inputFile, tmp, ';');
	//		row.push_back(tmp[0]);
	//	}

	//	column.push_back(row);
	//	getline(inputFile, tmp);
	//}


	//for (int i = 0; i < lvlHeight; i++)
	//{
	//	for (int j = 0; j < lvlWidth; j++)
	//	{
	//		std::cout << column[i][j];
	//	}

	//	std::cout << std::endl;
	//}

	inputFile.close();

	return 0;
}