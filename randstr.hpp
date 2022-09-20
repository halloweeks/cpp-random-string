#ifndef RANDOM_STRING_H
#define RANDOM_STRING_H 1

#include <string.h>
#include <unistd.h>
#include <time.h>

std::string randstr(unsigned int len = 10, bool uppercase_letters = true, bool lowercase_letters = true, bool numbers = true) {
  srand((unsigned)time(NULL) * getpid());
  /*
	static const char alphanum[] =
	    "0123456789"
	    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	    "abcdefghijklmnopqrstuvwxyz";
	*/
	char alphanum[63];
	
	if (uppercase_letters) {
	  strcpy(alphanum, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
	}
	if (lowercase_letters) {
	  strcat(alphanum, "abcdefghijklmnopqrstuvwxyz");
	}
	
	if (numbers) {
	  strcat(alphanum, "0123456789");
	}
	
	std::string tmp_s;
	tmp_s.reserve(len);
	
	for (unsigned int i = 0; i < len; ++i) {
	  tmp_s += alphanum[rand() % (strlen(alphanum))];
	}
	return tmp_s;
}

#endif