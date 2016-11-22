#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <sstream>
#include <queue>
#include <limits> 
#include <typeinfo>

#include "./util/util.h"
#include "./util/buildDataStructure.h"


class animal
{
public:

	animal(const std::string &name)
	{
		this->name = name;
	}

	bool operator < (const animal &b)
	{
		return ord < b.ord;
	}

	void operator = (const animal &b)
	{
		ord = b.ord;
		name = b.name;
	}

	void setOrder(int order)
	{
		ord = order;
	}

	int getOrder()
	{
		return ord;
	}

	virtual void property() = 0;

protected:
	std::string name;
	int ord;

};

class cat : public animal
{
public:
	cat(const std::string &name):animal(name)
	{

	}
	void property()
	{
		std::cout<<"i am a cat "<<name<<" order is "<<ord<<std::endl;
	}
};

class dog : public animal
{
public:
	dog(const std::string &name):animal(name)
	{

	}
	void property()
	{
		std::cout<<"i am a dog "<<name<<" order is "<<ord<<std::endl;
	}
};

class animalQueue
{
public:
	animalQueue()
	{
		ord = 0;
	}

	void enqueue(animal* a)
	{
		a->setOrder(ord);
		ord++;
		if(typeid(*a) == typeid(cat))
		{		
			cat* c = dynamic_cast<cat*>(a);
			catQueue.push(*c);
		}
		else
		{
			dog* d = dynamic_cast<dog*>(a);
			dogQueue.push(*d);
		}

	}

	animal* deQueueAny()
	{
		animal* ret = NULL;
		if(dogQueue.empty())
		{
			ret = new cat(deQueueCat());
			*ret = deQueueCat();					
			return ret;
		}
		
		if(catQueue.empty())
		{
			ret = new dog("");
			*ret = deQueueDog();
			return ret;
		}

		if(catQueue.front() < dogQueue.front())
		{
			ret = new cat("");
			*ret = deQueueCat(); 			
		}
		else
		{
			ret = new dog("");
			*ret = deQueueDog();
			
		}

		return ret;
	}

	dog deQueueDog()
	{
		dog d = dogQueue.front();
		dogQueue.pop();
		return d;
	}

	cat deQueueCat()
	{
		cat c = catQueue.front();
		catQueue.pop();
		return c;
	}


private:
	int ord;
	std::queue<dog>  dogQueue;
	std::queue<cat>  catQueue;

};

int main()
{
	std::vector<int> input;
    while(!getIntArrayFromConsole(input));

    animalQueue aq;
    for(auto e : input)
    {
    	if(e%2)
    	{
    		dog d(std::to_string(e));
    		aq.enqueue(&d);
    	}
    	else
    	{
    		cat c(std::to_string(e));
    		aq.enqueue(&c);
    	}
    }

    std::cout<<"get the oldest animal ";
    aq.deQueueAny()->property();
    std::cout<<"get the oldest dog ";
    aq.deQueueDog().property();
    std::cout<<"get the oldest cat ";
    aq.deQueueCat().property();    
}