#include "../includes/AForm.hpp"

AForm::AForm(void) : name("default"), is_signed(false), grade_sign_need(1), grade_execute_need(1)
{
    if (LOG)
        std::cout << "\e[32mThe AForm\e[0m default was created !" << std::endl;
}

AForm::AForm(const std::string name, const int grade_sign_need, const int grade_execute_need) :
name(name),
is_signed(false),
grade_sign_need(grade_sign_need),
grade_execute_need(grade_execute_need)
{
    if (LOG)
        std::cout << "\e[32mThe AForm\e[0m " << this->name << " was created !" << std::endl;
    if (grade_sign_need < 1 || grade_execute_need < 1)
        throw AForm::GradeTooHighException();
    else if (grade_sign_need > 150 || grade_execute_need > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm(void)
{
    if (LOG)
        std::cout << "\e[32mThe AForm\e[0m " << this->name << " was destroyed !" << std::endl;
}

AForm::AForm(const AForm &cpy) :
name(cpy.name),
is_signed(cpy.is_signed),
grade_sign_need(cpy.grade_execute_need),
grade_execute_need(cpy.grade_execute_need)
{
    if (LOG)
        std::cout << "\e[32mThe AForm\e[0m " << this->name << " was copied !" << std::endl;
   *this = cpy;
}

AForm	&AForm::operator=(const AForm &src)
{
    this->is_signed = src.isSigned();
    if (this == &src)
        return *this;
    if (LOG) { std::cout << "\e[32mThe AForm\e[0m Assignation operator called" << std::endl; }
	return *this;
}

std::string const AForm::getName(void) const
{
    return this->name;
}

int AForm::getGradeSignNeed(void) const
{
    return this->grade_sign_need;
}

int AForm::getGradeExecuteNeed(void) const
{
    return this->grade_execute_need;
}

bool AForm::isSigned(void) const
{
    return this->is_signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > 0 && bureaucrat.getGrade() <= this->getGradeSignNeed() && this->is_signed == false)
        this->is_signed = true;
    else if (bureaucrat.getGrade() > this->getGradeSignNeed())
        throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
    if (!this->isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getGradeExecuteNeed())
        throw AForm::GradeTooLowException();
    executeAction();
}

std::ostream	&operator<<(std::ostream &o, AForm const &AForm)
{
    o
    << AForm.getName() << ", grade need to sign it : "
    << AForm.getGradeSignNeed() << ", grade need to execute it : "
    << AForm.getGradeExecuteNeed() << ", is signed : "<< AForm.isSigned()
    << std::endl;
    return o;
}

const char *AForm::GradeTooHighException::what() const throw() { return("\e[31mException\e[0m : The grade is too high"); }
const char *AForm::GradeTooLowException::what() const throw() { return("\e[31mException\e[0m : The grade is too low"); }
const char *AForm::FormNotSignedException::what() const throw() { return("\e[31mException\e[0m : The form is not signed !"); }