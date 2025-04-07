#include "../includes/Form.hpp"

Form::Form(void) : name("default"), is_signed(false), grade_sign_need(1), grade_execute_need(1)
{
    if (LOG)
        std::cout << "\e[32mThe Form\e[0m default was created !" << std::endl;
}

Form::Form(const std::string name, const int grade_sign_need, const int grade_execute_need) :
name(name),
is_signed(false),
grade_sign_need(grade_sign_need),
grade_execute_need(grade_execute_need)
{
    if (LOG)
        std::cout << "\e[32mThe Form\e[0m " << this->name << " was created !" << std::endl;
    if (grade_sign_need < 1 || grade_execute_need < 1)
        throw Form::GradeTooHighException();
    else if (grade_sign_need > 150 || grade_execute_need > 150)
        throw Form::GradeTooLowException();
}

Form::~Form(void)
{
    if (LOG)
        std::cout << "\e[32mThe Form\e[0m " << this->name << " was destroyed !" << std::endl;
}

Form::Form(const Form &cpy) :
name(cpy.name),
is_signed(cpy.is_signed),
grade_sign_need(cpy.grade_execute_need),
grade_execute_need(cpy.grade_execute_need)
{
    if (LOG)
        std::cout << "\e[32mThe Form\e[0m " << this->name << " was copied !" << std::endl;
   *this = cpy;
}

Form	&Form::operator=(const Form &src)
{
    this->is_signed = src.isSigned();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe Form\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string const Form::getName(void) const
{
    return this->name;
}

int Form::getGradeSignNeed(void) const
{
    return this->grade_sign_need;
}

int Form::getGradeExecuteNeed(void) const
{
    return this->grade_execute_need;
}

bool Form::isSigned(void) const
{
    return this->is_signed;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= this->getGradeSignNeed() && this->is_signed == false)
        this->is_signed = true;
    else if (bureaucrat.getGrade() > this->getGradeSignNeed())
        throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &o, Form const &form)
{
    o
    << form.getName() << ", grade need to sign it : "
    << form.getGradeSignNeed() << ", grade need to execute it : "
    << form.getGradeSignNeed() << ", is signed : "<< form.isSigned()
    << std::endl;
    return o;
}

const char *Form::GradeTooHighException::what() const throw() { return("\e[31mException\e[0m : The grade is too high"); }
const char *Form::GradeTooLowException::what() const throw() { return("\e[31mException\e[0m : The grade is too low"); }