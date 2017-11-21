/******************************************************************************

 *  (C) COPYRIGHT Cambridge Consultants 2016 <<TODO>>

 *

 *  Project Reference <<TODO>>

 *

 *  FILE

 *      $HeadURL: $

 *      $Revision: $

 *      $Author: $

 *      $Date: $

 *

 *  DESCRIPTION

 *      logfind excercise from learn C the hard way. Specialised version of
 *      grep. Takes string search arguments and searches files within ~/.logfind
 *      and returns files that match arguments. Default if there are multiple
 *      words is to and search for them. Optional -o flag to be passed if or
 *      search is desired.

 *

 *  REFERENCES

 *      <<TODO>> Requirements Specification

 *      <<TODO>> Software Specification

 ******************************************************************************/



/*============================================================================*

    System-wide Header Files

 *============================================================================*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <glob.h>
#include <stdarg.h>



/*============================================================================*

    Interface Header Files

 *============================================================================*/

/* None */



/*============================================================================*

    Local Header Files

 *============================================================================*/

/* None */



/*============================================================================*

    Public Data

 *============================================================================*/

/* None */



/*============================================================================*

    Private Defines

 *============================================================================*/

#define _GNU_SOURCE


/*============================================================================*

    Private Data Types

 *============================================================================*/

/* None */



/*============================================================================*

    Private Function Prototypes

 *============================================================================*/

char * read_file(char *);

char **match_lines(char *, int, char *[], int*);

int num_lines(char *);

/*============================================================================*

    Private Data

 *============================================================================*/



/*============================================================================*

    Public Function Implementations

 *============================================================================*/


/*============================================================================*

    Private Function Implementations

 *============================================================================*/

char *read_file(char *path) {
    char * buffer = NULL;
    long length;
    FILE * f = fopen(path, "r");
    if (f)
    {
      fseek (f, 0, SEEK_END);
      length = ftell (f);
      fseek (f, 0, SEEK_SET);
      buffer = malloc (length);
      if (buffer)
      {
        fread (buffer, 1, length, f);
        return buffer;
      }
      fclose (f);
    }

    return buffer;
}

void get_files(int n_search_args, char* search_for[])
{
    glob_t globbuf;
    glob("~/.logfind/*", GLOB_TILDE, NULL, &globbuf);

    unsigned int i;

    for(i = 0; i < globbuf.gl_pathc; ++i) {
        char * file_contents = read_file(globbuf.gl_pathv[i]);
        int n_lines = num_lines(file_contents);
        char **matched_lines = match_lines(file_contents, n_search_args, search_for, &n_lines);
        for(int i = 0; i < n_lines; ++i) {
            printf("MATCH FOUND\n");
            printf("%s: *(matched_lines + %d): %s\n", globbuf.gl_pathv[i],i, *(matched_lines + i));
        }
    }

    if(globbuf.gl_pathc > 0 ) {
        globfree(&globbuf);
    }
    return;
}

int num_lines(char *file_contents) {
    char *save_file_contents = malloc(strlen(file_contents));
    strcpy(save_file_contents, file_contents);
    char *line = strtok(save_file_contents, "\n");

    int n_lines = 0;
    while(line != NULL) {
        line = strtok(NULL, "\n");
        ++n_lines;
    }
    free(save_file_contents);
    return n_lines;
}

char **match_lines(char *file_contents, int n_search_args, char *search_for[], int *n_lines) {
    char *copy_in = malloc(strlen(file_contents));
    strcpy(copy_in, file_contents);
    char *line;
    char *brkt;
    char **saved_lines = malloc(sizeof(char*)*(*n_lines));
    int n_matches = 0;

    for(line = strtok_r(copy_in , "\n", &brkt); line; line = strtok_r(NULL, "\n", &brkt)) {

        char *copy_line = malloc(strlen(line));
        strcpy(copy_line, line);
        char *brkt2;
        char *word;
        for(word = strtok_r(copy_line, " ", &brkt2); word; word = strtok_r(NULL, " ", &brkt2)) {
            for(int i = 1; i < n_search_args; ++i) {
                int ret = strcmp(search_for[i], word);
                if(ret == 0) {
                    *(saved_lines + (n_matches)) = line;
                    n_matches++;
                }
            }
        }
    }

    *n_lines = n_matches;
    return saved_lines;
}

int main(int argc, char* argv[]) {


    printf("argc = %d\n", argc);
    get_files(argc,argv);
    return 0;
}



/*============================================================================*

    End Of File

 *============================================================================*/


