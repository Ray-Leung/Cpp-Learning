#pragma once
#include <string>
#include <ostream>

class Screen {

	friend class Window_mgr;

public:
	typedef std::string::size_type pos;

	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd),
		contents(ht * wd, ' ') {}
	Screen(pos ht, pos wd, char c) : height(ht), width(wd),
		contents(ht * wd, c) {}

	char get() const { return contents[cursor]; }
	Screen &set(char);
	Screen &set(pos, pos, char);
	pos size() const;
	inline char get(pos ht, pos wd) const;
	void some_member() const;
	Screen &move(pos r, pos c);
	Screen &display(std::ostream &os) {
		do_display(os);
		return *this; }

	const Screen &display(std::ostream &os) const {
		do_display(os);
		return *this; }

	Screen& clear(char c = bkground) { height = 0; 
	width = 0;
	contents = bkground;
	return *this; }

private:
	pos cursor = 0;
	pos height = 0, width = 0;
	std::string contents;
	static const char bkground;
	static constexpr char plain = ' ';
	static char initBkground() { return plain; }
	mutable size_t access_ctr;
	void do_display(std::ostream &os) const { os << contents; }
};

constexpr char Screen::plain;
const char Screen::bkground = initBkground();

extern std::ostream& storeOn(std::ostream &, Screen &);

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;

	return *this;
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r * width + col] = ch;
	return *this;
}

void Screen::some_member() const
{
	++access_ctr;
}

Screen::pos Screen::size() const
{
	return height * width;
}

