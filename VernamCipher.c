/*
	=============================================================
	Name		: VernamCipher.c
	Created		: 07.06.2023
	Modified	: 11.08.2023
	Author		: bolatulyerdos
	Description	: Vernam cipher (one-time pad), command line tool
	=============================================================
*/

#include <stdio.h>

int main(int argc, const char* argv[])
{
	// Check if the correct number of command-line arguments is provided
	if (argc != 4)
	{
		printf("Usage: VernamCipher.exe [input_file] [key_file] [output_file]\n");
		return 1;
	}

	// Get input, key, and output file names from command-line arguments
	const char* inputName	= argv[1];
	const char* keyName		= argv[2];
	const char* outputName	= argv[3];

	// Open input and key files
	FILE* inputFile			= fopen(inputName,	"rb");
	FILE* keyFile			= fopen(keyName,	"rb");

	// Check if files are successfully opened
	if (!inputFile || !keyFile)
	{
		printf("ERROR: Can't open input file or key file.\n");
		return 1;
	}

	// Calculate sizes of input and key files
	fseek(inputFile,	0, SEEK_END);
	fseek(keyFile,		0, SEEK_END);

	unsigned long long inputSize	= ftell(inputFile);
	unsigned long long keySize		= ftell(keyFile);

	// Reset the files pointers to the beginning
	rewind(inputFile);
	rewind(keyFile);

	// Check if input and key files have the same size
	if (inputSize != keySize)
	{
		printf("ERROR: Input file and key file have different sizes.\n");
		fclose(inputFile);
		fclose(keyFile);
		return 1;
	}

	// Open output file for writing
	FILE* outputFile		= fopen(outputName,	"wb");

	// Check if the output file is successfully created
	if (!outputFile)
	{
		printf("ERROR: Can't create output file.\n");
		fclose(inputFile);
		fclose(keyFile);
		return 1;
	}

	int inputByte, keyByte;

	// Read input and key bytes, perform XOR operation, and write to output file
	while ((inputByte = fgetc(inputFile)) != EOF && (keyByte = fgetc(keyFile)) != EOF)
	{
		int outputByte	= inputByte ^ keyByte;
		fputc(outputByte, outputFile);
	}

	// Close files
	fclose(inputFile);
	fclose(keyFile);
	fclose(outputFile);

	return 0;
}