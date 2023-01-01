#pragma once
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

class Logger
{
	std::fstream log_file;
	Logger()
	{
		log_file = std::fstream("log.txt", std::ios::in | std::ios::out);
		if (!log_file)
			// Для создания файла используем параметр ios::trunc
			log_file = std::fstream("log.txt", std::ios::in | std::ios::out | std::ios::trunc);

		fs::permissions("log.txt", fs::perms::group_read | fs::perms::group_write | fs::perms::others_read | fs::perms::others_write, fs::perm_options::remove);
	}
	~Logger()
	{
		log_file.clear();
		log_file.seekg(0, std::ios_base::end);
		log_file.seekp(0, std::ios_base::end);
		log_file.close();
	}
	Logger(Logger const&) = delete;
	Logger& operator=(Logger const&) = delete;
public:
	static Logger& instance()
	{
		static Logger logger;
		return logger;
	}
	std::fstream& getLog_file()
	{
		return log_file;
	}
};

