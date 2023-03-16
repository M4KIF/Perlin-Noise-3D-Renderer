#pragma once

#include<fstream>
#include<iomanip>
#include<iostream>
#include<ctime>
#include<string>

/*
* This class is meant to log the information
* from the program execution
*/

class Logger
{
private:

	tm m_TimeString;
	time_t m_TimeType;
	FILE* m_LogFile;

public:

	/*
	* Default constructor and destructor
	* sets up for reading time and creates
	* a file with the current time in its name
	*/

	Logger();
	~Logger();

	/*Getters and setters*/

	inline tm* GetTimeString(void) { return &m_TimeString; };
	inline time_t* GetTimeType(void) { return &m_TimeType; };
	inline FILE* GetFilePointer(void) { return m_LogFile; };
	inline void SetTimeString(tm TimeString) { m_TimeString = TimeString; };
	inline void SetTimeType(time_t TimeType) { m_TimeType = TimeType; };
	inline FILE* SetFilePointer(FILE* NewFile) { m_LogFile = NewFile; };

	/*
	* Methods for basic logging purposes
	*/

	//Reads time into the var's that are private
	void UpdateTime(void);

	//Transmits the message to the file
	void Log(const char* Information);

	//Transmits the amount of visible chunks to the file
	void LogRenderedChunks(int ChunkAmount);

	//Comes handy at displaying time
	friend std::ostream& operator<<(std::ostream& log_file, Logger& log_object);

};

