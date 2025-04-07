#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
#include "Bureaucrat.hpp"
# define LOG 0

class Bureaucrat;

class AForm {

    private:
        const std::string name;
        bool is_signed;
        const int grade_sign_need;
        const int grade_execute_need;

    public:
        AForm(void);
        AForm(const std::string name, const int grade_sign_need, const int grade_execute_need);
        virtual ~AForm(void);
        AForm &operator=(const AForm &src);
        AForm(const AForm &cpy);

        void beSigned(Bureaucrat &bureaucrat);
        std::string const getName(void) const;
        int getGradeSignNeed(void) const;
        int getGradeExecuteNeed(void) const;
        bool isSigned(void) const;
        void execute(Bureaucrat const & executor) const;
        virtual void executeAction(void) const = 0;

        class GradeTooHighException : public std::exception {
        
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };
        class FormNotSignedException : public std::exception {
            
            public:
                virtual const char *what() const throw();
        };
};

std::ostream	&operator<<(std::ostream &o, AForm const &AForm);

#endif