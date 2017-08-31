#include <stdio.h>
#include <string.h>

#define MAX_BUFF 256

static int clear_buffer( char *buffer );

int parse_ewp_file( char *src_file, char *dst_file )
{
    FILE *fptr_src;
    FILE *fptr_dst;
    char src_str[MAX_BUFF] = { 0 };
    char read_char;
    int index = 0;

    fptr_src = fopen(src_file, "r");
    fptr_dst = fopen(dst_file, "w");

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

        if( read_char == '$' )
        {
            src_str[index++] = read_char;
            while( read_char != '<' )
            {
                read_char = fgetc( fptr_src );
                if( read_char == EOF )
                {
                    fclose( fptr_src );
                    fclose( fptr_dst );
                    return -1;
                }
                src_str[index++] = read_char;
            }
            src_str[index - 1] = 0;
            if( src_str[index - 2] == 'c' && src_str[index - 3] == '.' )
            {
                fputs( src_str, fptr_dst );
                fputc( '\n', fptr_dst );
            }
            index = 0;
            clear_buffer( src_str );
        }
    }

    fclose( fptr_src );
    fclose( fptr_dst );
    printf("\r\nFiles closed\r\n");

    return -1;


}

int parse_proj_files( char *dst_file, char *nf_file, char *my_dir )
{
    FILE *fptr_dst;
    FILE *fptr_nf;
    char dst_str[MAX_BUFF] = { 0 };
    char new_file_str[MAX_BUFF] = { 0 };
    char macro_proj_dir[MAX_BUFF] = { "$PROJ_DIR$" };
    char read_char;
    int index = 0;
    int nf_index = 0;

    fptr_dst = fopen(dst_file, "r");
    fptr_nf = fopen( nf_file, "w" );

    if( fptr_dst == NULL || fptr_nf == NULL )
        return 0;

    while( !feof( fptr_dst ) )  //Goes until read_char finds EOF
    {
        if( !feof( fptr_dst ))
        read_char = fgetc( fptr_dst );
        else
        {
            fclose( fptr_dst );
            fclose( fptr_nf );
            return -1;
        }

        if( read_char == '$' )
        {
            dst_str[index++] = read_char;

            if( !feof( fptr_dst ))
            read_char = fgetc( fptr_dst );
            else
            {
                fclose( fptr_dst );
                fclose( fptr_nf );
                return -1;
            }

            dst_str[index++] = read_char;
            while( read_char != '$' )
            {
                if( !feof( fptr_dst ))
                read_char = fgetc( fptr_dst );
                else
                {
                    fclose( fptr_dst );
                    fclose( fptr_nf );
                    return -1;
                }
                dst_str[index++] = read_char;
            }
            dst_str[index] = 0;
            if( strcmp( dst_str, macro_proj_dir ) == 0 )
            {
                while( new_file_str[nf_index] != 'c' && new_file_str[nf_index - 1] != '.' )
                {
                    if( !feof( fptr_dst ))
                    read_char = fgetc( fptr_dst );
                    else
                    {
                        fclose( fptr_dst );
                        fclose( fptr_nf );
                        return -1;
                    }
                    new_file_str[nf_index++] = read_char;
                }
                if( !feof( fptr_dst ))          /* After getting a ".c" read on more character ( the c ). */
                read_char = fgetc( fptr_dst );
                else
                {
                    fclose( fptr_dst );
                    fclose( fptr_nf );
                    return -1;
                }
                new_file_str[nf_index++] = read_char;
                new_file_str[nf_index] = 0;
                fputs( my_dir ,fptr_nf );
                fputs( new_file_str, fptr_nf );
                fputc( '\n', fptr_nf );
                nf_index = 0;
                clear_buffer( new_file_str );
            }
            index = 0;
            clear_buffer( dst_str );
        }
    }

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
