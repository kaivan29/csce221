// My_vec.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include "My_vec.h"

My_vec::My_vec()
{
	size = 0;
	capacity = 10;
	ptr = new char[capacity];
}

My_vec::~My_vec()
{
	delete ptr;
}

My_vec::My_vec(const My_vec& vec)
{
	size = vec.size;
	capacity = vec.capacity;
	ptr = new char[capacity];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = vec[i];
		
	}
}

//Not sure of this overloading operator 

//My_vec::My_vec& operator=(const My_vec& vec) ??

My_vec& My_vec::operator=(const My_vec& vec)  //We are passing the memory address which is a much better option than passing the whole object		
{ 
	//lhs=rhs and vec here is rhs
	if (this != &vec)       //check for self assignment
	{
		delete ptr;				//deallocate memory that might have some garbage
		ptr = new char[capacity];		//Allocate some memory now so that it can hold the contents of the rhs
		int s = vec.get_size();
		for (int i = 0; i < s; i++)
		{
			//if(&vec[i] != NULL)
				ptr[i] = vec[i];
		}
	//size = s;							
	//ptr = &vec;						//vec is const so just copy the elements instead of passing the reference 
	}
	return *this;
}

int My_vec::get_size()const{          //1. To get the size of the vector i.e. the number of elements in the vector
	return size;

}

int My_vec::get_capacity()const{      //2. To get the capacity of the vector i.e. the number of elements the vector can store at that instance
	return capacity;
}

char& My_vec::operator[](int i) const //When pointer is used to assign the variable a value i.e we cannot change the members of the vector
{
	return ptr[i];
}

char& My_vec::operator[](int i) //When we need to change the value of the pointer i.e it is used to change the members of the vector
{
	return ptr[i];
}

bool My_vec::is_empty() const{		  //3. to check whether the vector is empty
	if (size == 0)
		return true;					//note: Use this function to improve your code. IMPORTANT
}

char& My_vec::elem_at_rank(int r) const{    //4
	return ptr[r];
}
	
void My_vec::insert_at_rank(int r, const char& elem)    //5
{
	if(r > size)
		throw exception();
	else if (size == capacity)
	{
		capacity = capacity * 2;
		char* newptr = new char[capacity];
		for (int i = 0; i < size; i++)
		{
			newptr[i] = ptr[i];
		}
		delete ptr;
	 	for (int i = size; i > r-1 ; i--) //make a function shifting that shifts the elements and call the function multiple times whenever you want
		{
			newptr[i] = newptr[i-1];
		}
		newptr[r] = elem;
		size++;//increase the size as an element is inserted
	}
	else{
			for (int i = size; i > r - 1; i--) //make a function shifting that shifts the elements and call the function multiple times whenever you want
			{
				ptr[i] = ptr[i - 1];
			}
			ptr[r] = elem;
			size++;
	    }
}

void My_vec::replace_at_rank(int r, const char& elem)  //6
{
	if(r > size-1)
		throw exception();
	else
		ptr[r] = elem;
}

void My_vec::remove_at_rank(int r)   //7
{
	if(r > size-1)
		throw exception();
	else{
		for (int i = r; i < size; i++)
		{
			ptr[i] = ptr[i + 1];
		}
		size = size - 1;
	}
}

ostream& operator<<(ostream& out, const My_vec& vec) //cout
{
	for (int i = 0; i < vec.get_size(); i++) //This would print out the whole vec when mention the name of the object in cout in main
	{
		out<<vec[i];
	}
	return out;
}


int find_max_index(const My_vec& v, int size) //8 How did this work out?
{
	int temp = v[0];
	int pos = 0;
	for( int i = 1; i < size; i++)
	{
		if(v[i] > temp)   //Comparing a charachter to an int. No compile error and gives correct output
		{
			temp = v[i];
			pos = i;
		}
	}
	return pos;
}

void sort_max(My_vec& vec) //9
{
	int size = vec.get_size();
	char temp;
	for(int i = 0; i<size;)
	{
		int max_index = find_max_index(vec,size);
		temp = vec[size-1];
		vec[size-1] = vec[max_index];
		vec[max_index] = temp;
		--size;
	}
}
/*
	for(int i = 0; i < size; i++)
	{
		for( int j = 1; j < size -i; i++)
		{
			
				
			}
			
		}
	}
	for( int i = 0; i < size; i++)
	{
		cout<<vec[i]<<endl;
	}
	*/
