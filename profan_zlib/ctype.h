#ifndef CTYPE_H
#define CTYPE_H

#define isdigit(c) ((c) >= '0' && (c) <= '9')
#define isxdigit(c) (isdigit(c) || ((c) >= 'a' && (c) <= 'f') || ((c) >= 'A' && (c) <= 'F'))
#define isspace(c) ((c) == ' ' || (c) == '\t' || (c) == '\n')

char tolower(char c);
char toupper(char c);

#endif
