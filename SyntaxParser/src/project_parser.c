#include <stdio.h>
#include "c_file_parser.h"

#define MAX_BUFF 256

static int clear_buffer( char *buffer );

int project_parser( char *nfile, char *dst_file )
{
    FILE *fptr_nfile;
    char dst_str[MAX_BUFF] = { 0 };
    char read_char;
    int index = 0;

    fptr_nfile = fopen(nfile, "r");

    if( fptr_nfile == NULL )
        return 0;

    while( !feof( fptr_nfile ) )  //Goes until finds EOF
    {
        if( !feof( fptr_nfile ))
            read_char = fgetc( fptr_nfile );
        else
        {
            fclose( fptr_nfile );
            return -1;
        }

        if( read_char != '\n' && read_char != '\r' )
        {
            dst_str[index++] = read_char;
        }
        else
        {
            dst_str[index] = 0;
            printf("\r\nParsing %s ...", dst_str );
            if( parse_c_file( dst_str, dst_file ) )
                printf(" Complete!");
            else
                printf(" Failed.");
            index = 0;
            clear_buffer( dst_str );

        }

    }

    fclose( fptr_nfile );
    printf("\r\nFiles closed\r\n");

    return -1;

}

static int clear_buffer( char *buffer )
{
    int i = 0;

    for( i = 0; i < MAX_BUFF; i++ )
        buffer[i] = 0;

    return -1;
}

