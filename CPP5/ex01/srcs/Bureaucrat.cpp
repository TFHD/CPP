#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("default"), grade(1)
{
    if (LOG)
        std::cout << "\e[36mThe Bureaucrat\e[0m default was created !" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (LOG)
        std::cout << "\e[36mThe Bureaucrat\e[0m " << this->name << " was created !" << std::endl;
    if (grade < 1) { this->grade = 1; throw Bureaucrat::GradeTooHighException(); }
    else if (grade > 150) { this->grade = 1; throw Bureaucrat::GradeTooLowException(); }
    else { this->grade = grade; }
}

Bureaucrat::~Bureaucrat(void)
{
    if (LOG)
        std::cout << "\e[36mThe Bureaucrat\e[0m " << this->name << " was destroyed !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : name(cpy.name), grade(cpy.grade)
{
    if (LOG)
        std::cout << "\e[32mThe Bureaucrat\e[0m " << this->name << " was copied !" << std::endl;
   *this = cpy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &src)
{
    this->grade = src.getGrade();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Bureaucrat\e[0m Assignation operator called" << std::endl; }
	return *this;
}

const std::string Bureaucrat::getName(void) const
{
    return this->name;
}

int Bureaucrat::getGrade(void) const
{
    return this->grade;
}

void Bureaucrat::incrementGrade(void)
{
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    else
        this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
    std::string return_error = "";

    if (form.isSigned())
        return_error = "the form is already signed !";

    try { form.beSigned(*this); }

    catch (Form::GradeTooLowException &e)
    {
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because the grade is too low !" << std::endl;
        throw Form::GradeTooLowException();
    }

    if (!return_error.empty())
        std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " <<return_error << std::endl;
    else
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return o;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return("\e[31mException\e[0m : The grade is too high"); }
const char *Bureaucrat::GradeTooLowException::what() const throw() { return("\e[31mException\e[0m : The grade is too low"); }