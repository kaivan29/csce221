#include <iostream>
#include <stdexcept>
#include "My_vec.h"

	int main()
		try{
		//Charachter 
			cout<<"Char datatype\n \n \n \n \n";
			My_vec<char>v;    // define an object v of My_vec type
			v.insert_at_rank(0,'B');// insert 'B' at the rank 0 into the vector v
			cout<<"\nThe element(s) in v after insert are: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			v.insert_at_rank(0,'A');// insert 'A' at the rank 0 into the vector v
			cout<<"\nThe element(s) in v after insert are: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			v.insert_at_rank(10,'D');// insert 'D' at the rank 10 into the vector v
			cout<<"\nThe element(s) in v after insert are: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			//v = 'b';
			v.remove_at_rank(2);// remove a character at the rank 2 from the vector v , but i replaced it at rank 1
			cout<<"\nThe element(s) in v after remove are: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			v.replace_at_rank(2,'E');// replace a character at the rank 2 by the character 'E' 
			cout<<"\nThe element(s) in v after replace are: "<<v;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v: "<<v.get_size()<<"\n";// display the vector v size

			My_vec<char> v1 = v;// create a copy v1 of the vector v using a copy constructor
			cout<<"\nThe element(s) of v1 after copy from v are: "<<v1;// use the overloaded operator << to display the vector v1
			cout<<"\nThe size of the vector v1: "<<v1.get_size()<<"\n";
			v1.replace_at_rank(0,'Y');// replace a character at the rank 2 of the vector v1 with the character 'Y'
			cout<<"\nThe element(s) of v1 after replace are: "<<v1<<"\n";// use the overloaded operator << to display vector v1 elements

			My_vec<char> v2;// define an object v2 of My_vec type
			v2.insert_at_rank(0,'K');// insert 'K' at the rank 0 into the vector v2
			cout<<"\nThe element(s) v2 after insert are: "<<v2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v2: "<<v2.get_size()<<"\n";// display the vector v size

			v2=v1;// test the assignment operator and copy the vector v1 to v2 
			cout<<"\nThe element(s) v2 after copy from v1 are: "<<v2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v2: "<<v2.get_size()<<"\n";// display the vector v size

			//Inserting few elements becasue we need some to find the max_index and to sort_max later on. Because we need some elements to find max index and sort_max
			v2.insert_at_rank(0,'B');
			v2.insert_at_rank(0,'G');
			v2.insert_at_rank(0,'K');
			v2.insert_at_rank(0,'Z');
			v2.insert_at_rank(0,'L');
			cout<<"\nThe element(s) v after inserting elements: "<<v2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v2 : "<<v2.get_size()<<"\n";// display the vector v size
			
			int max = find_max_index(v2,v2.get_size());// test the function find_max_index using v2
			cout<<"\nThe max index of v2 is : "<<max<<"\n";// use the overloaded operator << to display vector elements
			cout<<"The element at the max index of v2 is : "<<v2[max]<<"\n";// display the vector v size

			sort_max(v2);// test the function sort_max using v2
			cout<<"\nThe sorted max for v2 is: "<<v2<<"\n";
			
			v2.replace_at_rank(14,'S');// replace in the vector v2 a character at the rank 14 with 'S'
			cout<<"The elements of the vector v2 are: "<<v2<<"\n";
			cout<<"The size of the vector v2: "<<v2.get_size()<<"\n";
			
		//***********************************************************************************************************************	
			cout<<"\n \n \n \n Int datatype\n \n \n \n \n";			
			//Integer
			My_vec<int>vi;    // define an object v of My_vec type
			vi.insert_at_rank(0,1);// insert 'B' at the rank 0 into the vector v
			cout<<"\nThe element(s) vi after insert are: "<<vi;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi: "<<vi.get_size()<<"\n";// display the vector v size

			vi.insert_at_rank(0,2);// insert 'A' at the rank 0 into the vector v
			cout<<"\nThe element(s) vi after insert are: "<<vi;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi: "<<vi.get_size()<<"\n";// display the vector v size

			vi.insert_at_rank(10,3);// insert 'D' at the rank 10 into the vector v
			cout<<"\nThe element(s) vi after insert are: "<<vi<<"\n";// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi: "<<vi.get_size()<<"\n";// display the vector v size


			vi.remove_at_rank(2);// remove a character at the rank 2 from the vector v , but i replaced it at rank 1
			cout<<"\nThe element(s) vi after remove are: "<<vi;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi: "<<vi.get_size()<<"\n";// display the vector v size

			vi.replace_at_rank(2,4);// replace a character at the rank 2 by the character 'E' 
			cout<<"\nThe element(s) vi after replace are: "<<vi;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi: "<<vi.get_size()<<"\n";// display the vector v size

			My_vec<int> vi1 = vi;// create a copy v1 of the vector v using a copy constructor
			cout<<"\nThe element(s) of vi1 after copy from v: "<<vi1;// use the overloaded operator << to display the vector v1
			cout<<"\nThe size of the vector vi1: "<<vi1.get_size()<<"\n";
			vi1.replace_at_rank(2,5);// replace a character at the rank 2 of the vector v1 with the character 'Y'
			cout<<"\nThe element(s) of v1 after the replace: "<<vi1<<"\n";// use the overloaded operator << to display vector v1 elements

			My_vec<int> vi2;// define an object v2 of My_vec type
			vi2.insert_at_rank(0,1);// insert 1 at the rank 0 into the vector v2
			cout<<"\nThe element(s) vi2 after insert are: "<<vi2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vi2: "<<vi2.get_size()<<"\n";// display the vector v size

			vi2=vi1;// test the assignment operator and copy the vector v1 to v2 
			cout<<"\nThe element(s) v2 after copy from v1: "<<vi2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector v2: "<<vi2.get_size()<<"\n";// display the vector v size

			//For that reason trying insert. Because we need some elements to find max index and sort_max
			vi2.insert_at_rank(0,8);
			vi2.insert_at_rank(0,4);
			vi2.insert_at_rank(0,9);
			vi2.insert_at_rank(0,7);
			vi2.insert_at_rank(0,6);
			cout<<"\nThe element(s) v after insert are: "<<vi2;
			cout<<"\nThe size of the vector v2 : "<<vi2.get_size()<<"\n";
			
			int maxi = find_max_index(vi2,vi2.get_size());// test the function find_max_index using v2
			cout<<"\nThe max index of vi2 is : "<<maxi<<"\n";
			cout<<"The element at the max index of v2 is : "<<vi2[maxi]<<"\n";

			sort_max(vi2);// test the function sort_max using v2
			cout<<"\nThe sorted max for v2 is: "<<vi2<<"\n";
			
			vi2.replace_at_rank(14,10);// replace in the vector v2 a character at the rank 14 with 10
			cout<<"The elements of the vector v2 after replace are: "<<vi2<<"\n";
			cout<<"The size of the vector v2: "<<vi2.get_size()<<"\n";
			
		//***********************************************************************************************************************	
				
			//Double
			cout<<"\n \n \n \n Int datatype\n \n \n \n \n";	
			My_vec<double>vd;    // define an object v of My_vec type
			vd.insert_at_rank(0,1.5);// insert 'B' at the rank 0 into the vector v
			cout<<"\nThe element(s) vd after insert are: "<<vd;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd: "<<vd.get_size()<<"\n";// display the vector v size

			vd.insert_at_rank(0,2.8);// insert 'A' at the rank 0 into the vector v
			cout<<"\nThe element(s) vd after insert are: "<<vd;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd: "<<vd.get_size()<<"\n";// display the vector v size

			vd.insert_at_rank(10,3.34);// insert 'D' at the rank 10 into the vector v
			cout<<"\nThe element(s) vd after insert are: "<<vd<<"\n";// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd: "<<vd.get_size()<<"\n";// display the vector v size

			//v = 'b';
			vd.remove_at_rank(1);// remove a character at the rank 2 from the vector v , but i replaced it at rank 1
			cout<<"\nThe element(s) vd after remove are: "<<vd;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd: "<<vd.get_size()<<"\n";// display the vector v size

			vd.replace_at_rank(2,4.89);// replace a character at the rank 2 by the character 'E' 
			cout<<"\nThe element(s) vd after replace are: "<<vd;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd: "<<vd.get_size()<<"\n";// display the vector v size

			My_vec<double> vd1 = vd;// create a copy v1 of the vector v using a copy constructor
			cout<<"\nThe element(s) of vd1 after copy from vd: "<<vd1;// use the overloaded operator << to display the vector v1
			cout<<"\nThe size of the vector vd1: "<<vd1.get_size()<<"\n";
			vd1.replace_at_rank(2,5.2);// replace a character at the rank 2 of the vector v1 with the character 'Y'
			cout<<"\nThe element(s) of vd1 after the replace: "<<vd1<<"\n";// use the overloaded operator << to display vector v1 elements

			My_vec<double> vd2;// define an object v2 of My_vec type
			vd2.insert_at_rank(0,1.11);// insert 'K' at the rank 0 into the vector v2
			cout<<"\nThe element(s) vd2 after insert are: "<<vd2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd2: "<<vd2.get_size()<<"\n";// display the vector v size

			vd2=vd1;// test the assignment operator and copy the vector v1 to v2 
			cout<<"\nThe element(s) v2 after copy from vd1: "<<vd2;// use the overloaded operator << to display vector elements
			cout<<"\nThe size of the vector vd2: "<<vd2.get_size()<<"\n";// display the vector v size

			//For that reason trying insert. Because we need some elements to find max index and sort_max
			vd2.insert_at_rank(0,8.3);
			vd2.insert_at_rank(0,4.5);
			vd2.insert_at_rank(0,9.1);
			vd2.insert_at_rank(0,7.8);
			vd2.insert_at_rank(0,6.6);
			cout<<"\nThe element(s) v after inserting elements: "<<vd2;
			cout<<"\nThe size of the vector v2 : "<<vd2.get_size()<<"\n";
			
			int maxd = find_max_index(vd2,vd2.get_size());// test the function find_max_index using v2
			cout<<"\nThe max index of vd2 is : "<<maxd<<"\n";
			cout<<"The element at the max index of vd2 is : "<<vd2[maxd]<<"\n";

			sort_max(vd2);// test the function sort_max using v2
			cout<<"\nThe sorted max for vd2 is: "<<vd2<<"\n";
			
			vi2.replace_at_rank(14,10.11);// replace in the vector v2 a character at the rank 14 with 10.11
			cout<<"The elements of the vector vd2 after replace are: "<<vd2<<"\n";
			cout<<"The size of the vector vd2: "<<vd2.get_size()<<"\n";
	
	}

		catch (exception &error){
			cerr << "Error: " << error.what() << endl;
		}
