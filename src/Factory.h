#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include <map>

// Uncomment this if you want to see what it registered
//#include <typeinfo>

// Factory template is an implementation of common "Factory method pattern"
//   https://en.wikipedia.org/wiki/Factory_method_pattern
// It stores 'workers' in a vector. Each worker can create the desired 'product'
//   on demand, based on some 'input'. We register such workers by adding
//   functions which take this 'input' and depending on it's value create a 
//   specific 'product' or return NULL, and delegate the task to the next
//   worker.


// Factory template
template <class Product, class Key>
class Factory {
	typedef Product ProductType;
	typedef Key KeyType;
	// Generic worker class
	class Worker {
	public:
		virtual Product* Produce()=0;
	};
	// Type to store all the workers
	typedef std::map < Key, Worker* > Workers;
	typedef std::pair< Key, Worker* > Pair;
	// All the workers are kept here
	static Workers Staff;
	// Class to register workers with static member notation
	template <class T>
	class RegisterMe {
	public:
		inline RegisterMe(const Key& k) {
// Uncomment this if you want to see what it registered
			Staff.insert( Pair(k, new T));
		};
	};
public:
        // Main function for executing the production process
	static Product* Produce(const Key& key) {
	        typename Workers::iterator it = Staff.find(key);
	        if (it == Staff.end()) {
	                return NULL;
                } else {
                        return it->second->Produce();
                }
	};
	// Template class for registration of the worker functions
	template <class T>
	class Register : public Worker {
	        // Static member, which will register this worker in it's constructor
		typedef RegisterMe< Register< T > > Idiot;
		static Idiot Dummy;
	public:
		virtual Product* Produce() { return new T; };
	};	
};

// Definition of the static members:
//   All the workers ...
template <class Product, class Key>
typename Factory<Product, Key>::Workers
         Factory<Product, Key>::Staff;
//   All the Dummies
template <class Product, class Key>
template <class T>
typename Factory<Product, Key>::template Register< T >::Idiot
         Factory<Product, Key>::Register< T >::Dummy(T::id);


typedef Factory<Player, std::string> PlayerFactory;


#endif