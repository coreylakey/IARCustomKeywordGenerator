#include <stdio.h>
#include "c_file_parser.h"
#include "ewp_file_parser.h"

int user_filenames_get( char *src_file, char *dst_file, char *nfile, char *sfile, char *dir );

int main()
{
    char p_src_file[128] = { 0 };
    char p_dst_file[128] = { 0 };
    char new_file[128] = { 0 };
    char syntax_file[128] = { 0 };
    char my_dir[128] = { 0 };

    user_filenames_get( p_src_file, p_dst_file, new_file, syntax_file, my_dir );

    printf("\r\nParsing %s...", p_src_file);
    if( parse_ewp_file( p_src_file, p_dst_file ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");
    printf("\r\nStarting parse of project filenames...\r\n");
    if( parse_proj_files( p_dst_file, new_file, my_dir ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");
    /* At this point, new_file has list of all .c files in your project. Now we must parse each file individually. */
    printf("\r\nStarting parse of all .c project files...\r\n");
    if( project_parser( new_file, syntax_file ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");

}

int user_filenames_get( char *src_file, char *dst_file, char *nfile, char *sfile, char *dir )
{
    printf("Please enter your source filename: ");
    scanf("%s", src_file);

    printf("Please enter your destination filename: ");
    scanf("%s", dst_file);

    printf("Please enter your filenames file filename: ");
    scanf("%s", nfile);

    printf("Please enter your syntax filename: ");
    scanf("%s", sfile);

    printf("Please enter your project directory: ");
    scanf("%s", dir);

    if( src_file == NULL || dst_file == NULL || nfile == NULL || sfile == NULL || dir == NULL )
        return 0;
    else
        return -1;
}
