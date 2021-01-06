#ifndef FERROR_H
#define FERROR_H
#include <stdio.h>
namespace fth {
    // not fully implemented so some code is in the header for the moment but will be moved in the c++ file ;) 
    #define FEATHER_SUCCESS 0

    #define feather_error(error_str, error_code) fth::ferror(error_str,error_code, __LINE__,__FILE__)
    class ferror{
    public:
        ferror(const char* error_string, int error_code, int line, const char* file);
        ferror() = default;
        void log_error() const;

        operator bool() const {
            return code == FEATHER_SUCCESS;
        }

        int get_code() const {
            return code;
        }

        const char* get_info() const {
            return error_str;
        }


    private:

        bool has_file_info = false;
        const char* error_str = "no error";
        int code = FEATHER_SUCCESS;
        int err_line = 0;
        const char* err_file;
    };


    template<typename possible_result>
    class result_or_error{
    public:
        result_or_error(ferror error) : is_error(error){
            is_an_error = true;
        }
        result_or_error(possible_result result) : if_result(result){
            is_an_error = false;
        }
        possible_result get(){
            if(is_an_error){
                is_error.log_error();
                return possible_result(); // i'm obligated to return something

            }else{
                return if_result;
            }
        }

    private:

        ferror is_error;
        possible_result if_result;
        bool is_an_error = false;
    };
}

#endif // FERROR_H
