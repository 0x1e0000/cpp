#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const string name, int grade) : _name(name)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

Bureaucrat::Bureaucrat(int grade) : _name("(Bureaucrat Default Name)")
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

Bureaucrat::Bureaucrat() : _name("(Bureaucrat Default Name)"), _grade(150)
{
    // Default values
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
{
    *this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    this->_grade = rhs._grade;
    return *this;
}

const string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::setGrade(int grade)
{
    try
    {
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade = grade;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Bureaucrat::incrementGrade()
{
    try
    {
        if (this->_grade == 1)
            throw Bureaucrat::GradeTooHighException();
        this->_grade--;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try
    {
        if (this->_grade == 150)
            throw Bureaucrat::GradeTooLowException();
        this->_grade++;
    }
    catch (std::exception &e)
    {
        cerr << e.what() << endl;
    }
}

void Bureaucrat::signForm(Form &form)
{
    if (form.getIsSigned())
        cout << this->_name << " signed " << form.getName() << endl;
    else
        cout << this->_name << " couldn’t sign " << form.getName() << " because the bureaucrat has low grade." << endl;
}

void Bureaucrat::executeForm(Form const &form)
{

    if (form.execute(*this))
    {
        form.action(*this);
        cout << this->_name << " executed " << form.getName() << endl;
    }
    else
        cout << this->_name << " failed to execute " << form.getName() << endl;
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &obj)
{
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << endl;
    return o;
}