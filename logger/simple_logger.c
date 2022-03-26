#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile FILE* fp = NULL;

void int_handler(int val)
{
    (void)val;

    if (fp)
    {
        fflush(fp);
        fclose(fp);
    }

    exit(0);
}

int main(int argc, char** argv)
{
    // Set up interrupt signal control
    struct sigaction act = { 0 };
    
    act.sa_handler = int_handler;
    sigaction(SIGINT, &act, NULL);

    // Make sure a file was specified
    if (argc < 2)
    {
        fprintf(stderr, "No file specified.\n");
        exit(1);
    }

    // Open File (if possible)
    if (!(fp = fopen(argv[1], "a")))
    {
        fprintf(stderr, "Unable to open file \"%s\".\n", argv[1]);
        exit(1);
    }

    // Do the thing
    while (1)
    {
        char c = getchar();
        
        if (!fprintf(fp, "%c", c))
        {
            fprintf(stderr, "Unable to write to file \"%s\".\n", argv[1]);
            fclose(fp);
            exit(1);
        }

        if (c == '\n' || c == '\r') fflush(fp);
    }

    return 0;
}
