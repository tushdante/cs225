#include <errno.h>
#include <unistd.h>
#include <stdint.h>

#include "coloredout.h"

using namespace std;

int colored_out::start()
{
	if (isatty(STDOUT_FILENO) == 0)
		return 0;

	pipe(fds);

	pid_t pid = fork();

	if (pid != 0)
	{
		sendnullchar = true;
		::close(STDOUT_FILENO);
		dup2(fds[WRITE_END], STDOUT_FILENO);
		return 0;
	}
	else
	{

//		cout << "***********************************" << endl;
//		cout << expected << endl;
//		cout << "***********************************" << endl;

		size_t i = 0;
		int error = 1;
		char c = '\0';
		char e = '\0';

		do
		{

			error = readn(fds[READ_END], &c, sizeof c);
			if (error <= 0) break;
			if (c == '\0') break;
			e = expected[i++];

			while ((c == '\n' || c == '=') && e != c && i < expected.size())
			{
				if (e == '\n')
					cout << e;
				else
					output_notfound(e);

				e = expected[i++];
			}
			while ((e == '\n' || e == '=') && c != e && c != '\0')
			{
				output_red(c);
				error = readn(fds[READ_END], &c, sizeof c);
				if (error <= 0) break;
			}
			if (c == '\0') break;

			if (isdigit(e) || e == '/' || e == '\\' || e == ' ')
			{
				if (c == e)
					output_green(c);
				else
					output_red(c);
			}
			else
			{
				if (c == e)
					cout << c;
				else
					output_red(c);
			}
		}
		while (c != '\0' && error > 0 && i < expected.size());

		while (c != '\0' && error > 0)
		{
			output_red(c);
			error = readn(fds[READ_END], &c, sizeof c);
			if (error <= 0) break;
		}

		while (i < expected.size())
		{
			e = expected[i++];
			
			if (e == '\n')
				cout << e;
			else
				output_notfound(e);
		}
		
		close(fds[READ_END]);
		return -1;
	}
}


// From Steven's Unix Net Programming
// http://www.kohala.com/start/
/* Read "n" bytes from a descriptor. */
ssize_t readn(int fd, void *vptr, size_t n)
{
	size_t   nleft;
	ssize_t  nread;
	int8_t * ptr;

	ptr = static_cast<int8_t*>(vptr);
	nleft = n;
	while (nleft > 0) {
		if ( (nread = ::read(fd, ptr, nleft)) < 0) {
			if (errno == EINTR)
				nread = 0; /* and call read() again */
			else
				return -1;
		}
		else if (nread == 0)
			break; /* EOF */

		nleft -= nread;
		ptr   += nread;
	}
	
	return n - nleft; /* return >= 0 */
}

