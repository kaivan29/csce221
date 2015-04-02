#include <iostream>
#include <stdexcept>
#include "My_vec.h"

	int main()
		try{
			My_vec v;    // define an object v of My_vec type
			v.insert_at_rank(0,'B');// insert 'B' at the rank 0 into the vector v
			cout<<"\nThe element(s) v after inserting B: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			v.insert_at_rank(0,'A');// insert 'A' at the rank 0 into the vector v
			cout<<"\nThe element(s) v after inserting A: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

/*			v.insert_at_rank(10,'D');// insert 'D' at the rank 10 into the vector v
			cout<<"\n"<<v<<"\n";// use the overloaded operator << to display vector elements
			cout<<v.get_size()<<"\n";// display the vector v size
*/
			//v = 'b';
			v.remove_at_rank(1);// remove a character at the rank 2 from the vector v , but i replaced it at rank 1
			cout<<"\nThe element(s) v after removing: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			v.replace_at_rank(0,'E');// replace a character at the rank 2 by the character 'E' 
			cout<<"\nThe element(s) v after replacing: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			My_vec v1 = v;// create a copy v1 of the vector v using a copy constructor
			cout<<"\nThe element(s) of v1 after copying from v: "<<v1;// use the overloaded operator << to display the vector v1
			cout<<"\nThe size of the vector v1: "<<v1.get_size()<<"\n";
			v1.replace_at_rank(0,'Y');// replace a character at the rank 2 of the vector v1 with the character 'Y'
			cout<<"\nThe element(s) of v1 after the replace: "<<v1<<"\n";// use the overloaded operator << to display vector v1 elements

			My_vec v2;// define an object v2 of My_vec type
			v2.insert_at_rank(0,'K');// insert 'K' at the rank 0 into the vector v2
			cout<<"\nThe element(s) v2 after inserting K: "<<v2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v2.get_size()<<"\n";// display the vector v size

			v2=v1;// test the assignment operator and copy the vector v1 to v2 
			cout<<"\nThe element(s) v2 after copying from v1: "<<v2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v2: "<<v2.get_size()<<"\n";// display the vector v size
			
			/*char a[9]={'E','F','G','H','I','A','B','C','D'}; 
			int s = 9;
			for(int i = 0; i < s; i++)
			{						//Also why I cannot do v2=&a[0];
				v2[i]=a[i];        //When I do this it does transfer the elements but it forgets to increase the size. Why?
				cout<<v2[i];
			}*/

			//For that reason trying insert. Because we need some elements to find max index and sort_max
			v2.insert_at_rank(0,'B');
			v2.insert_at_rank(0,'G');
			v2.insert_at_rank(0,'K');
			v2.insert_at_rank(0,'Z');
			v2.insert_at_rank(0,'L');
			cout<<"\nThe element(s) v after inserting elements: "<<v2;
			cout<<"\nThe size of the vector v2 : "<<v2.get_size()<<"\n";
			
			int max = find_max_index(v2,6);// test the function find_max_index using v2
			cout<<"\nThe max index of v2 is : "<<max<<"\n";
			cout<<"The element at the max index of v2 is : "<<v2[max]<<"\n";

			sort_max(v2);// test the function sort_max using v2
			cout<<"\nThe sorted max for v2 is: "<<v2<<"\n";
			
			// replace in the vector v2 a character at the rank 14 with 'S'

		}

		catch (exception &error){
			cerr << "Error: " << error.what() << endl;
		}
