#pragma once
#include <fstream>
#include <string>
class BinFile
{
	std::fstream file; //plik
public:
	//konstruktor przyjmuj�cy �cie�k� do pliku i informacj�, 
	//czy ma go nadpisa� - wyczy�ci� przed otwarciem (true), 
	//czy otworzy� bez zmian (false)
	BinFile(std::string filepath, bool overwrite); 
	//destruktor zamykaj�cy plik
	virtual ~BinFile();
	//odczyt zadanej ilo�ci bajt�w z pliku,
	//zwraca rzeczywi�cie odczytan� ilo�� bajt�w
	//(w strumieniu mo�e by� mniej ni� zadana ilo��)
	size_t Read(uint8_t * buffer, size_t bytes);
	//dopisanie zadanej ilo�ci bajt�w do pliku
	void Append(const uint8_t * buffer, size_t bytes);
	//informacja, czy plik uda�o si� otworzy�
	bool IsOpen();
};

