#include <stdio.h>
#include "c_file_parser.h"
#include "ewp_file_parser.h"
#include "project_parser.h"
#include "delete_reoccur.h"

int user_filenames_get( char *src_file, char *sfile, char *dir );

int main()
{
    char p_src_file[64]     = { 0 };
    char p_dst_file[16]     = { "temp1.txt" };
    char new_file[16]       = { "temp2.txt" };
    char syntax_file[64]    = { 0 };
    char my_dir[128]        = { 0 };

    user_filenames_get( p_src_file, syntax_file, my_dir );

    /* Parses the .ewp file provided, and places all files that end in ".c" and started with "$PROJ_DIR$" into temp1. */
    printf("\r\nParsing %s...", p_src_file);
    if( parse_ewp_file( p_src_file, p_dst_file ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");

    /* temp1 is populated w/ all files that end in ".c" and started with "$PROJ_DIR$" */
    printf("\r\nStarting parse of project filenames...\r\n");
    if( parse_proj_files( p_dst_file, new_file, my_dir ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");

    /* temp2 is populated w/ all .c files from project, now parse them */
    printf("\r\nStarting parse of all .c project files...\r\n");
    if( project_parser( new_file, syntax_file ) )
        printf("\r\nParsing Successful\r\n");
    else
        printf("\r\nParsing Failed\r\n");

    /* Delete re-occurrences. */
    printf("\r\nDeleting Re-occurrences in syntax file.\r\n");
    if( delete_reoccur( syntax_file ) )
        printf("\r\nDeleting Re-occurrences Successful!\r\n");
    else
        printf("\r\nDeleting Re-occurrences Failed.\r\n");
}

int user_filenames_get( char *src_file, char *sfile, char *dir )
{
    printf("Please enter your .ewp filename: ");
    scanf("%s", src_file);

    printf("Please enter your syntax filename: ");
    scanf("%s", sfile);

    printf("Please enter your project directory: ");
    scanf("%s", dir);

    if( src_file == NULL || sfile == NULL || dir == NULL )
        return 0;
    else
        return -1;
}
