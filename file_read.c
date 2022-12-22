/********************************************************************************
file_read: Vardera rad ur angiven fil l�ses in och skrivs ut till valfri utst�m.
           Filens inneh�ll skrivs ut i terminalen.
********************************************************************************/
#include "header.h"

int file_read(const char* filepath)
{
    FILE* istream = fopen(filepath, "r");

    if (!istream) 
    {
        fprintf(stderr, "Could not open file at path %s!\n\n", filepath);
        return 1;
    }
    else
    {
        char s[100] = { '\0' };

        while (fgets(s, sizeof(s), istream)) 
        {
            fprintf(stdout, "%s", s);
        }

        fclose(istream); 
        return 0;
    }
}