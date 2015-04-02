#include <iostream>
#ifndef RECORD_H_
#define RECORD_H_

using namespace std;

//Hold the record of the students
class Record
{
	private:
	string last_name, first_name; //make functions that return this private members so that they can be used outside the class.
	string UIN, ph_no;
	public:
	Record() //Default constructor
	{
		last_name=" ", first_name =" ";
	    UIN = " ", ph_no=" ";
	}		
	Record(string l_name, string f_name, string uin, string ph) //Parametrized constructor
	{
		last_name = l_name, first_name = f_name;
	    UIN = uin, ph_no=ph;
	}		
	
	//less-than operator
	//Big O(1)
	bool operator<(const Record& r)
	{
		int l = this->last_name.compare(r.last_name); //we compare the last names
		if(l<0)
			return false;
		else if(l>0)
			return true;
		
		//when l=0 that is the last name of a and b is equal, it compares the first name
		int f = this->first_name.compare(r.first_name); //to compare the first names
		if(f<0)
			return false;
		else if(f>0)
			return true;
		
		//when f=0 that is the first name of a and b is equal, it compares the UIN
		int g = this->UIN.compare(r.UIN);//to compare the UIN
		if(g<0)
			return false;
		else
			return true;
	}
	
	string get_last_name()const{return last_name;} //returns the last name
	string get_first_name()const{return first_name;} //returns the first name
	string get_UIN()const{ return UIN;} //returns the UIN
	string get_ph_no()const{return ph_no;} //returns the phone number
};

ostream& operator<<(ostream& out, const Record& rec) //prints the record to the screen
{
	out<<"Last name - First Name: " <<rec.get_last_name()<<"-"<<rec.get_first_name()<<"\nUIN:"<<rec.get_UIN()<<"\nph_no:"<<rec.get_ph_no();
	out<<"\n\n";
	return out;
}
#endif