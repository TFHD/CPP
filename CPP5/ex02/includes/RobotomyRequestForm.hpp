#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm {

    private:
        std::string target;

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        virtual ~RobotomyRequestForm(void);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        RobotomyRequestForm(const RobotomyRequestForm &cpy);

        std::string getTarget(void) const;
        void executeAction(void) const;
};

#endif