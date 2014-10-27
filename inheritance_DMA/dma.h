#ifndef DMA_H_
#define DMA_H_
#include <iostream>
     
// Base Class Using DMA
class baseDMA {
    private:
    	char * label;
    	int rating;
    public:
    	baseDMA(const char * l = "null", int r = 0);
    	baseDMA(const baseDMA & rs);
    	virtual ~baseDMA();
    	baseDMA & operator=(const baseDMA & rs);
    	friend std::ostream & operator<<(std::ostream & os,
    		const baseDMA & rs) {
    		os << "Label: " << rs.label << std::endl;
    		os << "Rating: " << rs.rating << std::endl;
    		return os;
    	}
};
     
// derived class without DMA
// no destructor needed
// uses implicit copy constructor
// uses implicit assignment operator
class lacksDMA :public baseDMA {
    private:
    	enum { COL_LEN = 40};
    	char color[COL_LEN];
    public:
    	lacksDMA(const char * c = "blank", const char * l = "null",
    	int r = 0);
    	lacksDMA(const char * c, const baseDMA & rs);
    	friend std::ostream & operator<<(std::ostream & os,
    		const lacksDMA & ls) {
    		os << (const baseDMA &) ls;
    		os << "Color: " << ls.color << std::endl;
    		return os;
    	}
};
     
// derived class with DMA
class hasDMA :public baseDMA {
    private:
    	char * style;
    public:
    	hasDMA(const char * s = "none", const char * l = "null",
    	int r = 0);
    	hasDMA(const char * s, const baseDMA & rs);
    	hasDMA(const hasDMA & hs);
    	~hasDMA();
    	hasDMA & operator=(const hasDMA & rs);
    	friend std::ostream & operator<<(std::ostream & os,
    		const hasDMA & hs) {
    		os << (const baseDMA &) hs;
    		os << "Style: " << hs.style << std::endl;
    		return os;
    	}
};
     
#endif


