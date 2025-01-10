#include "iostream"
using std::string; 

class AbstractEmployee {// This class serves as the contract (of promotion) (if the staff wants a promotion, these the steps the boss has to take) between the employer and the employee
	//has one rule which is that which ever class decides to use (sign) this contract, they(the class) must provide the implementation called "AskForPromotion" 
	 
	//Abstraction as a pillar  or concept of OOP making something complex to look simple - like the tech behind the smartphone camera is complex but to the user it is easy - just a click of the button.
//but what if another phone manufacturing company wants that complex side, we use Abstraction(Abstract classes)
//or the example we use above, of the complex steps it takes a boss to decide if a staff deserves a promotion when he/she asks the boss

	virtual void AskForPromotion() = 0; //We would make this obligatory i.e. any class they uses this class AbstractEmployee, must sign the method; AskForPromotion();  
	// how to make this obligatory is by making it a "pure virtual function" which is the Virtual... =0;
};

class Employee:AbstractEmployee // a class(room)
{
private:
	string Company;
	int Age;
protected: 
	string Name;

public: // is accessible outside this class and they are called access modifiers.
	//Public Private and Protected.
	//this Name Company and Age are the members(body) of this class and they are the attributes and behaviors of this class

	//Encapsulation as a pillar  or concept of OOP
	//i.e hiding properties private inside a class. The idea of this encapsulation is to hide the propertoes of the class and make anyone who wants to have access to it, to getters and setters
	//creation of getters and setters for the properties - Name

	void setName(string name) {//setter

		Name = name;
	}
	string getName() {//getter
		return Name;
	}

	void setCompany(string company) {//setter

		Company = company;
	}
	string getCompany() {//getter
			return Company;
	}

	void setAge(int age) {//setter
		// adding a check, a validation rule of "if"
		if(age>=18)
			Age = age;
	}
	int getAge() {//getter
			return Age;
	}

	void IntroduceYourself() // this is a class method that shows the behavior
	// and void here is the return type of this IntroduceYourself() method so the void is basically your return thats why a constructor doesnt have a void cause it has no return
	//we used IntroduceYourself(class method) here because if we wanted to introduce the "employee1" 5 times we would have had to do {std::cout "Name - " << Name << std::endl;} 5 times but insteead we would just call (employee1.IntroduceYourself();) 5 times.
	
	{
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	Employee(string name, string company, int age)
		// a constructor is a method but it doesnt have a return type
	// design rules for constructor method
	//1. no return type i.e. void at all
	//2. it has the same name as the class it belongs to meaning the name of our constructor here is Employee
	//3. it had to be public - at this level at least.
		
	//This is the constructor of this class (Employee)  and the name, company and age are called argument lists.
	//and its job is to construct the object of the class Employee
	{
		Name = name;
		Company = company;
		Age = age;
	} 
	void AskForPromotion() {
		//The contract states that if you want to get a promotion, you need to:
		if (Age > 30)
			std::cout << Name << " got promoted!" << std::endl; 
		else
			std::cout << Name << " sorry No promotion for you!" << std::endl;
	}

	//virtual void with the "virtual" is a virtual  function and when its invoked, it would check if there is an implementation of the function whcich in this case is "Work" in the derived classes and if Yes, execute that instead. 
	//basically saying that in the child/derived class Developer, if we didnt have the function(Work), the (Work) function of the Parentclass Employee, is the one to be implemented. 
	//Meaning if you were to comment out the Work function in Developer, the Work function in Employee is what would be used.
	virtual void Work() {
		std::cout << Name << " is checking email, task backlog, performing tasks..." << std::endl;
	}

};

//Inheritance as a concept or pillar of OOP
//Parent class(Car) - 
// and child class - as properties and methods - electric car with a method called charge and a property called BatteryStatus
// and child class - as properties and methods - internal combustion engine car with a method called Tank and a property called FuelStatus
class Developer : public Employee {
public: 
	string FavProgrammingLanguage;
	//We need a constructor  for the child class: Developer
	Developer(string name, string company, int age, string favProgrammingLanguage)
		:Employee(name, company, age)
	{
		FavProgrammingLanguage = favProgrammingLanguage;
	}
	//we are going to impliment a method called "FixBug"
	void FixBug() {

		std::cout << Name << " fixed bug using " << FavProgrammingLanguage << std::endl;
	} 
	void Work() {
		std::cout << Name << " is writing " << FavProgrammingLanguage << " code" << std::endl;
	}

};

class Teacher :public Employee {
public:
	string Subject;
	Teacher(string name, string company, int age, string subject)
		:Employee(name, company, age)
	
	{
		Subject = subject;
	}

	void PrepareLesson() {
		std::cout << Name << " is preparing " << Subject << "lesson " << std::endl; 
	}
	void Work() {
		std::cout << Name << " is teaching " << Subject << std::endl;
	}

};
int main() //The most common use of polymorphism is when a
           //parent class reference is used to refer to a child class object.
{
	Employee employee1 = Employee("Adewale", "Deskstones LTD", 33); //This line shows that we have successfully constructed our employee1 object.
	
	Employee employee2 = Employee("Fuad", "TechBros", 24);
	
	//creation of class d:Developer

	Developer d = Developer("Adewale", "Deskstones LTD", 33, "c++");

	Teacher t = Teacher ("Jack", "CoolSchool", 35, "History");
	
	//Creation of a based class pointer e1 of type Employee to the derived class teacher, d.
	Employee* e 1 = &d;
	Employee* e2 = &t;

	e1->Work();
	e2->Work();

}
//polymorphism as a concept or pillar of OOP
//in latin - many forms   
//in programming, it means the ability of an object or method to have many forms.

