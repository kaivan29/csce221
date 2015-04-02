#include <ostream>

using namespace std;

class My_vec {

	//member variables
	int size, capacity;
	char *ptr;

public:
	//member functions
	My_vec();
	~My_vec();
	My_vec(const My_vec& vec); //what is this? It is a copy constructor
	My_vec& operator=(const My_vec& vec); //Why is this operator declared as a constructor?
	int get_size() const; //1
	int get_capacity() const; //2
	char& operator[](int i) const;  //******
	char& operator[](int i); //what do we do?
	bool is_empty() const;  //3
	char& elem_at_rank(int r) const;  //4
	void insert_at_rank(int r, const char& elem);  //5
 	void replace_at_rank(int r, const char& elem);  //6
	void remove_at_rank(int r);  //7

};

ostream& operator<<(ostream& out, const My_vec& vec);
int find_max_index(const My_vec& v, int size);
void sort_max(My_vec& vec);