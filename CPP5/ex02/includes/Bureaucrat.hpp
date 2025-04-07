#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "AForm.hpp"
# define LOG 0

class AForm;

class Bureaucrat {

    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat(void);
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat(void);
        Bureaucrat &operator=(const Bureaucrat &src);
        Bureaucrat(const Bureaucrat &cpy);

        std::string const getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const & form);

    class GradeTooHighException : public std::exception {
        
        public:
            virtual const char *what() const throw();
    };
    class GradeTooLowException : public std::exception {
        
        public:
            virtual const char *what() const throw();
    };
};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat);

#endif