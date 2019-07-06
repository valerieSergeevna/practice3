#pragma once
#include <cstddef>

class Iterator
{
public:
	virtual int operator*() const = 0;
	virtual void operator++(int) = 0;
	virtual bool operator==(const nullptr_t) const = 0;
	virtual bool operator!=(const nullptr_t) const = 0;
};