#include "ferror.h"
namespace fth
{

    ferror::ferror(const char *error_string, int error_code, int line, const char *file)
    {
        error_str = error_string;
        code = error_code;
        err_line = line;
        err_file = file;
        has_file_info = true;
    }

    void ferror::log_error() const
    {
        if (has_file_info)
        {
            fprintf(stderr, "[ ERROR ] (feather) error (#%i) in file %s line %i : %s \n", code, err_file, err_line, error_str);
        }
        else
        {
            fprintf(stderr, "[ ERROR ] (feather) error (#%i) : %s \n", code, error_str);
        }
    }

    void ferror::log_if_error() const
    {
        if (code != FEATHER_SUCCESS)
        {
            log_error();
        }
    }

} // namespace fth
