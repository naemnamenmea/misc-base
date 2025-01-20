#pragma once

#include <sstream>
#include <string>
#include <iostream>

#if (defined(__GNUC__) || defined(__GNUG__)) && !defined(__clang__)
// #if defined(linux) && __GNUC__ >= 4
#define KONTROL_EXCEPTION(errorText) \
	throw KontrolException(std::string(__func__) + _T(": ") + std::string(errorText))
#else
#define KONTROL_EXCEPTION(errorText) \
	throw KontrolException(std::string(_T(__FUNCTION__)) + _T(": ") + std::string(errorText))
#endif

class KontrolException
{
public:
	KontrolException(const KontrolException&) = default;
	KontrolException(const char* newMessage_) : m_data(newMessage_)
	{
	}
	KontrolException(const std::string& newMessage_) : m_data(newMessage_)
	{
	}
	KontrolException& operator=(const KontrolException& o_)
	{
		m_data = o_.m_data;
		return *this;
	}
	KontrolException& operator<<(const std::string& str_)
	{
		m_data += str_;
		return *this;
	}
	KontrolException& operator<<(const char* str_)
	{
		m_data += str_;
		return *this;
	}
	KontrolException& operator<<(char ch_)
	{
		m_buffer[0] = ch_;
		m_buffer[1] = '\0';
		m_data += m_buffer;
		return *this;
	}
	template <typename T>
	KontrolException& operator<<(const T&);
	operator const char*() const
	{
		return m_data.c_str();
	}
	operator char*() const
	{
		m_data.copy(m_buffer, m_data.length());
		return m_buffer;
	}

	std::string m_data;

private:
	static char m_buffer[];
};

inline std::ostream& operator<<(std::ostream& out, const KontrolException& msg)
{
	out << msg.m_data;
	return out;
}

inline void Assert(bool assertion_, const KontrolException& msg_)
{
	if (!assertion_)
		throw msg_;
}

template <typename T>
inline KontrolException& KontrolException::operator<<(const T& v_)
{
	/*#if !defined __BORLANDC__  ||  __BORLANDC__ >= 0x550
	 std::
	#endif*/
	/* ostrstream(Buffer,4) << v_ << '\0';
	 Data += Buffer;*/
	std::ostringstream os;
	os << v_;
	m_data += os.str();
	return *this;
}
