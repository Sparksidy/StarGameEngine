#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H
#include <list>

enum class EVENT_TYPE
{
	COLLIDE,
	PLAYER_HIT,

	NUM
};

class Event
{
public:

	Event(EVENT_TYPE type);
	virtual ~Event(){};

public:
	EVENT_TYPE mType;
	float mtimer;


};


class EventManager
{
public:

	EventManager();
	~EventManager();
	void BroadcastEvent(Event* ev);
	void AddEvent(Event* ev);
	void Update(float frameTime);

public:
	std::list<Event *> mEvents;


};


#endif