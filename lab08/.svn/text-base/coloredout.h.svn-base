#ifndef COLOREDOUT_H
#define COLOREDOUT_H

#include <sys/wait.h>

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

class colored_out
{
	protected:
	int fds[2];
	static const int READ_END  = 0;
	static const int WRITE_END = 1;
	std::string expected;
	bool sendnullchar;

	public:
	colored_out()
		: sendnullchar(false) { }

	~colored_out()
	{
		if (sendnullchar)
		{
			std::cout << '\0';
			std::cout.flush();
			fflush(stdout);
			close(fds[WRITE_END]);
			int st;
			wait(&st);
		}
	}

	int set_expected_file(const std::string & str)
	{
		std::ifstream file;
		file.open(str.c_str());
		std::stringstream ss;
		if (file.good())
			while (file.good())
			{
				char c;
				file.get(c);
				ss << c;
//				if (!file.good()) break;
			}

		file.close();
		expected = ss.str();
		return 0;
	}
	int set_expected(const std::string & str)
	{
		expected = str;
		return 0;
	}

	protected:
	void output_red(char c)
	{
		std::cout << "\033[31m" << c << "\033[0m";
	}

	void output_green(char c)
	{
		std::cout << "\033[32m" << c << "\033[0m";
	}

	void output_notfound(char c)
	{
		std::cout << "\033[31;4m" << c << "\033[0m";
	}

	public:
	int start();
};

ssize_t readn(int fd, void *vptr, size_t n);

#endif
