#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>

using namespace  std;

class Employee{
  private:
    string firstName;
    string lastName;
    string Id;
  public:
    Employee(string &, string &,string &);
    void setFirstName(string &);
    string getFirstName();
    void setLastName(string &);
    string getLastName();
    void setId(string &);
    string getId();

    virtual double earnings()=0;
    virtual void print();

};

Employee::Employee(string &first,string &last,string &idValue):
firstName(first),lastName(last),Id(idValue)
{}

void Employee::setFirstName(string &first){
  firstName = first;
}

string Employee::getFirstName(){
  return firstName;
}

void Employee::setLastName(string &last){
  lastName = last;
}

string Employee::getLastName(){
  return lastName;
}

void Employee::setId(string &idValue){
  Id = idValue;
}

string Employee::getId(){
  return Id;
}

void Employee::print(){
  cout<<"Employee Information:"<<endl;
  cout<<" "<<getFirstName()<<endl<<" "<<getLastName()<<endl
      <<" "<<getId()<<endl;
}

class SalariedEmployee: public Employee{
  private:
    double monthlySalary;
  public:
    SalariedEmployee(string="",string="",string="", double=0.0);
    void setMonthlySalary(double salaryValue){
      monthlySalary = salaryValue<0.0?0.0:salaryValue;
    }
    double getMonthlySalary(){
      return monthlySalary;
    }

    virtual double earnings();
    virtual void print();
};

SalariedEmployee::SalariedEmployee(string first,string last,string idValue,double salary):Employee(first,last,idValue){
  setMonthlySalary(salary);
}

double SalariedEmployee::earnings(){
  return getMonthlySalary();
}

void SalariedEmployee::print(){
  cout<<"Salaried Employee:"<<endl;
  Employee::print();
}

class HourlyEmployee: public Employee{
  private:
    double wage;
    double hours;
  public:
    HourlyEmployee(string="",string="",string="",double=0.0,double=0.0);
    void setWage(double wageValue){
      wage=wageValue<0.0?0.0:wageValue;
    }
    void setHours(double hoursValue){
      hours = hoursValue<0.0?0.0:hoursValue;
    }
    double getWage(){
      return wage;
    }
    double getHours(){
      return hours;
    }
    virtual double earnings();
    virtual void print();
};

HourlyEmployee::HourlyEmployee(string first,string last,string idValue,double hourlyWage,double hoursWorked):Employee(first,last,idValue){
  setWage(hourlyWage);
  setHours(hoursWorked);
}

double HourlyEmployee::earnings(){
  if(hours<=40)
  {
    return wage*hours;
  }else{
    return 40*wage + (hours-40)*wage*1.5;
  }
}

void HourlyEmployee::print(){
  cout<<"Hourly Employee:"<<endl;
  Employee::print();
}

class SalariedAndHourlyEmployee: public Employee{
  private:
    double baseSalary;
    double hours;
  public:
    SalariedAndHourlyEmployee(string="",string="",string="",double=0.0,double=0.0);
    void setBaseSalary(double baseSalaryValue){
      baseSalary=baseSalaryValue<0.0?0.0:baseSalaryValue;
    }
    void setHours(double hoursValue){
      hours = hoursValue<0.0?0.0:hoursValue;
    }
    double getBaseSalary(){
      return baseSalary;
    }
    double getHours(){
      return hours;
    }
    virtual double earnings();
    virtual void print();
};

SalariedAndHourlyEmployee::SalariedAndHourlyEmployee(string first,string last,string idValue,double hourlyWage,double hoursWorked):Employee(first,last,idValue){
  setBaseSalary(baseSalary);
  setHours(hoursWorked);
}

double SalariedAndHourlyEmployee::earnings(){
  if(hours<=120)
  {
    return baseSalary+hours;
  }else{
    return baseSalary + hours*40;
  }
}

void SalariedAndHourlyEmployee::print(){
  cout<<"Salaried And Hourly Employee:"<<endl;
  Employee::print();
}




class ComissionEmployee:public Employee{
  private:
    double grossSales;
    double comissionRate;

  public:
   ComissionEmployee(string="",string="",string="",double=0.0,double=0.0);
   void setCommissionRate(double);
   double getCommissionRate();
   void setGrossSales(double);
   double getGrossSales();

   virtual double earnings();
   virtual void print();
};

ComissionEmployee::ComissionEmployee(string first,string last,string idValue,double grossMonthlySales,double percent):Employee(first,last,idValue){
  setCommissionRate(percent);
  setGrossSales(grossMonthlySales);
}

void ComissionEmployee::setCommissionRate(double percent){
  comissionRate=percent;
}

void ComissionEmployee::setGrossSales(double grossMonthlySales){
  grossSales = grossMonthlySales;
}

double ComissionEmployee::getCommissionRate(){
  return comissionRate;
}

double ComissionEmployee::getGrossSales(){
  return grossSales;
}

double ComissionEmployee::earnings(){
  return getCommissionRate()*getGrossSales();
}

void ComissionEmployee::print(){
  cout<<"Comission Employee:"<<endl;
  Employee::print();
}


class BasePlusComissionEmployee:public Employee{
  private:
    double grossBasePlusSales;
    double BasePluscomissionRate;

  public:
   BasePlusComissionEmployee(string= "",string="",string="",double=0.0,double=0.0);
   void setBasePlusCommissionRate(double);
   double getBasePlusCommissionRate();
   void setBasePlusGrossSales(double);
   double getBasePlusGrossSales();

