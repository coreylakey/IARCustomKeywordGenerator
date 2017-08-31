#include <stdio.h>

#define MAX_BUFF 256

static int clear_buffer( char *buffer );

int parse_c_file( char *src_file, char *dst_file )
{
    FILE *fptr_src;
    FILE *fptr_dst;
    char src_str[MAX_BUFF] = { 0 };
    char read_char;
    int index = 0;

    fptr_src = fopen(src_file, "r");
    fptr_dst = fopen(dst_file, "a");

    if(fptr_src == NULL || fptr_dst == NULL)
        return 0;

    while( 1 )  //Goes until read_char finds EOF
    {
        read_char = fgetc( fptr_src );
        if( read_char == EOF )
        {
            fclose( fptr_src );
            fclose( fptr_dst );
            return -1;
        }
        if( read_char == ' ' || read_char == '\n' || read_char == '\r' )
        {
            index = 0;
            clear_buffer( src_str );
        }
        if( read_char == '(' )
        {
            if( index > 4 )
            {
                src_str[index] = 0;
                if( src_str[0] != '\n' && src_str[0] != ' ' )
                {
                    fputs( src_str, fptr_dst );
                    fputc( '\n', fptr_dst );
                }
                else
                {
                    fputs( &src_str[1], fptr_dst );
                    fputc( '\n', fptr_dst );
                }
            }
                index = 0;
                clear_buffer( src_str );
        }
        else
        {
            if( read_char != '*' && read_char != '-' )
                src_str[index++] = read_char;
            else
            {
                clear_buffer( src_str );
                index = 0;
            }
        }
    }

    fclose( fptr_src );
    fclose( fptr_dst );
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
