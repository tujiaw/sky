#ifndef SKY_UTIL_H
#define SKY_UTIL_H

#ifndef DISALLOW_COPY
#define DISALLOW_COPY(ClassName) \
	private: \
	ClassName(ClassName&); \
	void operator=(ClassName&);
#endif

#endif // SKY_UTIL_H