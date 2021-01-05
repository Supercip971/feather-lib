#ifndef FERROR_H
#define FERROR_H
#include <stdio.h>
namespace fth {
    #define FEATHER_SUCCESS 0
    class ferror{
    public:
        ferror(const char* error_string, int error_code, int line = __LINE__, const char* file = __FILE__){
            error_str = error_string;
            code = error_code;
            err_line = line;
            err_file = file;
            has_file_info = true;
        }
        void log_error() const{
            if(has_file_info){
                fprintf(stderr, "[ ERROR ] (feather) error in file %s line %i : %i : %s \n", err_file, err_line, code, error_str);

            }else{
                fprintf(stderr, "[ ERROR ] (feather) error %i : %s \n", code, error_str);

            }
        }
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
        ferror is_error;
        possible_result& if_result;
        bool is_an_error = false;
    public:
        result_or_error(ferror error) : if_result(){
            is_an_error = true;
            is_error = error;
        }
        result_or_error(possible_result& result) : if_result(result){
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
    };
}

#endif // FERROR_H
