#include <iostream>
#include <mutex> // For thread safety

class Logger
{
private:
	Logger() = default; // Private constructor to prevent external instantiation
	~Logger() = default;
	Logger(const Logger &) = delete;			// Disallow copy constructor
	Logger &operator=(const Logger &) = delete; // Disallow copy assignment

	std::string log_message_;

public:
	static Logger &getInstance();
	void SetLogMessage(const std::string &message)
	{
		log_message_ = message;
	}

	// You can add other logging functionalities here

	void WriteLog();

	static std::mutex mutex_; // Mutex for thread safety
};

// Static member initialization (avoids global object problems)
std::mutex Logger::mutex_;
Logger &Logger::getInstance()
{
	static Logger instance; // Create the single instance on first call
	return instance;
}

void Logger::WriteLog()
{
	std::cout << log_message_ << std::endl;
	// You can implement more sophisticated logging mechanisms here (e.g., writing to files)
}

int main()
{
	Logger &logger = Logger::getInstance();
	logger.SetLogMessage("This is a log message.");
	logger.WriteLog(); // Output: This is a log message.

	// Since getInstance() returns the same reference, any subsequent calls will modify the same logger object
	logger.SetLogMessage("Another log message.");
	logger.WriteLog(); // Output: Another log message.

	return 0;
}
