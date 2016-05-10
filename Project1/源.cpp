#include "dick.h"
#include "RISales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"


using namespace std;
using std::vector;
using std::initializer_list;
using std::string;
using std::map;
using std::istringstream;
using std::placeholders::_1;
using std::placeholders::_2;

void print(struct Dick *dick);
int size();
int charToInt(char ch);
int getCount(int (&matrix)[4], int a);
void error_msg(initializer_list<string> il);
int randomString(string &s1, string &s2);
bool isShorter(const string &s1, const string &s2);
bool greaterThanFive(const string &s);
bool check_size(const string &s, int sz);
void word_transform(ifstream &map_file, ifstream &input);
map<string, string> buildMap(ifstream &map_file);
const string & transform(const string &s, const map<string, string> &m);
shared_ptr<vector<int>>  func();
shared_ptr<vector<int>>  add_val(shared_ptr<vector<int>> vec);
void print(shared_ptr<vector<int>> vec);

int main()
{	
	allocator<string> alloc;
	auto p = alloc.allocate(4);
	auto q = p;
	string s;
	while (q != p + 4 && cin >> s)
		alloc.construct(q++, s);
	q = p;
	while (q != p + 4)
		cout << *q++ << endl;

	while (q != p)
		alloc.destroy(--q);
	alloc.deallocate(p, 4);

	return 0;
}

bool check_size(const string &s, int sz)
{
	return s.size() <= sz;
}

bool greaterThanFive(const string &s)
{
	return s.size() >= 5;
}

bool isShorter(const string &s1, const string &s2) 
{
	return s1.size() < s2.size();
}

void print(struct Dick *dick)
{
	cout << dick -> name << "'s dick is " << dick -> length << " cm long & " <<
		dick -> width << " cm wide." << endl;
}

int charToInt(char ch)
{
	int res = ch - 0;
	return res;
}

int getCount(int (&matrix)[4], int a)
{
	for (auto i = begin(matrix); i != end(matrix); i++)
	{
		*i = a;
	}
	return 0;
}

void error_msg(initializer_list<string> il)
{
	for (auto i = il.begin(); i != il.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

int randomString(string &s1, string &s2)
{	
	char chs[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'k', 'l',
		'm', 'n' ,'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 10);
	uniform_int_distribution<> dist26(0, 25);
	int r = dist(gen);
	for (int i = 0; i < r; i++)
	{	
		s1 += chs[dist26(gen)];
		s2 += chs[dist26(gen)];
	}
	return 0;
}

void word_transform(ifstream &map_file, ifstream &input)
{
	auto trans_map = buildMap(map_file);
	string text;

	while (getline(input, text)) 
	{
		istringstream stream(text);
		string word;
		bool firstword = true;

		while (stream >> word)
		{
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}

}

map<string, string> buildMap(ifstream &map_file)
{
	map<string, string> trans_map;
	string key;
	string val;
	
	while (map_file >> key && getline(map_file, val))
	{
		if (val.size() > 1)
			trans_map[key] = val.substr(1);

		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

const string & transform(const string &s, const map<string, string> &m)
{
	auto map_it = m.find(s);
	
	if (map_it != m.cend())
		return map_it->second;
	else return s;
}

shared_ptr<vector<int>> func()
{
	return make_shared<vector<int>>();
}

shared_ptr<vector<int> > add_val(shared_ptr<vector<int>> vec)
{
	for (int i = 0; i < 10; i++) 
	{
		vec->push_back(i);
	}
	return vec;
}

void print(shared_ptr<vector<int>> vec)
{
	for (int i : *vec)
	{
		cout << i << " ";
	}
	cout << endl;
}