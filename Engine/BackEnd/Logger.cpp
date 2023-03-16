#include "Logger.h"

std::ostream& operator<<(std::ostream& m_LogFile, Logger& Logger)
{
	Logger.SetTimeType(time(Logger.GetTimeType()));
	localtime_s(Logger.GetTimeString(), Logger.GetTimeType());
	fprintf(Logger.GetFilePointer(), "%d-%02d-%02d %02d:%02d:%02d", (*Logger.GetTimeString()).tm_year + 1900, (*Logger.GetTimeString()).tm_mon + 1,
		(*Logger.GetTimeString()).tm_mday, (*Logger.GetTimeString()).tm_hour,
		(*Logger.GetTimeString()).tm_min, (*Logger.GetTimeString()).tm_sec);
	return m_LogFile;
}

Logger::Logger()
{
	/*
	* Setting the time up for being able to 
	* copy it into the Logger file name
	*/

	m_TimeType = time(&m_TimeType);
	localtime_s(&m_TimeString, &m_TimeType);

	//Comes in handy for creating the name
	std::string FileName;

	/*
	* Naive method of creating the 
	* file name
	*/

	FileName+="Log.txt";

	/*
	* Opening the error stream for enabling the 
	* Loggerging and sending the errors or messages to the file
	*/

	freopen_s(&m_LogFile, FileName.c_str(), "w", stderr);

	/*
	* Checks whether the file has been created, if not, the program continues w/o logging
	*/

	if (m_LogFile == nullptr) throw std::exception("An error while opening the Logger file");
	else
	{
		std::cerr << "[" << *this << "] " << "The Log file has been created\n";
	}

}

Logger::~Logger()
{

	std::cerr << "[" << *this << "] " << "The Log file has been closed\n";

}

void Logger::UpdateTime(void)
{

	m_TimeType = time(&m_TimeType);
	localtime_s(&m_TimeString, &m_TimeType);

}

void Logger::Log(const char* Information)
{

	std::cerr << "[" << *this << "] " << Information;

}

void Logger::LogRenderedChunks(int ChunkAmount)
{

	std::cerr << "[" << *this << "] " << "Currently drawing " << ChunkAmount << "chunks\n";

}
