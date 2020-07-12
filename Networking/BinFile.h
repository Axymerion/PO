#pragma once
#include <fstream>
#include <string>
class BinFile
{
	std::fstream file; //plik
public:
	//konstruktor przyjmuj¹cy œcie¿kê do pliku i informacjê, 
	//czy ma go nadpisaæ - wyczyœciæ przed otwarciem (true), 
	//czy otworzyæ bez zmian (false)
	BinFile(std::string filepath, bool overwrite); 
	//destruktor zamykaj¹cy plik
	virtual ~BinFile();
	//odczyt zadanej iloœci bajtów z pliku,
	//zwraca rzeczywiœcie odczytan¹ iloœæ bajtów
	//(w strumieniu mo¿e byæ mniej ni¿ zadana iloœæ)
	size_t Read(uint8_t * buffer, size_t bytes);
	//dopisanie zadanej iloœci bajtów do pliku
	void Append(const uint8_t * buffer, size_t bytes);
	//informacja, czy plik uda³o siê otworzyæ
	bool IsOpen();
};