   virtual double earnings();
   virtual void print();
};

BasePlusComissionEmployee::BasePlusComissionEmployee(string first,string last,string idValue,double grossMonthlySales,double percent):Employee(first,last,idValue){
  setBasePlusCommissionRate(percent);
  setBasePlusGrossSales(grossMonthlySales);
}

void BasePlusComissionEmployee::setBasePlusCommissionRate(double percent){
  BasePluscomissionRate=percent;
}

void BasePlusComissionEmployee::setBasePlusGrossSales(double grossMonthlySales){
    grossBasePlusSales = grossMonthlySales;
}

double BasePlusComissionEmployee::getBasePlusCommissionRate(){
  return BasePluscomissionRate;
}

double BasePlusComissionEmployee::getBasePlusGrossSales(){
  return grossBasePlusSales;
}

double BasePlusComissionEmployee::earnings(){
  return getBasePlusCommissionRate()+getBasePlusGrossSales();
}

void BasePlusComissionEmployee::print(){
  cout<<"Base Plus Comission Employee:"<<endl;
  Employee::print();
}


class SalariedComissionAndBonusEmployee: public Employee{
  private:
    double baseSalary;
    double hours;
  public:
    SalariedComissionAndBonusEmployee(string="",string="",string="",double=0.0,double=0.0,double= 0.0);
    void setBaseSalary(double baseSalaryValue){
      baseSalary=baseSalaryValue<0.0?0.0:baseSalaryValue;
    }
    void setHours(double hoursValue){
      hours = hoursValue<0.0?0.0:hoursValue;
    }
    double getBaseSalary(){
      return baseSalary;
    }
    double getHours(){
      return hours;
    }
    virtual double earnings();
    virtual void print();
};

SalariedComissionAndBonusEmployee::SalariedComissionAndBonusEmployee(string first,string last,string idValue,double hourlyWage,double hoursWorked, double percentage):Employee(first,last,idValue){
  setBaseSalary(baseSalary);
  setHours(hoursWorked);
}

double SalariedComissionAndBonusEmployee::earnings(){
  if(hours<=120)
  {
    return baseSalary+hours;
  }else{
    return baseSalary + hours*40;
  }
}

void SalariedComissionAndBonusEmployee::print(){
  cout<<"Salaried, comission And bonus Employee:"<<endl;
  Employee::print();
}





int main() {


Employee *emp;
  cout<<endl;

  char selection;
  cout<<endl<<"Payroll System";
  cout<<endl<<"________________";
  cout<<endl<< "A - Salaried Employee";
  cout<<endl<< "B - Hourly Employee";
  cout<<endl<< "C - Hourly and Salaried Employee";
  cout<<endl<< "D - Commission Employee";
  cout<<endl<< "E - Base Plus Comission Employee";
  cout<<endl<< "F - Salaried, comission and bounus Employee";
  cout<<endl<< "X - Exit";
  cout<<endl<<"Enter selection:";
  cin>>selection;
  switch(selection){
    case 'A':
    case 'a':
      emp = new SalariedEmployee("First name of the salaried employee is: Mizanur","Last name of the salaried employee is: Rahman","Id of the salaried employee is: 1001",8000.00);
      emp->print();
      cout<<"Earning of the monthly fixed salary employee is: "<<emp->earnings()<<endl<<endl;
    break;
    case 'B':
    case 'b':
      emp = new HourlyEmployee("First name of the hourly employee is: Towhidul","Last name of the hourly employee is: Islam","Id of the hourly employee is: 1002",160.75,90);

      emp->print();
      cout<<"Earning of the hourly based employee is: "<<emp->earnings()<<endl<<endl;
    break;
    case 'C':
    case 'c':
      emp = new SalariedAndHourlyEmployee("First name of the salaried and hourly employee is: Mohammad","Last name of the salaried and hourly employee is: Hridoy","Id of the hourly employee is: 1003",165.130,300);
      emp->print();
    cout<<"Earning of the salaried and hourly based employee is: "<<emp->earnings()<<endl<<endl;
    break;
    case 'D':
    case 'd':
      emp = new ComissionEmployee("First name of the comission based employee is: Jamal","Last name of the comission based employee is: Hossain","Id of the comission based employee is: 1004",18000,0.08);
      emp->print();
      cout<<"Earning of the commission based employee is: "<<emp->earnings()<<endl<<endl;
    break;
    case 'E':
    case 'e':
      emp= new BasePlusComissionEmployee("First name of the base plus commission based employee is: Sohana","Last name of the base plus commission based employee is: Akter","Id of the base plus comission based employee is: 1005",3000.0, 6000.0);
      emp->print();
      cout<<"Earning of the base plus comission based employee is :"<<emp->earnings()<<endl<<endl;
    break;
    case 'F':
    case 'f':
    emp=new SalariedComissionAndBonusEmployee("First name of the salaried, comission and bounus based employee is: Arafat","Last name of the salaried, comission and bonus based employee is: Khan","Id of the hourly employee is: 1006",170.125,250);
    emp->print();
    cout<<"Earning of the salaried, comission and bounus based employee is: "<<emp->earnings()<<endl<<endl;

    case 'X':
    case 'x':
     cout<<endl<<"To exit the menu";
    break;
    default: cout<<endl<<"Invalid selection";
}
}
