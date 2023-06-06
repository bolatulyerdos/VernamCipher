/*
	=============================================================
	Name		: VernamCipher.c
	Created		: 07.06.2023
	Modified	: 07.06.2023
	Author		: bolatulyerdos
	Description	: Vernam cipher (one-time pad), command line tool
	=============================================================
*/

#include <stdio.h>

int main(int argc, const char* argv[])
{
	if (argc != 4)
	{
		printf("Usage: VernamCipher.exe [input_file] [key_file] [output_file]\n");
		return 1;
	}

	const char* inputName	= argv[1];
	const char* keyName		= argv[2];
	const char* outputName	= argv[3];

	FILE* inputFile			= fopen(inputName,	"rb");
	FILE* keyFile			= fopen(keyName,	"rb");

	if (inputFile == NULL || keyFile == NULL)
	{
		printf("ERROR: Can't open input file or key file.\n");
		return 1;
	}

	fseek(inputFile,	0, SEEK_END);
	fseek(keyFile,		0, SEEK_END);

	unsigned long long inputSize	= ftell(inputFile);
	unsigned long long keySize		= ftell(keyFile);

	rewind(inputFile);
	rewind(keyFile);

	if (inputSize != keySize)
	{
		printf("ERROR: Input file and key file have different sizes.\n");
		fclose(inputFile);
		fclose(keyFile);
		return 1;
	}

	FILE* outputFile		= fopen(outputName,	"wb");

	if (outputFile == NULL)
	{
		printf("ERROR: Can't create output file.\n");
		fclose(inputFile);
		fclose(keyFile);
		return 1;
	}

	int inputByte;

	while ((inputByte = fgetc(inputFile)) != EOF)
	{
		int keyByte		= fgetc(keyFile);
		int outputByte	= inputByte ^ keyByte;
		fputc(outputByte, outputFile);
	}

	fclose(inputFile);
	fclose(keyFile);
	fclose(outputFile);

	return 0;
}