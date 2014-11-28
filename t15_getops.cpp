#include <iostream>
#include <string>
#include <unistd.h>

int main(int argc, char **argv)
{
    int verbose_level = 0;
    std::string output_file_name = "out.pgm";
    std::string input_file_name;
    int rc;

    while ((rc = getopt (argc, argv, "o:v:")) != -1)
        switch (rc)
        {
            case 'o':
                output_file_name = optarg;
                break;
            case 'v':
                verbose_level = std::stoi(optarg);
                if (verbose_level > 3)
                    verbose_level = 3;
                else if (verbose_level < 0)
                    verbose_level = 0;
                break;
            case '?':
                if (optopt == 'o')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                if (optopt == 'v')
                    fprintf (stderr, "Option -%c requires an argument.\n", optopt);
                return 1;
            default:
                abort ();
        }
    if (optind == argc)
    {
        fprintf(stderr, "*.pgm input file name required.\n");
        return 1;
    }

    input_file_name = argv [argc - 1];

    printf("-o: %s, -v: %d, -i: %s\n", output_file_name.c_str(), verbose_level, input_file_name.c_str());


    return 0;
}
