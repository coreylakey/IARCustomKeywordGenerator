#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BUFF 256

static int clear_buffer( char *buffer );
static int search_for_text( FILE *fptr, char *txt, int size );  //returns 0 if no match round, otherwise return is the index in file ( SEEK_SET + index )

int delete_reoccur( char *s_file )
{
    FILE *fptr_sfile;
    FILE *fptr_temp;
    char temp_file[16] = { "temp3.txt" };
    char read_char;
    int index = 0;
    char txt_buffer[MAX_BUFF] = { 0 };
    int found;

    fptr_sfile = fopen( s_file, "r" );
    fptr_temp = fopen( temp_file, "a+" );

    if( fptr_sfile == NULL || fptr_temp == NULL )
        return 0;

    while( !feof( fptr_sfile ) )
    {
        if( !feof( fptr_sfile ) )
            read_char = fgetc( fptr_sfile );
        else
        {
            fclose( fptr_sfile );
            fclose( fptr_temp );
            return -1;
        }

        if( read_char == '\r' || read_char == '\n' )
        {
            txt_buffer[index] = 0;

            found = search_for_text( fptr_temp, txt_buffer, index );
            if( !found )
            {
                fputs( txt_buffer, fptr_temp );
                fputc( '\n', fptr_temp );
            }
            index = 0;
            clear_buffer( txt_buffer );
        }
        else if( read_char == EOF )
        {
            fclose( fptr_sfile );
            fclose( fptr_temp );
            return -1;
        }
        else
        {
            txt_buffer[index++] = read_char;
        }
    }

    fclose( fptr_sfile );
    fclose( fptr_temp );
    return -1;
}

static int clear_buffer( char *buffer )
{
    int i = 0;

    for( i = 0; i < MAX_BUFF; i++ )
        buffer[i] = 0;

    return -1;
}

static int search_for_text( FILE *fptr, char *txt, int size )
{
    char buff[256] = { 0 };

    if( size < 1 )
        return 0;

    fseek( fptr, 0, SEEK_SET );  //reset to beginning of file.

    while( !feof( fptr ) )
    {
        if( fgets( buff, ( size + 1 ), fptr ) != NULL )
        {
            if( strcmp( buff, txt ) == 0 )
                return -1; //found a match
            clear_buffer( buff );
        }
        else
        {
            return 0;
        }
    }
    return 0;
}
