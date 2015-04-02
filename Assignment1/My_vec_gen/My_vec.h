#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
class My_vec {

	//member variables
	int size, capacity;	//size and capacity of the vector of type My_vec
	T *ptr;				//ptr is a pointer of datatype T i.e Template

public:
	//member functions
	My_vec()			//Default Constructor
	{
		size = 0;
		capacity = 10;
		ptr = new T[capacity];
	}
	
	~My_vec()			//Destructor
	{
		delete ptr;
	}
	
	My_vec(const My_vec<T>& vec) //what is this? It is a copy constructor
	{
		size = vec.size;
		capacity = vec.capacity;
		ptr = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = vec[i];
			
		}
	}
	
//Not sure of this overloading operator 

//My_vec::My_vec& operator=(const My_vec& vec) ??
	
	My_vec& operator=(const My_vec<T>& vec) //We are passing the memory address which is a much better option than passing the whole object		
{ 	//Assignment operator
	//lhs=rhs and vec here is rhs
	if (this != &vec)       //check for self assignment
	{
		delete ptr;				//deallocate memory that might have some garbage
		ptr = new T[capacity];		//Allocate some memory now so that it can hold the contents of the rhs
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
	
	int get_size() const{          //1. To get the size of the vector i.e. the number of elements in the vector
	return size;

}
	int get_capacity() const{      //2. To get the capacity of the vector i.e. the number of elements the vector can store at that instance
	return capacity;
}

	T& operator[](int i) const//When we pass a pointer's value to a variable i.e we cannot change the members of the vector
{
	return ptr[i];
}

	T& operator[](int i) //When we need to assign a value to the pointer i.e it is used to change the members of the vector
{
	return ptr[i];
}

	bool is_empty() const{		  //3. to check whether the vector is empty
	if (size == 0)
		return true;					//note: Use this function to improve your code.
}

	T& elem_at_rank(int r) const{    //4
	return ptr[r];
}

void insert_at_rank(int r, const T& elem)
	{	
		if(r>size)					//To check if the rank is greater than the size
		{
			if ( r>= capacity)		//To check if the rank is greater than capacity in that case we would need to increase the capacity of the vector.
			{
				capacity = r + 10; //instead of doubling the capacity which might fall short of the rank entered, I am increasing the capacity = r +10.
				T* newptr = new T[capacity]; //Assigning the new capacity to the newptr
				for (int i = 0; i < size; i++) //Copying the values of the ptr to newptr that has a bigger capacity
				{
					newptr[i] = ptr[i];
				}
				delete[] ptr;	//deallocating the memory to avoid memory leak. In C++ we need to deallocate physically.
				ptr=newptr;		//Copying back the elements of newptr to ptr. Capacity of ptr has increased now.
			}
			ptr[r] = elem;		//Inserting the element at the desired position
			size=r+1;			//increase the size of the element till the rank you insert
		}
		else if(r>=0&&r<=size)		//If we want to insert in between the elements
		{
			//This works here!!
			if(size == capacity)	//If the size is equal to capacity we are going to need to increase the capacity of the vector
			{
				capacity = capacity * 2;	//Increasing the capacity twice
				T* newptr = new T[capacity]; //Assigning the new capacity to the newptr
				for (int i = 0; i < size; i++) //Copying the values of the ptr to newptr that has a bigger capacity
				{
					newptr[i] = ptr[i];
				}
				delete[] ptr;//deallocating the memory to avoid memory leak. In C++ we need to deallocate physically.
				ptr=newptr;		//Copying back the elements of newptr to ptr. Capacity of ptr has increased now.
				for (int i = size; i > r; i--) //make a function shifting that shifts the elements and call the function multiple times whenever you want
				{
					ptr[i] = ptr[i - 1];
				}
				ptr[r] = elem;		//Inserting the element at the desired position
				size++;
			}
			else			//If the size is not equal to  capacity, just insert the element without increasing the capacity
			{
				for (int i = size; i > r; i--) //make a function shifting that shifts the elements and call the function multiple times whenever you want
				{
					ptr[i] = ptr[i - 1];
				}
				ptr[r] = elem;		//Inserting the element at the desired position
				size++;
			}
		}
	else
	throw exception();
	}

 	void replace_at_rank(int r, const T& elem) //6. To replace an element in the vector at a particular position with another element
	{
		if(r>size)		//If The rank given is greater than size then we need to replace the null/void value with the element passed
		{ 
			if ( r>= capacity)		//If the rank is greater than the capacity we need to increase the capacity of the ptr
			{
				capacity = capacity * 2;//Increasing the capacity twice
				T* newptr = new T[capacity]; //Assigning the new capacity to the newptr
				for (int i = 0; i < size; i++) //Copying the values of the ptr to newptr that has a bigger capacity
				{
					newptr[i] = ptr[i];
				}
				delete[] ptr;//deallocating the memory to avoid memory leak. In C++ we need to deallocate physically.
				ptr=newptr;		//Copying back the elements of newptr to ptr. Capacity of ptr has increased now.
			}
			ptr[r] = elem;	//Inserting the element at the desired position
			size=r+1;//increase the size of the element till the rank you insert
		}
		else
		ptr[r] = elem;		//Inserting the element at the desired position
	}

	void remove_at_rank(int r)  
	{
	if(r >=size)		//We cannot remove something that does not exist
		cout<<"\nThere is no element at this position \n";
	else{
			for (int i = r; i < size; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			size = size - 1;
		}
	}
};


template <class T>
ostream& operator<<(ostream& out, const My_vec<T>& vec) //cout
{
	for (int i = 0; i < vec.get_size(); i++) //This would print out the whole vec when mention the name of the object in cout in main
	{
		out<<vec[i]<<", ";
	}
	return out;
}

template <class T>
int find_max_index(const My_vec<T>& v, int size) //8 Finding the index of the highest value in the array
{
	int temp = v[0];
	int pos = 0;
	for( int i = 1; i < size; i++)
	{
		if(v[i] > temp)   //Comparing a charachter to an int. No compile error and gives correct output
		{
			temp = v[i];	//Storing the value of the maximum value
			pos = i;		//Storing the index of the maximum value
		}
	}
	return pos;
}

template <class T>
void sort_max(My_vec<T>& vec) //9
{
	int size = vec.get_size();
	T temp;
	for(int i = 0; i<size;) //To sort the elements of the vector
	{
		int max_index = find_max_index(vec,size);	//Finding max_index of the vector then swapping it with the value at the last position in the vector
		//Swapping
		temp = vec[size-1];
		vec[size-1] = vec[max_index];
		vec[max_index] = temp;
		--size; //The maximum value is locked in its position and the iteration runs from 0 to n-2 and so on
	}
}

