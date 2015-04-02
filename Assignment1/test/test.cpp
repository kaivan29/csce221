#include <iostream>
#include <stdexcept>
#include "My_vecgen.h"

int main()
{
	My_vec<char>v;
	v.insert_at_rank(0,'A');
	v.insert_at_rank(10,'C');
	cout<<"\nThe element(s) v after inserting D: "<<v<<"\n";
	v.insert_at_rank(10,'D');// insert 'D' at the rank 10 into the vector v
	cout<<"\nThe element(s) v after inserting D: "<<v<<"\n";
	v.replace_at_rank(10,'E');
	cout<<"\nThe element(s) v after inserting D: "<<v<<"\n";
	v.remove_at_rank(12);
	cout<<"\nThe element(s) v after inserting D: "<<v<<"\n";// use the overloaded operator << to display vector elements
	cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size
}