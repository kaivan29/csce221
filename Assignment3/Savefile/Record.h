#include <iostream>
#ifndef RECORD_H_
#define RECORD_H_

using namespace std;

class Record
{
	private:
	string last_name, first_name; //make functions that return this private memebbers so that they can be used outside the class.
	string UIN, ph_no;
	public:
	Record()
	{
		last_name=" ", first_name =" ";
	    UIN = " ", ph_no=" ";
	}		
	Record(string l_name, string f_name, string uin, string ph)
	{
		last_name = l_name, first_name = f_name;
	    UIN = uin, ph_no=ph;
	}		
	
	
	bool operator<(const Record& r)
	{
		int l = this->last_name.compare(r.last_name);
		if(l<0)
			return false;
		else if(l>0)
			return true;
		
		//when l=0 that is the last name of a and b is equal, it compares the first name
		int f = this->first_name.compare(r.first_name);
		if(f<0)
			return false;
		else if(f>0)
			return true;
		
		int g = this->UIN.compare(r.UIN);
		if(g<0)
			return false;
		else
			return true;
	}
	
	string get_last_name()const{return last_name;}
	string get_first_name()const{return first_name;}
	string get_UIN()const{ return UIN;}
	string get_ph_no()const{return ph_no;}
};

ostream& operator<<(ostream& out, const Record& rec){
	out<<"Last name - First Name: " <<rec.get_last_name()<<"-"<<rec.get_first_name()<<"\nUIN:"<<rec.get_UIN()<<"\nph_no:"<<rec.get_ph_no();
	out<<"\n\n";
	return out;
	}
/*ostream& operator<<(ostream& out, const Record& rec){
	out<<"Last name - First Name: " <<rec.last_name<<"-"<<rec.first_name<<"\nUIN:"<<rec.UIN<<"\nph_no:"<<rec.ph_no;
	return out;
	}
	*/
#endif