#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main(void)
{
    /* TEST BUREAUCRATS WITH A GOOD GRADE */
    std::cout << std::endl << std::endl << "TEST BUREAUCRATS WITH A GOOD GRADE" << std::endl << std::endl;

    ShrubberyCreationForm form("Aubin");
    Bureaucrat bureaucrat1("bureaucrat", 10);
    Bureaucrat bureaucrat2;
    bureaucrat1.signForm(form);
    //bureaucrat1.signForm(form);
    bureaucrat1.executeForm(form);

    bureaucrat2 = bureaucrat1;
    std::cout << bureaucrat2 << std::endl;

    return (0);
}

int main2(void)
{
    RobotomyRequestForm  a("caca");

    RobotomyRequestForm b;

    b = a;

    std::cout << a << a.getTarget() << "\n";
    std::cout << b << b.getTarget() << "\n";
    return 0;
}