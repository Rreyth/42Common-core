#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template <class T>
class Array
{
	public:
		Array(void) {
			elements = new T[0];
			arraySize = 0;
		}
	
		Array(unsigned int n) {
			elements = new T[n];
			for (unsigned int i = 0; i < n; i++)
				elements[i] = T();
			arraySize = n;
		}

		Array(const Array &obj){
			elements = NULL;
			*this = obj;
		}
	
		~Array() {
			delete [] elements;
		}

		Array	&operator=(const Array &obj) {
			if (elements)
				delete [] elements;
			elements = new T[obj.arraySize];
			for (unsigned int i = 0; i < obj.arraySize; i++)
				elements[i] = obj.elements[i];
			arraySize = obj.arraySize;
			return (*this);
		}

		T	&operator[](unsigned int n)
		{
			if (n >= arraySize)
				throw (std::out_of_range("number is out of the array"));
			return (elements[n]);
		}

		unsigned int	size() const {
			return (arraySize);
		}

	private:
		T				*elements;
		unsigned int	arraySize;
};

#endif