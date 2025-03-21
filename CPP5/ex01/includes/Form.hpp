#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"
# define LOG 1

class Bureaucrat;

class Form {

    private:
        const std::string name;
        bool is_signed;
        const int grade_sign_need;
        const int grade_execute_need;

    public:
        Form(void);
        Form(const std::string name, const int grade_sign_need, const int grade_execute_need);
        ~Form(void);
        Form &operator=(const Form &src);
        Form(const Form &cpy);

        void beSigned(Bureaucrat &bureaucrat);
        std::string const getName(void) const;
        int getGradeSignNeed(void) const;
        int getGradeExecuteNeed(void) const;
        bool isSigned(void) const;

        class GradeTooHighException : public std::exception {
        
            public:
                virtual const char *what() const throw() {
                    return("\e[31mException\e[0m : The grade is too high"); 
                }
        };
        class GradeTooLowException : public std::exception {
            
            public:
                virtual const char *what() const throw() {
                    return("\e[31mException\e[0m : The grade is too low"); 
                }
        };
};

std::ostream	&operator<<(std::ostream &o, Form const &form);

#endif